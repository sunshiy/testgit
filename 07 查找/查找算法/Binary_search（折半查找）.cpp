//折半查找算法，条件：线性表按顺序依次排列

#include<iostream>

using namespace std;

//折半查找
int Binary_search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;
	high=n;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(key<a[mid])
			high=mid-1;
		else if(key>a[mid])
		   low=mid+1;
		else
			return mid;
	}
	return 0;
}


int main()
{
	int a[10]={0,3,4,5,7,8,9,12,15,16};  //a[0]不存储数据
   int i=0;
   int b=9;
   cout<<"使用折半查找法的结果是:"<<endl;
   i=Binary_search(a,9,b);
   
   if(i==0)
	   cout<<"找不到！"<<endl;
   else
      cout<<"数字"<<b<<"在第"<<i<<"个位置"<<endl;

	system("pause");
	return 0;
}