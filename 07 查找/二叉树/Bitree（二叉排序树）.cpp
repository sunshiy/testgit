//����������
#include<iostream>

using namespace std;

typedef int status;
#define true 1
#define false 0

//����������ṹ����
typedef struct Bitnode
{
	int data;
	struct Bitnode *left,*right;
}Bitnode,*Bitree;



//����
status Searchbst(Bitree T,int key,Bitree f,Bitree *p);
status Insertbst(Bitree *T,int key);
status Delete(Bitree *p);
status Deletebst(Bitree *T,int key);
void Createbst(Bitree *T,int a[],int n);
void Showbst(Bitree T);  //����������������


//�����������Ĳ��ң�����T���Ƿ����Key

//fָ��T��˫�ף���Tָ����ڵ�ʱ�����f�ĳ�ʼ����ֵΪNull
//���ҳɹ���ָ��pָ�������Ԫ�صĽ�㣬����TRUE
//����ʧ�ܣ�Pָ�����·���Ϸ��ʵ����һ��Ԫ�أ�����false
status Searchbst(Bitree T,int key,Bitree f,Bitree *p)
{
	if(!T)    //���Ҳ��ɹ��������жϵ�ǰ�������Ƿ�Ҷ�ӽ��
	{
		*p=f;
		return false;
	}
	else if(key==T->data)   //���ҳɹ�
	{
		*p=T;
		return true;
	}
	else if(key<T->data)
		return Searchbst(T->left,key,T,p);
	else
		return Searchbst(T->right,key,T,p);
}

//�����������Ĳ������
//��T�в����ڹؼ��ֵ���key������Ԫ��ʱ������key������true�����򷵻�FALSE
status Insertbst(Bitree *T,int key)
{
	Bitree p,s;
	if(!Searchbst(*T,key,NULL,&p))   //������Ҳ��ɹ�
	{
		s=(Bitree)malloc(sizeof(Bitnode));
		s->data=key;
		s->left=s->right=NULL;

		if(!p)    //��ʱ��pָ�����·���Ϸ��ʵ����һ��Ԫ��,���pΪ�գ���p=Null
			*T=s;
		else if(key<p->data)
			p->left=s;
		else
			p->right=s;
		return true;
	}
	else            //������ҳɹ�
		return false;
}


//������������ɾ������
//��T�д��ڹؼ��ֵ���key������Ԫ��ʱ��ɾ��������Ԫ�ؽ��

status Deletebst(Bitree *T,int key)
{
	if(!*T)   //�����ڹؼ��ֵ���key������Ԫ��
		return false;
	else
	{
		if(key==(*T)->data)
			return Delete(T);
		else if(key<(*T)->data)
			return Deletebst(&(*T)->left,key);
		else
			return Deletebst(&(*T)->right,key);
	}
}


//�Ӷ�����������ɾ�����p�����ؽ���������������������
status Delete(Bitree *p)
{
	Bitree q,s;
	if((*p)->right==NULL)   //������Ϊ��
	{
		q=*p;
		*p=(*p)->left;
		free(q);
	}
	else if((*p)->left==NULL)   //������Ϊ��
	{
		q=*p;
		*p=(*p)->right;
		free(q);
	}
	else   //������������Ϊ��
	{
		q=*p;
		s=(*p)->left;
		while(s->right)
		{
			q=s;
			s=s->right;
		}
		(*p)->data=s->data;
		if(q!=*p)
			q->right=s->left;   //�ؽ�q��������
		else
			q->left=s->left;  //�ؽ�q��������
		free(s);
	}
	return false;
}


void Createbst(Bitree *T,int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Insertbst(T,a[i]);
	}
}


void Showbst(Bitree T)
{
	if(T)
	{
		Showbst(T->left);
		cout<<T->data<<" ";
		Showbst(T->right);
	}
}

int main()
{
	int a[]={62,88,58,47,35,73,51,99,37,93};

	Bitree T=NULL;

	//��������������
	Createbst(&T,a,10);
	cout<<"��������Ľ��Ϊ��"<<endl;
	Showbst(T);
	cout<<endl;

	//�ڶ����������в��ҽ��
	int b=58;  //��Ҫ���ҵ�ֵ
	Bitree p=NULL;
	if(!Searchbst(T,b,NULL,&p))
		cout<<"û�в��ҵ���"<<endl;
	else
		cout<<"���ҽ��Ϊ:\n"<<"ָ�룺"<<p<<endl
		<<"ָ���ֵΪ��"<<p->data<<endl;


	//�ڶ����������в���56
	Insertbst(&T,56);
	cout<<"��������Ľ��Ϊ��"<<endl;
	Showbst(T);
	cout<<endl;


	//�ڶ�����������ɾ��56
	Deletebst(&T,56);
	cout<<"��������Ľ��Ϊ��"<<endl;
	Showbst(T);
	cout<<endl;


	system("pause");
	return 0;
}