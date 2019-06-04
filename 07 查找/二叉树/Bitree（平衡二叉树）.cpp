//平衡二叉树，或者称为AVL树
#include<iostream>

using namespace std;

typedef int status;

#define true 1
#define false 0

#define LH +1   //左高
#define EH 0     //等高
#define RH -1     //右高


//二叉链表结点结构定义
typedef struct Bitnode
{
	int data;
	int bf;    //储存结点的平衡因子
	struct Bitnode *left,*right;
}Bitnode,*Bitree;


   //操作
void R_rotate(Bitree *p);
void L_rotate(Bitree *p);
void Leftbalance(Bitree *T);
void Rightbalance(Bitree *T);
status Insertavl(Bitree *T,int e,status *taller);
void Createavl(Bitree *T,int a[],int n);
void Showbst(Bitree T);       //中序遍历输出二叉树
   

//f指向T的双亲，当T指向根节点时，因此f的初始调用值为Null
//查找成功，指针p指向该数据元素的结点，返回TRUE
//查找失败，P指向查找路径上访问的最后一个元素，返回false
Bitree Searchavl(Bitree T,int key)
{
	if (!T) 
		return NULL;

    //搜索到  
    if (key==T->data)
        return T;
    else if (key<T->data)
    {
        //在左子树中搜索  
        return Searchavl(T->left,key);
    }
    else
    {
        //在右子树中搜索  
        return  Searchavl(T->right,key);
    }
}


//对以p为根的二叉排序树做右旋处理。处理之后p指向新的树根节点
//即旋转之前的左子树的根节点
void R_rotate(Bitree *p)
{
	Bitree L;
	L=(*p)->left;
	(*p)->left=L->right;
	L->right=*p;
	*p=L;
}

//对以p为根的二叉排序树做左旋处理。处理之后p指向新的树根节点
//即旋转之前的左子树的根节点
void L_rotate(Bitree *p)
{
	Bitree R;
	R=(*p)->right;
	(*p)->right=R->left;
	R->left=*p;
	*p=R;
}
//对以T为根的二叉排序树做左旋平衡处理
//处理之后T指向新的树根节点
void Leftbalance(Bitree *T)
{
	Bitree L,Lr;
	L=(*T)->left;  //L指向T的左子树根结点
	switch(L->bf)
	{
		//检查T左子树的平衡度，并做相应的处理
	case LH:  //新节点插入在T的左孩子的左子树上，要做单右旋处理
		(*T)->bf=L->bf=EH;
		R_rotate(T);
		break;
    case RH:    //新节点插入在T的左孩子的右子树上，要做单右旋处理
		Lr=L->right;  //Lr指向T的左孩子的右子树根
		switch(Lr->bf)
		{
		case LH: 
			(*T)->bf=RH;
			L->bf=EH;
			break;
		case EH:
			(*T)->bf=L->bf=RH;
			break;
		case RH:
			(*T)->bf=EH;
			L->bf=LH;
			break;
		}
		Lr->bf=EH;
		L_rotate(&(*T)->left);
		R_rotate(T);
	}
}


//T 的右边高，不平衡，使其平衡，左旋转，左旋转前先检查R->bf
//如果为LH，R要先进行右旋转，使T->rchild->bf和T->bf一致
void Rightbalance(Bitree *T)
{
    Bitree R,Rl;
    R = (*T)->right;
    Rl = R->left;
    switch(R->bf)
    {
        case RH:
            R->bf = (*T)->bf = EH;
            L_rotate(T);
            break;
        case LH:
            switch(R->bf)
            {
                case LH:
                    R->bf = RH;
                    (*T)->bf = EH;
                    break;
                case EH:
                    R->bf = (*T)->bf = EH;
                    break;
                case RH:
                    R->bf = EH;
                    (*T)->bf = LH;
                    break;
            }
            Rl->bf = EH;
            R_rotate(&R);
            L_rotate(T);
            break;
    }
}

//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个
//数据元素为e的新节点并返回1，否则返回0
//若因插入使得二叉树失去平衡，则做平衡旋转，布尔变量taller反映T长高与否
status Insertavl(Bitree *T,int e,status *taller)
{
	if(!*T)
	{
		//插入新节点，树长高，taller为true
		*T=(Bitree)malloc(sizeof(Bitnode));
		(*T)->data=e;
		(*T)->left=(*T)->right=NULL;
		(*T)->bf=EH;
		*taller=true;
	}
	else
	{
		if(e==(*T)->data)
		{
			//树中存在和e有相同关键字的结点将不再插入
			*taller=false;
			return false;
		}
		if(e<(*T)->data)
		{
			//应继续在t的左子树中进行搜索
			if(!Insertavl(&(*T)->left,e,taller))
				return false;
			if(*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					Leftbalance(T);
					*taller=false;
					break;
				case EH:
					(*T)->bf=LH;
					*taller=true;
					break;
				case RH:
					(*T)->bf=EH;
					*taller=false;
					break;
				}
			}
		}
		else
		{
			if(!Insertavl(&(*T)->right,e,taller))
				return false;
			if(*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					(*T)->bf=EH;
					*taller=false;
					break;
				case EH:
					(*T)->bf=RH;
					*taller=true;
					break;
				case RH:
					Rightbalance(T);
					*taller=false;
					break;
				}
			}
		}
	}
	return true;
}

void Createavl(Bitree *T,int a[],int n)
{
	int i;
	status taller;
	for(i=0;i<n;i++)
	{
		Insertavl(T,a[i],&taller);
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
	status taller=0;

	//创建二叉排序树
	Createavl(&T,a,10);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;


	//在二叉排序树中插入56
	Insertavl(&T,56,&taller);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;


	int b=58;  //需要查找的值
	Bitree p=NULL;
	T=Searchavl(T,b);
	cout<<"查找结果为:\n"<<"指针："<<T<<endl
		<<"指针的值为："<<T->data<<endl;


	system("pause");
	return 0;
}