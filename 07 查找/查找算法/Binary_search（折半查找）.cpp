//�۰�����㷨�����������Ա�˳����������

#include<iostream>

using namespace std;

//�۰����
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
	int a[10]={0,3,4,5,7,8,9,12,15,16};  //a[0]���洢����
   int i=0;
   int b=9;
   cout<<"ʹ���۰���ҷ��Ľ����:"<<endl;
   i=Binary_search(a,9,b);
   
   if(i==0)
	   cout<<"�Ҳ�����"<<endl;
   else
      cout<<"����"<<b<<"�ڵ�"<<i<<"��λ��"<<endl;

	system("pause");
	return 0;
}