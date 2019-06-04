#include<iostream>

using namespace std;

#define MAX_TREE_SIZE 100
typedef char Telemtype;
typedef int status;

#define ok 1
#define error 0


//����˫�ױ�ʾ���ṹ����
typedef struct Pnode  //���ṹ
{
	Telemtype data;
	int parent;   //˫��λ��
}Pnode;

typedef struct //���ṹ
{
	Pnode nodes[MAX_TREE_SIZE];   //�������
	int r,n;    //����λ�úͽ����
}Ptree;

/*
//���ĺ��ӱ�ʾ���ṹ����
typedef struct CTNode     //�������е�һ�����
{  
	int child;            //���ӽ����±�
	struct CTNode *next;  //ָ����һ�����ӽ���ָ��
}*ChildPtr;
 
//��ͷ�ṹ
typedef struct
{
	ElemType data;        //������н�������
	int parent;           //���˫���±�
	ChildPtr firstchild;  //ָ���һ�����ӵ�ָ��
}CTBox;
//���ṹ
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r;                //����λ������
	int n;                //���н�������
}PCTree;

*/

//operation
void Inittree(Ptree *T);   //����һ�ſ���
void Cleartree(Ptree *T);
status Treeempty(Ptree T);//�ж��Ƿ�Ϊ��
int Treedepth(Ptree T);   //���������
status Root(Ptree T,Telemtype *value);
Telemtype Value(Ptree T,int cur_e);   //��cur_e����ֵ
status Assign(Ptree *T,int cur_e,Telemtype value);  
Telemtype Parent(Ptree T,Telemtype cur_e);   //��cur_e����T�ķǸ��ڵ㣬�򷵻�����˫�ף����򷵻ؿ�
Telemtype LeftChild(Ptree T,Telemtype cur_e);   //��cur_e����T�ķǸ��ڵ㣬�򷵻����������ӣ����򷵻ؿ�
Telemtype RightSibling(Ptree T,Telemtype cur_e);  //��cur_e����T�ķǸ��ڵ㣬�򷵻��������ֵܣ����򷵻ؿ�
//Insertchild(Tree *T,*p,i,c);  //��Pָ�����е�ĳ���ڵ㣬�������Ϊ������cΪ��t��Pָ���ĵ�i������
//DeleteChild(Tree *T��*p,i);


//����
void Inittree(Ptree *T)   //����һ�ſ���
{
	cout<<"������˫�ױ�ʾ����������λ��:";
    cin>>T->r;
    cout<<"������˫�ױ�ʾ������������:";
    cin>>T->n;
    cout<<"������˫�ױ�ʾ���������ṹ:"<<endl;
    for(int i=0;i<T->n;i++)
    {
        cin>>T->nodes[i].data>>T->nodes[i].parent;
    }

    cout<<"index"<<"\t"<<"data"<<"\t"<<"parent"<<endl;

    for(int i=0;i<T->n;i++)
    {
        cout<<i<<"\t"<<T->nodes[i].data<<"\t"  <<T->nodes[i].parent<<endl;
    }
}

void Cleartree(Ptree *T)
{
	T->n=0;
}

status Treeempty(Ptree T)   //�ж��Ƿ�Ϊ��
{
	if(T.n==0)
		return 1;
	else
		return 0;
}

int Treedepth(Ptree T)   //���������
{
	int k,m,def,max;
 
	max = 0;
	//����ķ��������ҵ�����Ĳ�
	for(k = 0;k<T.n;k++) 
	{
		def = 1;	//��ʼ������˳Ѱ��def��ֵ
		m = T.nodes[k].parent;
 
		while(m != -1)   //�����Ǹ��ڵ�
		{
			m = T.nodes[m].parent;
			def++;
		}
	}
 
	if(max < def)
		max = def;
 
	return max;
}

status Root(Ptree T,Telemtype *value)	
{
	if(!Treeempty(T))
		*value=T.nodes[0].data;
	else
		return error;

	return ok;
}

Telemtype Value(Ptree T,int cur_e)
{
	return T.nodes[cur_e].data;

}

//�����Ľ��cur_e��ֵΪvalue
status Assign(Ptree *T,int cur_e,Telemtype value)
{
			T->nodes[cur_e].data=value;
			return ok;
}
 
 
/*
* @description:���ظ��׽ڵ��ֵ
*/
Telemtype Parent(Ptree T,Telemtype cur_e) 
{
	int i;
 
	for(i = 0; i < T.n; i++)
		if(T.nodes[i].data == cur_e)
			return T.nodes[T.nodes[i].parent].data;
 
	return NULL;
}
 
 
/*
* @description:����ĳ�������е�ֵ�����������ӵ�ֵ
		������Ϊ����ߵ�Ϊ���ӣ��������Һ��ӵ�˵��
*/
Telemtype LeftChild(Ptree T,Telemtype cur_e) 
{
	int i,j;
 
	for(i = 0;i < T.n;i++)
		if(T.nodes[i].data == cur_e)
			break;
	for(j = i+1;j < T.n ;j++)
		if(T.nodes[j].parent == i)
			return T.nodes[j].data;
	
	return NULL;
}
 
/*
* @description:�������ֵܵ�ֵ(��������ֵ���ָ��һ�������й�ͬparent�Ľڵ�)
*/
Telemtype RightSibling(Ptree T,Telemtype cur_e)
{
	int i;
 
	for(i = 0;i < T.n; i++)
		if(T.nodes[i].data == cur_e)
			break;
	
	if(T.nodes[i].parent == T.nodes[i+1].parent )
		return T.nodes[i+1].data;
 
	return NULL;
}
 
 
 
/*
* @description:�������ֵܵ�ֵ(��������ֵ���ָ��һ�������й�ͬparent�Ľڵ�)
*/
Telemtype LeftSibling(Ptree T,Telemtype cur_e) 
{
	int i;
 
	for(i = 0;i < T.n; i++)
		if(T.nodes[i].data == cur_e)
			break;
	
	if(T.nodes[i-1].parent == T.nodes[i].parent )
		return T.nodes[i-1].data;
 
	return NULL;
}


int main()
{
	Ptree T;
	Inittree(&T);

	Telemtype e;
	cout<<"�ж����Ƿ�Ϊ�գ�1:�ǣ�0����,���Ϊ��"<<Treeempty(T)<<endl;
	cout<<"�������Ϊ��"<< Treedepth(T)<<endl;
	Root(T,&e);
	cout<<"���ĸ��ڵ�Ϊ��"<<e<<endl;
	int cur=2;
	cout<<"����������ֵΪ:"<<Value(T,2)<<endl;
	cout<<"����Ԫ��B��˫��Ϊ��"<< Parent(T,'B')<<endl;
	cout<<"����Ԫ��C������Ϊ��"<<LeftChild(T,'C')<<endl;
	system("pause");
	return 0;
}