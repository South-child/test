#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//字符串+转义字符+注释
//int main()
//{
//	//字符串 
//	//"abcdef" -- 字符串
//	//这种由双引号引起来的一串字符称为字符串字面值，或者简称字符串。
//
//	//%s -- 打印字符串的格式
//	char ch1[] = "abcdef";
//	//数组中实际存放的是 a,b,c,d,e,f,\0
//	printf("%s\n", ch1);//打印结果是abcdef
//	//注：字符串的结束标志是一个\0的转义字符。在计算字符串长度的时候\0是结束标志，不算作字符串内容。
//	
//	char ch2[] = { 'a','b','c','d','e','f' };
//	//数组中实际存放的是 a,b,c,d,e,f
//	printf("%s\n", ch2);//打印结果是abcdef烫烫烫烫烫abcdef
//	//因为数组ch2中没有字符串结束标志 '\0'
//
//	char ch3[] = { 'a','b','c','d','e','f','\0' };
//	//数组中实际存放的是 a,b,c,d,e,f,\0
//	printf("%s\n", ch3);//打印结果是abcdef
//
//
//	//strlen() 是库函数 -- 求字符串的长度，\0是字符串的结束标志，不算长度
//	printf("%d\n", strlen(ch1));//6
//	printf("%d\n", strlen(ch2));//22 -- 由于数组ch2中没有\0，所以无法计算数组ch2的长度
//	printf("%d\n", strlen(ch3));//6
//	return 0;
//}


//int main()
//{
//	//转义字符
//	printf("c:\test\test.c\n");// \t是转义字符,作用是水平制表符 -- 相当于tab键
//	printf("c:\\test\\test.c\n");// \\ 用于表示一个反斜杠，防止它被解释为一个转义序列符。
//	return 0;
//}

//int main()
//{
//	// \32被解析成一个转义字符
//	printf("%d\n", strlen("c:\test\328\test.c")); 
//	return 0;
//}

//注释
//int main()
//{
//	//C++的注释风格
//	
//	/* C语言的注释风格
//	int a = 20;
//	*/
//
//	return 0;
//}


//选择语句

//int main()
//{
//	int input = 0;
//	printf("要好好敲代码吗（1：要、0：不要）？\n");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("拿到一个好offer\n");
//	}
//	else
//	{
//		printf("回家买红薯\n");
//	}
//	return 0;
//}


//循环语句

//int main()
//{
//	int line = 0;
//	printf("加入比特\n");
//	while (line<20000)
//	{
//		printf("敲代码:%d\n",line);
//		line++;
//	}
//	if(line >= 20000)
//	printf("好offer\n");
//	
//	return 0;
//}


//函数
//int Add(int a, int b)
//{
//	int z = 0;
//	z = a + b;
//	return z;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	//输入
//	scanf("%d%d", &num1, &num2);
//	//计算
//	//交给函数去计算
//	//函数计算后返回一个值，赋值给sum
//	sum = Add(num1, num2);
//	//输出
//	printf("%d\n", sum);
//	return 0;
//}



//数组
//一组相同类型元素的集合
//int main()
//{
//	//定义一个整形数组，最多放10个元素
//	int  arr[10] = {1,2,3,4,5,6,7,8,9,10};//整形数组 -- 一组数
//	//元素是通过数组下标访问的 -- 数组下标是从0开始的；
//	int i = 0;
//	//顺序打印
//	while (i < 10)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	printf("\n");
//	//倒序打印
//	int j = 9;
//	while (j >= 0)
//	{
//		printf("%d ", arr[j]);
//		j--;
//	}
//	char ch[5];//字符数组
//	return 0;
//}



//操作符

//int main()
//{
//	//算数操作符
//	// + - * /
//	//对于除，执行的是整形除法
//	int a = 5 / 2;//商2余1
//	printf("%d\n", a);//只取整数部分，不取小数部分；输出2
//
//	float b = 5 / 2;//计算的结果还是2，如果需要计算结果小数，则需要其中一个数为浮点数
//	printf("%f\n", b);
//
//	b = 5 / 2.0;//如果需要计算结果得到小数，则需要其中一个数为浮点数
//	printf("%f\n", b);
//
//
//	//% - 取模（余）得到的是整除之后的余数
//	int c = 7 % 2;//3....1
//	printf("%d\n", c);//输出1；
//	return 0;
//}

//int main()
//{
//	//移位操作符 --二进制位的
//	//右移操作符  >>
//	//左移操作符  <<
//	int a = 6;
//	int b = a << 1;
//	//移动的是二进制位
//	// a = 6
//	// 00000000 00000000 00000000 00000110
//	// 00000000 00000000 00000000 00001100 -- 左边丢弃右边补0
//	printf("%d\n", b);
//	return 0;
//}