//无向邻接矩阵
#include<iostream>

using namespace std;

//预定义
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

//操作
void CreateMgraph(Mgraph *G);
void ShowMgraph(Mgraph G);


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
        if(G.arc[i][j]==INFINITY) 
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


//迪杰斯特拉（Dijstra）算法求最短路径
typedef int Patharc[MAXVEX];   //用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];//用于存储到各点最短路径的权值和

//求最短路径P[v]及带权长度D[v]
//P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和

void ShortestPath_Dijstra(Mgraph G,int v0,Patharc *p,ShortPathTable *d)
{
	int v,w,k,min;
	int final[MAXVEX];    //final[w]=1表示求得顶点v0到vw的最短路径
	//final[w]=0表示未求得顶点v0到vw的最短路径

	/*初始化数据*/
	for(v=0;v<G.numvertexes;v++)
	{
		final[v]=0;  //全部顶点初始化为未知最短路径状态
		(*d)[v]=G.arc[v0][v];   //将与v0点有连线的顶点加上权值
		(*p)[v]=0;  //初始化路径数组P为0
	}
	(*d)[v0]=0;  //v0-v0路径为0
	final[v0]=1;  //v0-v0不需要求路径

	/*开始主循环*/
		for(v=1;v<G.numvertexes;v++)
		{
			min=INFINITY;  //当前所知离v0顶点的最近距离
			for(w=0;w<G.numvertexes;w++)  //寻找离v0最近的顶点
			{
				if(!final[w] &&(*d)[w]<min)
				{
					k=w;
					min=(*d)[w];   //w顶点离v0顶点更近
				}
			}

			final[k]=1;   //将目前找到的最近的顶点置为1
			for(w=0;w<G.numvertexes;w++)   //修正当前最短路径及距离
			{
				//如果经过v顶点的路径比现在这条路径的长度短的话
				if(!final[w] && (min+G.arc[k][w]<(*d)[w]))
				{
					//说明找到了更短的路径，修改D[w],p[w]
					(*d)[w]=min+G.arc[k][w];  //修正当前路径长度
					(*p)[w]=k;
				}
			}
		}
		/*打印Dijkstra最短路径的结果*/
		cout<<"Dijstra算法的结果为: "<<endl;
		for(int i=0;i<G.numvertexes;i++)
			cout<<"shortest("<<G.vexs[v0]<<","<<G.vexs[i]<<")="<<(*d)[i]<<endl;
}


	
int main()
{
	Mgraph G;

	CreateMgraph(&G);
	ShowMgraph(G);


	/*求最短路径的过程*/
	 Patharc p;
	 ShortPathTable d;

	 ShortestPath_Dijstra(G,0,&p,&d);

	 system("pause");
	 return 0;
}
