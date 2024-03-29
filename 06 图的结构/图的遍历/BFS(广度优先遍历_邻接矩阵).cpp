//无向邻接矩阵，广度优先遍历（BFS）
#include<iostream>

using namespace std;

#define MAXVEX 100
#define INFINITY 65535
#define true 1
#define false 0
#define ok 1
#define error 0


//邻接矩阵
typedef char Vertextype;  //顶点类型
typedef int Edgetype;    //边上的权值
typedef int status;

typedef struct Mgraph  //图的结构
{
	Vertextype vexs[MAXVEX];   //顶点表
	Edgetype arc[MAXVEX][MAXVEX];  //邻接矩阵	
	int numvertexes,numedges;   //图中当前的顶点数和边数
} Mgraph;

typedef int Boolean;  //布尔类型
Boolean visited[MAXVEX];  //访问标志的数组


//创建图的邻接矩阵结构
void CreateMgraph(Mgraph *G)
{
	int i,j,k,w;

	cout<<"输入顶点和边数:";
	cin>>G->numvertexes>>G->numedges;

	for(i=0;i<G->numvertexes;i++)  //输入顶点数和边数
	{
		cout<<"请输入第"<<i<<"个顶点:";
		cin>>G->vexs[i];
	}


	//初始化
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
		cout<<"输入边（vi,vj)的下标i,下标j,以及权值w:";
		cin>>i>>j>>w;
        
		G->arc[i][j]=w;
		G->arc[j][i]=w;
	}
}


//链队列的结构
typedef int QElemType;//这里QElemType的类型假设为int
 
typedef struct QNode //结点结构
{
	QElemType  data;
	struct QNode *next;
}QNode,*QueuePtr;
 

typedef struct //队列的链表结构
{
	QueuePtr front,rear;//队头、队尾指针
}LinkQueue;
 

//初始化队列
status initQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!q->front)    //存储分配失败
		return error;
	q->front->next = NULL;

	return ok;
}
 

//入队：插入元素e为q的新的队尾元素
status EnQueue(LinkQueue *q,QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if(!s)//存储分配失败
		return error;
	s->data = e;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
 
	return ok;
}
 
//出队
//若队列不为空，删除q的队头元素，用e返回其值，并返回OK，否则返回ERROR
status DeQueue(LinkQueue *q,QElemType *e)
{
	
	QueuePtr p;
 
	if(q->front==q->rear)
		return error;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
 
	if(q->rear==p)//若队头是队尾，则删除后将rear指向头结点
		q->rear = q->front;
	free(p);
	return ok;
}
 
//判断是否为空队列,若为空队列则返回1，否则返回0
status QueueEmpty(LinkQueue q)
{
	if(q.front == q.rear)
		return 1;
	return 0;
}

//邻接矩阵的广度遍历操作
void BFStraverse(Mgraph G)
{
	int i,j;
	LinkQueue Q;
 
	for(i=0;i<G.numvertexes;i++)
	{
		visited[i]=false;
	}
 
	initQueue(&Q);				//初始化一辅助用的队列
 
	for(i=0;i<G.numvertexes;i++)//对每一个顶点做循环
	{
		if(!visited[i])			//若是未被访问过就处理
		{
			visited[i]=true;	//设置当前顶点访问过
			cout<<G.vexs[i];    //打印顶点
			EnQueue(&Q,i);		//将此顶点入队列
 
			while(!QueueEmpty(Q))//若当前顶点不为空
			{
				DeQueue(&Q,&i);	 //将队中元素出队列，赋值给i
				for(j=0;j<G.numvertexes;j++)
				{
					//判断其他顶点若与当前顶点存在边且未被访问过
					if(G.arc[i][j] ==1 && !visited[j])
					{
						visited[j]=true;//将找到的此顶点标记为已访问
						cout<<G.vexs[j];//打印此顶点
						EnQueue(&Q,j);//将找到的此顶点入队列
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
