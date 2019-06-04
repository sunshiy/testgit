#include<iostream>

using namespace std;

#define MAX_TREE_SIZE 100
typedef char Telemtype;
typedef int status;

#define ok 1
#define error 0


//树的双亲表示法结构定义
typedef struct Pnode  //结点结构
{
	Telemtype data;
	int parent;   //双亲位置
}Pnode;

typedef struct //树结构
{
	Pnode nodes[MAX_TREE_SIZE];   //结点数组
	int r,n;    //根的位置和结点数
}Ptree;

/*
//树的孩子表示法结构定义
typedef struct CTNode     //定义树中的一个结点
{  
	int child;            //孩子结点的下标
	struct CTNode *next;  //指向下一个孩子结点的指针
}*ChildPtr;
 
//表头结构
typedef struct
{
	ElemType data;        //存放树中结点的数据
	int parent;           //存放双亲下标
	ChildPtr firstchild;  //指向第一个孩子的指针
}CTBox;
//树结构
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r;                //根的位置索引
	int n;                //树中结点的总数
}PCTree;

*/

//operation
void Inittree(Ptree *T);   //构造一颗空树
void Cleartree(Ptree *T);
status Treeempty(Ptree T);//判断是否为空
int Treedepth(Ptree T);   //求树的深度
status Root(Ptree T,Telemtype *value);
Telemtype Value(Ptree T,int cur_e);   //求cur_e结点的值
status Assign(Ptree *T,int cur_e,Telemtype value);  
Telemtype Parent(Ptree T,Telemtype cur_e);   //若cur_e是树T的非根节点，则返回它的双亲，否则返回空
Telemtype LeftChild(Ptree T,Telemtype cur_e);   //若cur_e是树T的非根节点，则返回它的最左孩子，否则返回空
Telemtype RightSibling(Ptree T,Telemtype cur_e);  //若cur_e是树T的非根节点，则返回它的右兄弟，否则返回空
//Insertchild(Tree *T,*p,i,c);  //若P指向树中的某个节点，操作结果为：插入c为树t中P指结点的第i颗子树
//DeleteChild(Tree *T，*p,i);


//定义
void Inittree(Ptree *T)   //构造一颗空树
{
	cout<<"请输入双亲表示法中树根的位置:";
    cin>>T->r;
    cout<<"请输入双亲表示法中树结点个数:";
    cin>>T->n;
    cout<<"请输入双亲表示法中树结点结构:"<<endl;
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

status Treeempty(Ptree T)   //判断是否为空
{
	if(T.n==0)
		return 1;
	else
		return 0;
}

int Treedepth(Ptree T)   //求树的深度
{
	int k,m,def,max;
 
	max = 0;
	//这里的方法在于找到最深的层
	for(k = 0;k<T.n;k++) 
	{
		def = 1;	//初始化本次顺寻中def的值
		m = T.nodes[k].parent;
 
		while(m != -1)   //当不是根节点
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

//给树的结点cur_e赋值为value
status Assign(Ptree *T,int cur_e,Telemtype value)
{
			T->nodes[cur_e].data=value;
			return ok;
}
 
 
/*
* @description:返回父亲节点的值
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
* @description:根据某个在树中的值，返回其左孩子的值
		这里认为最左边的为左孩子，不存在右孩子的说法
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
* @description:返回右兄弟的值(这里的右兄弟是指下一个与它有共同parent的节点)
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
* @description:返回左兄弟的值(这里的左兄弟是指上一个与它有共同parent的节点)
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
	cout<<"判断树是否为空？1:是，0：否,结果为："<<Treeempty(T)<<endl;
	cout<<"树的深度为："<< Treedepth(T)<<endl;
	Root(T,&e);
	cout<<"树的根节点为："<<e<<endl;
	int cur=2;
	cout<<"第三个结点的值为:"<<Value(T,2)<<endl;
	cout<<"返回元素B的双亲为："<< Parent(T,'B')<<endl;
	cout<<"返回元素C的左孩子为："<<LeftChild(T,'C')<<endl;
	system("pause");
	return 0;
}