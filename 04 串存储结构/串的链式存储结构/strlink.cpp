//string的链式存储结构
#include<iostream>

#define MAXSIZE 256
#define ERROR 0
#define OK 1

using namespace std;

typedef int Status;
typedef int Elemtype;

typedef struct snode
{
    char data;              //数据域
    struct snode *next;     //指针域
}Strlink;

//operation操作
Status Strassign(Strlink *&T,char *chars);  //生成一个值等于字符串常量chars的串T
Status Strcopy(Strlink *&T,Strlink *S);//由串S复制得到串T
Status Clearstring(Strlink *S);  //串S存在，将串清空
Status Stringempty(Strlink *S);
int Strlength(Strlink *S);
Status Strcompare(Strlink *S,Strlink *T);  //若S>T,返回S>T；若S=T,返回S=T；若S<T,返回S<T
Strlink *Concat(Strlink *S1,Strlink *S2);//用T返回S1和S2连接的新串
Strlink *Substring(Strlink *S,int pos,int len);//串S存在，用Sub返回S 的第POS个字符起len长度的子串

Strlink *Strinsert(Strlink S,int pos,Strlink T);//在串S的第POS个字符前插入串T
Strlink *Strdelete(Strlink S,int pos,int len);//在串S 中删除第POS个字符起长度为len的子串
Status Inputstring(Strlink S); //输出字符串

//////////////////////////////////////////////////////////

Status Strassign(Strlink *&T,char *chars)
{
	Strlink *r,*p;
	T=(Strlink *)malloc(sizeof(Strlink));
	r=T;

	for(int i=0;chars[i]!='\0';i++)
	{
		p=(Strlink *)malloc(sizeof(Strlink));
		p->data=chars[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;

	return OK;
}


Status Strcopy(Strlink *&T,Strlink *S)
	//由串S复制得到串T
{
	Strlink *p=S->next,*q,*r;
	T=(Strlink *)malloc(sizeof(Strlink));
	r=T;

	while(p!=NULL)
	{
		q=(Strlink *)malloc(sizeof(Strlink));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
	r->next=NULL;

	return OK;
}

Status Clearstring(Strlink *S)
{
	Strlink *t=S->next;
	while(t)
	{
	   S->next=t->next;
       free(t);
	   t=S->next;
	}
	return OK;  
}

Status Stringempty(Strlink *S)
{
	if(S==NULL)
		return OK;
	else
		return ERROR;
}

int Strlength(Strlink *S)
{
	int i=0;
	Strlink *p=S->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}

Status Strcompare(Strlink *S,Strlink *T)
{
	Strlink *p=S->next,*q=T->next;
	
	while(p!=NULL &&q!=NULL)
	{
		if(p->data==q->data)
		  {
			continue;
		p=p->next;
		q=q->next;
		   }
		else if(p->data>q->data)
			return 1;
		else
			return -1;
	}
		return 0;
}

Strlink* Concat(Strlink *S1,Strlink *S2)//用T返回S1和S2连接的新串
{
     Strlink *str,*p=S1->next,*q,*r;
	//新串str
	str=(Strlink *)malloc(sizeof(Strlink));
	r=str;
	//将S的全部节点复制到str
	while(p!=NULL)
	{
		q=(Strlink *)malloc(sizeof(Strlink));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
		p=S2->next;
    //将T的全部节点复制到Str
		while(p!=NULL)
	{
		q=(Strlink *)malloc(sizeof(Strlink));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
		r->next=NULL;

		return str;
}


Strlink *Substring(Strlink *S,int pos,int len)//串S存在，用Sub返回S 的第POS个字符起len长度的子串
{	
	int k;
    Strlink *str,*p=S->next,*q,*r;
    str=(Strlink *)malloc(sizeof(Strlink));
    str->next=NULL;
    r=str; //r指向新串str的尾节点
    if (pos<=0 || pos>Strlength(S) || len<0 || pos+len-1>Strlength(S))
        return str; //参数非法时的处理
    //移动到串s的第i个节点
    for (k=0; k<pos-1; k++)
        p=p->next;
    //将s的第i个节点开始的j个节点复制到str
    for (k=1; k<=len; k++)
    {
        q=(Strlink *)malloc(sizeof(Strlink));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //将尾节点的next置为NULL
    r->next=NULL;
    return str;
}


Strlink* Strinsert(Strlink *S,int pos,Strlink *T)//在串S的第POS个字符前插入串T
{
	Strlink *str,*p=S->next,*p1=T->next,*q,*r;
	str=(Strlink *)malloc(sizeof(Strlink));
    str->next=NULL;
    r=str; //r指向新串str的尾节点

	int k;
	if (pos <= 0 || pos>Strlength(S) + 1)		
		return str;
	for (k = 1; k<pos; k++)					
	{
		q = new Strlink();
		q->data = p->data;
		r->next = q; 
		r = q;					
		p = p->next;
	}
	while (p1 != NULL)					
	{
		q = new Strlink();
		q->data = p1->data;
		r->next = q; 
		r = q;					
		p1 = p1->next;
	}
	while (p != NULL)						
	{
		q = new Strlink();
		q->data = p->data;
		r->next = q;
		r = q;					
		p = p->next;
	}
	r->next = NULL;						
	return str;						
 

}

Strlink *Strdelete(Strlink *S,int pos,int len)//在串S中删除第POS个字符起长度为len的子串
{
	int k;
	Strlink *str,*p=S->next,*q,*r;
	str=(Strlink *)malloc(sizeof(Strlink));
    str->next=NULL;
    r=str; //r指向新串str的尾节点

	if (pos <= 0 || pos>Strlength(S) ||len<0 || pos+len-1>Strlength(S))
	return str;

	for (k = 0; k<pos-1; k++)				
	{
		q = new Strlink();
		q->data = p->data;
		r->next = q; 
		r = q;					
		p = p->next;
	}

	for (k = 0; k<len; k++)					
		p = p->next;
	while (p != NULL)						
	{
		q = new Strlink();
		q->data = p->data;
		r->next = q; 
		r = q;				
		p = p->next;
	}
	r->next = NULL;						
	return str;						
}



Status Inputstring(Strlink *S)
{
	Strlink *p=S->next;
	while(p!=NULL)
	{
		std::cout<<p->data<<endl;
		p=p->next;
	}
	std::cout<<std::endl;

	return OK;
}

int main() 
{
    using namespace std;
	int i,j;
	Status k;
	char s;
	Strlink *s1,*s2,*t;

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

	t= Concat(s1, s2);
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
   
	s2=Substring(t,i,j);
	if (k) 
	{
		cout<<"子串s2为: \n";
		Inputstring(s2);
	}

	cout<<"从串t的第pos个字符起,删除len个字符，请输入pos,len: \n";
 
	i = 4;
	j = 2;
	cout<<i<<" "<<j<<endl;
	t=Strdelete(t, i, j);
	cout<<"删除后的串t为: \n";
	Inputstring(t);

	
	i = Strlength(s2) / 2;
	cout<<"在串s2的第"<<i<<"个字符之前插入串t后,串s2为:\n";
	s2=Strinsert(s2, i, t);
	Inputstring(s2);


	s1=Concat(s1, t);
	cout<<"串s1为：\n";
	Inputstring(s1);


	system("pause");
	return 0;
}