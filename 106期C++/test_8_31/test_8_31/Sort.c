#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// �ʱ�临�Ӷ�O(N^2) -- ����
// ���ʱ�临�Ӷ�O(N) -- ˳������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		// [0,end] ���� end+1 [0, end+1]����
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
//
//void ShellSort(int* a, int n)
//{
	//int gap = 3;
	//for (int j = 0; j < gap; ++j)
	//{
	//	for (int i = j; i < n - gap; i += gap)
	//	{
	//		// [0,end] ���� end+gap [0, end+gap]����  -- ���Ϊgap������
	//		int end = i;
	//		int tmp = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (a[end] > tmp)
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = tmp;
	//	}
	//}	

	// gap > 1  Ԥ����
	// gap == 1 ֱ�Ӳ�������

// O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;

		// [0,end] ���� end+gap [0, end+gap]����  -- ���Ϊgap������
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

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		// �ҳ�С���Ǹ�����
		if (minChild + 1 < n && a[minChild + 1] > a[minChild])
		{
			minChild++;
		}

		if (a[minChild] > a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// O(N*logN)
void HeapSort(int* a, int n)
{
	// ��˼·��ѡ����������ѡ�����Ӻ���ǰ��
	// ���� -- ���
	// ���� -- С��
	// ���� -- ���µ������� - O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// ѡ�� N*logN
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		++i;
	}
}

// �ʱ�临�Ӷȣ�O(N^2)
// ���ʱ�临�Ӷȣ�O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// ѡ����С�ķ�beginλ��
		// ѡ�����ķ�endλ��
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		// ����һ��maxi
		if (maxi == begin)
			maxi = mini;

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// ������O(N^2)
// ��������O(N)
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}

// [left, right]
int PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		// 6 6 6 6 6
		// R��С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// L�Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		if (left < right)
			Swap(&a[left], &a[right]);
	}

	int meeti = left;

	Swap(&a[meeti], &a[keyi]);

	return meeti;
}

// [begin, end]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort(a, begin, end);
	//[begin, keyi-1] keyi [keyi+1, end]

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}



