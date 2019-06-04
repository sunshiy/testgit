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


//费洛伊德（Floyd）算法求最短路径
typedef int Pathmatirx[MAXVEX][MAXVEX];   //用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX][MAXVEX];//用于存储到各点最短路径的权值和

//求网图G中各顶点V到其他顶点W的最短路径p[v][w]及带权长度D[v][w]
void ShortestPath_Floyd(Mgraph G,Pathmatirx *p,ShortPathTable *d)
{
	int v,w,k;

	/*初始化数据*/
	for(v=0;v<G.numvertexes;v++)
	{
		for(w=0;w<G.numvertexes;w++)
		{
		(*d)[v][w]=G.arc[v][w];   //D[v][w]即为对应的权值
		(*p)[v][w]=w;  //初始化P
	    }
	}

	/*开始主循环*/
		for(k=0;k<G.numvertexes;k++)   //k是中转顶点的下标
		{
			for(v=0;v<G.numvertexes;v++)     //寻找离v0最近的顶点
			{
                for(w=0;w<G.numvertexes;w++)  //w是结束顶点
				{
					if((*d)[v][w]>(*d)[v][k]+(*d)[k][w])
					{
				    //如果经过下标为k顶点路径长度比原两点间路径更短
					//将当前两点间权值设为更小的一个
					(*d)[v][w]=(*d)[v][k]+(*d)[k][w];
					(*p)[v][w]=(*p)[v][k];
					}
				}
			}
		}


		/*打印Floyd最短路径的结果*/
		cout<<"Floyd算法中最短权值的结果为: "<<endl;
		for(v=0;v<G.numvertexes;v++)
			for(w=0;w<G.numvertexes;w++)
			cout<<"shortest("<<v<<","<<w<<")="<<(*d)[v][w]<<endl;

	    cout<<"Floyd算法中P矩阵的结果为: "<<endl;
		for(v=0;v<G.numvertexes;v++)
		{
			for(w=v+1;w<G.numvertexes;w++)
			{
			   cout<<"the weight of ("<<v<<","<<w<<"): "<<(*d)[v][w]<<endl;
			   int a=(*p)[v][w];
			   cout<<"path:"<<v;    //打印原点
			   while(a!=w)
			   {
				   cout<<"->"<<a;
				   a=(*p)[a][w];   //获得下一路径顶点的下标
			   }
			   cout<<"->"<<w<<endl;
			}
			cout<<endl;
		}
}


int main()
{
	Mgraph G;

	CreateMgraph(&G);
	ShowMgraph(G);


	/*求最短路径的过程*/
	 Pathmatirx p;
	 ShortPathTable d;

	 ShortestPath_Floyd(G,&p,&d);

	 system("pause");
	 return 0;
}
