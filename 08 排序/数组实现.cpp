#include<iostream>
#include<algorithm>

using namespace std;

//对数组a[]做改进冒泡排序
void Bubblesort(int a[], int len)
{
	int flag = 1;  //flag作为标记
	for (int i = 0; i<len && flag; i++)  //若flag为false，退出循环
	{
		flag = 0;   //初始值为false
		for (int j = len - 2; j >= i; j--)    //j是从后向前循环
		{
			if (a[j]>a[j + 1])   //前者大于后者
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
	}
}

//对数组a[]做选择排序
void Selectsort(int a[], int len)
{
	int min;
	for (int i = 0; i < len; i++)
	{
		min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[min]>a[j])
				min = j;
		}
		if (i != min)
			swap(a[i], a[min]);
	}
}

//对数组a[]做直接插入排序
void Insertsort(int a[], int len)
{
	int i, j;
	int temp = a[0];

	for (i = 0; i < len; i++)
	{
		if (a[i]<a[i - 1])    //需要将L->r[i]插入有序子表中
		{
			temp = a[i];
			for (j = i - 1; a[j]>temp; j--)
				a[j + 1] = a[j];
			a[j + 1] = temp;
		}
	}
}

//对顺序表L做希尔排序
void Shellsort(int a[], int len)
{
	int i, j;
	int increment = len;
	do
	{
		increment = increment / 3 + 1;    //增量序列
		for (i = increment; i <len; i++)
		{
			if (a[i] < a[i - increment])  //将L->r[i]插入有序增量子表中
			{
				int temp = a[i];    //暂存L->r[0]
				for (j = i - increment; j >= 0 && temp< a[j]; j = j - increment)
					a[j + increment] = a[j];   //记录后移，查找插入位置
				a[j + increment] = temp;   //插入
			}
		}
	} while (increment > 1);
}


//////////////////////////////////////////////
//大顶堆设计
void HeapAdjust(int a[], int s, int m)
{
	int temp, j;
	temp = a[s];
	for (j = 2 * s; j <= m; j *= 2)    //沿着关键字较大的孩子结点向下筛选
	{
		if (j < m && a[j] < a[j + 1])
			++j;    //j为关键字中较大的记录的下标
		if (temp >= a[j])
			break;     //rc应该插在位置s上
		a[s] = a[j];
		s = j;
	}
	a[s] = temp;    //输入
}

//对顺序表L做堆排序
void Heapsort(int a[],int len)
{
	int i;
	for (i = L->length / 2; i >= 0; i--)
		HeapAdjust(L, i, len);

	for (i =len - 1; i > 0; i--)
	{
		Swap(L, 0, i);
		HeapAdjust(L, 0, i - 1);
	}
}
int main()
{
	int b1[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Bubblesort(b1, 10);
	cout << " Bubblesort排序后，结果为：" << endl;
	for (int i = 0; i <10; i++)
		cout << b1[i] << ' ';
	cout << endl;

	int b2[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Selectsort(b2, 10);
	cout << " Selectsort排序后，结果为：" << endl;
	for (int i = 0; i < 10; i++)
		cout << b2[i] << ' ';
	cout << endl;

	int b3[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Insertsort(b3, 10);
	cout << " Insertsort排序后，结果为：" << endl;
	for (int i = 0; i < 10; i++)
		cout << b3[i] << ' ';
	cout << endl;

	int b4[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Insertsort(b4, 10);
	cout << " Shellsort排序后，结果为：" << endl;
	for (int i = 0; i < 10; i++)
		cout << b4[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}