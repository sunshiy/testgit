#include<iostream>
#include<cstdlib>

using namespace std;

#define ok 1
#define error 0
#define true 1
#define false 0
 
/* Status �Ǻ���������,��ֵ�Ǻ������״̬����,�� OK �� */
typedef int status;
/* ElemType ���͸���ʵ���������,�������Ϊ char */
typedef char Elemtype;

/* ���Ա��˫������洢�ṹ */
typedef struct Dulnode
{
	Elemtype data;
	struct Dulnode *prior;
	struct Dulnode *next;
} Dulnode,*Dulinklist;


//��ʼ������
Dulinklist Initlist()
{
	Dulinklist p,pnext,plast;   //p��ͷ���
	p=(Dulinklist)malloc(sizeof(Dulnode));
	p->prior=NULL;
	p->next=NULL;
	int i,n;

	cout<<"please input the length of the double linked list:";
    cin>>n;

	while(n!=0)
	{
		plast=p;
		for(i=0;i<n;i++)
		{
			pnext=(Dulinklist)malloc(sizeof(Dulnode));
			cout<<"��"<<i+1<<"�������������:";
			cin>>pnext->data;
			plast->next=pnext;
			pnext->prior=plast;
			plast=plast->next;
		}
		pnext->next=NULL;
		break;
	}
	return p;
}
//���Ա�ĳ���
int Listlength(Dulinklist pHead)
{
	int length = 0;
	Dulinklist pt = pHead->next;
 
	while (pt!= NULL)
	{
		length++;
		pt = pt->next;
	}
	return length;
}


//˫������Ĳ���,��i��λ�ò���Ԫ��value
status Listinsert(Dulinklist *L,int i,Elemtype value)
{
	int j;
	Dulinklist p,s;//pָ��Ҫ����λ�õ�ǰһ����㣬sΪ�½��
 
	if(i<1)//����λ�ò�����
		return error;
 
	p=*L;
	j=1;
 
	while(j<i)/*Ѱ�ҵ�i������ǰһ�����*/
	{
		p=p->next;
		j++;
		if(p==*L)//δ�ҵ�
			return error;
	}
 
	s=(Dulinklist) malloc(sizeof(Dulnode));
	s->data=value;
	s->prior=p;
	s->next=p->next;
	p->next->prior=s;
	p->next=s;
 
	return ok;
}

//˫�������ɾ��
status Listdelete(Dulinklist *L,int i,Elemtype *e)
{
	Dulinklist p;//pָ���i�����
	int j=1;
 
	p=(*L)->next;
 
	if(i<1)//ɾ��λ�ò�����
		return error;
 
	while(p!=*L&&j<i)
	{
		p=p->next;
		j++;
	}
 
	if(p==*L)//��i������Ԫ�ز�����
		return error;
	
	*e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
 
	return ok;
 }


//��ӡ�����е�ȫ������
void Listshow(Dulinklist L)
{
	Dulinklist p;
	p=L->next;
	Elemtype a;

	cout<<"��ǰ���Ĵ�ӡ���Ϊ��"<<endl;
	while(p!=NULL)
	{
		a=p->data;
		cout<<"����ֵΪ��"<<a<<endl;
		p=p->next;
	}
}

status ListEmpty(Dulinklist L)
{ 
	if(L->next==L && L->prior==L)
		return true;
    else
        return false;
}
 
/*��ʼ������˫��ѭ������L�Ѵ��ڡ�*/
/*�����������L����Ϊ�ձ�*/
status ClearList(Dulinklist *L)
{
	Dulinklist p;//pָ���һ�����
 
	p=(*L)->next;
	while(p!=*L)
	{
		p=p->next;
		free(p->prior);
	}
	(*L)->next=(*L)->prior=*L;//ͷ��������ָ����ָ�����Լ�
	
	return ok;
}
 

/*��ʼ������˫��ѭ������L�Ѵ��ڣ�1��i��ListLength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/
status GetElem(Dulinklist L,int i,Elemtype *e)
{
	Dulinklist p;
	int j;
 
	if(i<1)//ȡֵλ�ò�����
		return error;
 
	p=L->next;//pָ���һ�����
	j=1;
	while(p!=L&&j<i)
	{
		p=p->next;
		j++;
	}
 
	if(p==L)//��i������Ԫ�ز�����
		return error;
	*e=p->data;
 
	return ok;
}

int main() 
{
	Dulinklist L=Initlist();
	Listshow(L);
	Elemtype e=0;

	int i = 0;
	printf("��ʼ�� L ��:L.length=%d\n", Listlength(L));
	i = Listinsert(&L,1,'F');
	i = Listinsert(&L,1,'E');
	i = Listinsert(&L,1, 'D');
	i = Listinsert(&L,1, 'B');
	i = Listinsert(&L,1,'A');
	printf("�� L �ı�ͷ���β��� FEDBA ��:\nL.data=\n");
	Listshow(L);

	i = Listinsert(&L, 3, 'C');
	printf("\n �� L �ġ�B���롰D��֮����롰C����:\nL.data=\n");
	Listshow(L);

	i = Listdelete(&L,4,&e);
	printf("\n �� L ��ɾ����A����:\nL.data=\n");
	Listshow(L);
	cout<<"ɾ����ֵΪ:"<<e<<endl;

	system("pause");
	return 0;
}