#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//˳����ʼ��
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}
//˳�������
void SLDestory(SL* psl)
{
	assert(psl);

	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;

}
//˳����ӡ
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
//����
void SLCheckCapacity(SL* psl)
{
	//���û�пռ���߿ռ䲻�㣬����Ҫ����
	if (psl->size == psl->capacity)
	{
		int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		psl->a = tmp;
		psl->capacity = newcapacity;
	}
}

//���ݵĹ��� -- ��ɾ���
//β��
void SLPushBack(SL* psl, SLDataType x)
{
	//assert(psl);

	////�ж��Ƿ���Ҫ����
	//SLCheckCapacity(psl);
	//psl->a[psl->size] = x;
	//psl->size++;

	//���븴��
	SLInsert(psl, psl->size, x);
}
//βɾ
void SLPopBack(SL* psl)
{
	//assert(psl);
	////sizeҪ����0�ſ��Խ���ɾ��
	////�����������
	//assert(psl->size > 0);
	//psl->size--;
	////����������
	///*if (psl->size == 0)
	//	return;*/

	//���븴��
	SLEarse(psl, psl->size - 1);
}
//ͷ��
void SLPushFront(SL* psl, SLDataType x)
{
	////�ж��Ƿ�Ҫ����
	//SLCheckCapacity(psl);

	////�ƶ�����
	//for (int i = psl->size - 1; i >= 0; i--)
	//{
	//	psl->a[i+1] = psl->a[i];
	//}
	////��������
	//psl->a[0] = x;
	//psl->size++;

	//���븴��
	SLInsert(psl, 0, x);
}
//ͷɾ
void SLPopFront(SL* psl)
{
	//assert(psl);
	//assert(psl->size > 0);

	//for (int begin = 0; begin < psl->size - 1; begin++)
	//{
	//	psl->a[begin] = psl->a[begin + 1];
	//}

	//psl->size--;

	//���븴��
	SLEarse(psl, 0);
}

//˳������-- �ҵ������±�û�ҵ�����-1
int SLFind(SL* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		if (psl->a[i] == x)
			return i;
	}
	return -1;
}

//��posλ�ò�������
void SLInsert(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos <= psl->size);
	//��������֮ǰ��Ҫ�ж��Ƿ���Ҫ����
	SLCheckCapacity(psl);
	//��������
	//Ų������
	size_t end = psl->size;
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;

	//size_t end = psl->size - 1;
	//while (end >= pos) //pos����0ʱ��������ѭ�� ��Ϊend���޷�������
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	end--;
	//}
	//psl->a[pos] = x;
	//psl->size++;

}

//ɾ��posλ�õ�����
void SLEarse(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);
	int begin = pos;
	while (begin < psl->size - 1)
	{
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}
	psl->size--;
}

//�޸�posλ�õ�����
void SLModify(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}