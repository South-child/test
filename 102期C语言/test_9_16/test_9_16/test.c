#define _CRT_SECURE_NO_WARNINGS 1
//
//void* my_memcpy(void* dest, const void*src, size_t count)
//{
//	void* ret = dest;
//	assert(dest && src);
//
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	//重叠拷贝+不重叠拷贝
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//            1,2,1,2,3,4,7,8,9,10
//	//memcpy(arr+2, arr, 16);
//	//memcpy - 只要完成了不重叠的内存拷贝就完成任务
//	my_memmove(arr+2, arr, 16);
//	//内存拷贝时，出现内存重叠的现象，应该使用memmove
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//
//	//拷贝的是整型数据
//	my_memcpy(arr2, arr1, 10*sizeof(int));
//
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}



#include <stdio.h>
#include <assert.h>
//
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(src && dest);
//
//	if (dest < src)
//	{
//		//前->后
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//后->前
//		while (count--)
//		{
//			*((char*)dest+count) = *((char*)src + count);
//		}
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//my_memmove(arr+2, arr, 16);
//	my_memmove(arr, arr+2, 16);
//
//	return 0;
//}
//

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 ...
//	int arr2[] = { 1,2,3,6,6 };//01 00 00 00 02 00 00 00 03 00 00 00 06 00 00 00 ...
//
//	int ret = memcmp(arr1, arr2, 13);
//	
//	printf("%d\n", ret);
//
//	return 0;
//}

//memset
//memory set

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	memset(arr, 1, 24);
//
//	return 0;
//}


//0 1 2 3 4 5
//错误码
//错误码 - 错误信息
//3 - "打开文件失败"
//
#include <string.h>

//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//
//	return 0;
//}

//打开文件

//strerror
//perror

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	//errno
//	//strerror - 可以返回C语言内置的错误码对应的错误信息
//	//
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("测试");//打印+strerror
//	}
//	else
//	{
//		printf("打开文件成功\n");
//	}
//
//	return 0;
//}


//复杂对象
// 人：名字+年龄+身高+体重+身份证号码+电话
// 书：书名+作者+出版社+定价+书号
// 
//复杂类型
//

//结构体

//声明一个结构体类型
//struct Book
//{
//	char name[20];
//	char author[20];
//	int price;
//};

//struct Book
//{
//	char name[20];
//	char author[20];
//	int price;
//}b1, b2;//全局
//
//struct Book b3;//全局
//
//int main()
//{
//	struct Book b4;//局部变量
//
//	return 0;
//}

//struct
//{
//	int a;
//	char c;
//	double d;
//}s1, s2;
//
//struct
//{
//	int a;
//	char c;
//	double d;
//}* ps;
//
//int main()
//{
//	ps = &s1;
//
//	return 0;
//}
//

//err

//struct Node
//{
//	int data;
//	struct Node n;
//};
//

//struct Node
//{
//	int data;//数据域
//	struct Node* next;//指针域
//};
//

//
//struct Point
//{
//	int x;
//	int y;
//}p3 = { 5,6 }, p4 = {7,8};
//
//struct Point p2 = {1,2};
//
//struct S
//{
//	double d;
//	struct Point p;
//	char name[20];
//	int data[20];
//};
//
//int main()
//{
//	struct Point p1 = {3,4};
//	struct S s = { 3.14, {1,5} , "zhangsan", {1,2,3} };
//	printf("%lf\n", s.d);
//	printf("%d %d\n", s.p.x, s.p.x);
//	printf("%s\n", s.name);
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", s.data[i]);
//	}
//
//	return 0;
//}



//内存对齐
//结构体内存对齐

//12
struct S1
{
	char c1;//1
	int a;//4
	char c2;//1
};

//8
struct S2
{
	char c1;//1
	char c2;//1
	int a;//4
};

struct S3
{
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};

int main()
{
	//struct S1 s = {'x', 100, 'y'};
	//printf("%d\n", sizeof(struct S1));
	//printf("%d\n", sizeof(struct S2));

	printf("%d\n", sizeof(struct S4));

	//printf("%d\n", sizeof(s));
	return 0;
}