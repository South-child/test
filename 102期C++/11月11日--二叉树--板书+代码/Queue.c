#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	//if (pq->head == NULL)
	//	return;
	assert(!QueueEmpty(pq));

	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		++n;
		cur = cur->next;
	}

	return n;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}


//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//// oj ºóÌ¨²âÊÔ
//MyStack* myStackCreate() {
//	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&st->q1);
//	QueueInit(&st->q2);
//	return st;
//}
//void myStackPush(MyStack* obj, int x) {
//
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//}

//int main()
//{
//	MyStack* st = myStackCreate();
//	myStackPush(st, 1);
//	myStackPush(st, 2);
//	myStackPush(st, 3);
//	myStackPop(st);
//	myStackFree(st);
//
//	return 0;
//}