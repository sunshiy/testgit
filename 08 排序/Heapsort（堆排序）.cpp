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

//�󶥶����
void HeapAdjust(Sqlist *L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2)    //���Źؼ��ֽϴ�ĺ��ӽ������ɸѡ
	{
		if (j < m && L->r[j] < L->r[j + 1])
			++j;    //jΪ�ؼ����нϴ�ļ�¼���±�
		if (temp >= L->r[j])
			break;     //rcӦ�ò���λ��s��
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;    //����
}

//��˳���L��������
void Heapsort(Sqlist *L)
{
	int i;
	for (i = L->length / 2; i >= 0; i--)
		HeapAdjust(L, i, L->length);

	for (i = L->length - 1; i > 0; i--)
	{
		Swap(L, 0, i);
		HeapAdjust(L, 0, i - 1);
	}
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


	Heapsort(&L);
	cout << "Heapsort����󣬽��Ϊ��" << endl;
	Showsqlist(&L);

	system("pause");
	return 0;
}