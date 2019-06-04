//��ϣɢ�б�
#include<iostream>

using namespace std;

typedef int status;

#define success 1
#define unsuccess 0
#define ok 1
#define false 0

typedef int status;

#define hashsize 12   //����ɢ�б�Ϊ����ĳ���
#define nullkey -32768


//��ϣ��ṹ����
typedef struct Hashtable 
{
	int *elem;   //����Ԫ�ش洢��ַ����̬��������
	int count;    //��ǰ����Ԫ�ظ���
}Hashtable;
int m=0;  //ɢ�б�ı���ȫ�ֱ���



//����
status Inithashtable(Hashtable *H);
int Hash(int key);
void Inserthash(Hashtable *H,int key);
status Searchhash(Hashtable H,int key,int *addr);
void Createhash(Hashtable H,int a[],int n);
void Showhash(Hashtable H);


 //��ʼ��ɢ�б�
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

//ɢ�к���
int Hash(int key)
{
	return key%m;//����������
}
   
//����ؼ��ֽ�ɢ�б�
void Inserthash(Hashtable *H,int key)
{
	int addr=Hash(key);   //��ɢ�е�ַ
	while(H->elem[addr]!=nullkey)  //�����Ϊ�գ����ͻ
		addr=(addr+1)%m;   //���Ŷ�ַ��������̽��
	H->elem[addr]=key;    //ֱ���п�λ�����ؼ���
}


//ɢ�б���ҹؼ���
status Searchhash(Hashtable H,int key,int *addr)
{
	*addr=Hash(key);  //��ɢ�е�ַ
	while(H.elem[*addr]!=key)   //�����Ϊ�գ����ͻ
	{
		*addr=(*addr+1)%m;   //���Ŷ�ַ��������̽��
		if(H.elem[*addr]==nullkey||*addr==Hash(key))
		{
			//ѭ���ص�ԭ��
			return unsuccess;   //��˵���ؼ��ֲ�����
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
	   cout<<"��"<<i<<"������Ϊ��"<<H.elem[i]<<endl;

}


int main()
{
	int arr[hashsize]={12,67,56,16,25,37,22,29,15,47,48,34};
	int i,p,key,result;
	Hashtable H;
 
	key=39;
 
	Inithashtable(&H);
	cout<<"��ʼ���󣬴�ӡ�Ľ��Ϊ:"<<endl;
	Showhash(H);

	Createhash(H,arr,hashsize);
	cout<<"������ϣ��󣬴�ӡ�Ľ��Ϊ:"<<endl;
	Showhash(H);

	result=Searchhash(H,key,&p);
	if (result)
		cout<<"����"<<key<<"�ĵ�ַΪ��"<<p<<"\n";
	else
		cout<<"����"<<key<<"ʧ��.\n";
 

	for(i=0;i<m;i++)
	{
		key=arr[i];
		Searchhash(H,key,&p);
		cout<<"����"<<key<<"�ĵ�ַΪ��"<<p<<"\n";
	}

	system("pause");
	return 0;
}