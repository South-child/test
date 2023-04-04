#define _CRT_SECURE_NO_WARNINGS 1

//头文件
#include <stdio.h>
//stdio -- 标准输入输出

//主函数
//int -- 整形 -- 整数的类型
//main函数是程序的入口
//一个工程中 main函数有且只有一个
//int main()
//{
//	//库函数 -- 打印函数 -- 输出函数
//	printf("hello world\n");
//	return 0;
//}

//数据类型
//int main()
//{
//	//整形
//	int age = 10;
//	int price = 50;
//  //字符型
//	char ch = 'w';
//	//浮点型
//	double weight = 55.5;//双精度浮点型
//
//	//计算一个类型创建的变量所占空间的大小 -- sizeof()
//	printf("char：%d\n", sizeof(char));      // 1
//	printf("short：%d\n", sizeof(short));	   // 2
//	printf("int：%d\n", sizeof(int));       // 4
//	printf("long：%d\n", sizeof(long));      // 4
//	printf("long long：%d\n", sizeof(long long)); // 8
//	printf("float：%d\n", sizeof(float));     // 4
//	printf("double：%d\n", sizeof(double));    // 8
//
//
//	return 0;
//}


//变量、常量

//int main()
//{
//	//变量 -- 如 age
//	short age = 10;
//	age = 11;
//	float weight;
//	char sex = 'm';
//
//	return 0;
//}

//int a = 100; //全局变量
//int main()
//{
//	int a = 20;//局部变量
//	printf("%d\n", a);//就近原则，打印局部变量
//	//局部变量和全局变量的名字可以相同，相同时，局部优先打印。(不建议相同)
//	return 0;
//}

//变量的使用
//int main()
//{
//	//2个整数相加
//	int num1 = 0;
//	int num2 = 0;
//	//输入 -- scanf()
//	scanf("%d%d", &num1, &num2);
//	//做加法
//	int sum = num1 + num2;
//	//输出
//	printf("%d\n", sum);
//	return 0;
//}


//作用域与生命周期

//局部变量的作用域 -- 变量所在的局部范围
//int main()
//{
//	{
//		int a = 10;
//	}
//	//a的作用域在小括号中
//	//printf("%d\n", a);
//
//	return 0;
//}

//全局变量的作用域 -- 整个工程

//int a = 100;
//
//void test()
//{
//	printf("test: a = %d\n", a);
//}
//int main()
//{
//	test();
//	printf("main: a = % d\n", a);
//	return 0;
//}

//声明外部变量
//extern int g_val;
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}


//常量
//字面常量
//const修饰的常变量
// #define定义的标识符常量
// 枚举常量
//int main()
//{
//	//字面常量
//	3.14;
//	100;
//
//	//const修饰的常变量
//	//一个变量不能被改变，我们就说具有常属性 -- 不能被改变的属性
//	//const int a = 10;
//	//a = 20;
//
//	//const修饰的常变量
//	const int n = 100;//n不是常量，本质还是变量，只是具有常属性，不能被修改而已
//	//int arr[n] = { 0 };//数组
//	return 0;
//}

//#define定义的标识符常量

//#define MAX 100
//
//int main()
//{
//	int a = MAX;
//	printf("a = %d\n", a);
//	//MAX = 200;不可修改
//	int arr[MAX] = { 0 };
//	return 0;
//}


//枚举常量
//enum sex -- 枚举类型
//enum -- 枚举关键字
enum Sex
{
	//枚举的可能取值 - 枚举常量
	//枚举常量的取值，默认是第一个从零开始，依次往下递增的
	//枚举常量可以赋初值
	MALE = 3,
	FEMALE,
	SECRET
};
int main()
{
	enum Sex s = MALE;//枚举类型定义的变量
	//MALE = 4;错误，枚举常量可以赋初值，但不可被修改
	printf("%d\n", MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);

	return 0;
}

