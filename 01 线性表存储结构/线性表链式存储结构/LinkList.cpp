//单循环链表的操作，包含头结点
//说明：头结点和头指针的区别
//头指针是一定有的，没有头结点时指向第一个节点
//有头结点时指向头结点。

#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 100
#define error 0
#define ok 1
typedef int status;
typedef int Elemtype;

///线性表的单链表存储结构
typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode;
typedef LNode *LinkList;   //定义链表Linklist
//这是定义一个结构体，这个结构体有两个属性，一个是int类型的data; 另一个是这个结构体本身类型的指针next;
//给这个结构定义了一个指针别名:LinkList;
//Node a; 声明一个struct Node结构体类型的结构体变量a;
//LinkList b; 等价于 struct Node* b; 等价于 Node *b; 声明一个struct Node结构体类型的指针变量 b;


//操作
status InitList(LinkList *L);
status ClearList(LinkList *L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
void TraveList(LinkList L);
status GetElem(LinkList L, int i, Elemtype *e);
status ListInsert(LinkList *L, int i, Elemtype e);
status ListDelete(LinkList *L, int i, Elemtype *e);
status CreateListHead(LinkList *L, int n);
status CreateListTail(LinkList *L, int n);
status ListReverse0(LinkList L, LinkList *LR);
status ListReverse1(LinkList *L);


//初始化，加了一个头结点
status InitList(LinkList *L)
{
	*L = new LNode;    //头结点
	(*L)->next = nullptr;
	return ok;
}

//删除整个链表
status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;   //p指向第一个结点
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	(*L)->next = NULL;
	return ok;
}

status ListEmpty(LinkList L)
{
	LinkList p;
	p = L;
	if (L->next == NULL)
		return ok;
	return error;
}

//求链表的长度
int ListLength(LinkList L)
{
	int length = 0;
	LinkList p;
	p = L->next;   //p指向第一个结点
	while (p)
	{
		p = p->next;
		++length;
	}
	return length;
}


//输出
void TraveList(LinkList L)
{
	LinkList p;
	p = L->next;    //p指向链表的第一个结点
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}


//元素的获取
status GetElem(LinkList L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p;   //声明一个指针变量p
	p = L->next;   //将p指向链表L的第一个结点
	while (p &&j<i)
	{
		p = p->next;
		++j;
	}

	if (!p || j>i)
		return error;
	*e = p->data;
	return ok;
}

//插入元素
status ListInsert(LinkList *L, int i, Elemtype e)
{
	int j = 1;
	LinkList p, s;
	p = *L;             //P指向链表的头结点
	while (p && j<i)
	{
		p = p->next;
		j++;
	}

	if (!p || j>i)
		return error;
	s = new LNode;
	//插入结点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return ok;
}


//删除元素
status ListDelete(LinkList *L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p, q;
	p = *L;              //P指向链表的头结点
	while (p && j<i)
	{
		p = p->next;
		j++;
	}

	if (!p || j>i)
		return error;

	//删除结点
	q = p->next;
	p->next = q->next;
	*e = q->data;
	delete q;
	return ok;
}

//创建链表，传引用的方式，头插法
status CreateListHead(LinkList *L, int n)
{
	LinkList p;
	*L = new LNode;
	(*L)->next = NULL;

	for (int i = 0; i<n; i++)
	{
		cout << "请输入第" << i + 1 << "个元素的值:";
		p = new LNode;
		cin >> p->data;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return ok;

}

//创建链表，传引用的方式，尾插法
status CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	*L = new LNode;
	(*L)->next = NULL;
	r = *L;
	for (int i = 0; i<n; i++)
	{
		cout << "请输入" << i + 1 << "个元素的值:";
		p = new LNode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return ok;
}

/* 链表翻转：申请内存版本(头插法) */
status ListReverse0(LinkList L, LinkList *LR)
{
	if (ListEmpty(L) || !(*LR))
		return error;

	LinkList p, s;
	*LR = (LinkList)malloc(sizeof(LNode));
	(*LR)->next = NULL;
	p = L->next;
	while (p)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = p->data;
		s->next = (*LR)->next;
		(*LR)->next = s;
		p = p->next;
	}
	return ok;
}

/* 链表翻转：不得申请内存版本(在自身上进行修改) */
status ListReverse1(LinkList *L)
{
	if (ListEmpty(*L) || !(*L))
		return error;
	LinkList p, q, r;
	p = (*L)->next;
	q = p->next;
	p->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	(*L)->next = p;
	return ok;
}

int main()
{
	LinkList L;
	LinkList Lb;

	Elemtype e;
	status i;

	int j, k;
	i = InitList(&L);
	printf("初始化L后：L.length=%d\n", ListLength(L));

	cout << "链表的长度为:" << endl;
	int n;
	cin >> n;
	i = CreateListHead(&L, n);
	TraveList(L);
	i = InitList(&L);


	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	TraveList(L);


	printf("L.length=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);


	i = ClearList(&L);
	printf("清空L后：L.length=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);


	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	TraveList(L);
	printf("L.length=%d \n", ListLength(L));


	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	TraveList(L);
	printf("L.length=%d \n", ListLength(L));


	GetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);


	j = 5;
	ListDelete(&L, j, &e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", j, e);


	printf("依次输出L的元素：");
	TraveList(L);


	//构造一个有10个数的Lb
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);

	printf("依次输出Lb的元素：");
	TraveList(Lb);


	LinkList LR0;
	ListReverse0(L, &LR0);  //翻转链表
	TraveList(LR0);

	ListReverse1(&L);
	TraveList(L);

	system("pause");
}