//string����ʽ�洢�ṹ
#include<iostream>

#define MAXSIZE 256
#define ERROR 0
#define OK 1

using namespace std;

typedef int Status;
typedef int Elemtype;

typedef struct snode
{
    char data;              //������
    struct snode *next;     //ָ����
}Strlink;

//operation����
Status Strassign(Strlink *&T,char *chars);  //����һ��ֵ�����ַ�������chars�Ĵ�T
Status Strcopy(Strlink *&T,Strlink *S);//�ɴ�S���Ƶõ���T
Status Clearstring(Strlink *S);  //��S���ڣ��������
Status Stringempty(Strlink *S);
int Strlength(Strlink *S);
Status Strcompare(Strlink *S,Strlink *T);  //��S>T,����S>T����S=T,����S=T����S<T,����S<T
Strlink *Concat(Strlink *S1,Strlink *S2);//��T����S1��S2���ӵ��´�
Strlink *Substring(Strlink *S,int pos,int len);//��S���ڣ���Sub����S �ĵ�POS���ַ���len���ȵ��Ӵ�

Strlink *Strinsert(Strlink S,int pos,Strlink T);//�ڴ�S�ĵ�POS���ַ�ǰ���봮T
Strlink *Strdelete(Strlink S,int pos,int len);//�ڴ�S ��ɾ����POS���ַ��𳤶�Ϊlen���Ӵ�
Status Inputstring(Strlink S); //����ַ���

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
	//�ɴ�S���Ƶõ���T
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

Strlink* Concat(Strlink *S1,Strlink *S2)//��T����S1��S2���ӵ��´�
{
     Strlink *str,*p=S1->next,*q,*r;
	//�´�str
	str=(Strlink *)malloc(sizeof(Strlink));
	r=str;
	//��S��ȫ���ڵ㸴�Ƶ�str
	while(p!=NULL)
	{
		q=(Strlink *)malloc(sizeof(Strlink));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
		p=S2->next;
    //��T��ȫ���ڵ㸴�Ƶ�Str
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


Strlink *Substring(Strlink *S,int pos,int len)//��S���ڣ���Sub����S �ĵ�POS���ַ���len���ȵ��Ӵ�
{	
	int k;
    Strlink *str,*p=S->next,*q,*r;
    str=(Strlink *)malloc(sizeof(Strlink));
    str->next=NULL;
    r=str; //rָ���´�str��β�ڵ�
    if (pos<=0 || pos>Strlength(S) || len<0 || pos+len-1>Strlength(S))
        return str; //�����Ƿ�ʱ�Ĵ���
    //�ƶ�����s�ĵ�i���ڵ�
    for (k=0; k<pos-1; k++)
        p=p->next;
    //��s�ĵ�i���ڵ㿪ʼ��j���ڵ㸴�Ƶ�str
    for (k=1; k<=len; k++)
    {
        q=(Strlink *)malloc(sizeof(Strlink));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //��β�ڵ��next��ΪNULL
    r->next=NULL;
    return str;
}


Strlink* Strinsert(Strlink *S,int pos,Strlink *T)//�ڴ�S�ĵ�POS���ַ�ǰ���봮T
{
	Strlink *str,*p=S->next,*p1=T->next,*q,*r;
	str=(Strlink *)malloc(sizeof(Strlink));
    str->next=NULL;
    r=str; //rָ���´�str��β�ڵ�

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

Strlink *Strdelete(Strlink *S,int pos,int len)//�ڴ�S��ɾ����POS���ַ��𳤶�Ϊlen���Ӵ�
{
	int k;
	Strlink *str,*p=S->next,*q,*r;
	str=(Strlink *)malloc(sizeof(Strlink));
    str->next=NULL;
    r=str; //rָ���´�str��β�ڵ�

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

	t= Concat(s1, s2);
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
   
	s2=Substring(t,i,j);
	if (k) 
	{
		cout<<"�Ӵ�s2Ϊ: \n";
		Inputstring(s2);
	}

	cout<<"�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: \n";
 
	i = 4;
	j = 2;
	cout<<i<<" "<<j<<endl;
	t=Strdelete(t, i, j);
	cout<<"ɾ����Ĵ�tΪ: \n";
	Inputstring(t);

	
	i = Strlength(s2) / 2;
	cout<<"�ڴ�s2�ĵ�"<<i<<"���ַ�֮ǰ���봮t��,��s2Ϊ:\n";
	s2=Strinsert(s2, i, t);
	Inputstring(s2);


	s1=Concat(s1, t);
	cout<<"��s1Ϊ��\n";
	Inputstring(s1);


	system("pause");
	return 0;
}