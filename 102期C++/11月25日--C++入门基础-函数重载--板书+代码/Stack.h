#pragma once


struct Stack
{
	int* a;
	int top;
	int capacity;
};

void StackInit(struct Stack* ps, int capacity = 4);
void StackPush(struct Stack* ps, int x);

