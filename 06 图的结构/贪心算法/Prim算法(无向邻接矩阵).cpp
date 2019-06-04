//�����ڽӾ���
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



//���ͼ���ڽӾ���
void ShowMgraph(Mgraph G)
{
	int i,j;
	cout<<"��ӡ���:"<<endl;

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


//prim�㷨������С������
void MiniSpanTree_Prim(Mgraph G)
{
	int min,i,j,k;
	int adjvex[MAXVEX];   //������ض�����±�
	int lowcost[MAXVEX];   //������ض�����Ȩֵ

	lowcost[0]=0;  //��ʼ����һ��ȨֵΪ0����v0�Ѿ�����������
	//lowcost��ֵΪ0����������Ǵ��±��Ѿ�����������
	adjvex[0]=0;   //��ʼ����һ�������±�Ϊ0

	for(i=1;i<G.numvertexes;i++)  //ѭ�����±�Ϊ0���ȫ������
	{
		lowcost[i]=G.arc[0][i];  //��v0������֮�бߵ�Ȩֵ��������
		adjvex[i]=0;   //��ʼ����Ϊv0���±�
	}

	for(i=1;i<G.numvertexes;i++)  //ѭ�����±�Ϊ0���ȫ������
	{
		min=INFINITY;  //��ʼ����СȨֵΪ�����
		j=1,k=0;

		while(j<G.numvertexes)  //ѭ��ȫ������
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
				//���Ȩֵ��Ϊ0����ȨֵС��min
			{
				min=lowcost[j];  //�õ�ǰȨֵ��Ϊ��Сֵ

	            k=j;   //�򽫵�ǰ��Сֵ���±����k
			}
			j++;
		}

		cout<<"<"<<adjvex[k]<<"->"<<k<<">"<<endl;  //��ӡ��ǰ������Ȩֵ��С��
		lowcost[k]=0;    //��ǰ����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������

		for(j=1;j<G.numvertexes;j++)   //ѭ�����Զ���
		{
				if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
        //  ���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
				{
					lowcost[j]=G.arc[k][j];  //����Сֵ����lowcost
					adjvex[j]=k;//���±�Ϊk�Ķ������adjvex
				}
		}
	}
}

		
int main()
{
	Mgraph G;
	CreateMgraph(&G);
	ShowMgraph(G);

	cout<<"��С������Ϊ:"<<endl;
	MiniSpanTree_Prim(G);

	system("pause");
	return 0;
}
