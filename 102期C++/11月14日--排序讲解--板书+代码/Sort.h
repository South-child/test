#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 排序实现的接口
void PrintArray(int* a, int n);

// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 堆排序
void HeapSort(int* a, int n);