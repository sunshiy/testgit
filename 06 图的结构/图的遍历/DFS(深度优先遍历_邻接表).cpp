//�����ڽӱ�������ȵݹ��㷨
#include<iostream>

using namespace std;

#define MAXVEX 100

//�ڽӱ�������������ϵĴ洢����

typedef char Vertextype;  //��������
typedef int Edgetype;    //���ϵ�Ȩֵ
typedef int Boolean;  //��������
Boolean visited[MAXVEX];  //���ʱ�־������


typedef struct Edgenode  //�߱���
{
	int adjvex;   //�ڽӵ��򣬴洢�ö����Ӧ���±�
	Edgetype weight;   //�洢Ȩֵ
	struct Edgenode *next;
}Edgenode;


typedef struct Vertexnode  //�������
{
	Vertextype data;    //�����򣬴洢������Ϣ
	Edgenode *firstedge;    //�߱�ͷָ��
}Vertexnode,Adjlist[MAXVEX];


typedef struct 
{
	Adjlist adjlist;
	int numvertexes,numedges;   //ͼ�е�ǰ�Ķ������ͱ���
}Graphadjlist;


//����ͼ���ڽӱ�ṹ
void CreateAlgraph(Graphadjlist *G)
{
	int i,j,k;
	Edgenode *e;

	cout<<"���붥��ͱ���:";
	cin>>G->numvertexes>>G->numedges;

	for(i=0;i<G->numvertexes;i++)
	{
		cout<<"�������"<<i+1<<"������:";
		cin>>G->adjlist[i].data;
		G->adjlist[i].firstedge=NULL;  //���߱����ڿձ�
	}

	for(k=0;k<G->numedges;k++)
	{
		cout<<"����ߣ�vi,vj)���±�i,�±�j:";
		cin>>i>>j;
		e=new Edgenode;

		e->adjvex=j;    // �ڽ����Ϊj 
		e->next=G->adjlist[i].firstedge;//��e��ָ��ָ��ǰ������ָ��Ľ��
		G->adjlist[i].firstedge=e;  //����ǰ�����ָ��ָ��e 

		// ��������ͼ������������Բ�Ҫ 
		e=(Edgenode *)malloc(sizeof(Edgenode));

		e->adjvex=i;
		e->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=e;
	}
}


void Printgraph(Graphadjlist G)
{
	Edgenode *e;
	cout<<"ͼ�Ķ���Ϊ�� "<<endl;
	for(int i=0;i<G.numvertexes; i++)
		cout<<G.adjlist[i].data<<" ";
	cout<<endl;


	cout<<"ͼ�Ķ����Լ����Ӧ���ڽӶ���Ϊ��\n";
	cout<<2*G.numedges<<"����:\n";

	for(int i=0;i<G.numvertexes; i++)
	{
		// cout<<
		e=G.adjlist[i].firstedge;
		while(e!=NULL)
		{
			cout<<G.adjlist[i].data<<"->"<<G.adjlist[e->adjvex].data<<" ";
			e=e->next;
		}
		cout<<endl;
	}
}



void DFS(Graphadjlist G,int i)
{
	Edgenode *p;
	visited[i]=true;
	cout<<G.adjlist[i].data;   //��ӡ��㣬Ҳ������������
	p=G.adjlist[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);   //��δ���ʵ��ڽӶ���ݹ����
		p=p->next;
	}
}


//�ڽӾ������ȱ�������
void DFStraverse(Graphadjlist G)
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
	Graphadjlist G;
	CreateAlgraph(&G);
	Printgraph(G);
	DFStraverse(G);

	system("pause");
	return 0;
}
