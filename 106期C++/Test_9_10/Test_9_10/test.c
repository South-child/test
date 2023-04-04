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


// ����������
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
// �������ڵ����
int BinaryTreeSize(BTNode* root) {
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// �������
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int lh = BinaryTreeHeight(root->left);
	int rh = BinaryTreeHeight(root->right);

	return lh > rh ? lh + 1 : rh + 1;
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//�������ǣ���ȥ��������
	BTNode* left = NULL;
	left = BinaryTreeFind(root->left, x);
	if (left)
	{
		return left;
	}
	//��������û�У���ȥ��������7
	BTNode* right = NULL;
	right = BinaryTreeFind(root->right, x);
	if (right)
	{
		return right;
	}
	return NULL;
}

//ǰ�����
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
// �������
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

// �������
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
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//ʹ�ö��е��Ƚ��ȳ������ԣ��������
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		//����һ���ڵ㣬�ý������Һ��������
		//��һ�������
		if (front->left)
			QueuePush(&q, front->left);
		if(front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}
// �ж϶������Ƿ�����ȫ������
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

	//�������Ժ󣬺���ȫ�ǿգ�������ȫ������
	//�������Ժ󣬺�����ڷǿգ��Ͳ�����ȫ������
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

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

	//ǰ�����
	BinaryTreePreOrder(root);
	printf("\n");
	//�������
	BinaryTreeInOrder(root);
	printf("\n");
	//�������
	BinaryTreePostOrder(root);
	printf("\n");
	//�������
	BinaryTreeLevelOrder(root);
	printf("\n");

	//�ж��Ƿ�Ϊ��ȫ������
	int flag = BinaryTreeComplete(root);
	printf("%d\n", flag);

	//����������
	char arr[] = "ABD##E#H##CF##G##";
	int i = 0;
	root = BinaryTreeCreate(arr, strlen(arr), &i);

	BinaryTreeInOrder(root);
	printf("\n");

	BinaryTreeDestory(root);
	return 0;
}




//������
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void AdjustDown(int* a, int n, int parent)
//{
//	assert(a);
//	//���� -- ���
//	int maxChild = parent * 2 + 1;
//	while (maxChild < n)
//	{
//		//ѡ����ĺ���
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
//	//����
//	//���µ�������
//	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, size, i);
//	}
//
//	//���öѺ󣬿�ʼ����
//	//ѡ�Ѷ������һ��Ҷ�ӽڵ㽻����Ȼ�����µ���
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