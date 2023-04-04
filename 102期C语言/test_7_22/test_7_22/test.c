#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//strcpy--字符串拷贝复制函数('\0'也会拷贝过去)
//strlen--计算字符串长度
//int main()
//{
//	char arr1[20] = "xxxxxxxxx";//目标空间
//	char arr2[] = "hello";
//
//	char* ret = strcpy(arr1, arr2);
//
//	printf("%s\n", arr1);
//	printf("%s\n", ret);
//	return 0;
//}
//

//memset---内存操作函数
//void* memset ( void * ptr, int value, size_t num );
//将ptr指向的内存块的第一个字节开始设置为指定值
// value--- 改为什么(不能是字符串)    size_t num---改多少个字节
//int main()
//{
//	char arr[] = "hello bit";//xxxxx bit
//	int n = 5;
//	char *ret = (char*)memset(arr, 'x', n);
//	printf("%s\n", ret);
//
//	return 0;
//}



//函数 - 自定义函数
//
//int get_max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//
//	//求2个数的较大值
//	//int max = get_max(a, 20+1);
//	int max = get_max(a, get_max(4, 5));
//
//	//printf("max = %d\n", max);
//
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//	printf("交换前：a=%d b=%d\n", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("交换后：a=%d b=%d\n", a, b);
//
//	return 0;
//}
//
//

//void Swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("交换前：a=%d b=%d\n", a, b);
//	//函数
//	Swap(a, b);
//	//实参a和b，传给形参x,y的时候，形参将是实参的一份临时拷贝
//	//改变形参变量x,y，是不会影响实参a和b。
//
//	printf("交换后：a=%d b=%d\n", a, b);
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//
//	int* pa = &a;
//	*pa = 20;  //解引用操作
//
//	printf("%d\n", a);
//	return 0;
//}
//
//void Swap1(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//
//void Swap2(int* px, int* py)
//{
//	int z = 0;
//
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前：a=%d b=%d\n", a, b);
//	Swap2(&a, &b); //传址调用---需要对变量本身进行变化时
//	Swap1(a, b); //传值调用---不需对变量本身进行变化时
//	printf("交换后：a=%d b=%d\n", a, b);
//
//	return 0;
//}


//练习
//1.写一个函数可以判断一个数是不是素数
#include <math.h>
//判断n是否为素数
//int is_prime(int n)
//{
//	//试除法
//	//2~n-1
//	//2~sqrt(n)
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	//100-200之间的素数
//	int i = 0;
//	int cnt = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否为素数
//     //is_prime
//     //如果是素数 返回1
//     //不是素数， 返回0
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//			cnt++;
//		}
//	}
//	printf("\ncount = %d\n", cnt);
//
//	return 0;
//}



//2.写一个函数判断1000--2000年之间的闰年 
//int is_leap_year(int y)
//{
////	//方式1
////	//if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
////	//	return 1;
////	//else
////	//	return 0;
////	
////	//方式2
////	return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
//
//	//方式3
//	//	if (y % 4 == 0)
//	//	{
//	//		if (y % 100 != 0)
//	//		{
//	//			return 1;
//	//		}
//	//	}
//	//	if (y % 400 == 0)
//	//		return 1;
//	//	return 0;
//}

//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		//判断y是否为闰年
//		//函数
//		//是闰年，返回1
//		//不是闰年，返回0
//		if (is_leap_year(y) == 1)
//		{
//			printf("%d ", y);
//		}
//	}
//
//	return 0;
//}


//写一个函数，实现一个整形有序数组的二分查找
//方式1
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	//找不到
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 17;
//	//计算数组的元素个数
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//找到了，返回下标
//	//找不到，返回-1
//	int ret = binary_search(arr, k, sz);//TDD - 测试驱动开发
//	
//	if (ret == -1)
//		printf("找不到\n");
//	else
//		printf("找到了,下标是：%d\n", ret);
//
//	return 0;
//}

//方式2
//int binary_search(int arr[], int k, int left, int right) //直接将左下标和右下标传递过来
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	//找不到
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 3;
//	//计算数组的元素个数
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//找到了，返回下标
//	//找不到，返回-1
//	int ret = binary_search(arr, k, 0, 9);//TDD - 测试驱动开发
//
//	if (ret == -1)
//		printf("找不到\n");
//	else
//		printf("找到了,下标是：%d\n", ret);
//
//	return 0;
//}
//


//4.写一个函数，每调用一次这个函数，就会将num的值增加1
//void Add(int* p)
//{
//	*p = *p + 1;
//}
//
//int main()
//{
//	int num = 0;
//
//	Add(&num);
//	printf("%d\n", num);//1
//	Add(&num);
//	printf("%d\n", num);//2
//	Add(&num);
//	printf("%d\n", num);//3
//
//	return 0;
//}
//
//
//int Add(int n)
//{
//	return n + 1;
//}
//
//int main()
//{
//	int num = 0;
//
//	num = Add(num);
//	printf("%d\n", num);//1
//
//	num = Add(num);
//	printf("%d\n", num);//2
//	
//	num = Add(num);
//	printf("%d\n", num);//3
//
//	return 0;
//}
//

//函数的嵌套调用和链式访问

//int main()
//{
//	//嵌套定义是不支持的 - err
//	void test()
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//int main()
//{
//	//int len = strlen("abc");
//	//printf("%d\n", len);
//
//	//printf("%d\n", strlen("abc"));//链式访问
//
//	//char arr1[20] = "xxxxxx";
//	//char arr2[20] = "abc";
//
//	//printf("%s\n", strcpy(arr1, arr2));
//
//printf函数返回的是打印在屏幕上的字符的个数，如果发生错误，将返回负数
//	printf("%d", printf("%d", printf("%d", 43)));  //4321

 /*printf("%d", 43)在屏幕上打印43，两个字符，然后返回2，然后整个式子变成printf("%d", 2)，
接着在屏幕上打印2，一个字符，然后返回1，然后整个式子变成printf("%d",1)，然后打印1。
所以屏幕上打印4321*/
//	return 0;
//}