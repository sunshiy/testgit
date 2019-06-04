//算法思想简单描述：
//在要排序的一组数中，对当前还未排好序的范围内的全部数，自上而下对相邻的两个数依次进行比较和调整，让较大的数往下沉，较小的往上冒。
//即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换。
//下面是一种改进的冒泡算法，它记录了每一遍扫描后最后下沉数的位置k，这样可以减少外层循环扫描的次数。
//冒泡排序是稳定的。算法时间复杂度O(n2)--[n的平方]

//bubblesort.cpp 
#include<iostream>

using namespace std;

void bubblesort(int list[],int n);

int main()
{
	int a[]={2,3,6,8,1,3,0,5,3,2,6,7,8};
	for(int k=0;k<13;k++)
		cout<<a[k]<<" ";
	    cout<<endl;
	bubblesort(a,13);
	cout<<"排序之后的结果是:"<<endl;
	for(int k=0;k<13;k++)
		cout<<a[k]<<" ";
		cout<<endl;
	return 0;
}

void bubblesort(int list[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(list[j]>list[j+1])
				swap(list[j],list[j+1]);
		}
	}
}

