#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//

#include <string.h>
#include <stdlib.h>

//第一种改法
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//
//	strcpy(str, "hello world");
//	printf(str);
//	//释放
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//第二种改法
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//
//
//int main()
//{
//	const char* p = "hello world";
//	printf("hello world");
//	printf(p);
//
//	return 0;
//}


//
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}
//
//int* test()
//{
//	int n = 10;
//	return &n;
//}
//
//int main()
//{
//	int *p = test();
//
//	printf("hehe\n");
//
//	printf("%d\n", *p);
//
//	return 0;
//}

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//
//	free(str);
//	//str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}




//struct st_type2
//{
//	int i;
//	int a[0];//柔性数组成员
//};
//
//
#include<string.h>
#include <errno.h>

struct st_type
{
	int i;//4
	int a[];//柔性数组成员
};

int main()
{
	//printf("%d\n", sizeof(struct st_type));
	//包含柔性数组成员的结构体的使用，要配合malloc这样的动态内存分配函数使用
	//struct st_type st;
	struct st_type* ps = (struct st_type*)malloc(sizeof(struct st_type) + 10*sizeof(int));
	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	//开辟成功了
	ps->i = 100;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->a[i] = i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->a[i]);
	}
	//a数组的空间不够了，希望调整为20个整型数据
	struct st_type* ptr = (struct st_type*)realloc(ps, sizeof(struct st_type)+20*sizeof(int));
	if (ptr == NULL)
	{
		printf("扩展空间失败\n");
		return - 1;
	}
	else
	{
		ps = ptr;
	}

	//使用
	//...
	//释放
	free(ps);
	ps = NULL;

	return 0;
}



//struct st_type
//{
//	int i;//4
//	int* a;//4
//};
//
//int main()
//{
//	struct st_type* ps = (struct st_type*)malloc(sizeof(struct st_type));
//
//	ps->i = 100;
//	ps->a = (int*)malloc(10*sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->a[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	//a指向的空间不够了，希望可以调整大小
//	int* ptr = (int*)realloc(ps->a, 20*sizeof(int));
//	if (ptr == NULL)
//	{
//		printf("扩容失败\n");
//		return -1;
//	}
//	else
//	{
//		ps->a = ptr;
//	}
//	//使用
//	//..
//	
//	//释放
//	free(ps->a);
//	ps->a = NULL;
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}