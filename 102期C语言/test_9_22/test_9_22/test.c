#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int n = 10;//4 byte
//	int arr[10];//40 byte
//
//	return 0;
//}

//
//动态内存分配
//
#include <stdlib.h>
//
//int main()
//{
//	//int arr[10] = {0};
//	//申请空间
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return -1;
//	}
//	//开辟成功了
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	//释放空间
//	free(p);
//	p = NULL;
//	
//	return 0;
//}

#include <string.h>
#include <errno.h>
//
//int main()
//{
//	//申请10个int的空间
//	int*p = (int*)calloc(10, sizeof(int));
//	
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return -1;
//	}
//	
//	//申请成功
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	//空间不够了，增加空间至20 个int
//	int*ptr = (int*)realloc(p, 20*sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	else
//	{
//		return -1;
//	}
//	for (i = 10; i < 20; i++)
//	{
//		*(p + i) = i;
//	}
//	//打印
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//释放空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}
//
//int  main()
//{
//	int*p = (int*)malloc(20);
//	if (p == NULL)
//		return -1;
//	//
//	*p = 0;//直接这样写代码是有风险的！！！
//
//	return 0;
//}
//对动态开辟空间的越界访问
//
//int main()
//{
//	int* p = (int*)malloc(200);
//	if (p == NULL)
//	{
//		return -1;
//	}
//	//使用
//	int i = 0;
//	//越界访问
//	for (i = 0; i < 80; i++)
//	{
//		*(p + i) = i;
//	}
//
//	for (i = 0; i < 80; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//对非动态开辟内存使用free释放
//
//int main()
//{
//	int a = 10;
//	int*p = &a;
//	//
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//使用free释放一块动态开辟内存的一部分
//
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return -1;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;
//	}
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//对同一块动态内存多次释放
//
//int main()
//{
//	int *p = (int*)malloc(40);
//	if (p == NULL)
//		return -1;
//	//使用
//	//...
//
//	//2次释放-是错误的
//	free(p);
//	free(p);
//
//	return 0;
//}

//动态开辟内存忘记释放
//在堆区上申请的空间，有2中回收的方式
//1. 主动free
//2. 程序退出的时候，申请的空间也会回收
//

//int main()
//{
//	int *p = (int*)malloc(40);
//	if (p == NULL)
//		return -1;
//	//使用
//	//忘记释放了
//	getchar();//
//	return 0;
//}

int main()
{
	int *p = (int*)malloc(40);
	if (p == NULL)
		return -1;
	//使用
	//释放
	free(p);
	//p就是一个野指针

	p = NULL;
	//p就是NULL，不是野指针

	return 0;
}