//��ѭ������Ĳ���������ͷ���
//˵����ͷ����ͷָ�������
//ͷָ����һ���еģ�û��ͷ���ʱָ���һ���ڵ�
//��ͷ���ʱָ��ͷ��㡣

#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 100
#define error 0
#define ok 1
typedef int status;
typedef int Elemtype;

///���Ա�ĵ�����洢�ṹ
typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode;
typedef LNode *LinkList;   //��������Linklist
//���Ƕ���һ���ṹ�壬����ṹ�����������ԣ�һ����int���͵�data; ��һ��������ṹ�屾�����͵�ָ��next;
//������ṹ������һ��ָ�����:LinkList;
//Node a; ����һ��struct Node�ṹ�����͵Ľṹ�����a;
//LinkList b; �ȼ��� struct Node* b; �ȼ��� Node *b; ����һ��struct Node�ṹ�����͵�ָ����� b;


//����
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


//��ʼ��������һ��ͷ���
status InitList(LinkList *L)
{
	*L = new LNode;    //ͷ���
	(*L)->next = nullptr;
	return ok;
}

//ɾ����������
status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;   //pָ���һ�����
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

//������ĳ���
int ListLength(LinkList L)
{
	int length = 0;
	LinkList p;
	p = L->next;   //pָ���һ�����
	while (p)
	{
		p = p->next;
		++length;
	}
	return length;
}


//���
void TraveList(LinkList L)
{
	LinkList p;
	p = L->next;    //pָ������ĵ�һ�����
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}


//Ԫ�صĻ�ȡ
status GetElem(LinkList L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p;   //����һ��ָ�����p
	p = L->next;   //��pָ������L�ĵ�һ�����
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

//����Ԫ��
status ListInsert(LinkList *L, int i, Elemtype e)
{
	int j = 1;
	LinkList p, s;
	p = *L;             //Pָ�������ͷ���
	while (p && j<i)
	{
		p = p->next;
		j++;
	}

	if (!p || j>i)
		return error;
	s = new LNode;
	//������
	s->data = e;
	s->next = p->next;
	p->next = s;
	return ok;
}


//ɾ��Ԫ��
status ListDelete(LinkList *L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p, q;
	p = *L;              //Pָ�������ͷ���
	while (p && j<i)
	{
		p = p->next;
		j++;
	}

	if (!p || j>i)
		return error;

	//ɾ�����
	q = p->next;
	p->next = q->next;
	*e = q->data;
	delete q;
	return ok;
}

//�������������õķ�ʽ��ͷ�巨
status CreateListHead(LinkList *L, int n)
{
	LinkList p;
	*L = new LNode;
	(*L)->next = NULL;

	for (int i = 0; i<n; i++)
	{
		cout << "�������" << i + 1 << "��Ԫ�ص�ֵ:";
		p = new LNode;
		cin >> p->data;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return ok;

}

//�������������õķ�ʽ��β�巨
status CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	*L = new LNode;
	(*L)->next = NULL;
	r = *L;
	for (int i = 0; i<n; i++)
	{
		cout << "������" << i + 1 << "��Ԫ�ص�ֵ:";
		p = new LNode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return ok;
}

/* ����ת�������ڴ�汾(ͷ�巨) */
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

/* ����ת�����������ڴ�汾(�������Ͻ����޸�) */
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
	printf("��ʼ��L��L.length=%d\n", ListLength(L));

	cout << "����ĳ���Ϊ:" << endl;
	int n;
	cin >> n;
	i = CreateListHead(&L, n);
	TraveList(L);
	i = InitList(&L);


	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1��5��L.data=");
	TraveList(L);


	printf("L.length=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);


	i = ClearList(&L);
	printf("���L��L.length=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);


	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1��10��L.data=");
	TraveList(L);
	printf("L.length=%d \n", ListLength(L));


	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	TraveList(L);
	printf("L.length=%d \n", ListLength(L));


	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);


	j = 5;
	ListDelete(&L, j, &e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);


	printf("�������L��Ԫ�أ�");
	TraveList(L);


	//����һ����10������Lb
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);

	printf("�������Lb��Ԫ�أ�");
	TraveList(Lb);


	LinkList LR0;
	ListReverse0(L, &LR0);  //��ת����
	TraveList(LR0);

	ListReverse1(&L);
	TraveList(L);

	system("pause");
}