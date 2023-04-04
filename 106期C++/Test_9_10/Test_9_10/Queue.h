#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct Queue* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);
//���
void QueuePush(Queue* pq, QDataType x);
//����
void QueuePop(Queue* pq);

//ȡ��ͷԪ��
QDataType QueueFront(Queue* pq);
//ȡ��βԪ��
QDataType QueueBack(Queue* pq);

//�п�
bool QueueEmpty(Queue* pq);

//������д�С
int QueueSize(Queue* pq);