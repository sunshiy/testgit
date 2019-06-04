//������
#include <iostream>
#include<queue>
#include<vector>

using namespace std;
typedef char TelemType;

//�������Ķ���������ṹ����
typedef struct BinaryTreeNode
{
	TelemType data;
	struct BinaryTreeNode *Left;
	struct BinaryTreeNode *Right;
}Node;


//operation
Node* createBinaryTree();    //����������
void preOrderTraverse(Node* root);   //�������
void inOrderTraverse(Node* root);   //�������
void lastOrderTraverse(Node* root);   //�������
void PrintFromTopToBottom(Node* root);  //�������
int Nodenum(Node* root);     //�������ܽ��
int DepthOfTree(Node* root);   //�����������
int Leafnum(Node* root);  //������Ҷ�ӽڵ���

//������������˳������Ϊ�м�ڵ�->������->������
Node* createBinaryTree()
{
	Node *p;
	TelemType ch;
	cin >> ch;
	if (ch == '#')     //�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ#
	{
		p = NULL;
	}
	else
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ch;
		p->Left = createBinaryTree();  //�ݹ鴴��������
		p->Right = createBinaryTree();  //�ݹ鴴��������
	}
	return p;
}
//��ʾ�����Ĳ�
void visit(char ch, int i)
{
	cout << ch << "λ�ڵ�" << i << "��\n";
}

//�������
void preOrderTraverse(Node* root, int i)
{
	if (root)
	{
		cout << root->data << ' ';
		visit(root->data, i);
		preOrderTraverse(root->Left, i + 1);
		preOrderTraverse(root->Right, i + 1);
	}
}

//�������
void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);
		cout << root->data << ' ';
		inOrderTraverse(root->Right);
	}
}

//�������
void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		cout << root->data << ' ';
	}
}

//�������
void PrintFromTopToBottom(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		cout << q.front()->data << ' ';
		if (q.front()->Left != NULL)
			q.push(q.front()->Left);
		if (q.front()->Right != NULL)
			q.push(q.front()->Right);
		q.pop();
	}
}

//�������ڵ�����Ŀ
int Nodenum(Node* root)
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
int DepthOfTree(Node* root)
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
int Leafnum(Node* root)
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
	Node *root = NULL;
	root = createBinaryTree();
	printf("�����������ɹ�");
	cout << endl;

	cout << "�������ܽڵ���Ϊ��" << Nodenum(root) << endl;

	cout << "���������Ϊ��" << DepthOfTree(root) << endl;

	cout << "������Ҷ�ӽڵ���Ϊ��" << Leafnum(root) << endl;

	int i = 1;
	cout << "ǰ��������:" << endl;
	preOrderTraverse(root, i);
	cout << endl;

	cout << "����������:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "����������:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	cout << "����������:" << endl;
	PrintFromTopToBottom(root);
	cout << endl;

	system("pause");
}