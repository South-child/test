#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//����
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;

	while (cur)
	{
		QNode* del = cur;
		free(del);
		cur = cur->next;
	}
	pq->head = pq->tail = NULL;
}
//���
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//������Ҫ����һ���½��
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	//����Ϊ��
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	//���в�Ϊ��
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

	pq->size++;
}
//����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail =  NULL;
	}
	else
	{
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}
	pq->size--;
}

//ȡ��ͷԪ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}
//ȡ��βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//�п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

//������д�С
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}