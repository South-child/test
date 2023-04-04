#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{
	LTNode* plist = ListInit();
	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	//βɾ
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);

}
void TestList2()
{
	LTNode* plist = ListInit();
	//β��
	//ListPushBack(plist, 1);
	//ListPushBack(plist, 2);
	//ListPushBack(plist, 3);
	//ListPushBack(plist, 4);
	//ListPrint(plist);

	//ͷ��
	ListPushFront(plist, 10);
	ListPushFront(plist, 20);
	ListPushFront(plist, 30);
	ListPushFront(plist, 40);
	ListPrint(plist);

	//ͷɾ
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	//ListPopFront(plist);

}

void TestList3()
{
	LTNode* plist = ListInit();
	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	//����
	LTNode* pos = ListFind(plist, 1);
	if (pos)
	{
		ListInsert(pos, 30);
	}
	ListPrint(plist);
}
int main()
{
	TestList2();
	return 0;
}