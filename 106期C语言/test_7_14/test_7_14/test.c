#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//指针
//int main()
//{
//	int a = 10;//向内存申请了4个字节的空间，里边存放10
//	printf("%p\n", &a);//%p --打印地址格式
//	//& -- 取地址操作符
//    //&a -- 取出的是a的第一个字节的地址，也就是a的较小的一个地址
//
//	int* pa = &a;
//	//pa 是一个存放地址的变量，这样的变量就被称为指针变量
//	// * 表示pa是一个指针变量
//	//int 表示pa指向的对象是一个int类型的变量
//
//	char ch = 'w';
//	char* pc = &ch;
//	//* 表示pc是一个指针变量
//	//char 说明pc指向的那个对象是char类型的变量
//
//	*pa = 20;//* -- 解引用操作符
//	printf("%d\n", a);
//
//	*pc = 'b';
//	printf("%c\n", ch);
//	
//	return 0;
//}


//指针变量的大小
//
//int main()
//{
//	//printf("%d\n", sizeof(char*));
//	//printf("%d\n", sizeof(short*));
//	//printf("%d\n", sizeof(int*));
//	//printf("%d\n", sizeof(double*));
//
//	//指针大小在32为平台是4个字节，在64位平台是8个字节;
//
//	char ch = 'w';
//
//	char* pc = &ch;
//
//	printf("%d\n", sizeof(pc));//4
// //pc是一个指针变量
//	return 0;
//}


//结构体 --复杂类型
//可以用来描述复杂对象的类型

//struct -- 结构体关键字

//声明一个学生类型
struct Student
{
	char name[20];
	int age;
	char sex[5];
	char id[12];
};
int main()
{
	//创建的结构体变量
	struct Student s1 = {"张三",20,"男","2022717"};//初始化
	struct Student s2 = {"李四",18,"女","1234567"};


	//打印格式-- . / ->   结构体访问成员操作符
	printf("名字：%s \n年龄：%d \n性别：%s \n学号：%s\n", s1.name, s1.age, s1.sex, s1.id);//.-- 结构体变量 . 成员名

	struct Student* ps = &s1;
	printf("名字：%s \n年龄：%d \n性别：%s \n学号：%s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);

	printf("名字：%s \n年龄：%d \n性别：%s \n学号：%s\n", ps->name, ps->age, ps->sex, ps->id);//-> -- 结构体指针->成员名

	return 0;
}










