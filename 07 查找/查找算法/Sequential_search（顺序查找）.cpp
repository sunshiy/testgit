//顺序表查找算法

#include<iostream>

using namespace std;

//顺序查找，a为数组，n为要查找的数组长度，key为要查找的关键字
int Sequential_search(int *a,int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i+1;
	}
	return 0;
}

//设置哨兵，按顺序查找
int Sequential_search2(int *a,int n,int key)
{
	int i;
	i=n;
	a[0]=key;   //a[0]为哨兵

	while(a[i]!=key)
		i--;
	return i+1;
}


//设置哨兵，按顺序查找
int Sequential_search3(int *a,int n,int key)
{
	int i;
	i=n;
	if(a[0]==key)  //a[0]为哨兵
        return 1;
	else
	{
		a[0]=key;
	    while(a[i]!=key)
		i--;
		return i;
	}
	return 0;
}

int main()
{
	int a[10]={3,4,2,7,8,5,9,6,10,12};
	
   int b=0;
   cout<<"使用顺序查找法的结果是:"<<endl;
   b=Sequential_search(a,10,8);
   cout<<"数字8在第"<<b<<"个位置"<<endl;


   cout<<"使用哨兵顺序查找法的结果是:"<<endl;
   b=Sequential_search2(a,10,8);
   cout<<"数字8在第"<<b<<"个位置"<<endl;

   cout<<"使用哨兵顺序查找法3的结果是:"<<endl;
   b=Sequential_search3(a,10,1);
   if(b==0)
	   cout<<"找不到！"<<endl;
   else
      cout<<"数字在第"<<b<<"个位置"<<endl;

	system("pause");
	return 0;
}