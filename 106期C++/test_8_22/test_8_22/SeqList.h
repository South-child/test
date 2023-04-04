#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

//��̬˳���
//#define N 10
//struct SeqList
//{
//	SLDataType a[N];
//	int size;//�洢���ݵĸ���
//	int capacity;//����������
//};

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	size_t size;//������Ԫ��ʵ�ʸ���
	size_t capacity;//����������
}SL;

//˳����ʼ��
void SLInit(SL* psl);
//˳�������
void SLDestory(SL* psl);
//˳����ӡ
void SLPrint(SL* psl);

//���ݵĹ��� -- ��ɾ���

//β��
void SLPushBack(SL* psl, SLDataType x);
//βɾ
void SLPopBack(SL* psl);
//ͷ��
void SLPushFront(SL* psl, SLDataType x);
//ͷɾ
void SLPopFront(SL* psl);

//˳������-- �ҵ������±�û�ҵ�����-1
int SLFind(SL* psl, SLDataType x);

//��posλ�ò�������
void SLInsert(SL* psl, size_t pos, SLDataType x);


//ɾ��posλ�õ�����
void SLEarse(SL* psl, size_t pos);

//�޸�posλ�õ�����
void SLModify(SL* psl, size_t pos, SLDataType x);