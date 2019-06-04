#include<iostream>

#define MAXSIZE 100
#define ERROR 0
#define OK 1
using namespace std;

typedef int Selemtype;
typedef int Status;

typedef struct
{
	Selemtype data[MAXSIZE];
	int top;   //ջ��
}Sqstack;


//operation
Status Initstack(Sqstack *S);
Status Destorystack(Sqstack *S);
Status Clearstack(Sqstack *S);

Status Stackempty(Sqstack S);
Status Gettop(Sqstack *S,Selemtype *e);
Status Push(Sqstack *S,Selemtype e);
Status Pop(Sqstack *S,Selemtype *e);

int Stacklength(Sqstack S);
Status Inputstack(Sqstack *S);


//complex operation
Status Initstack(Sqstack *S)
{
	S->top=-1;
	return OK;
}


Status Clearstack(Sqstack *S)
{
	S->top=-1;
	return OK;

}

Status Destorystack(Sqstack *S)
{
	S->top=-1;
	return OK;
}

Status Stackempty(Sqstack S)
{
	if(S.top==-1)
		return OK;
	else
		return ERROR;
}

Status Gettop(Sqstack *S,Selemtype *e)
{
	if( S->top==-1)
		return ERROR;
	else
	{
		int length=S->top;
		*e=S->data[length];
	 }
	return OK;
}

Status Push(Sqstack *S,Selemtype e)
{
	if(S->top==MAXSIZE-1)
		return ERROR;
	S->top++;
	S->data[S->top]=e;
	return OK;
}

Status Pop(Sqstack *S,Selemtype *e)
{
	if(S->top==-1)
		return ERROR;
	*e=S->data[S->top];
	S->top--;
	return OK;
}


int Stacklength(Sqstack S)
{
	return S.top+1;
}

Status Inputstack(Sqstack *S)
{
	int length=S->top;
	for(int i=length;i>=0;i--)
		cout<<S->data[i]<<" "<<endl;
	return OK;
}


int main()
{
	Sqstack S;
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
	cout<<"ջ�е�Ԫ���ܹ��У�"<<Stacklength(S)<<endl;

	cout<<"ȡջ�����ݣ�";
	int b=Gettop(&S,&e);
	cout<<e<<endl;

	cout<<"�ж�ջ�Ƿ�Ϊ��(1:�գ�0:�ǿգ���"<<Stackempty(S)<<endl;

	Destorystack(&S);

	system("pause");
	return 0;
}