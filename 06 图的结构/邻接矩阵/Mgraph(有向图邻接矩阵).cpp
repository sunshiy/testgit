//有向邻接矩阵
#include<iostream>
#include <iomanip>//精度设置必须包括的头文件 

using namespace std;
#define MAXVEX 100
#define INFINITY 65535

//邻接矩阵
typedef char Vertextype;  //顶点类型
typedef int Edgetype;    //边上的权值

typedef struct Mgraph  //
{
	Vertextype vexs[MAXVEX];   //顶点表
	Edgetype arc[MAXVEX][MAXVEX];  //邻接矩阵	
	int numvertexes,numedges;   //图中当前的顶点数和边数
} Mgraph;


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

int main()
{
	Mgraph G;
	CreateMgraph(&G);
	ShowMgraph(G);

	system("pause");
	return 0;
}
