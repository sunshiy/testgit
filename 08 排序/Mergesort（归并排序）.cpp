//堆排序
#include<iostream>
using namespace std;

typedef int status;

#define true 1
#define false 0
#define error 0
#define ok 1
#define maxsize 10  //用于要排序数组个数最大值，可根据需要修改

//结构定义
typedef struct Sqlist
{
	int r[maxsize + 1];   //用于存储要排序的数组，r[0]用作哨兵或者临时变量
	int length;    //用于记录顺序表的长度
};

//操作
status Initlist(Sqlist *L);
status Listinsert(Sqlist *L, int i, int e);

//插入元素
status Listinsert(Sqlist *L, int i, int e)
{
	int k;
	if (L->length == maxsize)
		return error;
	if (i<1 || i>L->length + 1)
		return error;
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->r[k + 1] = L->r[k];
	}
	L->r[i - 1] = e;
	L->length++;
	return ok;
}

//交换L中数组r的下标i和j的值
void Swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

//操作
status Initlist(Sqlist *L)
{
	L->length = 0;
	return ok;
}

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++) /* 将SR中记录由小到大归并入TR */
	{
		if (SR[i]<SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];  /* 将剩余的SR[i..m]复制到TR */
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];  /* 将剩余的SR[j..n]复制到TR */
	}
}


/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[maxsize + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;   /* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
		MSort(SR, TR2, s, m); /* 递归地将SR[s..m]归并为有序的TR2[s..m] */
		MSort(SR, TR2, m + 1, t); /* 递归地将SR[m+1..t]归并为有序TR2[m+1..t] */
		Merge(TR2, TR1, s, m, t); /* 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] */
	}
}

//对顺序表L做堆排序
void Mergesort(Sqlist *L)
{
	MSort(L->r, L->r, 0, L->length - 1);
}


void Showsqlist(Sqlist *L)
{
	int a = L->length;
	for (int i = 0; i<a; i++)
		cout << "第" << i + 1 << "个数字为：" << L->r[i] << endl;
}

int main()
{
	Sqlist L;

	int e = 0;
	status i = 0;
	i = Initlist(&L);
	cout << "初始化L后：L.length=" << L.length << "\n";

	i = Listinsert(&L, 1, 9);
	i = Listinsert(&L, 1, 1);
	i = Listinsert(&L, 1, 5);
	i = Listinsert(&L, 1, 8);
	i = Listinsert(&L, 1, 3);
	i = Listinsert(&L, 1, 7);
	i = Listinsert(&L, 1, 4);
	i = Listinsert(&L, 1, 6);
	i = Listinsert(&L, 1, 2);
	cout << "在L的表头依次插入9,1,5,8,3,7,4,6,2后：L.data=" << endl;
	Showsqlist(&L);


	Mergesort(&L);
	cout << "Mergesort排序后，结果为：" << endl;
	Showsqlist(&L);

	system("pause");
	return 0;
}