#define _CRT_SECURE_NO_WARNINGS 1

//%s
//%c
//%d
//%p - 按时地址的方式来打印

#include <stdio.h>
//
//int main()
//{
//	//
//	int a = 10;//想内存申请4个字节的空间，里边存放10
//	//printf("%p\n", &a);//& - 取地址操作符
//	int* pa = &a;//0x0012ff44
//	*pa = 20;//*  - 解引用操作符
//
//	printf("%d\n", a);//20
//
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'b';
//	printf("%c\n", ch);
//
//	//
//	//pa 是一个存放地址的变量，这样的变量就被称为指针变量
//	// 
//	//sizeof(int) - 4
//	return 0;
//}

//int main()
//{
//	int a = 10;//[][][][]
//	char* p = &a; //int*
//
//	*p  = 2;
//	//int* pa = &a;
//	//*pa = 20;
//
//	return 0;
//}

//f10
//fn+f10

int main()
{
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));

	return 0;
}
//
//int main()
//{
//	char c = 'w';
//	char* pc = &c;
//	printf("%d\n", sizeof(pc));//4
//	return 0;
//}

//声明一个学生类型
//
//struct Student
//{
//	//
//	char name[20];
//	int age;
//	char sex[5];
//	char id[12];
//};
//
//struct Book
//{
//	//成员变量
//	char name[20];
//	int price;
//	char author[20];
//};
//
//int main()
//{
//	//创建的结构体变量
//	struct Student s1 = {"张三", 20, "男", "20200506"};
//	struct Student s2 = {"lisi", 30, "女", "20200908"};
//	struct Book b1 = { "C语言程序设计", 55, "谭浩强" };
//
//	printf("名字: %s 年龄: %d 性别: %s 学号: %s\n", s1.name, s1.age, s1.sex, s1.id);
//
//	printf("%s %d %s\n", b1.name, b1.price, b1.author);
//	struct Book * pb = &b1;
//	printf("%s %d %s\n", (*pb).name, (*pb).price, (*pb).author);
//	printf("%s %d %s\n", pb->name, pb->price, pb->author);
//
//	//.  - 结构体变量.成员名
//	//-> - 结构指针->成员名
//
//	return 0;
//}
//
//struct Student
//{
//	//
//	char name[20];
//	int age;
//	char sex[5];
//	char id[12];
//};
//int main()
//{
//	//创建的结构体变量
//	/*struct Student s1 = {"张三", 20, "男", "20200506"};
//	struct Student s2 = {"lisi", 30, "女", "20200908"};
//	struct Book b1 = { "C语言程序设计", 55, "谭浩强" };
//
//	printf("名字: %s 年龄: %d 性别: %s 学号: %s\n", s1.name, s1.age, s1.sex, s1.id);
//
//	printf("%s %d %s\n", b1.name, b1.price, b1.author);
//	struct Book * pb = &b1;
//	printf("%s %d %s\n", (*pb).name, (*pb).price, (*pb).author);
//	printf("%s %d %s\n", pb->name, pb->price, pb->author);*/
//
//	//.  - 结构体变量.成员名
//	//-> - 结构指针->成员名
//	struct Student s1 = { 0 };
//	scanf("%s", s1.name);
//	scanf("%d", &(s1.age));
//
//	return 0;
//}

//void test()
//{
//	int a = 20;
//}
//
//int main()
//{
//
//	return 0;
//}

#include <stdio.h>
//
//int main()
//{
//    int a = 0;
//    int c = 0;
//    scanf("%d %d", &a, &c);
//
//    printf("%d\n", (-8 + 22) * a - 10 + c / 2);
//    return 0;
//}
//




#include <stdio.h>
#include <string.h>

//int main()
//{
//    char arr[] = { 'b', 'i', 't' };
//    printf("%d\n", strlen(arr));
//
//    return 0;
//}


//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    printf("%d\n", strlen("c:\test\121"));//err
//    return 0;
//}
//
#include <stdio.h>
//
//int Max(int x, int y)
//{
//	/*int z = 0;
//	z = (x > y ? x : y);
//	return z;*/
//
//	/*if (x > y)
//		return x;
//	else
//		return y;*/
//
//	int z = 0;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//
//	return z;
//}
//
//
//int main()
//{
//	int num1 = 100;
//	int num2 = 20;
//	int m = Max(num1, num2);
//	printf("%d\n", m);
//
//	return 0;
//}
//
//
//#include <stdio.h>
//int sum(int a)
//{
//    int c = 0;
//    static int b = 3;
//    c += 1;
//    b += 2;
//    return (a + b + c);
//}
//int main()
//{
//    int i;
//    int a = 2;
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d,", sum(a));
//    }
//}

#include <stdio.h>

//int main()
//{
//	//输入
//	//int x = 0;
//	//int y = 0;
//	int x, y;
//	//scanf("%d", &x);
//	////计算
//	//if (x < 0)
//	//    y = 1;
//	//else if (x == 0)
//	//    y = 0;
//	//else
//	//    y = -1;
//
//	//输出
//	printf("%d\n", y);
//
//	return 0;
//}