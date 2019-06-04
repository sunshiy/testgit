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


//�Ͻ�˹������Dijstra���㷨�����·��
typedef int Patharc[MAXVEX];   //���ڴ洢���·���±������
typedef int ShortPathTable[MAXVEX];//���ڴ洢���������·����Ȩֵ��

//�����·��P[v]����Ȩ����D[v]
//P[v]��ֵΪǰ�������±꣬D[v]��ʾv0��v�����·�����Ⱥ�

void ShortestPath_Dijstra(Mgraph G,int v0,Patharc *p,ShortPathTable *d)
{
	int v,w,k,min;
	int final[MAXVEX];    //final[w]=1��ʾ��ö���v0��vw�����·��
	//final[w]=0��ʾδ��ö���v0��vw�����·��

	/*��ʼ������*/
	for(v=0;v<G.numvertexes;v++)
	{
		final[v]=0;  //ȫ�������ʼ��Ϊδ֪���·��״̬
		(*d)[v]=G.arc[v0][v];   //����v0�������ߵĶ������Ȩֵ
		(*p)[v]=0;  //��ʼ��·������PΪ0
	}
	(*d)[v0]=0;  //v0-v0·��Ϊ0
	final[v0]=1;  //v0-v0����Ҫ��·��

	/*��ʼ��ѭ��*/
		for(v=1;v<G.numvertexes;v++)
		{
			min=INFINITY;  //��ǰ��֪��v0������������
			for(w=0;w<G.numvertexes;w++)  //Ѱ����v0����Ķ���
			{
				if(!final[w] &&(*d)[w]<min)
				{
					k=w;
					min=(*d)[w];   //w������v0�������
				}
			}

			final[k]=1;   //��Ŀǰ�ҵ�������Ķ�����Ϊ1
			for(w=0;w<G.numvertexes;w++)   //������ǰ���·��������
			{
				//�������v�����·������������·���ĳ��ȶ̵Ļ�
				if(!final[w] && (min+G.arc[k][w]<(*d)[w]))
				{
					//˵���ҵ��˸��̵�·�����޸�D[w],p[w]
					(*d)[w]=min+G.arc[k][w];  //������ǰ·������
					(*p)[w]=k;
				}
			}
		}
		/*��ӡDijkstra���·���Ľ��*/
		cout<<"Dijstra�㷨�Ľ��Ϊ: "<<endl;
		for(int i=0;i<G.numvertexes;i++)
			cout<<"shortest("<<G.vexs[v0]<<","<<G.vexs[i]<<")="<<(*d)[i]<<endl;
}


	
int main()
{
	Mgraph G;

	CreateMgraph(&G);
	ShowMgraph(G);


	/*�����·���Ĺ���*/
	 Patharc p;
	 ShortPathTable d;

	 ShortestPath_Dijstra(G,0,&p,&d);

	 system("pause");
	 return 0;
}
