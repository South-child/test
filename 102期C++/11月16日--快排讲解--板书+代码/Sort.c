#include "Sort.h"

void PrintArray(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 时间复杂度：O(N^2)
// 最好：O(N)   -- 顺序有序或者接近有序
// 最坏：O(N^2) -- 逆序
// 空间复杂度：O(1)
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; ++i)
	{
		// 将x插入[0, end]有序区间
		int end = i;
		int x = a[end+1];
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = x;
	}
}

// 希尔排序
// O(N^1.3)
void ShellSort(int* a, int n)
{
	// 按gap分组数据进行预排序
	//int gap = 3;

	/*for (int j = 0; j < gap; ++j)
	{
		for (int i = j; i < n - gap; i += gap)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = x;
		}
	}*/

	// 多次预排序(gap > 1) +直接插入 (gap == 1)
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		
		// 多组一锅炖
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = x;
		}
	}	
}

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

// 选择排序
// 时间复杂度：O(N^2)
// 最好：O(N^2)
// 整体而言最差的排序，因为无论什么情况都是O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[mini])
				mini = i;

			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		// begin == maxi时，最大被换走了，修正一下maxi的位置
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// 如果小的孩子小于父亲，则交换，并继续向下调整
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆排序 -- O（N*logN）
void HeapSort(int* a, int n)
{
	// O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// 时间复杂度：O(N^2)
// 最好：O(N)
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				exchange = 1;
				Swap(&a[i - 1], &a[i]);
			}
		}
		--end;

		if (exchange == 0)
		{
			break;
		}
	}
		

	/*for (int j = 0; j < n; j++)
	{
	for (int i = 1; i < n-j; ++i)
	{
	if (a[i - 1] > a[i])
	{
	Swap(&a[i - 1], &a[i]);
	}
	}
	}*/
	

	/*for (int i = 0; i < n-1; ++i)
	{
		if (a[i] > a[i+1])
		{
			Swap(&a[i], &a[i+1]);
		}
	}*/
}

int GetMidIndex(int* a, int left, int right)
{
	//int mid = (left + right) / 2;
	int mid = left + ((right - left) >> 1);
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// hoare版本
// [left, right]
// O(N)
int Partion1(int* a, int left, int right)
{
	// 三数取中 -- 面对有序最坏情况，变成选中位数做key，变成最好情况
	int mini = GetMidIndex(a, left, right);
	Swap(&a[mini], &a[left]);

	int keyi = left;
	while (left < right)
	{
		// 右边先走，找小
		while (left < right && a[right] >= a[keyi])
			--right;

		//左边再走，找大
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);

	return left;
}

// 挖坑法
int Partion2(int* a, int left, int right)
{
	// 三数取中 -- 面对有序最坏情况，变成选中位数做key，变成最好情况
	int mini = GetMidIndex(a, left, right);
	Swap(&a[mini], &a[left]);

	int key = a[left];
	int pivot = left;
	while (left < right)
	{
		// 右边找小, 放到左边的坑里面
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[pivot] = a[right];
		pivot = right;

		// 左边找大，放到右边的坑里面
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[pivot] = a[left];
		pivot = left;
	}

	a[pivot] = key;
	return pivot;
}

// O(N*logN)
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = Partion2(a, left, right);
	// [left, keyi-1] keyi [keyi+1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi+1, right);
}