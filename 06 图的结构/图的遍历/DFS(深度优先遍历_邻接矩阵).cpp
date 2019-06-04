//�����ڽӾ���������ȱ�����DFS��
#include<iostream>

using namespace std;

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

typedef int Boolean;  //��������
Boolean visited[MAXVEX];  //���ʱ�־������


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


void DFS(Mgraph G,int i)
{
	int j;
	visited[i]=true;
	cout<<G.vexs[i];   //��ӡ��㣬Ҳ������������
	for(j=0;j<G.numvertexes;j++)
		if(G.arc[i][j]==1&&!visited[j])
			DFS(G,j);   //��δ���ʵ��ڽӶ���ݹ����
}


//�ڽӾ������ȱ�������
void DFStraverse(Mgraph G)
{
	int i;
	for(i=0;i<G.numvertexes;i++)
		visited[i]=false;   //��ʼ���ж���״̬����δ����״̬

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
