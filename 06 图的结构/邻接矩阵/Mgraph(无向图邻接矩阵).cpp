//�����ڽӾ���
#include<iostream>

using namespace std;

#define MAXVEX 100
#define INFINITY 65535   //���������

//�ڽӾ���
typedef char Vertextype;  //��������
typedef int Edgetype;    //���ϵ�Ȩֵ����

typedef struct Mgraph  //ͼ�Ķ���
{
	Vertextype vexs[MAXVEX];   //�����
	Edgetype arc[MAXVEX][MAXVEX];  //�ڽӾ���	
	int numvertexes,numedges;   //ͼ�е�ǰ�Ķ������ͱ���
} Mgraph;


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

int main()
{
	Mgraph G;
	CreateMgraph(&G);
	ShowMgraph(G);

	system("pause");
	return 0;
}


/*ʹ��cout������õ�����

//�����ڽӾ���
#include<iostream>
#include<iomanip>

using namespace std;

#define MAXVEX 100
#define INFINITY 65535   //���������

//�ڽӾ���
typedef char Vertextype;  //��������
typedef int Edgetype;    //���ϵ�Ȩֵ����

typedef struct Mgraph  //ͼ�Ķ���
{
	Vertextype vexs[MAXVEX];   //�����
	Edgetype arc[MAXVEX][MAXVEX];  //�ڽӾ���	
	int numvertexes,numedges;   //ͼ�е�ǰ�Ķ������ͱ���
} Mgraph;


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
		cout<<setw(8)<<G.vexs[i];
	       cout<<endl;
		for(i=0;i<G.numvertexes;i++)
		{
			cout<<endl<<setw(8)<<G.vexs[i];
        for(j=0;j<G.numvertexes;j++)
        { 
            if(G.arc[i][j]==INFINITY) 
        //������ͼ��һ����"0"��ʾ��������ͼ��һ����"��",
       // ����Ϊ�˷���ͳһ��� "��"
            cout<<setw(8)<<65535;
        else
            cout<<setw(8)<<G.arc[i][j];
        }
           cout<<endl;
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
*/
