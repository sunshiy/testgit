//insertionsort__q.cpp  
#include<iostream>

using namespace std;

template<class T>
void  insertionsort(T *a,int n);


int main()
{
	double x[]={2.2,4,6,8.9,0,2.1,3.2,4,5,6};

	for(int i=0;i<10;i++)
	cout<<x[i]<<" ";
	cout<<endl;

	insertionsort(x,10);

	cout<<"排列之后的结果是:";
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
