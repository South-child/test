#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//��ӡ������
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����
void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;

	while (cur != NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//�����ڵ�
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;

}


//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)//����Ϊ��
	{
		*pphead = newnode;
	}
	else
	{
		//����Ϊ��
		//��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	assert(*pphead != NULL);

	SLTNode* tmp = *pphead;

	*pphead = tmp->next;
	free(tmp);
	tmp = NULL;

}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	assert(*pphead != NULL);

	//1.ֻ��һ���ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//2.����ڵ�
	else
	{
		//��β -- ɾ��β��㣬��Ҫ��¼β����ǰһ���ڵ��λ��		
		SLTNode* tail = *pphead;
		SLTNode* prev = *pphead;

		//����һ
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//tail = NULL;
		//prev->next = NULL;

		//������
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;

	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//��posλ��֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)//posλ����ͷ�ڵ㣬�൱��ͷ��
	{
		/*SLTNode* newnode = BuySLTNode(x);
		newnode->next = *pphead;
		*pphead = newnode;*/

		//���븴��
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySLTNode(x);

		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;

			//������飬��pos���������У���prevΪ��,pos������
			assert(prev);
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

//��posλ��֮�����
void SListInsertAftre(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ɾ��posλ��
//����˼��Ϊʲô��ɾ��posλ�ã�
//�������ʺ�ɾ����ǰλ�ã���Ϊɾ����ǰλ����Ҫ֪������ǰһ��λ�ã���������ǰһ����Ҫ��ͷ��ʼ�ң���ʱʱ�临�ӶȾ���O(N)
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)//ͷɾ
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		//pos = NULL; //�����壬��Ϊ�������Ĳ��Ƕ���ָ�룬�βεĸı䲻Ӱ��ʵ��
		//������ʹ�õ�ʱ���Լ��ÿ�
	}
}

// ɾ��pos����λ��
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next != NULL);

	SLTNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}