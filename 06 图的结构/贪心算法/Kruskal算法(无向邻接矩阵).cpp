//�����ڽӾ���
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXVEX 100
#define MAXEDGE 100
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

//�Ա߼�����edge�ṹ�Ķ���
struct Edge
{
	int begin;
	int end;
	int weight;
};


//����
void CreateMgraph(Mgraph *G);
void ShowMgraph(Mgraph G);
int Find(int *parent,int f);
void MiniSpanTree_Kruskal(Mgraph G);


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
        if(G.arc[i][j]==65535) 
        //����֮��������ʱȨֵΪĬ�ϵ�32767��
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

bool comparison(Edge a,Edge b)
{
    return a.weight<b.weight;
}

//��³˹������kruskal���㷨������С������
void MiniSpanTree_Kruskal(Mgraph G)
{
	int i=0,n,m;
	int parent[MAXEDGE];    //����һ���������жϱ����֮���Ƿ��γɻ�·
	Edge edges[MAXEDGE];  /* ����߼�����,edge�ĽṹΪbegin,end,weight,��Ϊ���� */

    /* ���������߼����鲢����********************* */
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

	cout<<"��ӡ���߼�����:"<<endl;
	for(k=0;k<G.numedges;k++)
	{
		cout<<k<<":<"<<edges[k].begin<<" "<<edges[k].end<<">"<<edges[k].weight<<endl;
	}


/* ******************************************* */
	cout<<"\n��С������Ϊ:"<<endl;

	for(i=0;i<G.numedges;i++)
		parent[i]=0;   //��ʼ������Ϊ0

	for(i=0;i<G.numedges;i++)   //ѭ��ÿһ����
	{
		n=Find(parent,edges[i].begin);
		m=Find(parent,edges[i].end);

		if(n!=m)   //n!=m,˵���˱�û�����ֳ��������γɻ�·
		{
			parent[n]=m;   //���˱ߵĽ�β�������±����Ϊparnet��
			//��ʾ�˽ڵ��Ѿ�����������
			cout<<"("<<edges[i].end<<","<<edges[i].end<<")->"<<edges[i].weight<<endl;
		}
	}
}

int Find(int *parent,int f)  //�������߶����β���±�
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
