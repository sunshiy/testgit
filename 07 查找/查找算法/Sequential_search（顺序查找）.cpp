//˳�������㷨

#include<iostream>

using namespace std;

//˳����ң�aΪ���飬nΪҪ���ҵ����鳤�ȣ�keyΪҪ���ҵĹؼ���
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

//�����ڱ�����˳�����
int Sequential_search2(int *a,int n,int key)
{
	int i;
	i=n;
	a[0]=key;   //a[0]Ϊ�ڱ�

	while(a[i]!=key)
		i--;
	return i+1;
}


//�����ڱ�����˳�����
int Sequential_search3(int *a,int n,int key)
{
	int i;
	i=n;
	if(a[0]==key)  //a[0]Ϊ�ڱ�
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
   cout<<"ʹ��˳����ҷ��Ľ����:"<<endl;
   b=Sequential_search(a,10,8);
   cout<<"����8�ڵ�"<<b<<"��λ��"<<endl;


   cout<<"ʹ���ڱ�˳����ҷ��Ľ����:"<<endl;
   b=Sequential_search2(a,10,8);
   cout<<"����8�ڵ�"<<b<<"��λ��"<<endl;

   cout<<"ʹ���ڱ�˳����ҷ�3�Ľ����:"<<endl;
   b=Sequential_search3(a,10,1);
   if(b==0)
	   cout<<"�Ҳ�����"<<endl;
   else
      cout<<"�����ڵ�"<<b<<"��λ��"<<endl;

	system("pause");
	return 0;
}