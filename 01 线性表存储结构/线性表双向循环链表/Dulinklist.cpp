#include<iostream>
#include<cstdlib>

using namespace std;

#define ok 1
#define error 0
#define true 1
#define false 0
 
/* Status 是函数的类型,其值是函数结果状态代码,如 OK 等 */
typedef int status;
/* ElemType 类型根据实际情况而定,这里假设为 char */
typedef char Elemtype;

/* 线性表的双向链表存储结构 */
typedef struct Dulnode
{
	Elemtype data;
	struct Dulnode *prior;
	struct Dulnode *next;
} Dulnode,*Dulinklist;


//初始化链表
Dulinklist Initlist()
{
	Dulinklist p,pnext,plast;   //p是头结点
	p=(Dulinklist)malloc(sizeof(Dulnode));
	p->prior=NULL;
	p->next=NULL;
	int i,n;

	cout<<"please input the length of the double linked list:";
    cin>>n;

	while(n!=0)
	{
		plast=p;
		for(i=0;i<n;i++)
		{
			pnext=(Dulinklist)malloc(sizeof(Dulnode));
			cout<<"向"<<i+1<<"个结点输入数据:";
			cin>>pnext->data;
			plast->next=pnext;
			pnext->prior=plast;
			plast=plast->next;
		}
		pnext->next=NULL;
		break;
	}
	return p;
}
//线性表的长度
int Listlength(Dulinklist pHead)
{
	int length = 0;
	Dulinklist pt = pHead->next;
 
	while (pt!= NULL)
	{
		length++;
		pt = pt->next;
	}
	return length;
}


//双向链表的插入,第i个位置插入元素value
status Listinsert(Dulinklist *L,int i,Elemtype value)
{
	int j;
	Dulinklist p,s;//p指向要插入位置的前一个结点，s为新结点
 
	if(i<1)//插入位置不合理
		return error;
 
	p=*L;
	j=1;
 
	while(j<i)/*寻找第i个结点的前一个结点*/
	{
		p=p->next;
		j++;
		if(p==*L)//未找到
			return error;
	}
 
	s=(Dulinklist) malloc(sizeof(Dulnode));
	s->data=value;
	s->prior=p;
	s->next=p->next;
	p->next->prior=s;
	p->next=s;
 
	return ok;
}

//双向链表的删除
status Listdelete(Dulinklist *L,int i,Elemtype *e)
{
	Dulinklist p;//p指向第i个结点
	int j=1;
 
	p=(*L)->next;
 
	if(i<1)//删除位置不合理
		return error;
 
	while(p!=*L&&j<i)
	{
		p=p->next;
		j++;
	}
 
	if(p==*L)//第i个数据元素不存在
		return error;
	
	*e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
 
	return ok;
 }


//打印链表中的全部内容
void Listshow(Dulinklist L)
{
	Dulinklist p;
	p=L->next;
	Elemtype a;

	cout<<"从前向后的打印结果为："<<endl;
	while(p!=NULL)
	{
		a=p->data;
		cout<<"结点的值为："<<a<<endl;
		p=p->next;
	}
}

status ListEmpty(Dulinklist L)
{ 
	if(L->next==L && L->prior==L)
		return true;
    else
        return false;
}
 
/*初始条件：双向循环链表L已存在。*/
/*操作结果：将L重置为空表。*/
status ClearList(Dulinklist *L)
{
	Dulinklist p;//p指向第一个结点
 
	p=(*L)->next;
	while(p!=*L)
	{
		p=p->next;
		free(p->prior);
	}
	(*L)->next=(*L)->prior=*L;//头结点的两个指针域指向其自己
	
	return ok;
}
 

/*初始条件：双向循环链表L已存在，1≤i≤ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/
status GetElem(Dulinklist L,int i,Elemtype *e)
{
	Dulinklist p;
	int j;
 
	if(i<1)//取值位置不合理
		return error;
 
	p=L->next;//p指向第一个结点
	j=1;
	while(p!=L&&j<i)
	{
		p=p->next;
		j++;
	}
 
	if(p==L)//第i个数据元素不存在
		return error;
	*e=p->data;
 
	return ok;
}

int main() 
{
	Dulinklist L=Initlist();
	Listshow(L);
	Elemtype e=0;

	int i = 0;
	printf("初始化 L 后:L.length=%d\n", Listlength(L));
	i = Listinsert(&L,1,'F');
	i = Listinsert(&L,1,'E');
	i = Listinsert(&L,1, 'D');
	i = Listinsert(&L,1, 'B');
	i = Listinsert(&L,1,'A');
	printf("在 L 的表头依次插入 FEDBA 后:\nL.data=\n");
	Listshow(L);

	i = Listinsert(&L, 3, 'C');
	printf("\n 在 L 的“B”与“D”之间插入“C”后:\nL.data=\n");
	Listshow(L);

	i = Listdelete(&L,4,&e);
	printf("\n 在 L 的删除“A”后:\nL.data=\n");
	Listshow(L);
	cout<<"删除的值为:"<<e<<endl;

	system("pause");
	return 0;
}