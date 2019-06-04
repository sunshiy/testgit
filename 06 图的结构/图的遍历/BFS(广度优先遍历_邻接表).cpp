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

typedef int Boolean;  //��������
Boolean visited[MAXVEX];  //���ʱ�־������

typedef struct Edgenode  //�߱���
{
	int adjvex;   //�ڽӵ��򣬴洢�ö����Ӧ���±�
	Edgetype weight;   //�洢Ȩֵ
	struct Edgenode *next;
}Edgenode;


typedef struct Vertexnode  //�������
{
	Vertextype data;    //�����򣬴洢������Ϣ
	Edgenode *firstedge;    //�߱�ͷָ��
}Vertexnode,Adjlist[MAXVEX];


typedef struct 
{
	Adjlist adjlist;
	int numvertexes,numedges;   //ͼ�е�ǰ�Ķ������ͱ���
}Graphadjlist;


//����ͼ���ڽӱ�ṹ
void CreateAlgraph(Graphadjlist *G)
{
	int i,j,k;
	Edgenode *e;

	cout<<"���붥��ͱ���:";
	cin>>G->numvertexes>>G->numedges;

	for(i=0;i<G->numvertexes;i++)
	{
		cout<<"�������"<<i+1<<"������:";
		cin>>G->adjlist[i].data;
		G->adjlist[i].firstedge=NULL;  //���߱����ڿձ�
	}

	for(k=0;k<G->numedges;k++)
	{
		cout<<"����ߣ�vi,vj)���±�i,�±�j:";
		cin>>i>>j;
		e=new Edgenode;

		e->adjvex=j;    // �ڽ����Ϊj 
		e->next=G->adjlist[i].firstedge;//��e��ָ��ָ��ǰ������ָ��Ľ��
		G->adjlist[i].firstedge=e;  //����ǰ�����ָ��ָ��e 

		// ��������ͼ������������Բ�Ҫ 
		e=(Edgenode *)malloc(sizeof(Edgenode));

		e->adjvex=i;
		e->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=e;
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
	if(!q->front)
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
void BFStraverse(Graphadjlist G)
{
	int i,j;
	Edgenode *p;
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
			cout<<G.adjlist[i].data;       //��ӡ����
			EnQueue(&Q,i);		//���˶��������
 
			while(!QueueEmpty(Q))//����ǰ���㲻Ϊ��
			{
				DeQueue(&Q,&i);	 //������Ԫ�س����У���ֵ��i
				p=G.adjlist[i].firstedge;   //�ҵ���ǰ����߱�����ͷָ��
				  while(p)
				{
					//�ж������������뵱ǰ������ڱ���δ�����ʹ�
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=true;//���ҵ��Ĵ˶�����Ϊ�ѷ���
						cout<<G.adjlist[p->adjvex].data;   //��ӡ�˶���
						EnQueue(&Q,p->adjvex);//���ҵ��Ĵ˶��������
					}
					p=p->next;
				}
			}
		}
	}
}


int main()
{
	Graphadjlist G;
	CreateAlgraph(&G);
	BFStraverse(G);

	system("pause");
	return 0;
}
