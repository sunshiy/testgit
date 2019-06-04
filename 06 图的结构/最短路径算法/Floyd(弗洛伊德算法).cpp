//�����ڽӾ���
#include<iostream>

using namespace std;

//Ԥ����
#define MAXVEX 100
#define INFINITY 65535


//�ڽӾ���
typedef char Vertextype;  //��������
typedef int Edgetype;    //���ϵ�Ȩֵ

typedef struct Mgraph  //ͼ�Ľṹ
{
	Vertextype vexs[MAXVEX];   //�����
	Edgetype arc[MAXVEX][MAXVEX];  //�ڽӾ���	
	int numvertexes,numedges;   //ͼ�е�ǰ�Ķ������ͱ���
} Mgraph;

//����
void CreateMgraph(Mgraph *G);
void ShowMgraph(Mgraph G);


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


//���ͼ���ڽӾ���
void ShowMgraph(Mgraph G)
{
	int i,j;
	cout<<"\n��ӡ���:"<<endl;

	cout<<"����Ԫ��Ϊ��"<<endl;
	for(i=0;i<G.numvertexes;i++)
	    cout<<G.vexs[i]<<" ";
	cout<<endl;

	cout<<"������ڽӾ���Ϊ:\n";
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
        //������ͼ��һ����"0"��ʾ��������ͼ��һ����"��",
       // ����Ϊ�˷���ͳһ��� "��"
            printf("%8s", "��");
        else
            printf("%8d",G.arc[i][j]);
        }
        printf("\n"); 
		}
		 cout<<endl;
}


//�������£�Floyd���㷨�����·��
typedef int Pathmatirx[MAXVEX][MAXVEX];   //���ڴ洢���·���±������
typedef int ShortPathTable[MAXVEX][MAXVEX];//���ڴ洢���������·����Ȩֵ��

//����ͼG�и�����V����������W�����·��p[v][w]����Ȩ����D[v][w]
void ShortestPath_Floyd(Mgraph G,Pathmatirx *p,ShortPathTable *d)
{
	int v,w,k;

	/*��ʼ������*/
	for(v=0;v<G.numvertexes;v++)
	{
		for(w=0;w<G.numvertexes;w++)
		{
		(*d)[v][w]=G.arc[v][w];   //D[v][w]��Ϊ��Ӧ��Ȩֵ
		(*p)[v][w]=w;  //��ʼ��P
	    }
	}

	/*��ʼ��ѭ��*/
		for(k=0;k<G.numvertexes;k++)   //k����ת������±�
		{
			for(v=0;v<G.numvertexes;v++)     //Ѱ����v0����Ķ���
			{
                for(w=0;w<G.numvertexes;w++)  //w�ǽ�������
				{
					if((*d)[v][w]>(*d)[v][k]+(*d)[k][w])
					{
				    //��������±�Ϊk����·�����ȱ�ԭ�����·������
					//����ǰ�����Ȩֵ��Ϊ��С��һ��
					(*d)[v][w]=(*d)[v][k]+(*d)[k][w];
					(*p)[v][w]=(*p)[v][k];
					}
				}
			}
		}


		/*��ӡFloyd���·���Ľ��*/
		cout<<"Floyd�㷨�����Ȩֵ�Ľ��Ϊ: "<<endl;
		for(v=0;v<G.numvertexes;v++)
			for(w=0;w<G.numvertexes;w++)
			cout<<"shortest("<<v<<","<<w<<")="<<(*d)[v][w]<<endl;

	    cout<<"Floyd�㷨��P����Ľ��Ϊ: "<<endl;
		for(v=0;v<G.numvertexes;v++)
		{
			for(w=v+1;w<G.numvertexes;w++)
			{
			   cout<<"the weight of ("<<v<<","<<w<<"): "<<(*d)[v][w]<<endl;
			   int a=(*p)[v][w];
			   cout<<"path:"<<v;    //��ӡԭ��
			   while(a!=w)
			   {
				   cout<<"->"<<a;
				   a=(*p)[a][w];   //�����һ·��������±�
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


	/*�����·���Ĺ���*/
	 Pathmatirx p;
	 ShortPathTable d;

	 ShortestPath_Floyd(G,&p,&d);

	 system("pause");
	 return 0;
}
