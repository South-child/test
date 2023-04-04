#define  _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//打印
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	//gap为1时，为直接插入排序
	while (gap > 1)
	{
		//gap /= 2;
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//选择排序
void SelectSort(int* a, int n)
{

}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//向下调整
void AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int maxChild = parent * 2 + 1;

	while (maxChild < n)
	{
		//建大堆 
		//找出大的子节点
		if (maxChild + 1 < n && a[maxChild + 1] > a[maxChild])
		{
			maxChild++;
		}

		//向下调整
		if (a[maxChild] > a[parent])
		{
			Swap(&a[maxChild], &a[parent]);
			parent = maxChild;
			maxChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* a, int n)
{
	assert(a);

	//向下调整建堆
	for (int i = (n - 1 - 1) /2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//选数
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		++i;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	assert(a);
	for (int j = 0; j < n; j++)
	{
		int flag = 0;
		for (int i = 0; i < n - j - 1; ++i)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}

}

//快速排序递归实现
void QuickSort(int* a, int begin, int end);
//快速排序非递归实现
void QuickSortNonR(int* a, int begin, int end);

//归并排序递归实现
void MergeSort(int* a, int n);
//归并排序非递归实现
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);