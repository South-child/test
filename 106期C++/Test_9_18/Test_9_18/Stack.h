#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
namespace N1
{
	typedef struct Stack
	{
		int* a;
		int top;
		int capacity;
	}ST;

	void StackPush(ST* ps, int x);

	// ȱʡ���������ں��������Ͷ�����ͬʱ����,�������и�
	void StackInit(ST* ps, int defaultCP = 4);
	void StackPush(ST* ps, int x);
}