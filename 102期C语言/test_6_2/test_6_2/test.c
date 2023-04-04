#define _CRT_SECURE_NO_WARNINGS 1

//主函数
#include <stdio.h>
//stdio - 标准输入输出

//int - 整型 -整数的类型
//main函数 - 主函数是程序的入口
//有且仅有一个主函数

int main()
{
	//库函数 - 打印函数 - 输出函数
	printf("hello world\n");
	printf("hello world\n");
	printf("hello world\n");
	printf("hello world\n");
	printf("hello world\n");

	return 0;
}

//void - 明确的告诉我们，main函数不需要参数
//int main(void)
//{
//	return 0;
//}
// 
//main函数其实是可以有参数的
// 

//int main(int argc, char* argv[])
//{
//
//	return 0;
//}
//F10 
// 
//Ctrl + F5
//FN + Ctrl + F5

//过时了
//void main()
//{
//
//}

//int main()
//{
//	int age = 10;
//	int price = 50;
//	double weight = 55.5;//double-双精度浮点型
//
//	return 0;
//}
//
//int main()
//{
//	//如何计算一个类型创建的变量所占空间的大小呢？
//	printf("%d\n", sizeof(char));//1字节
//	printf("%d\n", sizeof(short));//2字节  ---short-->-32878~32767
//	printf("%d\n", sizeof(int));//4字节
//	printf("%d\n", sizeof(long));//4字节														1字节（byte）=8bit
//	printf("%d\n", sizeof(long long));//8字节
//	printf("%d\n", sizeof(float));//4字节
//	printf("%d\n", sizeof(double));//8字节
//
//	//sizeof();
//	//%d - 整数
//	//%c - 字符
//	//printf("%d\n", 100);
//	//printf("%c\n", 100);
//
//	return 0;
//}
//
//int main()
//{
//	char ch = 'e';
//	printf("%c\n", ch);//e
//	printf("%d\n", ch);//101
//
//	//abcdef!@#$ 字符
//	//二进制
//	//'a'
//	//'#'
//	//a-97
//	//b-98
//	//c-99
//	//d-100
//	//e   -101
//	//字符-ASCII码
//	//...
//	//ASCII 编码
//	//
//	return 0;
//}
//
//int main()
//{
//	//age是变量
//	short age = 10;
//	age = 11;
//	printf("%d\n", age);
//
//	//float weight;
//	//char sex = 'm';
//
//	return 0;
//}


//int g = 100;//全局变量
//
//void test()
//{
//	int b = 1000;
//}
//
//int main()
//{
//	int a = 10;//局部变量
//
//	return 0;
//}

//
//int a = 100;//全局变量
//
//int main()
//{
//	int a = 10;//局部变量
//	printf("%d\n", a);//?
//	return 0;
//}
//局部变量和全局变量的名字可以相同，相同时，局部优先

//int main()
//{
//	//2个整数相加
//	int num1 = 0;
//	int num2 = 0;
//	//输入
//	scanf("%d,%d", &num1, &num2);
//	//做加法
//	int sum = num1 + num2;
//	//输出
//	printf("%d\n", sum);
//
//	return 0;
//}