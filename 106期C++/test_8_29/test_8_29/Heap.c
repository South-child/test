#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


//��ӡ��
void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
//��ʼ��	
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;                
}
//����
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
//��������
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//С����
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	//��������ڵ��µĴ�С��δ�ĺ��ӽ��
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		if (minChild + 1 < n && a[minChild + 1] < a[minChild])
		//if (minChild + 1 < n && a[minChild + 1] > a[minChild])//���	
		{
			//�ҳ���\С���ĸ����
			minChild++;
		}
		if (a[minChild] < a[parent])   
		//if (a[minChild] > a[parent])//���
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//����
//void HeapCreate(HPDataType* a, int size)
//{
//	assert(a);
//	for (int i = 1; i < size; ++i)//�ӵڶ�����㿪ʼ����
//	{
//		//���ϵ���
//		AdjustUp(a, i);
//	}
//}
void HeapCreate(HPDataType* a, int size)
{
	assert(a);
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)//�����һ��Ҷ���ĸ���㿪ʼ�������
	{
		//���µ���
		AdjustDown(a,size, i);
	}
}

//����x�����������ֶ���̬
void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	//�����Ƿ���Ҫ����
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;

		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;

	//��Ҫ�жϲ�������ݣ��Ƿ��ܱ��ֶ���̬
	AdjustUp(php->a, php->size - 1);
}


// ɾ���Ѷ�Ԫ�أ������ֶ���̬
//ÿ���Ҵδ�Ļ��С�� -- ����ʱ�临�Ӷ�Ϊ O(logN)
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//���µ���
	AdjustDown(php->a, php->size, 0);
}
// ȡ�Ѷ�Ԫ��
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
//�п�
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
//���ض���Ԫ�ظ��� 
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
