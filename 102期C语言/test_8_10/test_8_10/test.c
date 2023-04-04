#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	char ch = 'w';
//	char * pc = &ch;//pc是指向一个字符变量
//
//	const char* p = "hello bit";//"hello bit"是一个常量字符串-存放在内存的常量区
//
//	*p = 'w';
//
//	//printf("%c\n", *p);
//	//printf("%s\n", p);
//
//	//上面表达式的作用是：把常量字符串"hello bit"的第一个字符h的地址赋值给p
//
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}


//指针数组 - 存放指针的数组
//int*
//char*
//short*
//
//int arr[10];//整型数组 - 存放整型的数组
//char arr[5];//字符数组 - 存放字符的数组

//
//int main()
//{
//	//char* arr[5];//arr是存放字符指针的数组
//	//int* arr2[4];//arr2是存放整形指针的数组
//
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	              //int* int* int* int*
//	int* arr2[4] = {&a, &b, &c, &d};//arr2就是整型指针的数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr2[i]));
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	
//	int* parr[] = { arr1, arr2, arr3 };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", parr[i][j]);//p[i] == *(p+i)
//			//parr[i][j] == *(parr[i]+j)
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	//const char* arr[5] = {"abcdef", "bcdefg", "hehe", "haha", "zhangsan"};
//	//int i = 0;
//	//for (i = 0; i < 5; i++)
//	//{
//	//	printf("%s\n", arr[i]);
//	//}
//	//printf("%s\n", arr[2]);
//
//	//int* arr[5];//指针数组
//	////arr 是数组名，数组名是数组首元素的地址，int* 类型变量的地址
//	//int** p = arr;//ok &arr[0]
//	//int** p2 = &arr[3];
//	return 0;
//}
//


//指针数组

//
//数组指针 - 指向数组的指针
// 
//int*p; 整型指针 - 指向整型的指针
//char*p; 字符指针 - 指向字符的指针
//


//int main()
//{
//	int a = 10;
//	int* pi = &a;//整型的地址存放在整型指针中
//	char ch = 'w';
//	char* pc = &ch;//字符的地址存放在字符指针中
//
//	int arr[10] = {0};
//	int* p = arr;// -是数组首元素的地址
//
//	//int* parr[10]; //这样写是数组
//	int (*parr)[10] = &arr;//取出的是数组的地址, 应该存放到数组指针中
//
//	return 0;
//}
//

//
//int main()
//{
//	int arr[10] = {0};
//	//arr;//数组名是首元素的地址
//	//&arr[0];//是首元素的地址
//	//&arr;//取出数组的地址
//	int (*p)[10] = &arr;
//
//	printf("%p\n", arr);//int*
//	printf("%p\n", &arr[0]);//int*
//	printf("%p\n", &arr);//数组的地址    int(*)[10]
//
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr+1);
//
//	return 0;
//}
//
//int main()
//{
//	//数组名是首元素的地址
//	//但是有2个例外：
//	//1. sizeof(数组名)， 这里的数组名是表示整个数组的，sizeof(数组名)计算的是整个数组的大小，单位是字节
//	//2. &数组名， 这里的数组名不是首元素的地址，数组名表示整个数组，所以取出的是整个数组的地址
//	//
//	int arr[10] = {0};
//	printf("%d\n", sizeof(arr));
//
//	return 0;
//}

//
//int main()
//{
//	int* arr[10] = {0};
//	int* (*p)[10] = &arr;
//
//	int** p2 = arr;//int*
//
//
//	return 0;
//}


//void print1(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void print2(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}

//数组指针
//void print3(int (*parr)[10], int sz)//这是一个错误的示范
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", parr[i]);//parr[i] == *(parr+i)
//	}
//}
//
//void print4(int (*parr)[10], int sz)
//{
//	//*(parr + 0);//parr[0]
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", parr[0][i]);
//		//printf("%d ", (*(parr + 0))[i]);
//		printf("%d ", (*parr)[i]);//(*parr) 相当于 parr指向的数组的数组名
//	}
//}
//
//
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print4(&arr, sz);
//
//	//print3(&arr, sz);
//	//print2(arr, sz);
//	//print1(arr, sz);//打印arr数组的内容
//
//	return 0;
//}

//参数部分也是二维数组
//void print1(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////数组指针
//void print2( int(*p)[5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6,3,4,5,6,7 };
//	//二维数组传参
//	//print1(arr, 3, 5);
//	print2(arr, 3, 5);//arr 是数组名，数组名是首元素地址
//	return 0;
//}
//
int main()
{
	int* arr[10];

	int(*parr3[10])[5];
	//parr3是一个数组,数组有10个元素
	//每个元素是一个数组指针，该指针指向的数组有5个元素
	//每个元素是int.
	return 0;
}