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

	// 缺省参数不能在函数声明和定义中同时出现,在声明中给
	void StackInit(ST* ps, int defaultCP = 4);
	void StackPush(ST* ps, int x);
}