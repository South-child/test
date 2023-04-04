#include "Singleton.h"

//CallInfo* CallInfo::_pInst = nullptr;
//mutex CallInfo::_mtx;
//CallInfo::CGarbo gc;


//int callCount = 0;

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		// 将x插入[0, end]有序区间
		int end = i;
		int x = a[end + 1];
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

void QuickSort(int* a, int left, int right)
{
	CallInfo::GetInstance().AddCallCount(1);
	CallInfo::GetInstance().Push(make_pair(left, right));

	if (left >= right)
		return;

	/*if (right - left + 1 > 10)
	{*/
		int keyi = left;
		int prev = left;
		int cur = prev + 1;
		while (cur <= right)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
			{
				swap(a[cur], a[prev]);
			}

			++cur;
		}

		swap(a[prev], a[keyi]);
		keyi = prev;

		// [left, keyi-1]keyi[keyi+1, right]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
		/*}
		else
		{
		InsertSort(a + left, right - left + 1);
		}*/
}