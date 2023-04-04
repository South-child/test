#define  _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
//÷±Ω”≤Â»Î
void TestInsertSort()
{
	int a[] = { 34,56,25,65,86,99,72,66 };
	printf("÷±Ω”≤Â»Î≈≈–Ú\n");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}
//œ£∂˚
void TestShellSort()
{
	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
	printf("œ£∂˚≈≈–Ú\n");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//—°‘Ò
void TestSelectSort()
{
	int a[] = { 100, 56, 25, 65, 86, 99, 72, 66 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//∂—≈≈
void TestHeapSort()
{
	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
	printf("∂—≈≈–Ú\n");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//√∞≈›≈≈–Ú
void TestBubbleSort()
{
	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
	printf("√∞≈›≈≈–Ú\n");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//void TestQuickSort()
//{
//	int a[] = { 100, 56, 25, 65, 86, 99, 72, 66 };
//	//int a[] = {1,2,3,4,5,6,7,8,9,10 };
//	//QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
//	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}

//πÈ≤¢
//void TestMergeSort()
//{
//	//int a[] = {10,6,7,1,3,9,4,2 };
//	//int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 5 };
//	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 5, 6 };
//
//	//MergeSort(a, sizeof(a) / sizeof(int));
//	MergeSortNonR(a, sizeof(a) / sizeof(int));
//
//	PrintArray(a, sizeof(a) / sizeof(int));
//}

//º∆ ˝
//void TestCountSort()
//{
//
//}


//void TestOP()
//{
//	srand(time(0));
//	const int N = 1000000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	int* a7 = (int*)malloc(sizeof(int) * N);
//
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//		a7[i] = a1[i];
//	}
//
//	int begin1 = clock();
//	//InsertSort(a1, N);
//	int end1 = clock();
//
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//
//	int begin3 = clock();
//	//SelectSort(a3, N);
//	int end3 = clock();
//
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//
//	int begin5 = clock();
//	QuickSort(a4, 0, N - 1);
//	int end5 = clock();
//
//	int begin6 = clock();
//	//MergeSort(a6, N);
//	int end6 = clock();
//
//	int begin7 = clock();
//	//BubbleSort(a7, N);
//	int end7 = clock();
//
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("BubbleSort:%d\n", end7 - begin7);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//	free(a7);
//}

int main()
{
	//≤Â»Î≈≈–Ú
	//TestInsertSort();//÷±Ω”≤Â»Î≈≈–Ú
	//TestShellSort();//œ£∂˚≈≈–Ú
	//printf("\n");

	////—°‘Ò≈≈–Ú
	TestSelectSort();//—°‘Ò≈≈–Ú
	TestHeapSort();//∂—≈≈–Ú
	printf("\n");

	////Ωªªª≈≈–Ú
	//TestBubbleSort();//√∞≈›≈≈–Ú
	//TestQuickSort();
	//printf("\n");

	////πÈ≤¢≈≈–Ú
	//TestMergeSort();
	//printf("\n");

	////º∆ ˝≈≈–Ú
	//TestCountSort();
	//printf("\n");

	return 0;
}