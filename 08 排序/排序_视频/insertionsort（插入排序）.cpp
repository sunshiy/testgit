//insertionsort.cpp   �ݹ�ʵ���������
#include<iostream>

using namespace std;

void  insertionsort(int *a,int n);


int main()
{
	int x[]={2,4,6,8,0,2,3,4,5,6};

	for(int i=0;i<10;i++)
	cout<<x[i]<<" ";
	cout<<endl;

	insertionsort(x,10);

	cout<<"����֮��Ľ����:";
	for(int i=0;i<10;i++)
	cout<<x[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}

void  insertionsort(int *a,int n)
{

	int in,out;
	//out=0�Ѿ���ȥ
	for(out=1;out<n;out++)
	{
		int temp=a[out];
		in=out;
		while(in>0&&a[in-1]>=temp)
		{
			a[in]=a[in-1];
			--in;
		}
		a[in]=temp;
	}
}

