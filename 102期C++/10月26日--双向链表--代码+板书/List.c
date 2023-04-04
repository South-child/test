#include "List.h"

LTNode* ListInit()
{
	// 哨兵位头结点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	//LTNode* tail = phead->prev;
	//LTNode* newnode = BuyListNode(x);

	//// phead                   tail  newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

//void ListPopBack(LTNode* phead)
//{
//	assert(phead);
//	assert(phead->next != phead);
//
//	LTNode* tail = phead->prev;
//	LTNode* tailPrev = tail->prev;
//	free(tail);
//
//	tailPrev->next = phead;
//	phead->prev = tailPrev;
//}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* tail = phead->prev;

	phead->prev = tail->prev;
	tail->prev->next = phead;

	free(tail);
}

void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;*/

	ListInsert(phead->next, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	// 链表空
	assert(phead->next != phead);

	LTNode* next = phead->next;
	LTNode* nextNext = next->next;

	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
}

LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// pos位置之前插入
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	// posPrev newnode pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

// 删除pos位置
void ListErase(LTNode* pos)
{
	assert(pos);
	// ...
}