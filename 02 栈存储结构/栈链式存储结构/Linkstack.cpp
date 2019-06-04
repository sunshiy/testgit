//ջ����ʽ�洢�ṹ
//����ջ����ʽ�洢�ṹ��˵������Ҫͷ���

#include<iostream>

#define ERROR 0
#define OK 1

using namespace std;

typedef int Selemtype;
typedef int Status;

typedef struct Stacknode
{
	Selemtype data;
	struct Stacknode *next;
}Stacknode,*Linkstackptr;

typedef struct Linkstack
{
	Linkstackptr top;
	int count;
}Linkstack;


//����������
Status Initstack(Linkstack *S);
Status Clearstack(Linkstack *S);
Status Stackempty(Linkstack *S);
Status Stacklength(Linkstack *S);
Status Gettop(Linkstack *S,Selemtype *e);
Status Push(Linkstack *S,Selemtype e);
Status Inputstack(Linkstack *S);

//�����Ķ���
Status Initstack(Linkstack *S)
{
	S->top=NULL;
	S->count=0;
	return OK;
}


Status Clearstack(Linkstack *S)
{
	Linkstackptr p;
	p=S->top;
	while(p)
{
    S->top=p->next;
	free(p);
	p=S->top;
}
	return OK;
}


Status Stackempty(Linkstack *S)
{
	if(S->top==NULL)
		return OK;
	else
		return ERROR;
}


Status Stacklength(Linkstack S)
{
	return S.count;
}

Status Gettop(Linkstack *S,Selemtype *e)
{
   if(S->top==NULL)
	   return ERROR;
   else
	   *e=S->top->data;
	return OK;
}


Status Push(Linkstack *S,Selemtype e)
{
	Linkstackptr s=(Linkstackptr)malloc(sizeof(Stacknode)); //�½�һ�����
	s->data=e;
	s->next=S->top; //�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½ڵ��ֱ�Ӻ��
	S->top=s;     //���µĽ�㸳ֵ��ջ��Ԫ��
	S->count++;

	return OK;
}

Status Pop(Linkstack *S,Selemtype *e)
{
	Linkstackptr p;
	if(Stackempty(S))
		return ERROR;
	*e=S->top->data;
	p=S->top;   //��ջ����㸳ֵ��p
	S->top=S->top->next;   //ʹ��ջ��ָ������һλ��ָ����һ�ڵ�
	free(p);  //�ͷŽ��p
	S->count--;

	return OK;
}


Status Inputstack(Linkstack *S)
{
	Linkstackptr p;
	p=S->top;

	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}

	return OK;
}


int main()
{
	Linkstack S;
	Selemtype e;
	Initstack(&S);
	cout<<"��1��2��3��4��5ѹ��ջ�У�"<<endl;
	Push(&S,1);
	Push(&S,2);
	Push(&S,3);
	Push(&S,4);
	Push(&S,5);
	Inputstack(&S);

	cout<<"��ջ�����ݵ�����"<<endl;
	Pop(&S,&e);
	Pop(&S,&e);
	Inputstack(&S);

	cout<<"ȡջ�����ݣ�";
	int b=Gettop(&S,&e);
	cout<<e<<endl;

	Clearstack(&S);
	cout<<"�ж�ջ�Ƿ�Ϊ��(1:�գ�0:�ǿգ���"<<Stackempty(&S)<<endl;

	system("pause");
	return 0;
}