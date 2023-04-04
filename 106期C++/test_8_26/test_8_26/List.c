#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//��ʼ��
LTNode* ListInit()
{
	LTNode* guard = (LTNode*)malloc(sizeof(LTNode));
	if (guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	guard->next = guard;
	guard->prev = guard;

	return guard;
}
//����
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
//�������
LTNode* BuyListNode(x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;

	return newnode;
}

//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

//��ӡ
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//β��
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/

	ListInsert(phead, x);
}
//βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	/*LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;

	phead->prev = prev;
	prev->next = phead;
	free(tail);
	tail = NULL;*/

	ListErase(phead->prev);
}

//ͷ��
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* cur = phead->next;
	
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = cur;
	cur->prev = newnode;*/

	ListInsert(phead->next, x);

}
//ͷɾ
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	//LTNode* first = phead->next;
	//LTNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;

	ListErase(phead->next);

}

//����
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;

}
//��posλ��֮ǰ����
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//ɾ��posλ��
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}