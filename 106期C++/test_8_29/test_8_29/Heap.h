#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//����
void HeapCreate(HPDataType* a, int size);
//��ʼ��
void HeapInit(HP* php);
//����
void HeapDestroy(HP* php);
//����x�����ֶ�
void HeapPush(HP* php, HPDataType x);
// ɾ���Ѷ�Ԫ�أ������ֶ���̬
void HeapPop(HP* php);
// ȡ�Ѷ�Ԫ��
HPDataType HeapTop(HP* php);
//�п�
bool HeapEmpty(HP* php);
//���ض���Ԫ�ظ��� 
int HeapSize(HP* php);

//��ӡ��
void HeapPrint(HP* php);
//����
void Swap(HPDataType* p1, HPDataType* p2);
//���ϵ���
void AdjustUp(HPDataType* a, int child);
//���µ���
void AdjustDown(HPDataType* a, int n, int parent);




