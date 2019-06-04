//线索二叉树,前序创建二叉树，中序线索
#include <iostream>
#include <cstdlib>

using namespace std;

//二叉树的二叉线索存储结构定义
typedef enum{ Link, Thread } Pointertag;  //link==0表示指向左右孩子指针 //thread==1表示前驱或者后继指针
typedef  char Telemtype;
#define ok 1
#define error 0

typedef struct Bithrnode  //二叉线索存储结点结构
{
	Telemtype data;   //结点 数据
	struct Bithrnode *lchild, *rchild;  //左右孩子指针
	Pointertag Ltag;
	Pointertag Rtag;   //左右标志
} Bithrnode, *Bithrtree;

Bithrtree pre = new Bithrnode;//全局变量
//前序创建二叉树,按先序顺序输入节点
void Createtree(Bithrtree &T)
{
	Telemtype ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
		return;
	}
	else
	{
		T = (Bithrtree)malloc(sizeof(Bithrnode));
		if (!T)
			exit(1);
		T->data = ch;
		T->Ltag = Link;
		T->Rtag = Link;
		Createtree(T->lchild);
		Createtree(T->rchild);
	}
}


void Inthreading(Bithrtree P)
{
	if (P) {
		Inthreading(P->lchild);
		if (!P->lchild)
		{
			P->Ltag = Thread;
			P->lchild = pre;
		}
		else P->Ltag = Link;

		if (!pre->rchild)
		{
			pre->Rtag = Thread;
			pre->rchild = P;
		}
		else P->Rtag = Link;
		pre = P;
		Inthreading(P->rchild);
	}
}



void InOrderThread_Head(Bithrtree &head, Bithrtree &P)
{
	head = (Bithrnode*)malloc(sizeof(Bithrnode));
	head->rchild = head;//右指针回指
	head->Ltag = Link;
	head->Rtag = Thread;//建立头结点
	if (!P)
	{
		head->lchild = head;//空树
	}
	else {
		head->lchild = P;
		pre = head;
		Inthreading(P);//中序遍历进行中序线索化
		pre->Rtag = Thread;
		pre->rchild = head;
		head->rchild = pre;
	}
}

Bithrtree InNext(Bithrtree p)
{
	Bithrtree q;
	if (p->Rtag == Thread)
	{
		q = p->rchild;
	}
	else
	{
		q = p->rchild;
		while (q->Ltag == Link)
			q = q->lchild;//右子树的最左节点
	}
	return q;
}

//实现中序线索链表的中序遍历。
void Inordertraverse_thr(Bithrtree T)
{
	Bithrtree p = T->lchild;

	while (p->Ltag == Link)
	{
		p = p->lchild;
	}
	while (p != T)
	{
		std::cout << p->data;
		p = InNext(p);
	}

}

int main()
{
	Bithrtree t = NULL;
	Bithrtree temp;

	pre->Rtag = Thread;
	pre->rchild = NULL;

	std::cout << "请输入前序二叉树的内容:\n";
	Createtree(t);//建立二叉树
	std::cout << "中序线索化ing\n";
	InOrderThread_Head(temp, t); //加入头结点，并线索化

	std::cout << "输出中序二叉树的内容:\n";
	Inordertraverse_thr(temp);
	std::cout << std::endl;

	system("pause");
	return 0;
}
//输入:abdh##i##ej###cf##g##