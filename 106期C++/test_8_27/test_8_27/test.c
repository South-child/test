#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include "Queue.h"

void TestStack()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d\n", StackSize(&st));

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

}
void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d\n", QueueSize(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}
int main()
{
	TestStack();
	printf("\n");

	TestQueue();

	return 0;
}