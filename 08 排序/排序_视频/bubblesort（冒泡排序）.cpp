//�㷨˼���������
//��Ҫ�����һ�����У��Ե�ǰ��δ�ź���ķ�Χ�ڵ�ȫ���������϶��¶����ڵ����������ν��бȽϺ͵������ýϴ�������³�����С������ð��
//����ÿ�������ڵ����ȽϺ������ǵ�����������Ҫ���෴ʱ���ͽ����ǻ�����
//������һ�ָĽ���ð���㷨������¼��ÿһ��ɨ�������³�����λ��k���������Լ������ѭ��ɨ��Ĵ�����
//ð���������ȶ��ġ��㷨ʱ�临�Ӷ�O(n2)--[n��ƽ��]

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
	cout<<"����֮��Ľ����:"<<endl;
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

