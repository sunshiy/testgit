#include <iostream>

using namespace std;

typedef char TelemType;

//�������Ķ���������ṹ����
typedef struct BiTNode
{
	TelemType data;
	struct BiTNode *Left, *Right;
}BiTNode, *BiTree;


//operation
void createBinaryTree(BiTree *T);    //����������
void preOrderTraverse(BiTree root);   //�������
void inOrderTraverse(BiTree root);   //�������
void lastOrderTraverse(BiTree root);   //�������
int Nodenum(BiTree root);     //�������ܽ��
int DepthOfTree(BiTree root);   //�����������
int Leafnum(BiTree root);  //������Ҷ�ӽڵ���

//������������˳������Ϊ�м�ڵ�->������->������
void createBinaryTree(BiTree *T)
{
	TelemType ch;
	cin >> ch;
	if (ch == '#')     //�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ0
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		createBinaryTree(&(*T)->Left);  //�ݹ鴴��������
		createBinaryTree(&(*T)->Right);  //�ݹ鴴��������
	}
}

//�������
void preOrderTraverse(BiTree root)
{
	if (root == NULL)
		return;
	cout << root->data << ' ';
	preOrderTraverse(root->Left);
	preOrderTraverse(root->Right);
}

//�������
void inOrderTraverse(BiTree root)
{
	if (root == NULL)
		return;
	inOrderTraverse(root->Left);
	cout << root->data << ' ';
	inOrderTraverse(root->Right);
}

//�������
void lastOrderTraverse(BiTree root)
{
	if (root == NULL)
		return;
	lastOrderTraverse(root->Left);
	lastOrderTraverse(root->Right);
	cout << root->data << ' ';
}

//�������ڵ�����Ŀ
int Nodenum(BiTree root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + Nodenum(root->Left) + Nodenum(root->Right);

	}
}

//�����������
int DepthOfTree(BiTree root)
{
	if (root)
	{
		return DepthOfTree(root->Left)>DepthOfTree(root->Right) ? DepthOfTree(root->Left) + 1 : DepthOfTree(root->Right) + 1;
	}
	if (root == NULL)
	{
		return 0;
	}
}

//������Ҷ�ӽڵ���
int Leafnum(BiTree root)
{
	if (!root)
	{
		return 0;
	}
	else if ((root->Left == NULL) && (root->Right == NULL))
	{
		return 1;
	}
	else
	{
		return  (Leafnum(root->Left) + Leafnum(root->Right));
	}
}


int main()
{
	BiTree root = NULL;
	cout << "������ǰ������������ɶ�������";
	createBinaryTree(&root);     //ʾ����AB#D##C##�������A������B���Һ���C��B���Һ���ΪD
	printf("�����������ɹ�");
	cout << endl;

	cout << "�������ܽڵ���Ϊ��" << Nodenum(root) << endl;

	cout << "���������Ϊ��" << DepthOfTree(root) << endl;

	cout << "������Ҷ�ӽڵ���Ϊ��" << Leafnum(root) << endl;

	cout << "ǰ��������:" << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "����������:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "����������:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	system("pause");
}
