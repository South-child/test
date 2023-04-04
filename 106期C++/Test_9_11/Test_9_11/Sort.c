#define  _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//��ӡ
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
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

//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	//gapΪ1ʱ��Ϊֱ�Ӳ�������
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

//ѡ������
void SelectSort(int* a, int n)
{

}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//���µ���
void AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int maxChild = parent * 2 + 1;

	while (maxChild < n)
	{
		//����� 
		//�ҳ�����ӽڵ�
		if (maxChild + 1 < n && a[maxChild + 1] > a[maxChild])
		{
			maxChild++;
		}

		//���µ���
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
//������
void HeapSort(int* a, int n)
{
	assert(a);

	//���µ�������
	for (int i = (n - 1 - 1) /2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//ѡ��
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		++i;
	}
}

//ð������
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

//��������ݹ�ʵ��
void QuickSort(int* a, int begin, int end);
//��������ǵݹ�ʵ��
void QuickSortNonR(int* a, int begin, int end);

//�鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
//�鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);