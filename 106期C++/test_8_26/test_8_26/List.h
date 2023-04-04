#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//��ʼ��
LTNode* ListInit();
//��ӡ
void ListPrint(LTNode* phead);

//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead);

//β��
void ListPushBack(LTNode* phead, LTDataType x);
//βɾ
void ListPopBack(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDataType x);
//ͷɾ
void ListPopFront(LTNode* phead);

//��posλ��֮ǰ����
void ListInsert(LTNode* pos, LTDataType x);
//ɾ��posλ��
void ListErase(LTNode* pos);

//����
LTNode* ListFind(LTNode* phead, LTDataType x);

//����
void ListDestory(LTNode* phead);