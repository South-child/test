#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//��ӡ������
void SListPrint(SLTNode* phead);

//����
void SListDestory(SLTNode** pphead);

//�����ڵ�
SLTNode* BuySLTNode(SLTDataType x);


//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);

//β��
void SListPushBack(SLTNode** pphead, SLTDataType x);

//ͷɾ
void SListPopFront(SLTNode** pphead);

//βɾ
void SListPopBack(SLTNode** pphead);

//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//��posλ��֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//��posλ��֮�����
void SListInsertAftre(SLTNode* pos, SLTDataType x);

// ɾ��posλ��
void SListErase(SLTNode** pphead, SLTNode* pos);

// ɾ��pos����λ��
void SListEraseAfter(SLTNode* pos);