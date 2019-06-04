//����������,ǰ�򴴽�����������������
#include <iostream>
#include <cstdlib>

using namespace std;

//�������Ķ��������洢�ṹ����
typedef enum{ Link, Thread } Pointertag;  //link==0��ʾָ�����Һ���ָ�� //thread==1��ʾǰ�����ߺ��ָ��
typedef  char Telemtype;
#define ok 1
#define error 0

typedef struct Bithrnode  //���������洢���ṹ
{
	Telemtype data;   //��� ����
	struct Bithrnode *lchild, *rchild;  //���Һ���ָ��
	Pointertag Ltag;
	Pointertag Rtag;   //���ұ�־
} Bithrnode, *Bithrtree;

Bithrtree pre = new Bithrnode;//ȫ�ֱ���
//ǰ�򴴽�������,������˳������ڵ�
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
	head->rchild = head;//��ָ���ָ
	head->Ltag = Link;
	head->Rtag = Thread;//����ͷ���
	if (!P)
	{
		head->lchild = head;//����
	}
	else {
		head->lchild = P;
		pre = head;
		Inthreading(P);//���������������������
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
			q = q->lchild;//������������ڵ�
	}
	return q;
}

//ʵ������������������������
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

	std::cout << "������ǰ�������������:\n";
	Createtree(t);//����������
	std::cout << "����������ing\n";
	InOrderThread_Head(temp, t); //����ͷ��㣬��������

	std::cout << "������������������:\n";
	Inordertraverse_thr(temp);
	std::cout << std::endl;

	system("pause");
	return 0;
}
//����:abdh##i##ej###cf##g##