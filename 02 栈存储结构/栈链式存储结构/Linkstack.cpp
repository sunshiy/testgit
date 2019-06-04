//栈的链式存储结构
//对于栈的链式存储结构来说，不需要头结点

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


//函数的声明
Status Initstack(Linkstack *S);
Status Clearstack(Linkstack *S);
Status Stackempty(Linkstack *S);
Status Stacklength(Linkstack *S);
Status Gettop(Linkstack *S,Selemtype *e);
Status Push(Linkstack *S,Selemtype e);
Status Inputstack(Linkstack *S);

//函数的定义
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
	Linkstackptr s=(Linkstackptr)malloc(sizeof(Stacknode)); //新建一个结点
	s->data=e;
	s->next=S->top; //把当前的栈顶元素赋值给新节点的直接后继
	S->top=s;     //将新的结点赋值给栈顶元素
	S->count++;

	return OK;
}

Status Pop(Linkstack *S,Selemtype *e)
{
	Linkstackptr p;
	if(Stackempty(S))
		return ERROR;
	*e=S->top->data;
	p=S->top;   //将栈顶结点赋值给p
	S->top=S->top->next;   //使得栈顶指针下移一位，指向下一节点
	free(p);  //释放结点p
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

	cout<<"取栈顶数据：";
	int b=Gettop(&S,&e);
	cout<<e<<endl;

	Clearstack(&S);
	cout<<"判断栈是否为满(1:空，0:非空）："<<Stackempty(&S)<<endl;

	system("pause");
	return 0;
}