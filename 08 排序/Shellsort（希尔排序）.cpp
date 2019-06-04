//ϣ������δ�����ڱ�
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

/* //��˳���L��ϣ������,L->r[0]Ϊ�ڱ�
void Shellsort(Sqlist *L)
{
int i, j;
int increment = L->length;
do
{
increment = increment / 3 + 1;    //��������
for (i = increment + 1; i <= L->length; i++)
{
if (L->r[i] < L->r[i - increment])  //��L->r[i]�������������ӱ���
{
L->r[0] = L->r[i];    //�ݴ�L->r[0]
for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
L->r[j + increment] = L->r[j];   //��¼���ƣ����Ҳ���λ��
L->r[j + increment] = L->r[0];   //����
}
}
} while (increment > 1);
}
*/

//��˳���L��ϣ������
void Shellsort(Sqlist *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;    //��������
		for (i = increment; i <L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])  //��L->r[i]�������������ӱ���
			{
				int temp = L->r[i];    //�ݴ�L->r[0]
				for (j = i - increment; j >= 0 && temp< L->r[j]; j = j - increment)
					L->r[j + increment] = L->r[j];   //��¼���ƣ����Ҳ���λ��
				L->r[j + increment] = temp;   //����
			}
		}
	} while (increment > 1);
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

	int j;
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


	Shellsort(&L);
	cout << "Shellsort����󣬽��Ϊ��" << endl;
	Showsqlist(&L);


	system("pause");
	return 0;
}