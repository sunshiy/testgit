
//直接插入排序，将一个记录插入到已经排好序的有序表中
#include<iostream>
//未设置哨兵
using namespace std;

typedef int status;

#define true 1
#define false 0
#define error 0
#define ok 1
#define maxsize 10  //用于要排序数组个数最大值，可根据需要修改

//结构定义
typedef struct Sqlist
{
	int r[maxsize+1];   //用于存储要排序的数组，r[0]用作哨兵或者临时变量
	int length;    //用于记录顺序表的长度
};


//操作
status Initlist(Sqlist *L);
status Listinsert(Sqlist *L,int i,int e);
//插入元素
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

//交换L中数组r的下标i和j的值
void Swap(Sqlist *L,int i,int j)
{
	int temp=L->r[i];
	L->r[i]=L->r[j];
	L->r[j]=temp;
}

//操作
status Initlist(Sqlist *L) 
{ 
    L->length=0;
    return ok;
}

//对顺序表L做直接插入排序
void Insertsort(Sqlist *L)
{
	int i,j，temp=L->r[0];
	for(i=1;i<=L->length;i++)
	{
		if(L->r[i]<L->r[i-1])    //需要将L->r[i]插入有序子表中
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
	   cout<<"第"<<i+1<<"个数字为："<<L->r[i]<<endl;
}


int main()
{
	Sqlist L;
    
    int e=0;
    status i=0;

	int j;
    i=Initlist(&L);
    cout<<"初始化L后：L.length="<<L.length<<"\n";

        i=Listinsert(&L,1,9);
		i=Listinsert(&L,1,1);
		i=Listinsert(&L,1,5);
		i=Listinsert(&L,1,8);
		i=Listinsert(&L,1,3);
		i=Listinsert(&L,1,7);
		i=Listinsert(&L,1,4);
		i=Listinsert(&L,1,6);
		i=Listinsert(&L,1,2);  
    cout<<"在L的表头依次插入9,1,5,8,3,7,4,6,2后：L.data="<<endl;
    Showsqlist(&L); 


	Insertsort(&L);
	cout<<"Insertsort排序后，结果为："<<endl;
	Showsqlist(&L); 


	system("pause");
	return 0;
}