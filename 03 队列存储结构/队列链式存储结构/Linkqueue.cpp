#include<iostream>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;

//队列的链式存储结构
typedef struct Qnode   //结点结构
{
	Elemtype data;
	struct Qnode *next;
}Qnode,*Queueptr;

typedef struct 
{
	Queueptr front,rear;
}Linkqueue;

//队列的操作
Status Initqueue(Linkqueue *Q);
Status Clearqueue(Linkqueue *Q);
Status Queueempty(Linkqueue Q);
Status Gethead(Linkqueue Q,Elemtype *e);
Status Enqueue(Linkqueue *Q,Elemtype e);
Status Dequeue(Linkqueue *Q,Elemtype *e);
int Queuelength(Linkqueue Q);
Status Inputqueue(Linkqueue Q);

//队列的具体操作
Status Initqueue(Linkqueue *Q)
{
	Qnode *p;     
	p=(Qnode*)malloc(sizeof(Qnode));
	p->next=NULL;
	Q->front=Q->rear=p;
	
	return OK;
}

Status Clearqueue(Linkqueue *Q)
{
	Queueptr p,q;
	Q->rear=Q->front;
	p=Q->front->next;
	Q->front->next=NULL;
    while(p)
   {
    q=p;
	p=p->next;
	free(q);
   }
	return OK;
}

Status Queueempty(Linkqueue Q)
{
	if(Q.front==Q.rear)
		return  OK;
	else
		return ERROR;
}

Status Gethead(Linkqueue Q,Elemtype *e)
{
	if(Queueempty(Q))
		return ERROR;
	else
	{  
		*e=Q.front->next->data;
	}
	return OK;
}

Status Enqueue(Linkqueue *Q,Elemtype e)
{
	Queueptr s;
	s=(Queueptr)malloc(sizeof(Qnode));
	if(!s)
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;
	Q->rear=s;

	return OK;
}

Status Dequeue(Linkqueue *Q,Elemtype *e)
{
	Queueptr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;

	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return OK;
}


int Queuelength(Linkqueue Q)
{
	int i=0;
	Queueptr p;
	p=Q.front;
	while(p!=Q.rear)
	{
		i++;
		p=p->next;
	}
	return i;
}


Status Inputqueue(Linkqueue *Q)
{
	Queueptr p;
	p=Q->front->next;
	while(p)
	{
		std::cout<<p->data<<std::endl;
		p=p->next;
	}
	return OK;
}
int main()
{
	using namespace std;
	Linkqueue Q;
	Elemtype e;
	Initqueue(&Q);
	cout<<"在队列中插入1，2，3，4，5，6："<<endl;
	for(int i=1;i<7;i++)
	Enqueue(&Q,i);
	Inputqueue(&Q);

	
	cout<<"删除后队列为:"<<endl;
	Dequeue(&Q,&e);
	Inputqueue(&Q);

	int b=Gethead(Q,&e);
	cout<<"队首的值为;"<<e<<endl;

	cout<<"在队后面插入10,5:"<<endl;
	Enqueue(&Q,10);
	Enqueue(&Q,5);
	Inputqueue(&Q);
	cout<<"队列的长度为："<<Queuelength(Q)<<endl;

	Clearqueue(&Q);
	cout<<"队列的长度为："<<Queuelength(Q)<<endl;

	system("pause");
	return 0;
}
