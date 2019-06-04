//冒泡排序，两两比较相邻记录的关键字，如果反序则交换
#include<iostream>
//未设置哨兵，程序部分修改
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
	int r[maxsize + 1];   //用于存储要排序的数组
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



//对顺序表L做交换排序（初级版）
void Bubblesort0(Sqlist *L)
{
	int i, j;
	for (i = 0; i<L->length; i++)
	{
		for (j = i + 1; j<L->length; j++)
		{
			if (L->r[i]>L->r[j])
				Swap(L, i, j);
		}
	}
}


//对顺序表L做冒泡排序
void Bubblesort(Sqlist *L)
{
	int i, j;
	for (i = 0; i<L->length; i++)
	{
		for (j = L->length - 2; j >= i; j--)    //j是从后向前循环
		{
			if (L->r[j]>L->r[j + 1])   //前者大于后者
				Swap(L, j, j + 1);
		}
	}
}

//对顺序表L做改进冒泡排序
void Bubblesort2(Sqlist *L)
{
	int i, j;
	status flag = true;  //flag作为标记
	for (i = 0; i<L->length && flag; i++)  //若flag为false，退出循环
	{
		flag = false;   //初始值为false
		for (j = L->length - 2; j >= i; j--)    //j是从后向前循环
		{
			if (L->r[j]>L->r[j + 1])   //前者大于后者
			{
				Swap(L, j, j + 1);
				flag = true;
			}
		}
	}
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


	Bubblesort0(&L);
	cout << "Bubblesort0排序后，结果为：" << endl;
	Showsqlist(&L);

	Bubblesort(&L);
	cout << "Bubblesort排序后，结果为：" << endl;
	Showsqlist(&L);

	Bubblesort2(&L);
	cout << " Bubblesort2排序后，结果为：" << endl;
	Showsqlist(&L);

	system("pause");
	return 0;
}