#include<iostream>
#include<algorithm>

using namespace std;

//������a[]���Ľ�ð������
void Bubblesort(int a[], int len)
{
	int flag = 1;  //flag��Ϊ���
	for (int i = 0; i<len && flag; i++)  //��flagΪfalse���˳�ѭ��
	{
		flag = 0;   //��ʼֵΪfalse
		for (int j = len - 2; j >= i; j--)    //j�ǴӺ���ǰѭ��
		{
			if (a[j]>a[j + 1])   //ǰ�ߴ��ں���
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
	}
}

//������a[]��ѡ������
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

//������a[]��ֱ�Ӳ�������
void Insertsort(int a[], int len)
{
	int i, j;
	int temp = a[0];

	for (i = 0; i < len; i++)
	{
		if (a[i]<a[i - 1])    //��Ҫ��L->r[i]���������ӱ���
		{
			temp = a[i];
			for (j = i - 1; a[j]>temp; j--)
				a[j + 1] = a[j];
			a[j + 1] = temp;
		}
	}
}

//��˳���L��ϣ������
void Shellsort(int a[], int len)
{
	int i, j;
	int increment = len;
	do
	{
		increment = increment / 3 + 1;    //��������
		for (i = increment; i <len; i++)
		{
			if (a[i] < a[i - increment])  //��L->r[i]�������������ӱ���
			{
				int temp = a[i];    //�ݴ�L->r[0]
				for (j = i - increment; j >= 0 && temp< a[j]; j = j - increment)
					a[j + increment] = a[j];   //��¼���ƣ����Ҳ���λ��
				a[j + increment] = temp;   //����
			}
		}
	} while (increment > 1);
}


//////////////////////////////////////////////
//�󶥶����
void HeapAdjust(int a[], int s, int m)
{
	int temp, j;
	temp = a[s];
	for (j = 2 * s; j <= m; j *= 2)    //���Źؼ��ֽϴ�ĺ��ӽ������ɸѡ
	{
		if (j < m && a[j] < a[j + 1])
			++j;    //jΪ�ؼ����нϴ�ļ�¼���±�
		if (temp >= a[j])
			break;     //rcӦ�ò���λ��s��
		a[s] = a[j];
		s = j;
	}
	a[s] = temp;    //����
}

//��˳���L��������
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
	cout << " Bubblesort����󣬽��Ϊ��" << endl;
	for (int i = 0; i <10; i++)
		cout << b1[i] << ' ';
	cout << endl;

	int b2[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Selectsort(b2, 10);
	cout << " Selectsort����󣬽��Ϊ��" << endl;
	for (int i = 0; i < 10; i++)
		cout << b2[i] << ' ';
	cout << endl;

	int b3[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Insertsort(b3, 10);
	cout << " Insertsort����󣬽��Ϊ��" << endl;
	for (int i = 0; i < 10; i++)
		cout << b3[i] << ' ';
	cout << endl;

	int b4[10] = { 5, 3, 1, 4, 7, 8, 9, 10, 33, 22 };
	Insertsort(b4, 10);
	cout << " Shellsort����󣬽��Ϊ��" << endl;
	for (int i = 0; i < 10; i++)
		cout << b4[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}