//希尔排序，未设置哨兵
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

/* //对顺序表L做希尔排序,L->r[0]为哨兵
void Shellsort(Sqlist *L)
{
int i, j;
int increment = L->length;
do
{
increment = increment / 3 + 1;    //增量序列
for (i = increment + 1; i <= L->length; i++)
{
if (L->r[i] < L->r[i - increment])  //将L->r[i]插入有序增量子表中
{
L->r[0] = L->r[i];    //暂存L->r[0]
for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
L->r[j + increment] = L->r[j];   //记录后移，查找插入位置
L->r[j + increment] = L->r[0];   //插入
}
}
} while (increment > 1);
}
*/

//对顺序表L做希尔排序
void Shellsort(Sqlist *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;    //增量序列
		for (i = increment; i <L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])  //将L->r[i]插入有序增量子表中
			{
				int temp = L->r[i];    //暂存L->r[0]
				for (j = i - increment; j >= 0 && temp< L->r[j]; j = j - increment)
					L->r[j + increment] = L->r[j];   //记录后移，查找插入位置
				L->r[j + increment] = temp;   //插入
			}
		}
	} while (increment > 1);
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

	int j;
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


	Shellsort(&L);
	cout << "Shellsort排序后，结果为：" << endl;
	Showsqlist(&L);


	system("pause");
	return 0;
}