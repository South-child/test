﻿#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//void test()
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	test();
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i + 1;
//		//scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//
//void test2()
//{
//	printf("test2\n");
//}
//void test1()
//{
//	test2();
//}
//void test()
//{
//	test1();
//}
//int main()
//{
//	test();
//	return 0;
//}

//
//
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	//n!= =!*2*3*..*n
//
//	int i = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//
//	//1+2+6 = 9
//	//15
//	//ÔËÐÐÊ±´íÎó
//	printf("%d\n", sum);
//	return 0;
//}



//
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	//n!= =!*2*3*..*n
//
//	int i = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		int ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//
//	//1+2+6 = 9
//	//15
//	//ÔËÐÐÊ±´íÎó
//	printf("%d\n", sum);
//	return 0;
//}

#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", &i);
//
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[9]);
//
//	//0~9
//
//	/*for (i = 0; i <=12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}*/
//
//	return 0;
//}


//
//int main()
//{
//	printf("hehe\n");
//	return 0;
//}

//int ADd(int x, int y)
//{
//	return x + y;
//}

//int Add(int x, int y)
//{
//	return x + y + 1;
//}
//
//int main()
//{
//	int ret = Add(2, 3);
//
//	printf("%d\n", ret);
//
//	return 0;
//}





//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
void fun(int* pa,int sz)
{
	//冒泡法
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (*(pa + j) % 2 == 0 && *(pa + j + 1) % 2 != 0)
			{
				int tmp = *(pa + j);
				*(pa + j) = *(pa + j + 1);
				*(pa + j + 1) = tmp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 1, 2, 13, 14, 8, 3, 5, 4, 7, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	fun(arr,sz);

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}