//二叉树
#include <iostream>
#include<queue>
#include<vector>

using namespace std;
typedef char TelemType;

//二叉树的二叉链表结点结构定义
typedef struct BinaryTreeNode
{
	TelemType data;
	struct BinaryTreeNode *Left;
	struct BinaryTreeNode *Right;
}Node;


//operation
Node* createBinaryTree();    //创建二叉树
void preOrderTraverse(Node* root);   //先序遍历
void inOrderTraverse(Node* root);   //中序遍历
void lastOrderTraverse(Node* root);   //后序遍历
void PrintFromTopToBottom(Node* root);  //层序遍历
int Nodenum(Node* root);     //二叉树总结点
int DepthOfTree(Node* root);   //二叉树的深度
int Leafnum(Node* root);  //二叉树叶子节点数

//创建二叉树，顺序依次为中间节点->左子树->右子树
Node* createBinaryTree()
{
	Node *p;
	TelemType ch;
	cin >> ch;
	if (ch == '#')     //如果到了叶子节点，接下来的左、右子树分别赋值为#
	{
		p = NULL;
	}
	else
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ch;
		p->Left = createBinaryTree();  //递归创建左子树
		p->Right = createBinaryTree();  //递归创建右子树
	}
	return p;
}
//显示出在哪层
void visit(char ch, int i)
{
	cout << ch << "位于第" << i << "层\n";
}

//先序遍历
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

//中序遍历
void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);
		cout << root->data << ' ';
		inOrderTraverse(root->Right);
	}
}

//后序遍历
void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		cout << root->data << ' ';
	}
}

//层序遍历
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

//二叉树节点总数目
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

//二叉树的深度
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

//二叉树叶子节点数
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
	printf("二叉树建立成功");
	cout << endl;

	cout << "二叉树总节点数为：" << Nodenum(root) << endl;

	cout << "二叉树深度为：" << DepthOfTree(root) << endl;

	cout << "二叉树叶子节点数为：" << Leafnum(root) << endl;

	int i = 1;
	cout << "前序遍历结果:" << endl;
	preOrderTraverse(root, i);
	cout << endl;

	cout << "中序遍历结果:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "后序遍历结果:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	cout << "层序遍历结果:" << endl;
	PrintFromTopToBottom(root);
	cout << endl;

	system("pause");
}