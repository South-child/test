#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//
//	//char ch[5] = { 0 };
//	//printf("%d\n", &arr[9] - &ch[0]);//err
//
//	//printf("%d\n", &arr[9] - &arr[0]);//?
//	//printf("%d\n", &arr[0] - &arr[9]);//?
//	//ָ��-ָ���ǰ��������ָ��ָ��ͬһ������
//	//ָ��-ָ�� �õ������ֵľ���ֵ��ָ���ָ��֮��Ԫ�صĸ���
//
//
//	/*int *p = &arr[9];
//
//	printf("%p\n", p);
//	printf("%p\n", p-2);*/
//
//	return 0;
//}
//

//���ַ�������

#include <string.h>

//int my_strlen(char* s)
//{
//	int count = 0;
//	while (*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}
//
//int my_strlen(char* s)
//{
//	int count = 0;
//	char* start = s;
//
//	while (*s != '\0')
//	{
//		s++;
//	}
//
//	return s-start;
//}
//
//
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}

//
//
//int main()
//{
//	int arr[10] = {0};
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		*(p + i) = i;
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//int* p = &arr[5];
//	//int* q = arr;
//
//	//int sz = sizeof(arr);
//	//printf("%d\n", sz);
//
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr[0]);
//	
//	//������ȷʵ����Ԫ�صĵ�ַ
//	//������2�����⣺
//	//1. sizeof(������)  - �����������������Ԫ�صĵ�ַ���Ǳ�ʾ��������ģ�������������������Ĵ�С����λ�����ֽ�
//	//2. &������ - �����������������Ԫ�صĵ�ַ���Ǳ�ʾ��������ģ��õ�������������ĵ�ַ
//	//
//
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);//����������Ԫ�صĵ�ַ
//	printf("%p\n", arr+1);
//
//	printf("%p\n", &arr[0]);//��һ��Ԫ�صĵ�ַ
//	printf("%p\n", &arr[0]+1);
//
//	printf("%p\n", &arr);//ȡ����������ĵ�ַ
//	printf("%p\n", &arr + 1);
//
//	return 0;
//}

//
//
//int main()
//{
//	int a = 10;//4byte
//	int * p = &a;
//	int** pp = &p;//pp���Ƕ���ָ��
//
//	**pp = 20;
//
//	printf("%d\n", a);//20
//
//	//int** * ppp = &pp;//ppp��������ָ��
//
//	return 0;
//}
//
//int main()
//{
//	int arr[10];//�������� - ������͵����������������
//	char ch[5];//�ַ����� - ����ַ�����������ַ�����
//	//ָ������ - ���ָ����������ָ������
//	//int* ����ָ�������
//	//char* �ַ�ָ�������
//
//	int* parr[5];//����ָ�������
//	char* pc[6];//�ַ�ָ�������
//
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	int* arr[3] = {&a, &b, &c};
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));
//	}
//
//	//int* pa = &a;
//	//int* pb = &b;
//	//int* pc = &c;
//
//	return 0;
//}


//�ṹ������
//struct Book
//{
//	char name[20];
//	char author[15];
//	float price;
//}b1, b2;//b1, b2 ��ȫ�ֱ��� - ��̬��
//
//struct Book b3;
//
//struct Point
//{
//	int x;
//	int y;
//}p1, p2;//p1,p2 ��ȫ�ֱ���
//
//typedef struct Stu
//{
//	char name[20];
//	int age;
//	char id[20];
//}Stu;


//int main()
//{
//	struct Stu s1 = {"����", 20, "2020010506"};
//	Stu s2 = {"����", 30, "2021020506"};
//
//	/*struct B
//	{
//		char name[20];
//		char author[15];
//		float price;
//	}sb;*/
//
//	struct Book b;//�ֲ����� - ջ��
//	struct Point p = {10, 20};//�ֲ�����
//
//	return 0;
//}
//
//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//
//struct T
//{
//	struct S s;
//	char name[20];
//	int num;
//};
//
//int main()
//{
//	struct T t = { {100,'c', 3.14}, "lisi", 30 };
//	return 0;
//}
//
//
//struct S
//{
//	int a;
//	char c;
//	double d;
//};

//struct T
//{
//	struct S s;
//	char name[20];
//	int num;
//};
//
//int main()
//{
//	struct T t = { {100, 'w', 3.14}, "zhangsan", 200 };
//	printf("%d %c %f %s %d\n", t.s.a, t.s.c, t.s.d, t.name, t.num);
//
//	struct T* pt = &t;
//	
//	printf("%d %c %f %s %d\n", pt->s.a, pt->s.c, pt->s.d, pt->name, pt->num);
//
//	return 0;
//}

//
//struct S
//{
//	int arr[100];
//	int num;
//	char ch;
//	double d;
//};
//
//void print1(struct S ss)
//{
//	printf("%d %d %d %d %c %lf\n", ss.arr[0], ss.arr[1], ss.arr[2], ss.num, ss.ch, ss.d);
//}
//
//void print2(struct S * ps)
//{
//	printf("%d %d %d %d %c %lf\n", ps->arr[0], ps->arr[1], ps->arr[2], ps->num, ps->ch, ps->d);
//}
//
//int main()
//{
//	struct S s = { {1,2,3,4,5}, 100, 'w', 3.14};
//	print1(s);
//	print2(&s);//4���ֽ�
//	return 0;
//}


//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	c = Add(a, b);
//
//	return 0;
//}




//дһ����������������һ���ַ��������ݡ�
//#include <string.h>
//void fun(char* arr, int len)
//{
//	char arr2[100] = { 0 };
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		arr2[i] = *(arr + len - 1 - i);
//	}
//	printf("%s", arr2);
//}
//
//int main()
//{
//	char arr1[100] = { 0 };
//	gets(arr1);
//	int len = strlen(arr1);
//
//	fun(arr1, len);
//
//	return 0;
//}


//��ӡ����

//int main()
//{
//	int row = 0;
//	scanf("%d", &row);//����
//	int i = 0;
//	//�ϰ벿��
//	for (i = 0; i < row; i++)//������
//	{
//		int j = 0;//�ո�
//		for (j = 0; j < row - i - 1; j++)
//		{
//			printf(" ");
//		}
//		int k = 0;//*��
//		for (k = 0; k < 2 * i + 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//�°벿��
//	for (i = 0; i < row - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		int k = 0;
//		for (k = 0; k < 2*(row-1-i)-1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
//1  2	3	4	5	6...Ǯ
//1  3  5   7   9   11...ƿ��
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int count = 0;//ͳ�ƿ��Ժ���ˮ������
//	if (money <= 0)
//	{
//		printf("count = 0\n");
//	}
//	else
//	{
//		printf("count = %d\n", 2 * money - 1);
//	}
//	return 0;
//}