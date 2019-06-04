//算法思想简单描述：
//在要排序的一组数中，选出最小的一个数与第一个位置的数交换；
//然后在剩下的数当中再找最小的与第二个位置的数交换，如此循环到倒数第二个数和最后一个数比较为止。
//选择排序是不稳定的。算法复杂度O(n2)--[n的平方]

//selectsort.cpp 
#include<iostream>

using namespace std;

void selectsort(int *list,const int n);

int main()
{
	int a[]={2,3,6,8,1,3,0,5,3,2,6,7,8};
	for(int k=0;k<13;k++)
		cout<<a[k]<<" ";
	    cout<<endl;
	selectsort(a,13);
	cout<<"排序之后的结果是:"<<endl;
	for(int k=0;k<13;k++)
		cout<<a[k]<<" ";
		cout<<endl;
	return 0;
}

void selectsort(int *list,const int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(list[j]<list[min])
			  min=j;
            
		}
		swap(list[i],list[min]);
	}

}

