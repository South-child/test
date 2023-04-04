#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// ≈≈–Ú µœ÷µƒΩ”ø⁄
void PrintArray(int* a, int n);

// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

// ∂—≈≈–Ú
void HeapSort(int* a, int n);

// MaoPaoSort
// MaoPaoPaixXu
void BubbleSort(int* a, int n);

void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

void MergeSort(int* a, int n);