//�����ڽӾ��󣬹�����ȱ�����BFS��
#include<iostream>

using namespace std;

#define MAXVEX 100
#define INFINITY 65535
#define true 1
#define false 0
#define ok 1
#define error 0


//�ڽӾ���
typedef char Vertextype;  //��������
typedef int Edgetype;    //���ϵ�Ȩֵ
typedef int status;

typedef struct Mgraph  //ͼ�Ľṹ
{
	Vertextype vexs[MAXVEX];   //�����
	Edgetype arc[MAXVEX][MAXVEX];  //�ڽӾ���	
	int numvertexes,numedges;   //ͼ�е�ǰ�Ķ������ͱ���
} Mgraph;

typedef int Boolean;  //��������
Boolean visited[MAXVEX];  //���ʱ�־������


//����ͼ���ڽӾ���ṹ
void CreateMgraph(Mgraph *G)
{
	int i,j,k,w;

	cout<<"���붥��ͱ���:";
	cin>>G->numvertexes>>G->numedges;

	for(i=0;i<G->numvertexes;i++)  //���붥�����ͱ���
	{
		cout<<"�������"<<i<<"������:";
		cin>>G->vexs[i];
	}


	//��ʼ��
	for(i=0;i<G->numvertexes;i++) 
	    for(j=0;j<G->numvertexes;j++)
		{
			if(i==j)
				G->arc[i][j]=0;
			else
			G->arc[i][j]=INFINITY;
		}


	for(k=0;k<G->numedges;k++)
	{
		cout<<"����ߣ�vi,vj)���±�i,�±�j,�Լ�Ȩֵw:";
		cin>>i>>j>>w;
        
		G->arc[i][j]=w;
		G->arc[j][i]=w;
	}
}


//�����еĽṹ
typedef int QElemType;//����QElemType�����ͼ���Ϊint
 
typedef struct QNode //���ṹ
{
	QElemType  data;
	struct QNode *next;
}QNode,*QueuePtr;
 

typedef struct //���е�����ṹ
{
	QueuePtr front,rear;//��ͷ����βָ��
}LinkQueue;
 

//��ʼ������
status initQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!q->front)    //�洢����ʧ��
		return error;
	q->front->next = NULL;

	return ok;
}
 

//��ӣ�����Ԫ��eΪq���µĶ�βԪ��
status EnQueue(LinkQueue *q,QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if(!s)//�洢����ʧ��
		return error;
	s->data = e;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
 
	return ok;
}
 
//����
//�����в�Ϊ�գ�ɾ��q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
status DeQueue(LinkQueue *q,QElemType *e)
{
	
	QueuePtr p;
 
	if(q->front==q->rear)
		return error;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
 
	if(q->rear==p)//����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
		q->rear = q->front;
	free(p);
	return ok;
}
 
//�ж��Ƿ�Ϊ�ն���,��Ϊ�ն����򷵻�1�����򷵻�0
status QueueEmpty(LinkQueue q)
{
	if(q.front == q.rear)
		return 1;
	return 0;
}

//�ڽӾ���Ĺ�ȱ�������
void BFStraverse(Mgraph G)
{
	int i,j;
	LinkQueue Q;
 
	for(i=0;i<G.numvertexes;i++)
	{
		visited[i]=false;
	}
 
	initQueue(&Q);				//��ʼ��һ�����õĶ���
 
	for(i=0;i<G.numvertexes;i++)//��ÿһ��������ѭ��
	{
		if(!visited[i])			//����δ�����ʹ��ʹ���
		{
			visited[i]=true;	//���õ�ǰ������ʹ�
			cout<<G.vexs[i];    //��ӡ����
			EnQueue(&Q,i);		//���˶��������
 
			while(!QueueEmpty(Q))//����ǰ���㲻Ϊ��
			{
				DeQueue(&Q,&i);	 //������Ԫ�س����У���ֵ��i
				for(j=0;j<G.numvertexes;j++)
				{
					//�ж������������뵱ǰ������ڱ���δ�����ʹ�
					if(G.arc[i][j] ==1 && !visited[j])
					{
						visited[j]=true;//���ҵ��Ĵ˶�����Ϊ�ѷ���
						cout<<G.vexs[j];//��ӡ�˶���
						EnQueue(&Q,j);//���ҵ��Ĵ˶��������
					}
				}
			}
		}
	}
}


int main()
{
	Mgraph G;
	CreateMgraph(&G);
	BFStraverse(G);

	system("pause");
	return 0;
}
