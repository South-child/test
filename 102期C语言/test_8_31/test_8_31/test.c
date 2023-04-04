#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//int main()
//{
//	//char ch = 'w';
//
//	//char* pc = &ch;
//	//const char* ps = "abcdef";
//
//	////指针数组 - 存放指针的数组
//	//int* arr[5];
//	//char* arr2[5];
//
//	//数组指针  - p2
//	//int arr[10];
//	//int * p = arr;  //int*
//	//int (*p2)[10] = &arr; //int(*)[10]
//
//	//printf("%p\n", arr);//数组名是数组首元素的地址
//	//printf("%p\n", &arr);//&arr 就是数组的地址
//
//	//
//	//函数指针
//	//指针 - 指向函数的
//	//
//
//	return 0;
//}

//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//printf("%p\n", Add);
//	//printf("%p\n", &Add);
//	
//	//pf是一个函数指针
//	int (*pf)(int x, int y) = Add;
//
//	//
//	//int sum = (*pf)(2, 3);
//	int sum = pf(2, 3);
//	//int sum = Add(2, 3);
//
//	printf("%d\n", sum);
//
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}

//int main()
//{
//	//int (*pA)(int, int) = Add;
//	//int (*pS)(int, int) = Sub;
//	//函数指针数组
//	int (*pArr[5])(int, int) = {Add, Sub};//pArr就是函数指针的数组
//
//	//指向函数指针数组的指针
//	//p是一个数组指针
//	//该指针指向了一个数组
//	//数组的每个元素是函数指针
//	//(p是一个指向函数指针数组的指针)
//
//	int (*(*p)[5])(int, int) = &pArr;
//	return 0;
//}


//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//void Calc(int(*pf)(int, int))
//{
//	int ret = pf(3, 5);
//	printf("%p\n", pf);
//
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	//Calc(Add);
//	Calc(Sub);
//	printf("%p\n", Sub);
//	return 0;
//}




//
//void bubble_sort(int arr[], int sz)
//{
//	//趟数
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//升序
//	bubble_sort(arr, sz);
//
//	//打印
//	print_arr(arr, sz);
//
//	return 0;
//}


//void qsort(void* base, 
//	       size_t num, //待排序的元素个数
//	       size_t width, //一个元素的大小，单位是字节
//	       int(* cmp)(const void* e1, const void* e2) //cmp指向的是：排序时，用来比较2个元素的函数
//);
//
//int main()
//{
//	int a = 10;
//	float f = 5.5f;
//
//	//char* p = &a;//int*
//	//char* p2 = &f;//float*
//
//	//
//	//void*  - 无具体类型的指针
//	//能够接收任意类型的地址
//	//缺点：不能进行运算,不能+-整数，不能解引用
//	//
//	//int* p1 = &a;
//	//p1++;
//	//p1 = p1 + 1;
//
//	//void* p3 = &a;//int*
//	//void* p4 = &f;//float*
//
//
//	return 0;
//}

#include <stdlib.h>
#include <string.h>
//
//
////比较2个整型函数
//int cmp_int(const void* e1, const void*e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	//打印
//	print_arr(arr, sz);
//}
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_by_name(const void*e1, const void*e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//int cmp_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age -((struct Stu*)e2)->age;
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan", 15}, {"lisi", 30},{"wangwu", 10}};
//
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	//按照名字排序
//	//qsort(s, sz, sizeof(s[0]), cmp_by_name);
//
//	//按照年龄来排序
//	qsort(s, sz, sizeof(s[0]), cmp_by_age);
//}
//
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
////使用回调函数实现一个通用的冒泡排序函数
//
//void BubbleSort(void* base, size_t num, size_t width, int (*cmp)(const void*, const void*))
//{
//	size_t i = 0;
//	//趟数
//	for (i = 0; i < num - 1; i++)
//	{
//		//比较的对数
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			//base[j] ==> *(base+j)
//			if (cmp((char*)base+j*width, (char*)base+(j+1)*width)>0)
//			{
//				//交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
////测试自定义的BubbleSort();
//void test3()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz, sizeof(arr[0]), cmp_int);
//	//打印
//	print_arr(arr, sz);
//}
//
////测试自定义的BubbleSort() 排序结构体
//void test4()
//{
//	struct Stu s[3] = { {"zhangsan", 15}, {"lisi", 30},{"wangwu", 10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//按照名字排序
//	//BubbleSort(s, sz, sizeof(s[0]), cmp_by_name);
//
//	//按照年龄来排序
//	BubbleSort(s, sz, sizeof(s[0]), cmp_by_age);
//}
//
//
//
//int main()
//{
//	//测试排序整型数组
//	//test1();
//	// 
//	//排序结构体数据
//	//test2();
//
//	//测试自定义的BubbleSort();
//	//test3();
//
//	test4();
//	return 0;
//}
//
//


int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//数组名a单独放在sizeof内部，数组名表示整个数组，计算的是整个数组的大小
	printf("%d\n", sizeof(a + 0));//a表示首元素的地址，a+0还是首元素的地址，地址的大小是4/8字节
	printf("%d\n", sizeof(*a));   //a表示首元素的地址，*a 就是首元素 ==> a[0] ,大小就是4
	//*a <==> *(a+0) <==> a[0]
	printf("%d\n", sizeof(a + 1));//a表示首元素的地址,a+1是第二个元素的地址，大小就是4/8
	printf("%d\n", sizeof(a[1])); //a[1] 就是第二个元素 - 4
	printf("%d\n", sizeof(&a));   //&a - 数组的地址 - 4/8 - int(*)[4]
	printf("%d\n", sizeof(*&a));  //*&a - &a是数组的地址，对数组的地址解引用拿到的是数组，所以大小时候16
	//printf("%d\n", sizeof(a));//16

	printf("%d\n", sizeof(&a + 1));//4/8 &a是数组的地址，&a+1 是数组的地址+1，跳过整个数组，虽然跳过了数组，
	//还是地址  4/8
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0] + 1));//第二个元素的地址 4/8


	return 0;
}