#include "Heap.h"

// 在N个数找出最大的前K个  or  在N个数找出最小的前K个
void PrintTopK(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	// 创建一个K个数的小堆
	for (int i = 0; i < k; ++i)
	{
		HeapPush(&hp, a[i]);
	}

	// 剩下的N-K个数跟堆顶的数据比较，比他大，就替换他进堆
	for (int i = k; i < n; ++i)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
			//hp.a[0] = a[i];
			//AdjustDown(hp.a, hp.size, 0);
		}
	}

	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void TestTopk()
{
	int n = 1000000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	// 再去设置10个比100w大的数
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[5355] = 1000000 + 3;
	a[51] = 1000000 + 4;
	a[15] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

void TestHeap()
{
	int a[] = { 70, 56, 30, 25, 15, 10, 75 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

// 升序  空间复杂度是多少? O(N) 要求优化到O(1) -> 不能用Heap
//void HeapSort(int* a, int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	// 建议一个N个小堆
//	for (int i = 0; i < n; ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	// Pop N 次
//	for (int i = 0; i < n; ++i)
//	{
//		a[i] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}

// 升序
void HeapSort(int* a, int n)
{
	// 把a构建成小堆
	// 方法1：
	/*for (int i = 1; i < n; ++i)
	{
	AdjustUp(a, i);
	}*/

	// 方法2：
	// O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// 依次选数，调堆
	// O(N*logN)
	for (int end = n - 1; end > 0; --end)
	{
		Swap(&a[end], &a[0]);

		// 再调堆，选出次小的数
		AdjustDown(a, end, 0);
	}
}

//int main()
//{
//	//TestTopk();
//	int a[] = { 70, 56, 30, 25, 15, 10, 75, 33, 50, 69 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	node->data = x;
	node->left = node->right = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');
	BTNode* nodeG = BuyNode('G');


	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;
	nodeF->right = nodeG;

	return nodeA;
}

// 二叉树前序遍历 
void PreOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

// 二叉树中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%C ", root->data);
	InOrder(root->right);
}

// 二叉树后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%C ", root->data);
}

// 二叉树节点个数
// 遍历计数思想：多次调用存在问题
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	static int count = 0;
//
//	++count;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//
//	return count;
//}

//void BinaryTreeSize(BTNode* root, int* pn)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	++(*pn);
//	BinaryTreeSize(root->left, pn);
//	BinaryTreeSize(root->right, pn);
//}

int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : 
		BinaryTreeSize(root->left) 
		+ BinaryTreeSize(root->right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	/*if (k < 1)
	{
	return 0;
	}*/
	assert(k >= 1);

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	// root不等空，k也不等于1，说明root这颗树的第k节点在子树里面
	// 转换成求左右子树的第k-1等的节点数量
	return BinaryTreeLevelKSize(root->left, k - 1)
		+ BinaryTreeLevelKSize(root->right, k - 1);
}

// 二叉树深度/高度
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//return BinaryTreeDepth(root->left) > BinaryTreeDepth(root->right) ? BinaryTreeDepth(root->left) + 1 : BinaryTreeDepth(root->right) + 1;

	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet)
		return leftRet;

	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet)
		return rightRet;

	return NULL;

	//return BinaryTreeFind(root->right, x);
}

int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");

	/*int n1 = 0;
	BinaryTreeSize(root, &n1);
	printf("TreeSize:%d\n", n1);

	int n2 = 0;
	BinaryTreeSize(root, &n2);
	printf("TreeSize:%d\n", n2);*/

	printf("TreeSize:%d\n", BinaryTreeSize(root));
	printf("TreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("TreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("BinaryTreeDepth:%d\n", BinaryTreeDepth(root));


	return 0;
}