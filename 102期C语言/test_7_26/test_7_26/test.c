#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//getchar - 函数 - 从键盘读取字符的

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}

//
//int main()
//{
//	char password[20] = {0};
//
//	printf("请输入密码:>");
//	scanf("%s", password);
//
//	//把缓冲区中的内容
//	int tmp = 0;
//	while ((tmp = getchar()) != '\n')
//	{
//		;
//	}
//
//	printf("请确认密码(Y/N):>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr[20] = "xxxxxxxxxxx";
//
//	scanf("%s", arr);
//
//	return 0;
//}
//
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//
//		putchar(ch);
//	}
//	return 0;
//}


//int test()
//{
//	int a = 10;
//	int b = 20;
//	return a, b;//err
//}
//int main()
//{
//	int ret = test();
//	printf("%d\n", ret);
//
//	return 0;
//}


//void test(int arr[])
//{
//	int a = 10;
//	int b = 20;
//
//	arr[0] = a;
//	arr[1] = b;
//}
//
//int main()
//{
//	int arr[2] = {0};
//	test(arr);
//	
//	printf("%d %d\n", arr[0], arr[1]);
//
//	return 0;
//}
//
//void test(int* px, int* py)
//{
//	int a = 10;
//	int b = 20;
//	*px = a;
//	*py = b;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	test(&x, &y);
//	
//	printf("%d %d\n", x, y);//10 20
//
//	return 0;
//}
//


//
//int x = 0;
//int y = 0;
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	x = a;
//	y = b;
//}
//
//int main()
//{
//	test();
//	printf("%d %d\n", x, y);//10 20
//
//	return 0;
//}

////函数声明
//int Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);
//	printf("%d\n", ret);
//
//	return 0;
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}

//exec((vl，v2)，(v3，v4)，v5，v6);

//在一个函数内复合语句中定义的变量在本函数范围内有效（复合语句指函数中的成对括号构成的代码） - err

//void test()
//{
//	{
//		int a = 10;
//	}
//	printf("a=%d\n", a);//err
//}
//int main()
//{
//	return 0;
//}

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//1*1=1
//2*1=2 2*2=4
//3*1=3 3*3=6 3*3=9
//...
//void print_table(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		//打印一行
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_table(n);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
#include <string.h>

//逆序字符串
//void reverse_string(char* str)
//{
//	int len = strlen(str);
//
//	//char* left = str;
//	//char* right = str + len - 1;
//	int left = 0;//'a'
//	int right = len - 1;//'f'
//
//	while (left<right)
//	{
//		char tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
////递归版本
//void reverse_string(char str[])
//{
//	int len = my_strlen(str);
//	char tmp = str[0];
//	str[0] = str[len - 1];
//	str[len - 1] = '\0';
//
//	if(my_strlen(str+1) >= 2)
//		reverse_string(str+1);
//	str[len - 1] = tmp;
//}
//
//int main()
//{
//	char arr[20] = "abcdef";
//	//const char* arr = "abcdef";//err
//	//数组名是首元素的地址
//	//首元素就是char类型
//	//char*
//	reverse_string(arr);
//	printf("%s\n", arr);//期望结果是：fedcba
//
//	return 0;
//}
//
//int DigitSum(unsigned int n)//1234
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	unsigned int num = 1729;
//	int ret = DigitSum(num);
//
//	printf("%d\n", ret);
//	return 0;
//}

//编写一个函数实现n的k次方，使用递归实现


//double Pow(int n, int k)
//{
//	if (k > 0)
//		return n * Pow(n, k - 1);
//	else if (k == 0)
//		return 1.0;
//	else
//		return 1.0 / Pow(n, -k);
//}
//
//
//int main()
//{
//	int n = 2;
//	int k = -3;
//	double ret = Pow(n, k);//库函数中的pow就是计算次方的 - 不要同名
//	printf("%lf\n", ret);
//	return 0;
//}
//
//int arr[5];
//
//int main()
//{
//	//初始化
//	int arr6[5];
//
//	int arr1[20] = {1,2,3};//不完全初始化，剩余的默认初始化为0
//	int arr2[] = { 1,2,3};
//	char arr3[] = "abc";
//	char arr4[] = { 'a', 'b', 'c' };
//	char arr5[] = { 'a', 98, 'c' };
//	
//	return 0;
//}
//
//int main()
//{
//	float sc[5] = {0.0f, 3.0f};
//	//结构体数组也可以创建
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13};
//	//0~9
//	//printf("%d\n", arr[4]);
//	int i = 0;
//	//计算数组元素个数
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//
//	//计算数组元素个数
//	int a = 10;
//	int* p = &a;
//	printf("%p\n", p);
//	printf("%p\n", p+1);
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%p\n", &arr[i]);
//	//}
//	return 0;
//}


