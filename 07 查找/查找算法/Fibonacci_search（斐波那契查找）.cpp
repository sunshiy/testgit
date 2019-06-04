//斐波那契查找算法，条件：斐波那契数列

#include<iostream>

using namespace std;

int F[11]={0,1,1,2,3,5,8,13,21,35,46};
//斐波那契查找
int Fibonacci_search(int *a,int n,int key)
{
	int low,high,mid,i,k;
	low=1;
	high=n;
	k=0;

	while(n>F[k]-1)   //计算n位于斐波那契数列的位置
		k++;

	for(i=n;i<F[k]-1;i++)
		a[i]=a[n];

	while(low<=high)
	{
		mid=low+F[k-1]-1;
		if(key<a[mid])
		{
			high=mid-1;
			k=k-1;
		}
		else if(key>a[mid])
		{
		   low=mid+1;
		   k=k-2;
		}
		else
			
		{
			if(mid<=n)
				return mid;
			else
				return n;
		}
	}
	return 0;
}


int main()
{
	int a[10]={0,3,4,5,7,8,9,12,15,16};  //a[0]不存储数据
   int i=0;
   int b=9;
   cout<<"使用斐波那契查找法的结果是:"<<endl;
   i=Fibonacci_search(a,9,b);
   
   if(i==0)
	   cout<<"找不到！"<<endl;
   else
      cout<<"数字"<<b<<"在第"<<i<<"个位置"<<endl;

	system("pause");
	return 0;
}