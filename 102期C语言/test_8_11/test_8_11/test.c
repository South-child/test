#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//
//int main()
//{
//	//char ch = 'w';
//	//char* p = &ch;
//	//*p = 'b';
//
//	//const char* str = "abcdef";
//
//	//指针数组
//	//int* arr[10];
//	//char* arr2[4];
//
//	//数组指针 - 指针
//
//	//int (*arr) [5];
//	//int* (*p) [5];
//
//	
//	return 0;
//}



//void test(int arr[])
//{}

//void test(int arr[10])
//{}
//
//void test(int arr[100]) //虽然语法正确，但是不建议
//{}
//
//void test(int* p)
//{}
//
//int main()
//{
//	int arr[10] = {0};
//	test(arr);
//	return 0;
//}


//
//void test2(int* arr[10])
//{}

//
//void test2(int* arr[])
//{}

//
//void test2(int** p)
//{}
//
//int main()
//{
//	int* arr[10] = { 0 };//[int*][int*][int*][int*][int*][int*][int*][int*][int*][int*]
//	test2(arr);
//	return 0;
//}

//void test(int arr[3][5])
//{}//ok

//void test(int arr[][])
//{}//err

//void test(int arr[][5])
//{}
//
//void test(int (*p)[5])
//{}

//void test(int** p)
//{}//err

//int main()
//{
//	int arr[3][5] = {0};
//	test(arr);//
//
//	return 0;
//}

//void print(int* ptr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(ptr + i));
//	}
//}
//
//void print(int ptr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(ptr + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int*p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(p, sz);
//
//	return 0;
//}

//void test(int *p)
//{}
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	int arr[10] = {0};
//
//	test(&a);
//	test(arr);
//	test(p1);
//	test(NULL);//考虑清楚
//
//	return 0;
//}
//
//void test(int **ppa)
//{}
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//	
//	int* arr[5];
//
//	test(ppa);
//	test(&pa);
//	test(arr);
//
//	return 0;
//}


//整型指针
//字符指针
//数组指针
//函数指针变量 - 存放函数的地址

//
//&数组名 - 数组的地址
//数组名 - 数组首元素的地址
//

//
//函数名
//&函数名
//
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);//0x0012ff40 -  int(*)(int,int)
//	//int a = 10;//int
//
//	//int arr[10] = {0};//int [10]
//	////int(*)[10]
//	//int (*parr)[10] = &arr;//parr就是数组指针变量
//
//	//int(*)(int, int)
//
//	//int (*pf)(int , int) = &Add;//pf是用来存放函数的地址 - pf就是函数指针变量
//
//	int (*pf)(int, int) = Add;
//	int ret = Add(2, 3);
//	printf("%d\n", ret);//5
//
//	//ret = (*pf)(4, 5);//9
//	ret = pf(4, 5);
//	printf("%d\n", ret);
//
//	return 0;
//}
//
//int main()
//{
//	//代码是一次函数调用
//	//解析：
//	// 1. 代码中把0强制类型转换为类型为void (*)()的一个函数的地址。
//	// 2. 解引用0地址，就是去0地址处的这个函数，被调用的函数是无参，返回类型是void
//	// <C陷阱和缺陷>
//	//
//	(*( void (*)() ) 0)();
//
//	return 0;
//}

//函数声明
//函数定义
//函数调用
//
//typedef void(* pfun_t)(int) ;
////typedef int int32;
//int main()
//{
//	//这个代码是一次函数声明
//	//声明的函数名signal
//	//signal函数有2个参数，第一个是int类型，第二个是void(*)(int)的函数指针类型
//	//signal函数的返回类型依然是：void(*)(int)的函数指针类型
//	//
//	void (* signal(int, void(*)(int) ) )(int);
//
//	pfun_t signal2(int, pfun_t);
//
//	//void (*)(int) signal(int, void(*)(int));//err
//
//	return 0;
//}
//
//int Add(int x, int y)//int (*)(int, int)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)//int (*)(int, int)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)//int (*)(int, int)
//{
//	return x * y;
//}
//
//int Div(int x, int y)//int (*)(int, int)
//{
//	return x / y;
//}
//
//int main()
//{
//	//int* arr[10];//整型指针的数组
//	//函数指针数组 - 存放函数指针的数组
//
//	//int (*pf1)(int, int) = Add;
//	//int (*pf2)(int, int) = Sub;
//	//int (*pf3)(int, int) = Mul;
//	//int (*pf4)(int, int) = Div;
//
//	//pfArr就是一个函数指针的数组
//	int (* pfArr[4])(int, int) = {Add, Sub, Mul, Div};
//
//	return 0;
//}


void menu()
{
	printf("**********************************\n");
	printf("******* 1.add     2. sub    ******\n");
	printf("******* 3.mul     4. div    ******\n");
	printf("******* 0.exit              ******\n");
	printf("**********************************\n");
	//x&y x|y x>>y x<<y x^y
}
int Add(int x, int y)//int (*)(int, int)
{
	return x + y;
}

int Sub(int x, int y)//int (*)(int, int)
{
	return x - y;
}

int Mul(int x, int y)//int (*)(int, int)
{
	return x * y;
}

int Div(int x, int y)//int (*)(int, int)
{
	return x / y;
}

void Calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;

	printf("请输入2个操作数:>");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("ret = %d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}

//回调函数


//
//int main()
//{
//	int input = 0;
//	do
//	{
//		int x = 0;
//		int y = 0;
//		int ret = 0;
//		menu();
//		printf("请选择:>");//1
//		scanf("%d", &input);
//
//		//转移表 - 《C和指针》
//		int (*pfArr[5])(int, int) = {0, Add, Sub, Mul, Div};
//		                            //0   1   2    3    4
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//		}
//		else if(input>=1 && input<=4)
//		{
//			printf("请输入2个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//	return 0;
//}