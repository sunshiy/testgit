//二叉排序树
#include<iostream>

using namespace std;

typedef int status;
#define true 1
#define false 0

//二叉链表结点结构定义
typedef struct Bitnode
{
	int data;
	struct Bitnode *left,*right;
}Bitnode,*Bitree;



//操作
status Searchbst(Bitree T,int key,Bitree f,Bitree *p);
status Insertbst(Bitree *T,int key);
status Delete(Bitree *p);
status Deletebst(Bitree *T,int key);
void Createbst(Bitree *T,int a[],int n);
void Showbst(Bitree T);  //中序遍历输出二叉树


//二叉排序树的查找，查找T中是否存在Key

//f指向T的双亲，当T指向根节点时，因此f的初始调用值为Null
//查找成功，指针p指向该数据元素的结点，返回TRUE
//查找失败，P指向查找路径上访问的最后一个元素，返回false
status Searchbst(Bitree T,int key,Bitree f,Bitree *p)
{
	if(!T)    //查找不成功，用来判断当前二叉树是否到叶子结点
	{
		*p=f;
		return false;
	}
	else if(key==T->data)   //查找成功
	{
		*p=T;
		return true;
	}
	else if(key<T->data)
		return Searchbst(T->left,key,T,p);
	else
		return Searchbst(T->right,key,T,p);
}

//二叉排序树的插入操作
//当T中不存在关键字等于key的数据元素时，插入key并返回true，否则返回FALSE
status Insertbst(Bitree *T,int key)
{
	Bitree p,s;
	if(!Searchbst(*T,key,NULL,&p))   //如果查找不成功
	{
		s=(Bitree)malloc(sizeof(Bitnode));
		s->data=key;
		s->left=s->right=NULL;

		if(!p)    //此时的p指向查找路径上访问的最后一个元素,如果p为空，即p=Null
			*T=s;
		else if(key<p->data)
			p->left=s;
		else
			p->right=s;
		return true;
	}
	else            //如果查找成功
		return false;
}


//二叉排序树的删除操作
//当T中存在关键字等于key的数据元素时，删除该数据元素结点

status Deletebst(Bitree *T,int key)
{
	if(!*T)   //不存在关键字等于key的数据元素
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


//从二叉排序树中删除结点p，并重接它的左子树或者右子树
status Delete(Bitree *p)
{
	Bitree q,s;
	if((*p)->right==NULL)   //右子树为空
	{
		q=*p;
		*p=(*p)->left;
		free(q);
	}
	else if((*p)->left==NULL)   //左子树为空
	{
		q=*p;
		*p=(*p)->right;
		free(q);
	}
	else   //左右子树均不为空
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
			q->right=s->left;   //重接q的右子树
		else
			q->left=s->left;  //重接q的左子树
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

	//创建二叉排序树
	Createbst(&T,a,10);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;

	//在二叉排序树中查找结点
	int b=58;  //需要查找的值
	Bitree p=NULL;
	if(!Searchbst(T,b,NULL,&p))
		cout<<"没有查找到！"<<endl;
	else
		cout<<"查找结果为:\n"<<"指针："<<p<<endl
		<<"指针的值为："<<p->data<<endl;


	//在二叉排序树中插入56
	Insertbst(&T,56);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;


	//在二叉排序树中删除56
	Deletebst(&T,56);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;


	system("pause");
	return 0;
}