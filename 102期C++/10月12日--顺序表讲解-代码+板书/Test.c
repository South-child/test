#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 20);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

// 写一个类似通讯录的菜单
void menu()
{
	print("************************************\n");
	printf("请选择你的操作:>\n");
	printf("1、头插  2、头删\n");
	printf("3、尾插  4、尾删\n");
	// ...
	print("************************************\n");
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();

	return 0;
}