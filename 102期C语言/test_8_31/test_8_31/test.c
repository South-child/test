#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//int main()
//{
//	//char ch = 'w';
//
//	//char* pc = &ch;
//	//const char* ps = "abcdef";
//
//	////ָ������ - ���ָ�������
//	//int* arr[5];
//	//char* arr2[5];
//
//	//����ָ��  - p2
//	//int arr[10];
//	//int * p = arr;  //int*
//	//int (*p2)[10] = &arr; //int(*)[10]
//
//	//printf("%p\n", arr);//��������������Ԫ�صĵ�ַ
//	//printf("%p\n", &arr);//&arr ��������ĵ�ַ
//
//	//
//	//����ָ��
//	//ָ�� - ָ������
//	//
//
//	return 0;
//}

//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//printf("%p\n", Add);
//	//printf("%p\n", &Add);
//	
//	//pf��һ������ָ��
//	int (*pf)(int x, int y) = Add;
//
//	//
//	//int sum = (*pf)(2, 3);
//	int sum = pf(2, 3);
//	//int sum = Add(2, 3);
//
//	printf("%d\n", sum);
//
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}

//int main()
//{
//	//int (*pA)(int, int) = Add;
//	//int (*pS)(int, int) = Sub;
//	//����ָ������
//	int (*pArr[5])(int, int) = {Add, Sub};//pArr���Ǻ���ָ�������
//
//	//ָ����ָ�������ָ��
//	//p��һ������ָ��
//	//��ָ��ָ����һ������
//	//�����ÿ��Ԫ���Ǻ���ָ��
//	//(p��һ��ָ����ָ�������ָ��)
//
//	int (*(*p)[5])(int, int) = &pArr;
//	return 0;
//}


//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//void Calc(int(*pf)(int, int))
//{
//	int ret = pf(3, 5);
//	printf("%p\n", pf);
//
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	//Calc(Add);
//	Calc(Sub);
//	printf("%p\n", Sub);
//	return 0;
//}




//
//void bubble_sort(int arr[], int sz)
//{
//	//����
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//����
//	bubble_sort(arr, sz);
//
//	//��ӡ
//	print_arr(arr, sz);
//
//	return 0;
//}


//void qsort(void* base, 
//	       size_t num, //�������Ԫ�ظ���
//	       size_t width, //һ��Ԫ�صĴ�С����λ���ֽ�
//	       int(* cmp)(const void* e1, const void* e2) //cmpָ����ǣ�����ʱ�������Ƚ�2��Ԫ�صĺ���
//);
//
//int main()
//{
//	int a = 10;
//	float f = 5.5f;
//
//	//char* p = &a;//int*
//	//char* p2 = &f;//float*
//
//	//
//	//void*  - �޾������͵�ָ��
//	//�ܹ������������͵ĵ�ַ
//	//ȱ�㣺���ܽ�������,����+-���������ܽ�����
//	//
//	//int* p1 = &a;
//	//p1++;
//	//p1 = p1 + 1;
//
//	//void* p3 = &a;//int*
//	//void* p4 = &f;//float*
//
//
//	return 0;
//}

#include <stdlib.h>
#include <string.h>
//
//
////�Ƚ�2�����ͺ���
//int cmp_int(const void* e1, const void*e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	//��ӡ
//	print_arr(arr, sz);
//}
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_by_name(const void*e1, const void*e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//int cmp_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age -((struct Stu*)e2)->age;
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan", 15}, {"lisi", 30},{"wangwu", 10}};
//
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	//������������
//	//qsort(s, sz, sizeof(s[0]), cmp_by_name);
//
//	//��������������
//	qsort(s, sz, sizeof(s[0]), cmp_by_age);
//}
//
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
////ʹ�ûص�����ʵ��һ��ͨ�õ�ð��������
//
//void BubbleSort(void* base, size_t num, size_t width, int (*cmp)(const void*, const void*))
//{
//	size_t i = 0;
//	//����
//	for (i = 0; i < num - 1; i++)
//	{
//		//�ȽϵĶ���
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			//base[j] ==> *(base+j)
//			if (cmp((char*)base+j*width, (char*)base+(j+1)*width)>0)
//			{
//				//����
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
////�����Զ����BubbleSort();
//void test3()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz, sizeof(arr[0]), cmp_int);
//	//��ӡ
//	print_arr(arr, sz);
//}
//
////�����Զ����BubbleSort() ����ṹ��
//void test4()
//{
//	struct Stu s[3] = { {"zhangsan", 15}, {"lisi", 30},{"wangwu", 10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//������������
//	//BubbleSort(s, sz, sizeof(s[0]), cmp_by_name);
//
//	//��������������
//	BubbleSort(s, sz, sizeof(s[0]), cmp_by_age);
//}
//
//
//
//int main()
//{
//	//����������������
//	//test1();
//	// 
//	//����ṹ������
//	//test2();
//
//	//�����Զ����BubbleSort();
//	//test3();
//
//	test4();
//	return 0;
//}
//
//


int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//������a��������sizeof�ڲ�����������ʾ�������飬���������������Ĵ�С
	printf("%d\n", sizeof(a + 0));//a��ʾ��Ԫ�صĵ�ַ��a+0������Ԫ�صĵ�ַ����ַ�Ĵ�С��4/8�ֽ�
	printf("%d\n", sizeof(*a));   //a��ʾ��Ԫ�صĵ�ַ��*a ������Ԫ�� ==> a[0] ,��С����4
	//*a <==> *(a+0) <==> a[0]
	printf("%d\n", sizeof(a + 1));//a��ʾ��Ԫ�صĵ�ַ,a+1�ǵڶ���Ԫ�صĵ�ַ����С����4/8
	printf("%d\n", sizeof(a[1])); //a[1] ���ǵڶ���Ԫ�� - 4
	printf("%d\n", sizeof(&a));   //&a - ����ĵ�ַ - 4/8 - int(*)[4]
	printf("%d\n", sizeof(*&a));  //*&a - &a������ĵ�ַ��������ĵ�ַ�������õ��������飬���Դ�Сʱ��16
	//printf("%d\n", sizeof(a));//16

	printf("%d\n", sizeof(&a + 1));//4/8 &a������ĵ�ַ��&a+1 ������ĵ�ַ+1�������������飬��Ȼ���������飬
	//���ǵ�ַ  4/8
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0] + 1));//�ڶ���Ԫ�صĵ�ַ 4/8


	return 0;
}