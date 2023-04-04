#define _CRT_SECURE_NO_WARNINGS 1
//猜数字的游戏
//1. 生成一个随机数
//2. 猜数字（大、小、对了）
//3. 可以反复玩

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void menu()
//{
//	printf("***************************\n");
//	printf("*******   1. play    ******\n");
//	printf("*******   0. exit    ******\n");
//	printf("***************************\n");
//}
//
//
//void game()
//{
//	int guess = 0;
//	//猜数字游戏的逻辑
//	//1. 生成随机数（1~100）
//	int ret = rand()%100+1;
//	//printf("%d\n", ret);
//	//2. 猜数字
//
//	while (1)
//	{
//		printf("请猜数字:>");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	//设置随机数的生成起点
//	srand((unsigned int)time(NULL));//拿时间戳作为参数
//
//	do
//	{
//		//打印菜单
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);//1 0 
//		switch (input)
//		{
//		case 1:
//			game();//调用游戏函数
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择!\n");
//			break;
//		}
//	} while (input);
//
//	//0 表示假，非0表示真
//
//	return 0;
//}
//
//




//#include <stdio.h>
//int main() {
//	int x = 3;
//	int y = 3;
//	switch (x % 2) {
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}



//写代码将三个整数数按从大到小输出
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	//输入
//	scanf("%d %d %d", &a, &b, &c);
//	//调整
//	int tmp = 0;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	//输出
//	printf("%d %d %d\n", a, b, c);
//
//	return 0;
//}


//写一个代码打印1-100之间所有3的倍数的数字


//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//判断i是否为3的倍数
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//
//	for (i = 3; i <= 100; i+=3)
//	{
//		//判断i是否为3的倍数
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//给定两个数，求这两个数的最大公约数
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);//24 18
//	//求这两个数的最大公约数
//	//辗转相除法
//	int r = 0;
//
//	while (r=a % b)
//	{
//		a = b;
//		b = r;
//	}
//	printf("%d\n", b);
//
//	// 
//	//暴力求解
//	//假设a和b的较小值就是最大公约数
//	//int m = (a > b ? b : a);//m=18
//	//while (1)
//	//{
//	//	if (a % m == 0 && b % m == 0)
//	//	{
//	//		printf("最大公约数是：%d\n", m);
//	//		break;
//	//	}
//	//	m--;
//	//}
//
//
//
//	return 0;
//}
//

//打印1000年到2000年之间的闰年

//
//int main()
//{
//	int y = 0;
//	//1.
//	//for (y = 1000; y <= 2000; y++)
//	//{
//	//	//判断y是否为闰年
//	//	//1. 能被4整除，不能被100整除
//	//	//2. 能被400整除是闰年
//	//	if (y % 4 == 0 && y % 100 != 0)
//	//		printf("%d ", y);
//	//	else if (y % 400 == 0)
//	//		printf("%d ", y);
//	//}
//	//2
//	//for (y = 1000; y <= 2000; y++)
//	//{
//	//	//判断y是否为闰年
//	//	//1. 能被4整除，不能被100整除
//	//	//2. 能被400整除是闰年
//	//	if (y % 4 == 0 && y % 100 != 0)
//	//		printf("%d ", y);
//	//	if (y % 400 == 0)
//	//		printf("%d ", y);
//	//}
//	//3
//	//for (y = 1000; y <= 2000; y++)
//	//{
//	//	//判断y是否为闰年
//	//	//1. 能被4整除，不能被100整除
//	//	//2. 能被400整除是闰年
//	//	// 
//	//	//错误示范
//	//	if (y % 4 == 0)
//	//	{
//	//		if(y%100 != 0)
//	//			printf("%d ", y);
//	//	}
//	//	else if (y % 400 == 0)
//	//		printf("%d ", y);
//	//}
//
//	for (y = 1000; y <= 2000; y++)
//	{
//		//判断y是否为闰年
//		//1. 能被4整除，不能被100整除
//		//2. 能被400整除是闰年
//		// 
//		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//			printf("%d ", y);
//	}
//	return 0;
//}


//打印100~200之间的素数
//素数 - 质数 - 只能被1和他本身整除的数字
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否为素数
//		//如果是素数就打印
//		//拿2~i-1之间的数字取试除i
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j < i; j++)
//		{
//			//拿j试除i
//			if (i % j == 0)
//			{
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);//素数打印
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}





//
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否为素数
//		//如果是素数就打印
//		//拿2~i-1之间的数字取试除i
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			//拿j试除i
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);//素数打印
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//


#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	//只提供奇数
//	for (i = 101; i <= 200; i+=2)
//	{
//		//判断i是否为素数
//		//如果是素数就打印
//		//拿2~i-1之间的数字取试除i
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			//拿j试除i
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);//素数打印
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//

//素数求解的N种境界

//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}



//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//找出10个数中的最大值
//	int max = arr[0];//假设第一个元素就是最大的
//	//拿剩下的9个元素和max比较
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//找出10个数中的最大值
//	int max = 0;//错误示范
//	//拿剩下的9个元素和max比较
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//
//	return 0;
//}


//在屏幕上输出9 * 9乘法口诀表

//1*1=1
//2*1=2 2*2=4
//3*1=3 3*2=6 3*3=9
//....

//9行

int main()
{
	int i = 0;
	//行数
	for (i = 1; i <= 9; i++)
	{
		//打印一行
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			//打印一项
			printf("%d*%d=%-2d ", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}