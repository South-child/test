#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	char ch = 'w';
//	char * pc = &ch;//pc��ָ��һ���ַ�����
//
//	const char* p = "hello bit";//"hello bit"��һ�������ַ���-������ڴ�ĳ�����
//
//	*p = 'w';
//
//	//printf("%c\n", *p);
//	//printf("%s\n", p);
//
//	//������ʽ�������ǣ��ѳ����ַ���"hello bit"�ĵ�һ���ַ�h�ĵ�ַ��ֵ��p
//
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}


//ָ������ - ���ָ�������
//int*
//char*
//short*
//
//int arr[10];//�������� - ������͵�����
//char arr[5];//�ַ����� - ����ַ�������

//
//int main()
//{
//	//char* arr[5];//arr�Ǵ���ַ�ָ�������
//	//int* arr2[4];//arr2�Ǵ������ָ�������
//
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	              //int* int* int* int*
//	int* arr2[4] = {&a, &b, &c, &d};//arr2��������ָ�������
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr2[i]));
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	
//	int* parr[] = { arr1, arr2, arr3 };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", parr[i][j]);//p[i] == *(p+i)
//			//parr[i][j] == *(parr[i]+j)
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	//const char* arr[5] = {"abcdef", "bcdefg", "hehe", "haha", "zhangsan"};
//	//int i = 0;
//	//for (i = 0; i < 5; i++)
//	//{
//	//	printf("%s\n", arr[i]);
//	//}
//	//printf("%s\n", arr[2]);
//
//	//int* arr[5];//ָ������
//	////arr ������������������������Ԫ�صĵ�ַ��int* ���ͱ����ĵ�ַ
//	//int** p = arr;//ok &arr[0]
//	//int** p2 = &arr[3];
//	return 0;
//}
//


//ָ������

//
//����ָ�� - ָ�������ָ��
// 
//int*p; ����ָ�� - ָ�����͵�ָ��
//char*p; �ַ�ָ�� - ָ���ַ���ָ��
//


//int main()
//{
//	int a = 10;
//	int* pi = &a;//���͵ĵ�ַ���������ָ����
//	char ch = 'w';
//	char* pc = &ch;//�ַ��ĵ�ַ������ַ�ָ����
//
//	int arr[10] = {0};
//	int* p = arr;// -��������Ԫ�صĵ�ַ
//
//	//int* parr[10]; //����д������
//	int (*parr)[10] = &arr;//ȡ����������ĵ�ַ, Ӧ�ô�ŵ�����ָ����
//
//	return 0;
//}
//

//
//int main()
//{
//	int arr[10] = {0};
//	//arr;//����������Ԫ�صĵ�ַ
//	//&arr[0];//����Ԫ�صĵ�ַ
//	//&arr;//ȡ������ĵ�ַ
//	int (*p)[10] = &arr;
//
//	printf("%p\n", arr);//int*
//	printf("%p\n", &arr[0]);//int*
//	printf("%p\n", &arr);//����ĵ�ַ    int(*)[10]
//
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr+1);
//
//	return 0;
//}
//
//int main()
//{
//	//����������Ԫ�صĵ�ַ
//	//������2�����⣺
//	//1. sizeof(������)�� ������������Ǳ�ʾ��������ģ�sizeof(������)���������������Ĵ�С����λ���ֽ�
//	//2. &�������� �����������������Ԫ�صĵ�ַ����������ʾ�������飬����ȡ��������������ĵ�ַ
//	//
//	int arr[10] = {0};
//	printf("%d\n", sizeof(arr));
//
//	return 0;
//}

//
//int main()
//{
//	int* arr[10] = {0};
//	int* (*p)[10] = &arr;
//
//	int** p2 = arr;//int*
//
//
//	return 0;
//}


//void print1(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void print2(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}

//����ָ��
//void print3(int (*parr)[10], int sz)//����һ�������ʾ��
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", parr[i]);//parr[i] == *(parr+i)
//	}
//}
//
//void print4(int (*parr)[10], int sz)
//{
//	//*(parr + 0);//parr[0]
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", parr[0][i]);
//		//printf("%d ", (*(parr + 0))[i]);
//		printf("%d ", (*parr)[i]);//(*parr) �൱�� parrָ��������������
//	}
//}
//
//
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print4(&arr, sz);
//
//	//print3(&arr, sz);
//	//print2(arr, sz);
//	//print1(arr, sz);//��ӡarr���������
//
//	return 0;
//}

//��������Ҳ�Ƕ�ά����
//void print1(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////����ָ��
//void print2( int(*p)[5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6,3,4,5,6,7 };
//	//��ά���鴫��
//	//print1(arr, 3, 5);
//	print2(arr, 3, 5);//arr ��������������������Ԫ�ص�ַ
//	return 0;
//}
//
int main()
{
	int* arr[10];

	int(*parr3[10])[5];
	//parr3��һ������,������10��Ԫ��
	//ÿ��Ԫ����һ������ָ�룬��ָ��ָ���������5��Ԫ��
	//ÿ��Ԫ����int.
	return 0;
}