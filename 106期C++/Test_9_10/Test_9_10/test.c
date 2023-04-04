#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Queue.h"
#include <string.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;


// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root) {
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 树的深度
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int lh = BinaryTreeHeight(root->left);
	int rh = BinaryTreeHeight(root->right);

	return lh > rh ? lh + 1 : rh + 1;
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//若根不是，就去左子树找
	BTNode* left = NULL;
	left = BinaryTreeFind(root->left, x);
	if (left)
	{
		return left;
	}
	//若左子树没有，就去右子树找7
	BTNode* right = NULL;
	right = BinaryTreeFind(root->right, x);
	if (right)
	{
		return right;
	}
	return NULL;
}

//前序遍历
void BinaryTreePreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	BinaryTreePreOrder(root->left);
	BinaryTreePreOrder(root->right);

}
// 中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}

// 后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);

}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	//使用队列的先进先出的特性，层序遍历
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		//打完一个节点，该结点的左右孩子入队列
		//下一层入队列
		if (front->left)
			QueuePush(&q, front->left);
		if(front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	//遇到空以后，后面全是空，就是完全二叉树
	//遇到空以后，后面存在非空，就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	assert(root);
	root->data = a[*pi];
	(*pi)++;
	root->left = BinaryTreeCreate(a, n, pi);
	root->right = BinaryTreeCreate(a, n, pi);
	return root;
}



BTNode* CreateTree()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	assert(n1);
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	assert(n2);
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	assert(n3);
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	assert(n4);
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	assert(n5);
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	assert(n6);
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	assert(n7);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n2->right = NULL;
	n4->left = n5;
	n4->right = n6;
	n3->left = NULL;
	n3->right = NULL;
	n5->left = NULL;
	n5->right = NULL;
	n6->left = NULL;
	n6->right = NULL;

	n3->right = n7;
	n7->left = NULL;
	n7->right = NULL;

	return n1;
}

int main()
{
	BTNode* root = CreateTree();

	printf("Tree size:%d\n", BinaryTreeSize(root));
	printf("Tree Leaf size:%d\n", BinaryTreeLeafSize(root));
	printf("Tree Leaf  k size:%d\n", BinaryTreeLevelKSize(root,2));
	printf("Tree Find:%p\n", BinaryTreeFind(root, 8));

	//前序遍历
	BinaryTreePreOrder(root);
	printf("\n");
	//中序遍历
	BinaryTreeInOrder(root);
	printf("\n");
	//后序遍历
	BinaryTreePostOrder(root);
	printf("\n");
	//层序遍历
	BinaryTreeLevelOrder(root);
	printf("\n");

	//判断是否为完全二叉树
	int flag = BinaryTreeComplete(root);
	printf("%d\n", flag);

	//构建二叉树
	char arr[] = "ABD##E#H##CF##G##";
	int i = 0;
	root = BinaryTreeCreate(arr, strlen(arr), &i);

	BinaryTreeInOrder(root);
	printf("\n");

	BinaryTreeDestory(root);
	return 0;
}




//堆排序
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void AdjustDown(int* a, int n, int parent)
//{
//	assert(a);
//	//升序 -- 大堆
//	int maxChild = parent * 2 + 1;
//	while (maxChild < n)
//	{
//		//选出大的孩子
//		if (maxChild + 1 < n && a[maxChild + 1] > a[maxChild])
//		{
//			maxChild++;
//		}
//
//		if (a[maxChild] > a[parent])
//		{
//			Swap(&a[maxChild], &a[parent]);
//			parent = maxChild;
//			maxChild = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int size)
//{
//	assert(a);
//
//	//建堆
//	//向下调整建堆
//	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, size, i);
//	}
//
//	//建好堆后，开始排序
//	//选堆顶和最后一个叶子节点交换，然后向下调整
//	int i = 1;
//	while(i < size)
//	{
//		Swap(&a[0], &a[size - i]);
//		AdjustDown(a, size - i, 0);
//		++i;
//	}
//}
//int main()
//{
//	int a[] = { 6,10,3,5,1,7,4,9,2,0 };
//	HeapSort(a,sizeof(a) / sizeof(int));
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}