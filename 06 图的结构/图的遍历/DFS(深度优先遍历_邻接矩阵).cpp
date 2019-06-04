//无向邻接矩阵，深度优先遍历（DFS）
#include<iostream>

using namespace std;

#define MAXVEX 100
#define INFINITY 65535


//邻接矩阵
typedef char Vertextype;  //顶点类型
typedef int Edgetype;    //边上的权值

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


void DFS(Mgraph G,int i)
{
	int j;
	visited[i]=true;
	cout<<G.vexs[i];   //打印结点，也可以其他操作
	for(j=0;j<G.numvertexes;j++)
		if(G.arc[i][j]==1&&!visited[j])
			DFS(G,j);   //对未访问的邻接顶点递归调用
}


//邻接矩阵的深度遍历操作
void DFStraverse(Mgraph G)
{
	int i;
	for(i=0;i<G.numvertexes;i++)
		visited[i]=false;   //初始所有顶点状态都是未访问状态

	for(i=0;i<G.numvertexes;i++)
		if(!visited[i])
			DFS(G,i);
}



int main()
{
	Mgraph G;
	CreateMgraph(&G);
	DFStraverse(G);

	system("pause");
	return 0;
}
