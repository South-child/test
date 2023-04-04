#define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	1 + 2;//语句 3 
//	;//空语句
//
//	return 0;
//}
#include <stdio.h>
//
//int main()
//{
//	/*int age = 10;
//	if (age > 18)
//	{
//		printf("成年\n");
//		printf("可以谈恋爱\n");
//	}*/
//
//	//int age = 10;
//	//if (18 <= age < 30)//err
//	//{
//	//	printf("青年\n");
//	//}
//
//
//	//if (age < 18)
//	//	printf("青少年\n");
//	//else if (age >= 18 && age < 30)
//	//	printf("青年\n");
//	//else if (age >= 30 && age < 50)
//	//	printf("中年\n");
//	//else if (age >= 50 && age < 80)
//	//	printf("老年\n");
//	//else
//	//	printf("老寿星\n");
//
//
//	//if (age >= 18)
//	//	printf("成年\n");
//	//else
//	//	printf("未成年\n");
//
//	/*if (age >= 18)
//		printf("成年\n");*/
//
//	return 0;
//}

//非0 就是真
//0  就是假


#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 2;
//    if (a == 1)
//    {
//        if (b == 2)
//            printf("hehe\n");
//        else
//            printf("haha\n");
//    }
//    return 0;
//}

//代码风格非常重要
//要养成良好的编码风格
//
//int main()
//{
//	//int a=10;
//	//int a = 10;//
//	//int i = 0;
//	//for(i=0;i<10;i++)
//	//{
//	//}
//	//for (i = 0; i < 10; i++)
//	//{
//
//	//}
//
//	Add(10, 20);
//	char firstname[20];
//	char first_name[20];
//	char FirstName[20];
//
//	return 0;
//}

//
//int test()
//{
//	if (0)
//	{
//		printf("hehe\n");
//		return 3;
//	}
//	printf("haha\n");
//	return -3;
//}
//
//int main()
//{
//	int ret = test();
//	return 0;
//}
//
//

//
//int main()
//{
//	int num = 3;
//	//常量和变量比较相等的时候
//	//常量放在左边 更好一些
//
//	if (5 == num)
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}




//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	//判断
//	if (num % 2 == 1)
//	{
//		printf("%d是奇数\n", num);
//	}
//	else
//	{
//		printf("%d不是奇数\n", num);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		printf("%d ", i);
//		i += 2;
//	}
//
//	//while (i <= 100)
//	//{
//	//	//判断i是否为奇数
//	//	//是奇数就打印
//	//	if (i % 2 == 1)
//	//		printf("%d ", i);
//
//	//	i++;
//	//}
//
//	return 0;
//}
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//
//	int n = 1;
//	switch (day)
//	{
//	case 1:
//		printf("星期1\n");
//		break;
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期天\n");
//		break;
//	}
//
//
//	/*if (1 == day)
//	{
//		printf("星期1\n");
//	}
//	else if (2 == day)
//	{
//		printf("星期2\n");
//	}
//	else if (3 == day)
//	{
//		printf("星期3\n");
//	}*/
//	//...
//	return 0;
//}


//1-5 工作日
//6-7 休息日
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//
//	int n = 1;
//	switch (day)
//	{
//	default:
//		printf("输入数据有误，请输入1-7的数字\n");
//		break;
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//
//	}
//	return 0;
//}


#include <stdio.h>
//
//int main()
//{
//    int n = 1;
//    int m = 2;
//    switch (n)
//    {
//    case 1:m++;
//    case 2:n++;
//    case 3:
//        switch (n)
//        {//switch允许嵌套使用
//        case 1:n++;
//        case 2:
//            m++;n++;
//            break;
//        }
//    case 4:
//        m++;
//        break;
//    default:
//        break;
//    }
//    printf("m = %d, n = %d\n", m, n);
//    return 0;
//}

//
//int main()
//{
//	while (1)
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}
//
//int main()
//{
//
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	i++;
//	//	if (5 == i)
//	//		continue;
//	//	printf("%d ", i);//2 3 4 6...
//	//}
//
//
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	if (5 == i)
//	//		continue;
//	//	printf("%d ", i);
//	//	i++;
//	//}
//	//continue 的作用是：跳过本次循环continue后边的代码
//	//直接到while循环的判断部分
//
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	if (5 == i)
//	//		break;
//
//	//	printf("%d ", i);
//	//	i++;
//	//}
//	//1 2 3 4
//	//break是永久的终止循环的
//
//	return 0;
//}
//

//gets(password);
//printf("%s\n", password);
//
//int main()
//{
//	int ch = 0;
//	char password[20] = {0};
//	printf("请输入密码>:");
//	//scanf("%s", password);
//
//
//	//清理\n
//	//getchar(); //不可取
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//
//	printf("请确认密码(Y/N)>:");
//	ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//
//	//EOF - end of file - 文件结束的标志
//	//getchar读取失败的时候就会返回EOF
//	//1. 返回的字符，本质是字符也是ASCII码值，是整数
//	//2. getchar 函数不仅仅是返回正常字符，还会返回EOF 是-1，所以放在整形变量中
//
//	/*while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}*/
//
//	//ch = getchar();
//	//putchar(ch);
//	
//	//scanf("%c", &ch);
//	//printf("%c\n", ch);
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 4;
//	int c = (b = 5);
//	printf("%d\n", c);
//	printf("%d\n", b);
//
//
//	return 0;
//}

int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch>'9')
		{
			continue;
		}
		putchar(ch);
	}
	return 0;
}