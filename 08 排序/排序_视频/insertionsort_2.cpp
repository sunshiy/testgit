//insertionsort_2.cpp   递归实现排列组合
#include<iostream>

using namespace std;

template<class T>
void  insertionsort(T *a,int n);

template<class T>
void  insertionsort_2(T *a,int n);


int main()
{
	double x[]={2.2,4,6,8.9,0.2,2.1,3.2,4,5,6};

	for(int i=0;i<10;i++)
	cout<<x[i]<<" ";
	cout<<endl;

	insertionsort(x,10);

	cout<<"排列之后的结果是:";
	for(int i=0;i<10;i++)
	cout<<x[i]<<" ";
	cout<<endl;

	cout<<"-----------------------------------"<<endl;

	insertionsort_2(x,10);

	cout<<"排列2之后的结果是:";
	for(int i=0;i<10;i++)
	cout<<x[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}

template <class T>
void  insertionsort(T *a,int n)
{

	int in,out;
	//out=0已经出去
	for(out=1;out<n;out++)
	{
		T temp=a[out];
		in=out;
		while(in>0&&a[in-1]>=temp)
		{
			a[in]=a[in-1];
			--in;
		}
		a[in]=temp;
	}
}

template<class T>
void  insertionsort_2(T *a,int n)      //0不能完整
{
	for(int j=2;j<=n;j++)
	{
		T temp=a[j];
		a[0]=temp;
		int i=j-1;
		while(temp<a[j])
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=temp;
	}
}