//输入一个正整数n(1 ≤ n ≤ 10^9)
//输出一行，为正整数n表示为六进制的结果
#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[20] = { 0 };
//	while (n != 0)
//	{
//		int r = 0;
//		r = n % 6;
//		n = n / 6;
//		
//		arr[i] = r;
//		i++;
//	
//	}
//	int j = 0;
//	for (j = i-1; j >=0; j--)
//	{
//		printf("%d", arr[j]);
//	}
//	return 0;
//}

//小乐乐学校教学楼的电梯前排了很多人，他的前面有n个人在等电梯。
//电梯每次可以乘坐12人，每次上下需要的时间为4分钟（上需要2分钟，下需要2分钟）。
//请帮助小乐乐计算还需要多少分钟才能乘电梯到达楼上。
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	printf("%d", 4 * (n / 12) + 2);
//	return 0;
//}


//每组输入包含两个正整数n和m。(1 ≤ n ≤ 109，1 ≤ m ≤ 109)
//输出描述：
//对于每组输入，输出一个正整数，为n和m的最大公约数与最小公倍数之和。
//int main()
//{
//	long int n = 0;
//	long int m = 0;
//	scanf("%d %d", &n, &m);
//	long int a = n * m;
//	long int t = 0;
//	while (t = n % m)
//	{
//		n = m;
//		m = t;
//	}
//	long int k = m;//最大公约数
//	long int ret = a / k;//最小公倍数
//	printf("%ld\n", k + ret);
//	return 0;
//}


//多组输入，每行输入包括一个字符。
//输出描述：
//针对每行输入，输出该字符是字母（YES）或不是（NO）
//int main()
//{
//	char ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))
//			printf("YES\n");
//		else
//			printf("NO\n");
//		getchar();
//	}
//	return 0;
//}


//多组输入，一个整数（3~20），表示输出的行数，也表示组成正方形边的“*”的数量。
//输出描述：
//针对每行输入，输出用“*”组成的“空心”正方形，每个“*”后面有一个空格。
//* * * *
//*     *
//*     *
//* * * *
//方法一
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		int i = 0;
//		//1. 仔细观察图形  可以看到  第一行  最后一行  以及第一列  最后一列都是*号后面加一个空格
//		//2. 其他位置都是2个空格
//		for (i = 0; i < n; i++)//行数
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)//列数
//			{
//				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//					printf("* ");
//				else
//					printf("  ");//两个空格
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//方法二
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)//行数
//		{
//			int j = 0;
//			if (i == 0 || i == n - 1)//第一行与最后一行
//			{
//				//第一行与最后一行打印*的个数
//				for (j = 0; j < n; j++)
//				{
//					printf("* ");
//				}
//			}
//			else
//			{
//				printf("*");
//				for (j = 0; j < 2 * n - 3; j++)
//				{
//					printf(" ");
//				}
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//}



//输入描述：一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
//输出描述：一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。
//int main()
//{
//	int arr[8] = { 0 };
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum = sum + arr[i];
//	}
//	int max = arr[0];
//	int min = arr[0];
//	for (i = 0; i < 7; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//		if (min>arr[i])
//			min = arr[i];
//	}
//	double ret = (sum - max - min) / 5.0;
//	printf("%.2lf\n", ret);
//	return 0;
//}



//题目有多组输入数据，每一行输入三个a，b，c(0<a, b, c<1000)，作为三角形的三个边，用空格分隔。
//输出描述：针对每组输入数据，输出占一行，如果能构成三角形，等边三角形则输出“Equilateral triangle!”，
//等腰三角形则输出“Isosceles triangle!”，其余的三角形则输出“Ordinary triangle!”，反之输出“Not a triangle!”
//int main()
//{
//	int a, b, c;
//	while ((scanf("%d %d %d", &a, &b, &c)) != EOF)
//	{
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if (a == b && b == c && a == c)
//				printf("Equilateral triangle!\n");
//			else if (a == b || a == c || b == c)
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//			printf("Not a triangle!\n");
//
//	}
//	return 0;
//}