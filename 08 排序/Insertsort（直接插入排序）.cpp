
//ֱ�Ӳ������򣬽�һ����¼���뵽�Ѿ��ź�����������
#include<iostream>
//δ�����ڱ�
using namespace std;

typedef int status;

#define true 1
#define false 0
#define error 0
#define ok 1
#define maxsize 10  //����Ҫ��������������ֵ���ɸ�����Ҫ�޸�

//�ṹ����
typedef struct Sqlist
{
	int r[maxsize+1];   //���ڴ洢Ҫ��������飬r[0]�����ڱ�������ʱ����
	int length;    //���ڼ�¼˳���ĳ���
};


//����
status Initlist(Sqlist *L);
status Listinsert(Sqlist *L,int i,int e);
//����Ԫ��
status Listinsert(Sqlist *L,int i,int e)
{
	int k;
	if(L->length==maxsize)
		return error;
	if(i<1||i>L->length+1)
		return error;
	if(i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--)
			L->r[k+1]=L->r[k];
	}
	L->r[i-1]=e;
	L->length++;
	return ok;
}

//����L������r���±�i��j��ֵ
void Swap(Sqlist *L,int i,int j)
{
	int temp=L->r[i];
	L->r[i]=L->r[j];
	L->r[j]=temp;
}

//����
status Initlist(Sqlist *L) 
{ 
    L->length=0;
    return ok;
}

//��˳���L��ֱ�Ӳ�������
void Insertsort(Sqlist *L)
{
	int i,j��temp=L->r[0];
	for(i=1;i<=L->length;i++)
	{
		if(L->r[i]<L->r[i-1])    //��Ҫ��L->r[i]���������ӱ���
		{
			temp=L->r[i];
			for(j=i-1;L->r[j]>temp;j--)
				L->r[j+1]=L->r[j];
			L->r[j+1]=temp;
		}
	}
}

void Showsqlist(Sqlist *L)
{
   int a=L->length;
   for(int i=0;i<a;i++)
	   cout<<"��"<<i+1<<"������Ϊ��"<<L->r[i]<<endl;
}


int main()
{
	Sqlist L;
    
    int e=0;
    status i=0;

	int j;
    i=Initlist(&L);
    cout<<"��ʼ��L��L.length="<<L.length<<"\n";

        i=Listinsert(&L,1,9);
		i=Listinsert(&L,1,1);
		i=Listinsert(&L,1,5);
		i=Listinsert(&L,1,8);
		i=Listinsert(&L,1,3);
		i=Listinsert(&L,1,7);
		i=Listinsert(&L,1,4);
		i=Listinsert(&L,1,6);
		i=Listinsert(&L,1,2);  
    cout<<"��L�ı�ͷ���β���9,1,5,8,3,7,4,6,2��L.data="<<endl;
    Showsqlist(&L); 


	Insertsort(&L);
	cout<<"Insertsort����󣬽��Ϊ��"<<endl;
	Showsqlist(&L); 


	system("pause");
	return 0;
}