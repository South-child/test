#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//作用域与生命周期
//局部变量的作用域是变量所在的局部范围
//全局变量的作用域是整个工程
//局部变量的生命周期是：进入作用域生命周期开始，出作用域生命周期结束
//全局变量的生命周期是：整个程序的生命周期

//int a = 100;//全局变量
//
//void test()
//{
//	printf("%d\n", a);//100
//}
//int main()
//{
//	int a = 10;//局部变量
//	printf("%d\n", a);//局部优先 -- 10
//	a = 20;
//	test();
//	printf("%d\n", a);//局部优先 - 20
//	return 0;
//}


//int main()
//{
//	int b = 100;
//		{
//			int a = 10;
//			printf("a = %d\n", a);
//			printf("b = %d\n", b);
//		}
//	//printf("a = %d\n", a);//错误，此处不是a的作用域
//	printf("b = %d\n", b);
//	return 0;
//}


//int a = 100;//全局变量
//void test()
//{
//	printf("test: a=%d\n", a);
//}
//int main()
//{
//	test();
//	printf("main: a=%d\n", a);
//
//	return 0;
//}



//声明外部变量----关键字---extern
//extern int g_val;
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}



//int main()
//{
//	{
//		int a = 10;//只在内方块中起作用
//	}
//	return 0;
//}


//常量

//int main()
//{
//	//字面常量--直接写出来
////3.14
//	float a = 3.14;//浮点型的字面常量
//	return 0;
//}
//

//常变量--const修饰的
//int main()
//{
//	//int a = 100;//局部变量
//	//一个变量不能被改变我们就说具有常属性 - 不能被改变的属性
//	//const int a = 100;
//	//a = 200;//错误，a被const修饰，不能被改变
//	//printf("%d\n", a);
//	//const修饰的常变量
//	//const int n = 100;//n不是常量，只是具有常属性，不能被修改而已，本质还是变量
//	//int arr[n] = {0};//数组中，参数必须是常量，n不是常量，还是变量
//	return 0;
//}


//#define定义的标识符常量
//
//#define MAX 100
//
//int main()
//{
//	int a = MAX;
//	int arr[MAX] = {0};
//	printf("a = %d\n", a);
//	//MAX = 200;//错误，此时MAX是常量，赋值号左边应该为变量
//	return 0;
//}


//枚举常量
//性别
//enum Sex 枚举类型
//枚举关键字---enum
//enum Sex
//{
//	//枚举的可能取值 - 枚举常量
//	MALE=3,
//	FEMALE=7,					//枚举常量若没有初始化，则从第一个开始，默认从0一次向下取值，如：0，1，2，3.....
//	SECRET
//};
//int main()
//{
//	//enum Sex s = SECRET;
//
//	printf("%d\n", MALE);//3
//	printf("%d\n", FEMALE);//7
//	printf("%d\n", SECRET);//8
//
//	MALE = 4;//错误，枚举常量--所以MALE是常量
//	return 0;
//}



//字符串+转义字符+注释
//
//#include <string.h>
//
//int main()
//{
//	//char - 字符类型;
//	//字符串类型？---没有字符串类型
//	//'a';
//	//'x';
//	//"abcdef"  -字符串
//	//数组 - 一组数
//	//1 2 3 4 5
//	//int arr[] = { 1,2,3,4,5 };
//	//字符串字面值
//	//%s - 打印字符串的格式
//	//strlen 是库函数 - 求字符串长度的,\0是字符串的结束标志，不算长度
//
//	char ch1[] = "abcdef";
//	//printf("%s\n", ch1);//abcdef
//	printf("%d\n", strlen(ch1));//6
//	
//	char ch2[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
//	//printf("%s\n", ch2);//abcdef
//	printf("%d\n", strlen(ch2));//随机值--因为没有'\0'
//
//	//abcdef\0\0\0\0
//	return 0;
//}


//int main()
//{
//	//printf("%s\n", "c:\test\test.c");
//
//	return 0;
//}
//


//int main()
//{
//	//三字母词;
//	//??) --> ]
//	//??( --> [
//	//printf("%s\n", "????)");
//	//??]
//
//	//printf("%c", 'a');
//	//printf("%c", '\'');
//	//printf("%s\n", "\"");
//	
//	//printf("%s\n", "c:\\test\\test.c");
//	//printf("%c\n", '\065');
//	//\ddd - ddd的8进制数字转换成10进制后的值，作为ASCII值代表的字符
//	
//	//8进制的065转换成10进制是：53
//
//	//printf("%c\n", '5');
//	//printf("%c\n", '\x51');//81 -Q
//
//	return 0;
//}

//int main()
//{
//	//C++注释风格
//	//创建整型变量a，并赋值10
//	int a = 10;
//
//	/* C语言的注释风格
//	int b = 20;
//	*/
//
//	return 0;
//}
//



//选择语句
//
//int main()
//{
//	int input = 0;
//	printf("加入比特\n");
//	printf("要好好敲代码吗(1/0)?");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("好offer\n");
//	}
//	else
//	{
//		printf("卖红薯\n");
//	}
//
//	return 0;
//}
//
//



//循环语句
//20000行
//
//int main()
//{
//	int line = 0;
//	printf("加入比特\n");
//
//	while (line<20000)
//	{
//		printf("敲代码:%d\n", line);
//		line++;
//	}
//
//	if(line >= 20000)
//		printf("好offer\n");
//
//	return 0;
//}
//



//函数
//int Add(int x, int y)
//{
//	int sum = 0;
//	sum = x + y;
//	return sum;
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	//输入
//	scanf("%d %d", &num1, &num2);
//
//	//计算
//	//sum = num1 + num2;
//	sum = Add(num1, num2);
//
//	//盘子 = 张三(20元， 蛋炒饭)
//	//输出
//	printf("%d\n", sum);
//
//	return 0;
//}



//数组
//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//	
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//数组 - 一组数
//	return 0;
//}
//

//
//int main()
//{
//	//char ch[5] = {'a', 'b', 'c'};
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int i = 9;
//	while (i>=0)//---倒序输出
//	{
//		printf("%d ", arr[i]);
//		i--;
//	}
//	//0-9
//	//int i = 0;
//	//while (i < 10)//--正序输出
//	//{
//	//	printf("%d ", arr[i]);
//	//	i++;
//	//}
//	//printf("%d\n", arr[5]);
//	return 0;
//}



//操作符
//int main()
//{
//	float a = 5.0 / 2.0;//商2余1
//	printf("%f\n", a);//2
//
//	return 0;
//}

//int main()
//{
//	//% - 取模(余)得到的是整除之后的余数
//	int a = 7 % 2;//3 ... 1
//	printf("%d\n", a);
//
//	return 0;
//}

//int main()
//{
//	int a = 6;
//	int b = a << 1;
//	//int b = a + 1;
//	printf("%d\n", b);//12
//	printf("%d\n", a);//?
//
//
//	//移动的是二进制位
//	//a=6  -4个字节 - 32bit
//	//00000000000000000000000000000110
//	//00000000000000000000000000001100---左移一位后的数--12
//	return 0;
//}
