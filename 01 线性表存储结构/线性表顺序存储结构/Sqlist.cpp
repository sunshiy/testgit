/////ʹ��һά������ʵ�����Ա��˳��洢�ṹ
////�����Ҫ�ı����Ա�����봫��ָ�����
///�����Ҫ�ı䴫�����ݵ�ֵ��Ҳ���봫��ָ�����

#include<iostream>

using namespace std;

//���Ա�˳��洢�Ľṹ����
#define MAXSIZE 20    //�洢�ռ��ʼ������
#define ok 1
#define error 0

typedef int Elemtype;
typedef int status;

//����
typedef struct
{
	Elemtype data[MAXSIZE];   //����洢����Ԫ��
	int length;    //���Ա�ĵ�ǰ����
}Sqlist;
   
//����
status Initlist(Sqlist *L);
status Listempty(Sqlist L);
status Clearlist(Sqlist *L);
int Listlength(Sqlist L);
status Getelem(Sqlist L,int i,Elemtype *e);   //���ص�i��Ԫ�ص�ֵ
status Listinsert(Sqlist *L,int i,Elemtype e);   //�ڵ�i ��λ�ò���Ԫ��
status Listdelete(Sqlist *L,int i,Elemtype *e);
int Locateelem(Sqlist L,Elemtype e);
status Listtraverse(Sqlist L);
void unionl(Sqlist *La,Sqlist Lb);  //�����е������Ա�Lb���ǲ���La�е�����Ԫ�ز��뵽La��


//��ʼ�����Ա�
status Initlist(Sqlist *L) 
{ 
    L->length=0;
    return ok;
}

//�ж��Ƿ�Ϊ�ձ�
status Listempty(Sqlist L)
{ 
if(L.length==0)
   return ok;
else
   return error;
}


//��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
status Clearlist(Sqlist *L)
{ 
    L->length=0;
    return ok;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int Listlength(Sqlist L)
{
return L.length;
}

//���Ԫ��
status Getelem(Sqlist L,int i,Elemtype *e)
{
	
	if(L.length==0||i<1||i>L.length)
		return error;
	*e=L.data[i-1];
	return ok;
}


//����Ԫ��
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

//ɾ���㷨
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

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
status Listtraverse(Sqlist L)
{
    int i;
    for(i=0;i<L.length;i++)
         visit(L.data[i]);
    printf("\n");
    return ok;
}


//����
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
    printf("��ʼ��L��L.length=%d\n",L.length);

    for(j=1;j<=5;j++)
        i=Listinsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L.data=");
    Listtraverse(L); 


    printf("L.length=%d \n",L.length);
    i=Listempty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);


    i=Clearlist(&L);
    printf("���L��L.length=%d\n",L.length);
    i=Listempty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);


    for(j=1;j<=10;j++)
        Listinsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    Listtraverse(L); 


    printf("L.length=%d \n",L.length);


    Listinsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    Listtraverse(L); 
    printf("L.length=%d \n",L.length);


    Getelem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=Locateelem(L,j);
            if(k)
                   printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                  printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=Listlength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=Listdelete(&L,j,&e); /* ɾ����j������ */
            if(i==error)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    Listtraverse(L); 


    j=5;
    Listdelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);


    printf("�������L��Ԫ�أ�");
    Listtraverse(L); 


//����һ����10������Lb
    i=Initlist(&Lb);
    for(j=6;j<=15;j++)
      i=Listinsert(&Lb,1,j);

	 printf("�������Lb��Ԫ�أ�");
     Listtraverse(Lb); 

	unionl(&L,Lb);
    printf("��������ϲ���Lb��L��Ԫ�أ�");
    Listtraverse(L); 


	system("pause");
	return 0;
}