#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include <time.h>
//int main()
//{
//	int a[] = { 65, 100, 70, 32, 50, 60 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	HeapPrint(&hp);
//
//	HeapPush(&hp, 20);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	while (!HeapEmpty(&hp))
//	{
//		HPDataType tmp =  HeapTop(&hp);
//		printf("%d ", tmp);
//		HeapPop(&hp);
//	}
//	return 0;
//}

//int main()
//{
//	int a[] = { 65, 100, 70, 32, 50, 60 };
//	HeapCreate(a, sizeof(a) / sizeof(int));
//
//	return 0;
//}


//void HeapSort(int* a, int n)
//{
//	int a[] = { 65, 100, 70, 32, 50, 60 };
//	// 升序 -- 大堆
//	// 降序 -- 小堆
//	// 建堆 -- 向下调整建堆 - O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// 选数
//	int i = 1;
//	while (i < n)
//	{
//		Swap(&a[0], &a[n - i]);
//		AdjustDown(a, n - i, 0);
//		++i;
//	}
//}

void PrintTopK(int* a, int n, int k)
{
	assert(a);
	HP hp;
	HeapInit(&hp);
	//创建一个k个数的小堆
	for (int i = 0; i < k; ++i)
	{
		HeapPush(&hp, a[i]);
	}
	
	
	//剩下的N-K个数根堆顶的数据比较，比它大，就替换它
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
	int* a = (int*)malloc(sizeof(int) * n);
	assert(a);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//设置10个比100w大的数 -- 若选出来了，则成功
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
int main()
{
	TestTopk();

}