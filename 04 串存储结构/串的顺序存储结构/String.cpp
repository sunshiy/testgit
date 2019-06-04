//string��˳��洢�ṹ
#include<iostream>

#define MAXSIZE 100
#define ERROR 0
#define OK 1

using namespace std;

typedef int Status;
typedef int Elemtype;
typedef char String[MAXSIZE + 1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */

//operation
Status Strassign(String T,char *chars);  //����һ��ֵ�����ַ�������chars�Ĵ�T
Status Strcopy(String T,String S);//�ɴ�S���Ƶõ���T
Status Clearstring(String S);  //��S���ڣ��������
Status Stringempty(String S);
int Strlength(String S);
Status Strcompare(String S,String T);  //��S>T,����S>T����S=T,����S=T����S<T,����S<T
Status Concat(String T,String S1,String S2);//��T����S1��S2���ӵ��´�
Status Substring(String Sub,String S,int pos,int len);//��S���ڣ���Sub����S �ĵ�POS���ַ���len���ȵ��Ӵ�
Status Index(String S,String T,int pos);//��S��T���ڣ�������S���ںʹ�Tֵ��ͬ���Ӵ���
//�򷵻�S �ĵ�POS���ַ�֮���һ�γ��ֵ�λ�ã����򷵻�0
Status Replace(String S,String T,String V);//��S,T��V���ڣ�T�Ƿǿմ�����V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
Status Strinsert(String S,int pos,String T);//�ڴ�S�ĵ�POS���ַ�ǰ���봮T
Status Strdelete(String S,int pos,int len);//�ڴ�S ��ɾ����POS���ַ��𳤶�Ϊlen���Ӵ�
Status Inputstring(String S); //����ַ���

//////////////////////////////////////////////////////////
Status Strassign(String T,char *chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else 
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}


Status Strcopy(String T,String S)
	//�ɴ�S���Ƶõ���T
{
	int i;
	T[0]=S[0];
	for(i=1;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

Status Clearstring(String S)
{
	S[0]=0;
	return OK;
}

Status Stringempty(String S)
{
	if(S[0]==0)
		return OK;
	else
		return ERROR;
}


int Strlength(String S)
{
	return S[0];
}

Status Strcompare(String S,String T)
{
	int a=S[0],b=T[0];
	for(int i=1;i<max(a,b);i++)
	{
		if(S[i]==T[i])
			continue;
		else
		{
			if(S[i]>T[i])
				return 1;
			else if(S[i]<T[i])
				return -1;
		}
		return 0;
	}
}

Status Concat(String T,String S1,String S2)//��T����S1��S2���ӵ��´�
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return OK;
	}
	else
	{
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return OK;
	}
}


Status Substring(String Sub,String S,int pos,int len)//��S���ڣ���Sub����S �ĵ�POS���ַ���len���ȵ��Ӵ�
{
	if(S[0]==0)
		return ERROR;
	if(pos<1||pos>S[0]||len<0||pos+len-1>S[0])
		return ERROR;
	for(int i=1;i<=len;i++)
	Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return OK;
}
//TΪ�ǿմ�������S��pos���ַ�������T��ȵ��Ӵ�
//�򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
int Index(String S,String T,int pos)
{
	int n,m,i;
	String sub;
	if(pos>0)
	{
		n=Strlength(S);
		m=Strlength(T);
		i=pos;
		while(i<=n-m+1)
		{
			Substring(sub,S,i,m);
			if(Strcompare(sub,T)!=0)
				++i;
			else
				return i;
		}
	}
	return 0;
}


Status Replace(String S,String T,String V)//��S,T��V���ڣ�T�Ƿǿմ�����V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
{
	int i = 1; /*  �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
	if (Stringempty(T)) /*  T�ǿմ� */
		return ERROR;
	do 
	{
		i = Index(S, T, i); /*  ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
		if (i) /*  ��S�д��ڴ�T */
		{
			Strdelete(S, i, Strlength(T)); /*  ɾ���ô�T */
			Strinsert(S, i, V); /*  ��ԭ��T��λ�ò��봮V */
			i += Strlength(V); /*  �ڲ���Ĵ�V����������Ҵ�T */
		}
	} while (i);
	return OK;
}

Status Strinsert(String S,int pos,String T)//�ڴ�S�ĵ�POS���ַ�ǰ���봮T
{
	int i;
	if (pos < 1 || pos > S[0] + 1)
		return ERROR;

	if(S[0]+T[0]<=MAXSIZE)
	{
	for(i=pos;i<=S[0];i++)
		S[i+T[0]]=S[i];
	for(i=pos;i<T[0]+pos;i++)
		S[i]=T[i-pos+1];
	S[0]=S[0]+T[0];
	return OK;
	}
	else
	{
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
        for(i=pos;i<T[0]+pos;i++)
			S[i]=T[i-pos+1];
		S[0] = MAXSIZE;
		return ERROR;
	}
}

Status Strdelete(String S,int pos,int len)//�ڴ�S ��ɾ����POS���ַ��𳤶�Ϊlen���Ӵ�
{
	if(pos<0||pos>S[0]||len<0||pos+len-1>S[0])
		return ERROR;
	int i;
	for(i=pos+len;i<=S[0];i++)
	S[i-len]=S[i];
	S[0]=S[0]-len;
	return OK;
}


Status Inputstring(String S)
{
	int i;
	for(i=1;i<=S[0];i++)
		std::cout<<S[i];
	std::cout<<std::endl;
	return OK;
}

int main() 
{
    using namespace std;
	int i, j;
	Status k;
	char s;
	String t, s1, s2;

	cout<<"�����봮s1: "<<endl;
	k = Strassign(s1, "abcd");
	Inputstring(s1);

	if (!k) 
	{
		cout<<"��������"<<MAXSIZE<<endl;
		exit(0);
	}
	cout<<"����Ϊ"<<Strlength(s1)<<"  ,���շ�(1:�� 0:��)  "<<Stringempty(s1)<<endl;

	Strcopy(s2, s1);  
	cout<<"����s1���ɵĴ�Ϊ: "<<endl;
	Inputstring(s2);
	
	cout<<"�����봮s2: "<<endl;
	k = Strassign(s2, "efghijk");
	Inputstring(s2);

	if (!k) 
	{
		cout<<"��������"<<MAXSIZE<<endl;
		exit(0);
	}
	i = Strcompare(s1, s2);
	if (i < 0)
		s = '<';
	else if (i == 0)
		s = '=';
	else
		s = '>';
	cout<<"��s1 "<<s<<" ��s2\n"<<endl;

	k = Concat(t, s1, s2);
	cout<<"��s1���Ӵ�s2�õ��Ĵ�tΪ: "<<endl;
    Inputstring(t);

	if (k == ERROR)
		cout<<"��t�нض�\n";

	Clearstring(s1);
	cout<<"��Ϊ�մ���,��s1Ϊ: \n";
	Inputstring(s1);
	cout<<"����Ϊ "<<Strlength(s1)<<" ���շ�(1:�� 0:��) "<< Stringempty(s1)<<endl;

	cout<<"��t���Ӵ�,�������Ӵ�����ʼλ��i,�Ӵ�����j: \n";
 
	i = 2;
	j = 3;
	cout<<i<<" "<<j<<endl;
   
	k = Substring(s2, t, i, j);
	if (k) 
	{
		cout<<"�Ӵ�s2Ϊ: ";
		Inputstring(s2);
	}

	cout<<"�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: \n";
 
	i = 4;
	j = 2;
	cout<<i<<" "<<j<<endl;
	Strdelete(t, i, j);
	cout<<"ɾ����Ĵ�tΪ: \n";
	Inputstring(t);

	
	i = Strlength(s2) / 2;
	cout<<"�ڴ�s2�ĵ�"<<i<<"���ַ�֮ǰ���봮t��,��s2Ϊ:\n";
	Strinsert(s2, i, t);
	Inputstring(s2);

	i = Index(s2, t, 1);
	cout<<"s2�ĵ�"<<i<<"����ĸ���t��һ��ƥ��.\n";

	Substring(t, s2, 1, 1);
	cout<<"��tΪ��";
	Inputstring(t);

	Concat(s1, t, t);
	cout<<"��s1Ϊ��";
	Inputstring(s1);

	Replace(s2, t, s1);//��S,T��V���ڣ�T�Ƿǿմ�����V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
	cout<<"�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: \n";
	Inputstring(s2);
 
	system("pause");
	return 0;
}