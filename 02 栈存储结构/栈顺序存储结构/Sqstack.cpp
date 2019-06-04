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
	int top;   //栈顶
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
	cout<<"将1，2，3，4，5压入栈中："<<endl;
	Push(&S,1);
	Push(&S,2);
	Push(&S,3);
	Push(&S,4);
	Push(&S,5);
	Inputstack(&S);
	cout<<"将栈顶数据弹出："<<endl;
	Pop(&S,&e);
	Pop(&S,&e);
	Inputstack(&S);
	cout<<"栈中的元素总共有："<<Stacklength(S)<<endl;

	cout<<"取栈顶数据：";
	int b=Gettop(&S,&e);
	cout<<e<<endl;

	cout<<"判断栈是否为空(1:空，0:非空）："<<Stackempty(S)<<endl;

	Destorystack(&S);

	system("pause");
	return 0;
}