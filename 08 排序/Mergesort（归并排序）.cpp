//������
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

/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++) /* ��SR�м�¼��С����鲢��TR */
	{
		if (SR[i]<SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];  /* ��ʣ���SR[i..m]���Ƶ�TR */
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];  /* ��ʣ���SR[j..n]���Ƶ�TR */
	}
}


/* ��SR[s..t]�鲢����ΪTR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[maxsize + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;   /* ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] */
		MSort(SR, TR2, s, m); /* �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m] */
		MSort(SR, TR2, m + 1, t); /* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ����TR2[m+1..t] */
		Merge(TR2, TR1, s, m, t); /* ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] */
	}
}

//��˳���L��������
void Mergesort(Sqlist *L)
{
	MSort(L->r, L->r, 0, L->length - 1);
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


	Mergesort(&L);
	cout << "Mergesort����󣬽��Ϊ��" << endl;
	Showsqlist(&L);

	system("pause");
	return 0;
}