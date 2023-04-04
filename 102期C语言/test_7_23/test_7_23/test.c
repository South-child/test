#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//函数的声明----函数的声明一般要放在头文件中

//方法一：教科书上的方式
//int Add(int x, int y);
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);//函数要先声明后使用
//
//	printf("%d\n", ret);
//	return 0;
//}
//int Add(int x, int y)  //函数定义
//{
//	int z = x + y;
//	return z;
//}

//方法二---一般在工程中
//#include <stdio.h>
//#include "add.h"
//
////导入静态库
//#pragma comment(lib,"add.lib")//封装和隐藏的效果
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);//函数要先声明后使用
//
//	printf("%d\n", ret);
//	return 0;
//}




//函数递归

//练习
//1.接受一个整型值（无符号），按照顺序打印它的每一位。例如：输入1234，输出1 2 3 4
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	print(num);
//	return 0;
//}

//2.编写函数不允许创建临时变量，求字符串的长度。
//#include <stdio.h>
//int my_strlen(char* s)
//{
//	//方法一：循环
//	//int count = 0;
//	//while (*s != '\0')
//	//{
//	//	count++;
//	//	s++;
//	//}
//	//return count;
//
//	//方法二：递归
//	if (*s != '\0')
//	{
//		return 1 + my_strlen(s + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	//求字符串长度
//	char arr[10] = "abcdef";
//	//数组名arr是数组首元素的地址---char*
//	int len = my_strlen(arr);//6
//	printf("%d\n", len);
//	return 0;
//}

//字符指针+1：向后跳1个字节
//char* p;
//p+1 -->向后跳一个字节

//整型指针+1：向后跳4个字节
//int* p;
//p+1 -->向后跳四个字节



//3.求n的阶乘
//int Fac1(int n)//方法一：循环（迭代）
//{
//	int i = 0;
//	int ret1 = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret1 *= i;
//	}
//	return ret1;
//}
//int Fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//求n的阶乘
//	int ret1 = Fac1(n);
//	int ret = Fac(n);
//
//	printf("ret1 = %d\n", ret1);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}


//4.求第n个斐波那契数
int Fib1(int n)//方法一：递归（不建议）
{
	if (n <= 2)
		return 1;
	else
		return  Fib1(n - 1) + Fib1(n - 2);
}
int Fib(n)//方法二：循环（迭代）
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret1 = Fib1(n);//方法一：递归（不建议）
	int ret = Fib(n);//方法二：循环（迭代）

	printf("ret1 = %d\n", ret1);
	printf("ret = %d\n", ret);
	return 0;
}