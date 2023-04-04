#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
// int main()
//{
//	int line = 0;
//	scanf("%d", &line);//7
//
//	//上 - 7行
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//打印一行
//		//打印空格
//		int j = 0;
//		for (j = 0; j < line-1-i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//下 - 6行
//	for (i = 0; i < line-1; i++)
//	{
//		//空格打印
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//* 打印
//		for (j = 0; j < (line - 1-i)*2-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//


//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left<right)
//	{
//		//从前向后找到一个偶数
//		while ((left<right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//从后向前找到一个奇数
//		while ((left<right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		//交换
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
////}
//
//int main()
//{
//	//全部奇数
//	//全部偶数
//	//奇数偶数交替
//
//	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int arr[] = { 1,3,5,7,9,11,13,15,17 };
//	int arr[] = { 2,4,6,8,10,12,14,16,18 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}


//int main()
//{
//	//int a = 10;
//	//float f = 10.0f;
//	signed short int a = 0;
//	unsigned short b = 0;
//
//	char a;//有符号？还是无符号？
//	//取决于编译器，大部分的编译器下char 就是signed char
//
//	//short int long  - 都是有符号的
//	//short  == signed short
//	//unsigned short
//	//int    == signed int
//	//unsigned int
//	//long   == signed long
//	//unsigned long
//
//	short c;//
//	signed short d;
//	return 0;
//}
//
//int main()
//{
//	unsigned char c1 = 255;
//	printf("%d\n", c1);
//
//	char c2 = 255;//char --> signed char
//	printf("%d\n", c2);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int arr[10] = {0};
//	printf("%d\n", sizeof(a));//4
//	printf("%d\n", sizeof(int));//4
//
//	printf("%d\n", sizeof(arr));//40
//	printf("%d\n", sizeof(int [10]));//
//
//	int arr2[5];//int [5]
//	return 0;
//}

//void test(void)
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	test();
//	test(100);
//
//	//int sz = sizeof(void);//err
//
//	return 0;
//}

int main()
{
	//int a = -1;
	//10000000000000000000000000000001 -原码
	//11111111111111111111111111111110 -反码
	//11111111111111111111111111111111 -补码

	int a = 0x11223344;

	return 0;
}