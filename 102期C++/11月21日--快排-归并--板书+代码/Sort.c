#include "Sort.h"
#include "Stack.h"

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

// 前后指针
//int Partion3(int* a, int left, int right)
//{
//	int keyi = left;
//	int prev = left;
//	int cur = prev + 1;
//	while (cur <= right)
//	{
//		while (cur <= right && a[cur] >= a[keyi])
//		{
//			++cur;
//		}
//
//		if (cur <= right)
//		{
//			Swap(&a[cur], &a[++prev]);
//			cur++;
//		}
//	}
//
//	Swap(&a[prev], &a[keyi]);
//	return prev;
//}

// 推荐掌握这个 -- 思想三种大家都要掌握
int Partion3(int* a, int left, int right)
{
	// 三数取中 -- 面对有序最坏情况，变成选中位数做key，变成最好情况
	int mini = GetMidIndex(a, left, right);
	Swap(&a[mini], &a[left]);

	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		++cur;
	}

	Swap(&a[prev], &a[keyi]);
	return prev;
}

// O(N*logN)
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	// 小区间优化，当分割到小区间时，不再用递归分割思路让这段子区间有序
	// 对于递归快排，减少递归次数
	/*if (right - left + 1 < 10)
	{
	InsertSort(a + left, right - left + 1);
	}
	else*/
	{
		int keyi = Partion3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}	
}

// 递归深度太深的程序，只能考虑改非递归
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);

		int begin = StackTop(&st);
		StackPop(&st);

		int keyi = Partion3(a, begin, end);
		// [begin, keyi-1] keyi [keyi+1, end]
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi+1);
			StackPush(&st, end);
		}

		if (begin < keyi-1)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi-1);
		}
	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	// [left, mid] [mid+1, right] 有序
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid+1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// tmp 数组拷贝回a
	for (int j = left; j <= right; ++j)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			// [i,i+gap-1] [i+gap,i+2*gap-1]
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i+gap, end2 = i + 2*gap-1;
//			//printf("[%d,%d][%d,%d]", begin1, end1, begin2, end2);
//
//			// end1 越界，[begin2,end2]不存在
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//			}
//
//			//[begin1,end1]存在 [begin2,end2]不存在
//			if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//			//printf("[%d,%d][%d,%d]", begin1, end1, begin2, end2);
//
//			int index = i;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				//printf(" %d ", index);
//
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1)
//			{
//				//printf(" %d ", index);
//
//				tmp[index++] = a[begin1++];
//			}
//
//			while (begin2 <= end2)
//			{
//				//printf(" %d ", index);
//
//				tmp[index++] = a[begin2++];
//			}
//		}
//		printf("\n");
//		
//		// 把归并数据拷贝回原数组
//		for (int i = 0; i < n; ++i)
//		{
//			a[i] = tmp[i];
//		}
//
//		gap *= 2;
//	}
//
//	free(tmp);
//	tmp = NULL;
//}

// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 核心思想：end1、begin2、end2都有可能越界
			// end1越界 或者 begin2 越界都不需要归并
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			
			// end2 越界，需要归并，修正end2
			if (end2 >= n)
			{
				end2 = n- 1;
			}

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			// 把归并小区间拷贝回原数组
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tmp[j];
			}
		}

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

// 时间复杂度：O(Max(N, Range))
// 空间复杂度：O(range)
// 适合范围比较集中的整数数组
// 范围较大，或者是浮点数等等都不适合排序了
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	// 统计次数
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	// 根据次数，进行排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}