#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//����ͷ�壬β��
void TestSListNode1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPushBack(&plist, 10);
	SListPushBack(&plist, 20);
	SListPushBack(&plist, 30);
	SListPrint(plist);


}

//����ͷɾβɾ
void TestSListNode2()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 10);
	SListPushBack(&plist, 20);
	SListPushBack(&plist, 30);
	SListPushBack(&plist, 40);
	SListPushBack(&plist, 50);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);


}

//���Բ���
void TestSListNode3()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 10);
	SListPushBack(&plist, 20);
	SListPushBack(&plist, 30);
	SListPushBack(&plist, 40);
	SListPushBack(&plist, 50);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos == NULL)
	{
		printf("û�ҵ�");
	}
	else
	{
		pos->data = (pos->data) * 10;
	}
	SListPrint(plist);
}

//���Բ���
void TestSListNode4()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
		SListInsertAftre(pos, 30);
	}
	SListPrint(plist);
}

//����ɾ��pos��Ľڵ�
void TestSListNode5()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos)
	{
		SListEraseAfter(pos);
		pos = NULL;
	}
	SListPrint(plist);
}
//����ɾ��posλ�õĽڵ�
void TestSListNode6()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos)
	{
		SListErase(&plist, pos);
		pos = NULL;
	}
	SListPrint(plist);
}
int main()
{
	TestSListNode5();
	return 0;
}