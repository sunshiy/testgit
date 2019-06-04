//无向邻接矩阵
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



//输出图的邻接矩阵
void ShowMgraph(Mgraph G)
{
	int i,j;
	cout<<"打印结果:"<<endl;

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


//prim算法生成最小生成树
void MiniSpanTree_Prim(Mgraph G)
{
	int min,i,j,k;
	int adjvex[MAXVEX];   //保存相关顶点的下标
	int lowcost[MAXVEX];   //保存相关顶点间的权值

	lowcost[0]=0;  //初始化第一个权值为0，即v0已经加入生成树
	//lowcost的值为0，在这里就是此下标已经加入生成树
	adjvex[0]=0;   //初始化第一个顶点下表为0

	for(i=1;i<G.numvertexes;i++)  //循环除下标为0外的全部顶点
	{
		lowcost[i]=G.arc[0][i];  //将v0顶点与之有边的权值存入数组
		adjvex[i]=0;   //初始化都为v0的下标
	}

	for(i=1;i<G.numvertexes;i++)  //循环除下标为0外的全部顶点
	{
		min=INFINITY;  //初始化最小权值为无穷大
		j=1,k=0;

		while(j<G.numvertexes)  //循环全部顶点
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
				//如果权值不为0，且权值小于min
			{
				min=lowcost[j];  //让当前权值成为最小值

	            k=j;   //则将当前最小值的下标存入k
			}
			j++;
		}

		cout<<"<"<<adjvex[k]<<"->"<<k<<">"<<endl;  //打印当前顶点中权值最小边
		lowcost[k]=0;    //当前顶点权值设置为0，表示此顶点已经完成任务

		for(j=1;j<G.numvertexes;j++)   //循环所以顶点
		{
				if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
        //  若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
				{
					lowcost[j]=G.arc[k][j];  //将较小值存入lowcost
					adjvex[j]=k;//将下标为k的顶点存入adjvex
				}
		}
	}
}

		
int main()
{
	Mgraph G;
	CreateMgraph(&G);
	ShowMgraph(G);

	cout<<"最小生成树为:"<<endl;
	MiniSpanTree_Prim(G);

	system("pause");
	return 0;
}
