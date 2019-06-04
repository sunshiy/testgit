//��������
#include<iostream>
using namespace std;

typedef int status;
#define true 1
#define false 0
#define error 0
#define ok 1
#define maxsize 10  //����Ҫ��������������ֵ���ɸ�����Ҫ�޸�

//�ṹ����
typedef struct Sqlist
{
	int r[maxsize + 1];   //���ڴ洢Ҫ��������飬r[0]�����ڱ�������ʱ����
	int length;    //���ڼ�¼˳���ĳ���
};

//����
status Initlist(Sqlist *L);
status Listinsert(Sqlist *L, int i, int e);
//����Ԫ��
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

//����L������r���±�i��j��ֵ
void Swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

//����
status Initlist(Sqlist *L)
{
	L->length = 0;
	return ok;
}

//�����㷨
//����˳���L���ӱ�ļ�¼��ʹ���м�ֵ��¼��λ��������������λ��
//��ʱ��֮ǰ�Ľ������������֮��Ľ����С����
int Partition(Sqlist *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];   //���ӱ�ĵ�һ����¼���м�ֵ
	while (low < high)  //�ӱ���������м�ɨ��
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
//��˳����е�������L->r[low..high]����������
void Qsort(Sqlist *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGRH_INSERT_SORT)
	{
		while (low < high)
		{
			pivot = Partition(L, low, high);   //��L->r[low..high]һ��Ϊ��������м�ֵpivot
			Qsort(L, low, pivot - 1);   //�Ե��ӱ�ݹ�����
			low = pivot + 1;   //β�ݹ�
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
//�����Ż�
int Partition1(Sqlist *L, int low, int high)
{
	int pivotkey;
	//////////����ȡ���㷨
	int m = low + (high - low) / 2;
	if (L->r[low]>L->r[high])
		Swap(L, low, high);
	if (L->r[m] > L->r[high])
		Swap(L, high, m);
	if (L->r[m] > L->r[low])
		Swap(L, m, low);
	//////////////////
	pivotkey = L->r[low];   //���ӱ�ĵ�һ����¼���м�ֵ
	int temp = pivotkey;   //���ؼ��ֱ���

	while (low < high)  //�ӱ���������м�ɨ��
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


//��˳����е�������L->r[low..high]����������
void Qsort1(Sqlist *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition1(L, low, high);   //��L->r[low..high]һ��Ϊ��������м�ֵpivot
		Qsort1(L, low, pivot - 1);   //�Ե��ӱ�ݹ�����
		Qsort1(L, pivot + 1, high);   //�Ը��ӱ�ݹ�����
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
		cout << "��" << i + 1 << "������Ϊ��" << L->r[i] << endl;
}


int main()
{
	Sqlist L;

	int e = 0;
	status i = 0;
	i = Initlist(&L);
	cout << "��ʼ��L��L.length=" << L.length << "\n";

	i = Listinsert(&L, 1, 9);
	i = Listinsert(&L, 1, 1);
	i = Listinsert(&L, 1, 5);
	i = Listinsert(&L, 1, 8);
	i = Listinsert(&L, 1, 3);
	i = Listinsert(&L, 1, 7);
	i = Listinsert(&L, 1, 4);
	i = Listinsert(&L, 1, 6);
	i = Listinsert(&L, 1, 2);
	cout << "��L�ı�ͷ���β���9,1,5,8,3,7,4,6,2��L.data=" << endl;
	Showsqlist(&L);


	Quicksort1(&L);
	cout << "Quicksort����󣬽��Ϊ��" << endl;
	Showsqlist(&L);

	system("pause");
	return 0;
}