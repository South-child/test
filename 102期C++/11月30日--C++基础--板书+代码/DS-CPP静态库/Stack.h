#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// C++静态库，extern "C"告诉编译器以下函数按C的函数名修饰规则去处理
//#ifdef __cplusplus
//#define EXTRERN_C extern "C"
//#else
//#define EXTRERN_C
//#endif
//

//EXTRERN_C void StackInit(ST* ps);
//EXTRERN_C void StackDestroy(ST* ps);
//EXTRERN_C void StackPush(ST* ps, STDataType x);
//EXTRERN_C void StackPop(ST* ps);
//EXTRERN_C STDataType StackTop(ST* ps);
//EXTRERN_C int StackSize(ST* ps);
//EXTRERN_C bool StackEmpty(ST* ps);

#ifdef __cplusplus
extern "C"
{
#endif
	void StackInit(ST* ps);
	void StackDestroy(ST* ps);
	void StackPush(ST* ps, STDataType x);
	void StackPop(ST* ps);
	STDataType StackTop(ST* ps);
	int StackSize(ST* ps);
	bool StackEmpty(ST* ps);
#ifdef __cplusplus
}
#endif
