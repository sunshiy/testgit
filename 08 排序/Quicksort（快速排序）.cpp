//快速排序
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

//快排算法
//交换顺序表L中子表的记录，使得中间值记录到位，并返回其所在位置
//此时它之前的结果不大于它，之后的结果不小于它
int Partition(Sqlist *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];   //用子表的第一个记录做中间值
	while (low < high)  //从表的两段向中间扫描
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		Swap(L, low, high);
		while (low < high && L->r[low] <= pivotkey)
			low++;
		Swap(L, low, high);
	}
	return low;
}

#define MAX_LENGRH_INSERT_SORT 7
//对顺序表中的子序列L->r[low..high]做快速排序
void Qsort(Sqlist *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGRH_INSERT_SORT)
	{
		while (low < high)
		{
			pivot = Partition(L, low, high);   //将L->r[low..high]一分为二，算出中间值pivot
			Qsort(L, low, pivot - 1);   //对低子表递归排序
			low = pivot + 1;   //尾递归
		}
		/*else
		Insertsort(L);*/
	}
}


void Quicksort(Sqlist *L)
{
	Qsort(L, 0, L->length - 1);
}


//////////////////////////////////////////////
//代码优化
int Partition1(Sqlist *L, int low, int high)
{
	int pivotkey;
	//////////三数取中算法
	int m = low + (high - low) / 2;
	if (L->r[low]>L->r[high])
		Swap(L, low, high);
	if (L->r[m] > L->r[high])
		Swap(L, high, m);
	if (L->r[m] > L->r[low])
		Swap(L, m, low);
	//////////////////
	pivotkey = L->r[low];   //用子表的第一个记录做中间值
	int temp = pivotkey;   //将关键字备份

	while (low < high)  //从表的两段向中间扫描
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		L->r[low] = L->r[high];
		while (low < high && L->r[low] <= pivotkey)
			low++;
		L->r[high] = L->r[low];
	}
	L->r[low] = temp;
	return low;
}


//对顺序表中的子序列L->r[low..high]做快速排序
void Qsort1(Sqlist *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition1(L, low, high);   //将L->r[low..high]一分为二，算出中间值pivot
		Qsort1(L, low, pivot - 1);   //对低子表递归排序
		Qsort1(L, pivot + 1, high);   //对高子表递归排序
	}
}

void Quicksort1(Sqlist *L)
{
	Qsort1(L, 0, L->length - 1);
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


	Quicksort1(&L);
	cout << "Quicksort排序后，结果为：" << endl;
	Showsqlist(&L);

	system("pause");
	return 0;
}