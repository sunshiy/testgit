//string的顺序存储结构
#include<iostream>

#define MAXSIZE 100
#define ERROR 0
#define OK 1

using namespace std;

typedef int Status;
typedef int Elemtype;
typedef char String[MAXSIZE + 1]; /*  0号单元存放串的长度 */

//operation
Status Strassign(String T,char *chars);  //生成一个值等于字符串常量chars的串T
Status Strcopy(String T,String S);//由串S复制得到串T
Status Clearstring(String S);  //串S存在，将串清空
Status Stringempty(String S);
int Strlength(String S);
Status Strcompare(String S,String T);  //若S>T,返回S>T；若S=T,返回S=T；若S<T,返回S<T
Status Concat(String T,String S1,String S2);//用T返回S1和S2连接的新串
Status Substring(String Sub,String S,int pos,int len);//串S存在，用Sub返回S 的第POS个字符起len长度的子串
Status Index(String S,String T,int pos);//串S和T存在，若主串S存在和串T值相同的子串，
//则返回S 的第POS个字符之后第一次出现的位置，否则返回0
Status Replace(String S,String T,String V);//串S,T和V存在，T是非空串，用V替换主串S中出现的所有与T相等的不重叠的子串
Status Strinsert(String S,int pos,String T);//在串S的第POS个字符前插入串T
Status Strdelete(String S,int pos,int len);//在串S 中删除第POS个字符起长度为len的子串
Status Inputstring(String S); //输出字符串

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
	//由串S复制得到串T
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

Status Concat(String T,String S1,String S2)//用T返回S1和S2连接的新串
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


Status Substring(String Sub,String S,int pos,int len)//串S存在，用Sub返回S 的第POS个字符起len长度的子串
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
//T为非空串，主串S第pos个字符存在与T相等的子串
//则返回第一个这样的子串在S中的位置，否则返回0
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


Status Replace(String S,String T,String V)//串S,T和V存在，T是非空串，用V替换主串S中出现的所有与T相等的不重叠的子串
{
	int i = 1; /*  从串S的第一个字符起查找串T */
	if (Stringempty(T)) /*  T是空串 */
		return ERROR;
	do 
	{
		i = Index(S, T, i); /*  结果i为从上一个i之后找到的子串T的位置 */
		if (i) /*  串S中存在串T */
		{
			Strdelete(S, i, Strlength(T)); /*  删除该串T */
			Strinsert(S, i, V); /*  在原串T的位置插入串V */
			i += Strlength(V); /*  在插入的串V后面继续查找串T */
		}
	} while (i);
	return OK;
}

Status Strinsert(String S,int pos,String T)//在串S的第POS个字符前插入串T
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

Status Strdelete(String S,int pos,int len)//在串S 中删除第POS个字符起长度为len的子串
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

	cout<<"请输入串s1: "<<endl;
	k = Strassign(s1, "abcd");
	Inputstring(s1);

	if (!k) 
	{
		cout<<"串长超过"<<MAXSIZE<<endl;
		exit(0);
	}
	cout<<"串长为"<<Strlength(s1)<<"  ,串空否？(1:是 0:否)  "<<Stringempty(s1)<<endl;

	Strcopy(s2, s1);  
	cout<<"拷贝s1生成的串为: "<<endl;
	Inputstring(s2);
	
	cout<<"请输入串s2: "<<endl;
	k = Strassign(s2, "efghijk");
	Inputstring(s2);

	if (!k) 
	{
		cout<<"串长超过"<<MAXSIZE<<endl;
		exit(0);
	}
	i = Strcompare(s1, s2);
	if (i < 0)
		s = '<';
	else if (i == 0)
		s = '=';
	else
		s = '>';
	cout<<"串s1 "<<s<<" 串s2\n"<<endl;

	k = Concat(t, s1, s2);
	cout<<"串s1联接串s2得到的串t为: "<<endl;
    Inputstring(t);

	if (k == ERROR)
		cout<<"串t有截断\n";

	Clearstring(s1);
	cout<<"清为空串后,串s1为: \n";
	Inputstring(s1);
	cout<<"串长为 "<<Strlength(s1)<<" 串空否？(1:是 0:否) "<< Stringempty(s1)<<endl;

	cout<<"求串t的子串,请输入子串的起始位置i,子串长度j: \n";
 
	i = 2;
	j = 3;
	cout<<i<<" "<<j<<endl;
   
	k = Substring(s2, t, i, j);
	if (k) 
	{
		cout<<"子串s2为: ";
		Inputstring(s2);
	}

	cout<<"从串t的第pos个字符起,删除len个字符，请输入pos,len: \n";
 
	i = 4;
	j = 2;
	cout<<i<<" "<<j<<endl;
	Strdelete(t, i, j);
	cout<<"删除后的串t为: \n";
	Inputstring(t);

	
	i = Strlength(s2) / 2;
	cout<<"在串s2的第"<<i<<"个字符之前插入串t后,串s2为:\n";
	Strinsert(s2, i, t);
	Inputstring(s2);

	i = Index(s2, t, 1);
	cout<<"s2的第"<<i<<"个字母起和t第一次匹配.\n";

	Substring(t, s2, 1, 1);
	cout<<"串t为：";
	Inputstring(t);

	Concat(s1, t, t);
	cout<<"串s1为：";
	Inputstring(s1);

	Replace(s2, t, s1);//串S,T和V存在，T是非空串，用V替换主串S中出现的所有与T相等的不重叠的子串
	cout<<"用串s1取代串s2中和串t相同的不重叠的串后,串s2为: \n";
	Inputstring(s2);
 
	system("pause");
	return 0;
}