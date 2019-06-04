/////使用一维数组来实现线性表的顺序存储结构
////如果需要改变线性表，则必须传入指针变量
///如果需要改变传入数据的值，也必须传入指针变量

#include<iostream>

using namespace std;

//线性表顺序存储的结构代码
#define MAXSIZE 20    //存储空间初始分配量
#define ok 1
#define error 0

typedef int Elemtype;
typedef int status;

//定义
typedef struct
{
	Elemtype data[MAXSIZE];   //数组存储数据元素
	int length;    //线性表的当前长度
}Sqlist;
   
//操作
status Initlist(Sqlist *L);
status Listempty(Sqlist L);
status Clearlist(Sqlist *L);
int Listlength(Sqlist L);
status Getelem(Sqlist L,int i,Elemtype *e);   //返回第i个元素的值
status Listinsert(Sqlist *L,int i,Elemtype e);   //在第i 个位置插入元素
status Listdelete(Sqlist *L,int i,Elemtype *e);
int Locateelem(Sqlist L,Elemtype e);
status Listtraverse(Sqlist L);
void unionl(Sqlist *La,Sqlist Lb);  //将所有的在线性表Lb但是不在La中的数据元素插入到La中


//初始化线性表
status Initlist(Sqlist *L) 
{ 
    L->length=0;
    return ok;
}

//判断是否为空表
status Listempty(Sqlist L)
{ 
if(L.length==0)
   return ok;
else
   return error;
}


//初始条件：顺序线性表L已存在。操作结果：将L重置为空表
status Clearlist(Sqlist *L)
{ 
    L->length=0;
    return ok;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int Listlength(Sqlist L)
{
return L.length;
}

//获得元素
status Getelem(Sqlist L,int i,Elemtype *e)
{
	
	if(L.length==0||i<1||i>L.length)
		return error;
	*e=L.data[i-1];
	return ok;
}


//插入元素
status Listinsert(Sqlist *L,int i,Elemtype e)
{
	int k;
	if(L->length==MAXSIZE)
		return error;
	if(i<1||i>L->length+1)
		return error;
	if(i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--)
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;
	L->length++;
	return ok;
}

//删除算法
status Listdelete(Sqlist *L,int i,Elemtype *e)
{
	int k;
	if(L->length==0)
		return error;
	if(i<1||i>L->length)
		return error;
	*e=L->data[i-1];
	if(i<L->length)
	{
		for(k=i;k<L->length;k++)
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return ok;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int Locateelem(Sqlist L,Elemtype e)
{
    int i;
    if (L.length==0)
           return 0;
    for(i=0;i<L.length;i++)
    {
         if (L.data[i]==e)
              break;
    }
    if(i>=L.length)
          return 0;

    return i+1;
}

status visit(Elemtype c)
{
    cout<<c<<endl;
    return ok;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
status Listtraverse(Sqlist L)
{
    int i;
    for(i=0;i<L.length;i++)
         visit(L.data[i]);
    printf("\n");
    return ok;
}


//集合
void unionl(Sqlist *La,Sqlist Lb)
{
  int La_len,Lb_len,i;
  Elemtype e;
  La_len=Listlength(*La);
  Lb_len=Listlength(Lb);

    for (i=1;i<=Lb_len;i++)
   {
    Getelem(Lb,i,&e);
    if (!Locateelem(*La,e)) 
    Listinsert(La,++La_len,e);
   }
}


int main()
{
	Sqlist L;
    Sqlist Lb;
    
    Elemtype e;
    status i;

    int j,k;
    i=Initlist(&L);
    printf("初始化L后：L.length=%d\n",L.length);

    for(j=1;j<=5;j++)
        i=Listinsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    Listtraverse(L); 


    printf("L.length=%d \n",L.length);
    i=Listempty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);


    i=Clearlist(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=Listempty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);


    for(j=1;j<=10;j++)
        Listinsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    Listtraverse(L); 


    printf("L.length=%d \n",L.length);


    Listinsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    Listtraverse(L); 
    printf("L.length=%d \n",L.length);


    Getelem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=Locateelem(L,j);
            if(k)
                   printf("第%d个元素的值为%d\n",k,j);
            else
                  printf("没有值为%d的元素\n",j);
    }
    

    k=Listlength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=Listdelete(&L,j,&e); /* 删除第j个数据 */
            if(i==error)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    Listtraverse(L); 


    j=5;
    Listdelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);


    printf("依次输出L的元素：");
    Listtraverse(L); 


//构造一个有10个数的Lb
    i=Initlist(&Lb);
    for(j=6;j<=15;j++)
      i=Listinsert(&Lb,1,j);

	 printf("依次输出Lb的元素：");
     Listtraverse(Lb); 

	unionl(&L,Lb);
    printf("依次输出合并了Lb的L的元素：");
    Listtraverse(L); 


	system("pause");
	return 0;
}