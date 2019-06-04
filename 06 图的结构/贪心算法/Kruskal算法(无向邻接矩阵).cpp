//无向邻接矩阵
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXVEX 100
#define MAXEDGE 100
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

//对边集数组edge结构的定义
struct Edge
{
	int begin;
	int end;
	int weight;
};


//操作
void CreateMgraph(Mgraph *G);
void ShowMgraph(Mgraph G);
int Find(int *parent,int f);
void MiniSpanTree_Kruskal(Mgraph G);


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



//输出图的邻接矩阵
void ShowMgraph(Mgraph G)
{
	int i,j;
	cout<<"\n打印结果:"<<endl;

	cout<<"顶点元素为："<<endl;
	for(i=0;i<G.numvertexes;i++)
	    cout<<G.vexs[i]<<" ";
	cout<<endl;

	cout<<"输出的邻接矩阵为:\n";
	cout<<"\t";

	for(i=0;i<G.numvertexes;i++)
		printf("%8c",G.vexs[i]);
	  //  cout<<G.vexs[i]<<setw(10);
		for(i=0;i<G.numvertexes;i++)
		{
			printf("\n%8c",G.vexs[i]);
        for(j=0;j<G.numvertexes;j++)
        { 
        if(G.arc[i][j]==65535) 
        //两点之间无连接时权值为默认的32767，
        //在无向图中一般用"0"表示，在有向图中一般用"∞",
       // 这里为了方便统一输出 "∞"
            printf("%8s", "∞");
        else
            printf("%8d",G.arc[i][j]);
        }
        printf("\n"); 
		}
		 cout<<endl;
}

bool comparison(Edge a,Edge b)
{
    return a.weight<b.weight;
}

//克鲁斯卡尔（kruskal）算法生成最小生成树
void MiniSpanTree_Kruskal(Mgraph G)
{
	int i=0,n,m;
	int parent[MAXEDGE];    //定义一数组用来判断边与边之间是否形成环路
	Edge edges[MAXEDGE];  /* 定义边集数组,edge的结构为begin,end,weight,均为整型 */

    /* 用来构建边集数组并排序********************* */
	int j,k=0;
    for(i = 0; i < G.numvertexes - 1; i++)
    {
        for(j = i + 1; j < G.numvertexes; j++)
        {
            if(G.arc[i][j]<INFINITY)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++;
            }
        }
    }
    sort(edges,edges+G.numedges,comparison);

	cout<<"打印出边集数组:"<<endl;
	for(k=0;k<G.numedges;k++)
	{
		cout<<k<<":<"<<edges[k].begin<<" "<<edges[k].end<<">"<<edges[k].weight<<endl;
	}


/* ******************************************* */
	cout<<"\n最小生成树为:"<<endl;

	for(i=0;i<G.numedges;i++)
		parent[i]=0;   //初始化数组为0

	for(i=0;i<G.numedges;i++)   //循环每一条边
	{
		n=Find(parent,edges[i].begin);
		m=Find(parent,edges[i].end);

		if(n!=m)   //n!=m,说明此边没有与现成生成树形成环路
		{
			parent[n]=m;   //将此边的结尾结点放入下标起点为parnet中
			//表示此节点已经在生成树中
			cout<<"("<<edges[i].end<<","<<edges[i].end<<")->"<<edges[i].weight<<endl;
		}
	}
}

int Find(int *parent,int f)  //查找连线顶点的尾部下标
{
	while(parent[f]>0)
		f=parent[f];
	return f;
}

	
int main()
{
	Mgraph G;

	CreateMgraph(&G);
	ShowMgraph(G);

	MiniSpanTree_Kruskal(G);

	system("pause");
	return 0;
}
