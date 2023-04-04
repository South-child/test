#define _CRT_SECURE_NO_WARNINGS 1
//小乐乐与进制转换
// 
#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	int arr[50] = { 0 };
//	//输入
//	scanf("%d", &num);
//	//转换
//	int i = 0;
//	while (num)
//	{
//		arr[i] = num % 6;
//		i++;
//		num = num / 6;
//	}
//	//输出
//	for (i--; i >= 0; i--)
//	{
//		printf("%d", arr[i]);
//	}
//
//	return 0;
//}

//小乐乐排电梯
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	//输入
//	scanf("%d", &n);
//	//计算
//	int t = n / 12 * 4 + 2;
//	//输出
//	printf("%d\n", t);
//
//	return 0;
//}

//小乐乐与欧几里得
//#include <stdio.h>
//
///*
//int main()
//{
//long long n = 0;
//long long m = 0;
////输入
//scanf("%d %d", &n, &m);
////计算
////1. 计算最大公约数
//long long max = (m>n)?(n):(m);
//while(1)
//{
//if((m%max==0) && (n%max==0))
//break;
//max--;
//}
//
////2. 计算最小公倍数
//long long min = (m>n)?(m):(n);
//while(1)
//{
//if((min%m==0)&&(min%n==0))
//{
//break;
//}
//min++;
//}
//
////3. 求和
//long long sum = min+max;
////打印
//printf("%lld\n", sum);
//
//return 0;
//}
//*/
//
//int main()
//{
//	long long n = 0;
//	long long m = 0;
//	//输入
//	scanf("%d %d", &n, &m);
//	//计算
//	long long n2 = n;
//	long long m2 = m;
//
//	//1. 计算最大公约数
//	long long c = 0;
//	while (c = m2 % n2)
//	{
//		m2 = n2;
//		n2 = c;
//	}
//
//	//2. 最小公倍数
//	long long min = m * n / n2;
//	printf("%lld", min + n2);
//
//	return 0;
//}


//BC35-判断字母
//#include <stdio.h>
//
//int main()
//{
//	//多组输入
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//		getchar();//处理\n
//	}
//
//	return 0;
//}

//空心正方形图案

#include <stdio.h>

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 1; i <= n; i++)
		{
			//打印一行
			int j = 0;
			for (j = 1; j <= n; j++)
			{
				if (i == 1 || i == n || j == 1 || j == n)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}


//公务员面试

//#include <stdio.h>
//
//int main()
//{
//	//输入
//	int i = 0;
//	int sc = 0;
//	int sum = 0;
//	int max = 0;//假设0就是最高分
//	int min = 100;//假设100就是最低分
//
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &sc);
//		sum += sc;
//
//		if (sc > max)
//			max = sc;
//
//		if (sc < min)
//			min = sc;
//	}
//
//	//计算
//	double avg = (sum - max - min) / 5.0;
//	//输出
//	printf("%.2lf\n", avg);
//
//	return 0;
//}


//三角形判断

//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	//while(scanf("%d %d %d",&a, &b, &c) != EOF)
//
//	while (~scanf("%d %d %d", &a, &b, &c))
//	{
//		if ((a + b > c) && (a + c > b) && (b + c > a))
//		{
//			//是不是等边
//			if (a == b && b == c)
//			{
//				printf("Equilateral triangle!\n");
//			}
//			else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
//			{
//				printf("Isosceles triangle!\n");
//			}
//			else
//			{
//				printf("Ordinary triangle!\n");
//			}
//		}
//		else
//		{
//			printf("Not a triangle!\n");
//		}
//	}
//
//	return 0;
//}





//#include <stdio.h>
//int main()
//{
//    char str[] = "hello bit";
//    //[h e l l o _ b i t \0]
//
//    printf("%d %d\n", sizeof(str), strlen(str));
//    //10 9
//    return 0;
//}




//void test(int arr[], int sz)
//void test(int * arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", arr[i]); //arr[i] --> *(arr+i)
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	test(arr, sz);//数组传参传过去的是数组首元素的地址
//	return 0;
//}



//将数组A中的内容和数组B中的内容进行交换。
//
//void exchange(int a[], int b[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;
//	}
//}
//
//int main()
//{
//	int a[] = { 1,3,5,7,9 };
//	int b[] = { 2,4,6,8,0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	exchange(a, b, sz);
//
//	return 0;
//}


//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
//
//void Init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*(arr + i) = i;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[], int sz)
//{
//	int l = 0;
//	int r = sz - 1;
//
//	while (l<r)
//	{
//		int tmp = arr[l];
//		arr[l] = arr[r];
//		arr[r] = tmp;
//		l++;
//		r--;
//	}
//}
//
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz);//初始化 0~9
//	Print(arr, sz);//打印
//	Reverse(arr, sz);//逆置
//	Print(arr, sz);//打印 9~0
//
//	return 0;
//}



////下标引用操作符[]
//int main()
//{
//	int a[10] = { 0 };
//	a[4] = 10;
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int i = 0;
//	printf("%d\n", arr[4]);
//	printf("%d\n", 4[arr]);
//
//
//	//a + b;
//	//b + a;
//	//arr[4] -- > *(arr+4) --> *(4+arr) --> 4[arr]
//	//arr[4];  *(arr+4)
//
//	//for (i = 0; i < 5; i++)
//	//{
//	//	printf("%p --- %p\n", &arr[i], arr+i);//arr+i - 就是数组arr中，下标为i的元素的地址
//	//}
//
//	return 0;
//}

//函数调用--()
//#include <string.h>
//
//void test()
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	//printf("%d\n", strlen("abc"));
//	//printf("%u\n", strlen("abc"));
//	test();
//	return 0;
//}

//结构体操作符
//.
//->
//自定义类型
//
//#include <string.h>
//
//struct Book
//{
//	char name[20];
//	float price;
//	char id[10];
//};
//
//
//void print1(struct Book b)
//{
//	printf("书名: %s\n", b.name);
//	printf("价格: %f\n", b.price);
//	printf("书号: %s\n", b.id);
//
//	//*(b.name);
//}
//
//void print2(struct Book* pb)
//{
//	/*printf("书名: %s\n", (*pb).name);
//	printf("价格: %f\n", (*pb).price);
//	printf("书号: %s\n", (*pb).id);*/
//
//	printf("书名: %s\n", pb->name);
//	printf("价格: %f\n", pb->price);
//	printf("书号: %s\n", pb->id);
//}
//
//int main()
//{
//	struct Book b = {"C语言程序设计", 55.5f, "C20190201"};
//	print2(&b);
//
//	//print1(b);
//
//	//b.price = 100.0f;
//	////字符串拷贝 -strcpy - 库函数 - string.h
//	//strcpy(b.name, "数据结构");
//	//print1(b);
//
//	//结构成员访问操作符
//	//结构变量.成员名
//	//结构体指针->成员名
//	// 
//	//(*结构体指针).成员名
//
//	return 0;
//}