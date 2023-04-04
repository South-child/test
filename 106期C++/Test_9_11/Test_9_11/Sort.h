#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
//��ӡ
void PrintArray(int* a, int n);

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//���µ���
void AdjustDown(int* a, int n, int parent);
//������
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

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
