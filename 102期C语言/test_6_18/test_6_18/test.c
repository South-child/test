#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//int main()
//{
//	int i = 1;//1.初始化
//
//	while (i <= 10)//2.判断
//	{
//		printf("%d ", i);
//
//		i++;//3.调整
//	}
//
//	return 0;
//}

//for循环出来
//
//int main()
//{
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (5 == i)
//	//		break;
//	//	printf("%d ", i);
//	//}
//	
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (5 == i)
//	//		continue;
//	//	printf("%d ", i);
//	//}
//
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	printf("%d ", i);
//
//	//	i++;
//	//}
//
//	return 0;
//}


//
//F10 - 单步执行（逐过程）
//F11 - 单步执行（逐语句） - 遇到自定函数，想进入函数，你可以按F11
//


//int main()
//{
//	int arr[10] = { 0 };//0~9
//	int i = 0;
//	for (i = 0; i <10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	//初始化，判断，调整 三个部分都省略了
//	//1. 可以省略
//	//2. 判断部分只要省略了，就意味着判断恒为“真”
//	//3. 尽量不要省略
//	/*for (i=0; ; i++)
//	{
//		printf("hehe\n");
//	}*/
//
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//		//j=10
//	}
//
//	return 0;
//}


//int main()
//{
//	int i = 1;
//
//	do
//	{
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);
//		i++;
//	}while (i <= 10);
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//8
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}

//1！+2！+3！ = 
//1 + 2 + 6 = 9
//4!
//5! = 4!*5
//6! = 5!*6
//7! = 6!*7
//n! = (n-1)!*n
//
//int main()
//{
//	int n = 0;
//
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//
//	for (n = 1; n <= 5; n++)
//	{
//		ret = 1; //若在此不进行初始化，ret值保留上一次计算的结果，运行时，最后所得结果错误
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//
//	printf("%d\n", sum);
//
//	//程序可以运行，但是结果是错误的 - 运行时错误
//	//调试 - 一步一步的执行代码，观察代码是不是按照我们期望的效果来走的，如果发现不是是按照期望的效果在走
//	//bug就出现了！
//
//
//	return 0;
//}

//
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}


//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//0~9
//	//在有序数组arr中找7
//	//找到了打印下标，找不到打印：找不到
//	int i = 0;
//	int k = 17;
//	//求数据的元素个数
//	//          40      /   4
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("找到了，下标是：%d\n", i);
//			break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//0~9
//	//在有序数组arr中找7
//	//找到了打印下标，找不到打印：找不到
//	//折半查找(二分查找)
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int k = 17;//被查找的数字
//
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}

//hello world!!!!!!!
//##################
//h################!
//he##############!!
//..
//hello world!!!!!!!
#include <windows.h>
#include <string.h>
#include <stdlib.h>
//
//int main()
//{
//	char arr1[] = "hello world!!!!!!!";
//	char arr2[] = "##################";
//	int len = strlen(arr1);
//	
//	int left = 0;
//	int right = len - 1;
//
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//1000毫秒 - 1秒
//		system("cls");
//		//system是库函数，用来执行系统命令的
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}
//
//


#include <string.h>
//
//int main()
//{
//	int i = 0;
//	char password[20] = {0};
//	//假设密码是：abcdef
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		//两个字符串比较，不能使用==
//
//		if (strcmp(password, "abcdef") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码输入错误，退出程序\n");
//	}
//
//	return 0;
//}

//
//
//int main()
//{
//	//
//	//C99
//	//C++
//	//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	int a = 10;
//
//	a = a + 10;
//	printf("a = %d\n", a);
//
//	int b = 20;
//	//
//	//C语言规定，变量要创建到当前代码块的最前面
//	//missing ; before type
//	//...
//
//	return 0;
//}
//


//void test()
//{
//
//}
//int main()
//{
//again:
//
//	printf("hehe\n");
//	goto again;
//
//	return 0;
//}

//关机程序
//程序运行起来就倒计时关机，1分钟内，输入：我是猪，就取消关机
//
#include <string.h>
#include <stdlib.h>

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//again:
//	printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//



//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}