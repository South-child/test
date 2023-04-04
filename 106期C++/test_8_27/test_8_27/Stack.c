#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//����
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//��Ҫ�ж�ջ�Ƿ�����,���˾�Ҫ����
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;

		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

//�п�
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//����ջ��Ԫ�ظ���
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}