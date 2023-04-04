#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__
////...
//#endif


// ��̬��˳��� -- ��֪��Ҫ�洢�������ݣ�
//#define N 10000
//typedef int SLDataType;
//struct SeqList
//{
//	SLDataType a[N];
//	int size; // �洢���ݵĸ���
//};

// ��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;      // �洢���ݵĸ���
	int capacity;  // �洢�ռ�Ĵ�С
}SL;

//void SeqListInit(SL sl);
void SLInit(SL* psl);
void SLDestory(SL* psl);
void SLPrint(const SL* psl);

// ͷ��ͷɾ β��βɾ
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

// û���ҵ��ͷ���-1
int SLFind(SL* psl, SLDataType x);

// ˳�����posλ�ò���x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// ˳���ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos);

void SLModify(SL* psl, size_t pos, SLDataType x);

size_t SLSize(SL* psl);
SLDataType& SlAt(SL* psl, size_t pos);