#include <iostream>

using namespace std;

typedef char TelemType;

//二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
	TelemType data;
	struct BiTNode *Left, *Right;
}BiTNode, *BiTree;


//operation
void createBinaryTree(BiTree *T);    //创建二叉树
void preOrderTraverse(BiTree root);   //先序遍历
void inOrderTraverse(BiTree root);   //中序遍历
void lastOrderTraverse(BiTree root);   //后序遍历
int Nodenum(BiTree root);     //二叉树总结点
int DepthOfTree(BiTree root);   //二叉树的深度
int Leafnum(BiTree root);  //二叉树叶子节点数

//创建二叉树，顺序依次为中间节点->左子树->右子树
void createBinaryTree(BiTree *T)
{
	TelemType ch;
	cin >> ch;
	if (ch == '#')     //如果到了叶子节点，接下来的左、右子树分别赋值为0
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		createBinaryTree(&(*T)->Left);  //递归创建左子树
		createBinaryTree(&(*T)->Right);  //递归创建右子树
	}
}

//先序遍历
void preOrderTraverse(BiTree root)
{
	if (root == NULL)
		return;
	cout << root->data << ' ';
	preOrderTraverse(root->Left);
	preOrderTraverse(root->Right);
}

//中序遍历
void inOrderTraverse(BiTree root)
{
	if (root == NULL)
		return;
	inOrderTraverse(root->Left);
	cout << root->data << ' ';
	inOrderTraverse(root->Right);
}

//后序遍历
void lastOrderTraverse(BiTree root)
{
	if (root == NULL)
		return;
	lastOrderTraverse(root->Left);
	lastOrderTraverse(root->Right);
	cout << root->data << ' ';
}

//二叉树节点总数目
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

//二叉树的深度
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

//二叉树叶子节点数
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
	cout << "请输入前序遍历序列生成二叉树：";
	createBinaryTree(&root);     //示例：AB#D##C##，结果：A的左孩子B，右孩子C，B的右孩子为D
	printf("二叉树建立成功");
	cout << endl;

	cout << "二叉树总节点数为：" << Nodenum(root) << endl;

	cout << "二叉树深度为：" << DepthOfTree(root) << endl;

	cout << "二叉树叶子节点数为：" << Leafnum(root) << endl;

	cout << "前序遍历结果:" << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "中序遍历结果:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "后序遍历结果:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	system("pause");
}
