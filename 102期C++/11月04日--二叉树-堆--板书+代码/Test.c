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
			//HeapPop(&hp);
			//HeapPush(&hp, a[i]);
			hp.a[0] = a[i];
			AdjustDown(hp.a, hp.size, 0);
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

// 升序  空间复杂度是多少? 要求优化到O(1) -> 不能用Heap
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

void HeapSort(int* a, int n)
{
	// 直接把a构建成堆，直接控制a数组
}

int main()
{
	//TestTopk();
	int a[] = { 70, 56, 30, 25, 15, 10, 75 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	HeapSort(a, sizeof(a) / sizeof(a[0]));

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}