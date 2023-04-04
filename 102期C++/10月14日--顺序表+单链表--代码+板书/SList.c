#include "SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ÕÒµ½Î²½Úµã
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}	
}