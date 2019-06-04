//哈希散列表
#include<iostream>

using namespace std;

typedef int status;

#define success 1
#define unsuccess 0
#define ok 1
#define false 0

typedef int status;

#define hashsize 12   //定义散列表为数组的长度
#define nullkey -32768


//哈希表结构定义
typedef struct Hashtable 
{
	int *elem;   //数据元素存储基址，动态分配数组
	int count;    //当前数据元素个数
}Hashtable;
int m=0;  //散列表的表长，全局变量



//操作
status Inithashtable(Hashtable *H);
int Hash(int key);
void Inserthash(Hashtable *H,int key);
status Searchhash(Hashtable H,int key,int *addr);
void Createhash(Hashtable H,int a[],int n);
void Showhash(Hashtable H);


 //初始化散列表
status Inithashtable(Hashtable *H)
{
	int i;
	m=hashsize;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=nullkey;
	return ok;
}

//散列函数
int Hash(int key)
{
	return key%m;//除留余数法
}
   
//插入关键字进散列表
void Inserthash(Hashtable *H,int key)
{
	int addr=Hash(key);   //求散列地址
	while(H->elem[addr]!=nullkey)  //如果不为空，则冲突
		addr=(addr+1)%m;   //开放定址法的线性探测
	H->elem[addr]=key;    //直到有空位后插入关键字
}


//散列表查找关键字
status Searchhash(Hashtable H,int key,int *addr)
{
	*addr=Hash(key);  //求散列地址
	while(H.elem[*addr]!=key)   //如果不为空，则冲突
	{
		*addr=(*addr+1)%m;   //开放定址法的线性探测
		if(H.elem[*addr]==nullkey||*addr==Hash(key))
		{
			//循环回到原点
			return unsuccess;   //则说明关键字不存在
		}
	}
	return success;
}


void Createhash(Hashtable H,int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Inserthash(&H,a[i]);
	}
}


void Showhash(Hashtable H)
{
   int a=H.count;
   for(int i=0;i<a;i++)
	   cout<<"第"<<i<<"个数字为："<<H.elem[i]<<endl;

}


int main()
{
	int arr[hashsize]={12,67,56,16,25,37,22,29,15,47,48,34};
	int i,p,key,result;
	Hashtable H;
 
	key=39;
 
	Inithashtable(&H);
	cout<<"初始化后，打印的结果为:"<<endl;
	Showhash(H);

	Createhash(H,arr,hashsize);
	cout<<"创建哈希表后，打印的结果为:"<<endl;
	Showhash(H);

	result=Searchhash(H,key,&p);
	if (result)
		cout<<"查找"<<key<<"的地址为："<<p<<"\n";
	else
		cout<<"查找"<<key<<"失败.\n";
 

	for(i=0;i<m;i++)
	{
		key=arr[i];
		Searchhash(H,key,&p);
		cout<<"查找"<<key<<"的地址为："<<p<<"\n";
	}

	system("pause");
	return 0;
}