//�㷨˼���������
//��Ҫ�����һ�����У�ѡ����С��һ�������һ��λ�õ���������
//Ȼ����ʣ�µ�������������С����ڶ���λ�õ������������ѭ���������ڶ����������һ�����Ƚ�Ϊֹ��
//ѡ�������ǲ��ȶ��ġ��㷨���Ӷ�O(n2)--[n��ƽ��]

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
	cout<<"����֮��Ľ����:"<<endl;
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

