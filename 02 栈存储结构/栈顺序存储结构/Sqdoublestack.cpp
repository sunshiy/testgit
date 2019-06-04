//两栈共享的情况
#include<iostream>

#define MAXSIZE 15
#define ERROR 0
#define OK 1
using namespace std;

typedef int Selemtype;
typedef int Status;

typedef struct
{
	Selemtype data[MAXSIZE];
	int top1;  //栈1的栈顶指针
	int top2;  //栈2的栈顶指针
}Sqdoublestack;



Status Initstack(Sqdoublestack *S)
{
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
}


Status Clearstack(Sqdoublestack *S)
{
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;

}

//判断栈是不是满
Status Stackfull(Sqdoublestack *S)
{
	if(S->top1+1==S->top2)
		return OK;
	else
		return ERROR;
}

Status Gettop(Sqdoublestack *S,Selemtype *e,int stacknumber)
{
if(stacknumber==1)
	{
	if( S->top1==-1)
		return ERROR;
	else
		*e=S->data[S->top1];
	}
else if(stacknumber==2)
	{
	if( S->top2==MAXSIZE)
		return ERROR;
	else
		*e=S->data[S->top2];
	}
	return OK;
}


Status Push(Sqdoublestack *S,Selemtype e,int stacknumber)
{
	if(S->top1+1==S->top2)
		return ERROR;
	if(stacknumber==1)
	{
	S->top1++;
	S->data[S->top1]=e;
	}
	else if(stacknumber==2)
	{
	S->top2--;
	S->data[S->top2]=e;

	}
	return OK;
}

Status Pop(Sqdoublestack *S,Selemtype *e,int stacknumber)
{
	if(stacknumber==1)
	{
	    if(S->top1==-1)
		return ERROR;
	    *e=S->data[S->top1];
	    S->top1--;
	}
	else if(stacknumber==2)
	{
	    if(S->top2==MAXSIZE)
		return ERROR;
	    *e=S->data[S->top2];
	    S->top2++;
	}
	 return OK;
}


Status Inputstack(Sqdoublestack *S)
{
	int length=S->top1;
	cout<<"栈1的数据为："<<endl;
	for(int i=length;i>=0;i--)
		cout<<S->data[i]<<" "<<endl;

	int length1=S->top2;
	cout<<"栈2的数据为："<<endl;
	for(int i=length1;i<MAXSIZE;i++)
		cout<<S->data[i]<<" "<<endl;

	return OK;
}


int main()
{
	Sqdoublestack S;
	Selemtype e;
	Initstack(&S);
	cout<<"将1，2，3，4，5压入栈1,将6，7，8，9，10压入栈2中："<<endl;
	Push(&S,1,1);
	Push(&S,2,1);
	Push(&S,3,1);
	Push(&S,4,1);
	Push(&S,5,1);
	Push(&S,6,2);
	Push(&S,7,2);
	Push(&S,8,2);
	Push(&S,9,2);
	Push(&S,10,2);
	Inputstack(&S);
	cout<<"将栈顶数据弹出："<<endl;
	Pop(&S,&e,1);
	Pop(&S,&e,2);
	Inputstack(&S);

	cout<<"取栈1顶数据：";
	int b=Gettop(&S,&e,1);
	cout<<e<<endl;

	cout<<"取栈2顶数据：";
	int c=Gettop(&S,&e,2);
	cout<<e<<endl;


	Clearstack(&S);
	cout<<"判断栈是否为满(1:满，0:非满）："<<Stackfull(&S)<<endl;

	system("pause");
	return 0;
}