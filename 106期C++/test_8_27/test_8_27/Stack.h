#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ��
void StackInit(ST* ps);

//����
void StackDestroy(ST* ps);

//��ջ
void StackPush(ST* ps, STDataType x);

//��ջ
void StackPop(ST* ps);

//ȡջ��Ԫ��
STDataType StackTop(ST* ps);

//�п�
bool StackEmpty(ST* ps);

//����ջ��Ԫ�ظ���
int StackSize(ST* ps);