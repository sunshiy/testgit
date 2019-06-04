//有向邻接表
#include<iostream>

using namespace std;

#define MAXVEX 100

//邻接表，数组和链表相结合的存储方法

typedef char Vertextype;  //定点类型
typedef int Edgetype;    //边上的权值

typedef struct Edgenode  //边表结点
{
	int adjvex;   //邻接点域，存储该顶点对应的下标
	Edgetype weight;   //存储权值
	struct Edgenode *next;
}Edgenode;


typedef struct Vertexnode  //顶点表结点
{
	Vertextype data;    //顶点域，存储顶点信息
	Edgenode *firstedge;    //边表头指针
}Vertexnode,Adjlist[MAXVEX];


typedef struct 
{
	Adjlist adjlist;
	int numvertexes,numedges;   //图中当前的定点数和边数
}Graphadjlist;


//创建图的邻接表结构
void CreateAlgraph(Graphadjlist *G)
{
	int i,j,k;
	Edgenode *e;

	cout<<"输入顶点和边数:";
	cin>>G->numvertexes>>G->numedges;

	for(i=0;i<G->numvertexes;i++)
	{
		cout<<"请输入第"<<i+1<<"个顶点:";
		cin>>G->adjlist[i].data;
		G->adjlist[i].firstedge=NULL;  //将边表至于空表
	}

	for(k=0;k<G->numedges;k++)
	{
		cout<<"输入边（vi,vj)的下标i,下标j:";
		cin>>i>>j;
		e=new Edgenode;

		e->adjvex=j;    // 邻接序号为j 
		e->next=G->adjlist[i].firstedge;//将e的指针指向当前顶点上指向的结点
		G->adjlist[i].firstedge=e;  //将当前顶点的指针指向e 
	}
}


void Printgraph(Graphadjlist G)
{
	Edgenode *e;
	cout<<"图的顶点为： "<<endl;
	for(int i=0;i<G.numvertexes; i++)
		cout<<G.adjlist[i].data<<" ";
	cout<<endl;


	cout<<"图的顶点以及其对应的邻接顶点为：\n";
	cout<<G.numedges<<"条边:\n";

	for(int i=0;i<G.numvertexes; i++)
	{
		e=G.adjlist[i].firstedge;
		while(e!=NULL)
		{
			cout<<G.adjlist[i].data<<"->"<<G.adjlist[e->adjvex].data<<" ";
			e=e->next;
		}
		cout<<endl;
	}
}

int main()
{
	Graphadjlist G;
	CreateAlgraph(&G);
	Printgraph(G);

	system("pause");
	return 0;
}
