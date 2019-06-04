#include<iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;
//���е�˳��洢�ṹ
typedef struct 
{
	Elemtype data[MAXSIZE];
	int front;
	int rear;
}Squeue;

//���еĲ���
Status Initqueue(Squeue *Q);
Status Clearqueue(Squeue *Q);
Status Queueempty(Squeue Q);
Status Gethead(Squeue Q,Elemtype *e);
Status Enqueue(Squeue *Q,Elemtype e);
Status Dequeue(Squeue *Q,Elemtype *e);
int Queuelength(Squeue Q);
Status Inputqueue(Squeue Q);

//���еľ������
Status Initqueue(Squeue *Q)
{
	Q->front=0;
	Q->rear=0;
	return OK;
}

Status Clearqueue(Squeue *Q)
{
	Q->front=0;
	Q->rear=0;
	return OK;
}

Status Queueempty(Squeue Q)
{
	if(Q.front==Q.rear)
		return  OK;
	else
		return ERROR;
}

Status Gethead(Squeue Q,Elemtype *e)
{
	if(Queueempty(Q))
		return ERROR;
	else
	{  
		int a=(Q.front)%MAXSIZE;
		*e=Q.data[a];
	}
	return OK;
}

Status Enqueue(Squeue *Q,Elemtype e)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
		return ERROR;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}

Status Dequeue(Squeue *Q,Elemtype *e)
{
	if(Q->front==Q->rear)
		return ERROR;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return OK;
}


int Queuelength(Squeue Q)
{
	int length;
	length=(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
	return length;
}

Status Inputqueue(Squeue Q)
{
	for(int i=Q.front;i<Q.rear;i++)
		std::cout<<Q.data[i]<<std::endl;
	return OK;
}
int main()
{
	using namespace std;
	Squeue Q;
	Elemtype e=0;
	Initqueue(&Q);
	cout<<"�ڶ����в���1��2��3��4��5��6��"<<endl;
	for(int i=1;i<7;i++)
	Enqueue(&Q,i);
	Inputqueue(Q);

	
	cout<<"ɾ�������Ϊ:"<<endl;
	Dequeue(&Q,&e);
	Inputqueue(Q);

	int b=Gethead(Q,&e);
	cout<<"���׵�ֵΪ;"<<e<<endl;

	cout<<"�ڶӺ������10,5:"<<endl;
	Enqueue(&Q,10);
	Enqueue(&Q,5);
	Inputqueue(Q);
	cout<<"���еĳ���Ϊ��"<<Queuelength(Q)<<endl;

	Clearqueue(&Q);
	cout<<"���еĳ���Ϊ��"<<Queuelength(Q)<<endl;

	system("pause");
	return 0;
}
