#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
//打印
void PrintArray(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//向下调整
void AdjustDown(int* a, int n, int parent);
//堆排序
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

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
