#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//һά����Ķ���
//һά���� 
//int main()
//{
//	//����һ������--�������-10�� 
//	int arr[10]={1,2,3};//����ȫ��ʼ��,ʣ�µ�Ԫ��Ĭ�ϳ�ʼ��Ϊ0 
////	char arr2[10]={'a','b'};
////	char arr3[10]="ab";
//	char arr4[]="abcdef"; 
//	printf("%d\n",sizeof(arr4));//7 
//	//sizeof ����arr4��ռ�ռ�Ĵ�С 
//	printf("%d\n",strlen(arr4));//6
//	//strlen �����ַ����ĳ��� --'\0'֮ǰ���ַ����� 
//	return 0;
//}
//1.strlen ��sizeofû��ʲô����
//2.strlen �����ַ������ȵ�--ֻ������ַ����󳤶�--�⺯��-ʹ�õ���ͷ�ļ�
//3.sizeof ������������顢���ʹ�С--��λ���ֽ�--������ 

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a','b','c'};
//	printf("%d\n",sizeof(arr1));//4
//	printf("%d\n",sizeof(arr2));//3
//	printf("%d\n",strlen(arr1));//3
//	printf("%d\n",strlen(arr2));//���ֵ ---arr2��û��'\0'
//	return 0;
//}


//һά�����ʹ��
//������ʹ���±������ʵģ��±��Ǵ�0��ʼ��
//�����С����ͨ������õ� 
//int sz = sizeof(arr)/sizeof(arr[0]); 

//int main()
//{
//	char arr[] = "abcdef";//[a][b][c][d][e][f][\0]
//	//printf("%c\n",arr[3]);
//	int i = 0;
//	int len = strlen(arr);
//	for(i=0;i<len;i++)
//	{
//		printf("%c\n",arr[i]);
//	}
//	return 0;
// } 

//int main()
//{
//	char arr[] = {1,2,3,4,5,6,7,8,9,0};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for(i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
// }

//һά�������ڴ��еĴ洢--������ŵ�--ÿ��Ԫ��֮�����4���ֽ�  
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		printf("&arr[%d] = %p\n",i,&arr[i]); 
//	}
//	return 0; 
//} 

//��ά����Ķ���
//int main()
//{
//	//��ά����Ĵ���
//	int arr1[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
//	int arr2[3][5] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
//	int arr3[][5] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
//	//��ά����ĳ�ʼ������ʡ�����±꣬������ʡ�����±�
//
//	char ch1[4][6] = {'a', 'b'};
//	char ch2[4][6] = { {'a'},{ 'b'} };
//	char ch3[4][6] = {"abc", "def", "qwe"};
//	return 0;
//}


//��ά�����ʹ��
//��ά�����ʹ��Ҳ��ͨ���±�ķ�ʽ��
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9, 0 } };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��ά�������ڴ��еĴ洢
//��ά�������ڴ��еĴ洢--������ŵ�--ÿ��Ԫ��֮�����4���ֽ� 
//int main()
//{
//	/*int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr[0]);
//
//	//int arr[3][5] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9, 0 } };
//	//int* p = &arr[0][0];
//	//int i = 0;
//	//for (i = 0; i < 15; i++)
//	//{
//	//	printf("%d ", *p);
//	//	p++;
//	//}
//
//	//int arr[3][5] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9, 0 } };
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	int j = 0;
//	//	for (j = 0; j < 5; j++)
//	//	{
//	//		printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//	return 0;
//}

//����Խ��
//������±����з�Χ���Ƶġ�
//������±�涨��0��ʼ�ģ������n��Ԫ�أ����һ��Ԫ�ص��±����n-1��
//����������±����С��0�����ߴ���n-1����������Խ������ˣ�����������Ϸ��ռ�ķ��ʡ�



//������Ϊ��������
//���򷽷���ð�ݡ�ѡ�񡢲��롢��������ȵ�
//ʵ��һ�������������ð������
//void bubble_sort(int* arr,int sz)//����
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	//����
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		//ÿ��Ҫ���жԱȵĶ���
//		int flag = 1;//����ÿ���Ѿ�����
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//���˲���ȫ����
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//void Print(int* p,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", p[i]);
//		//printf("%d ", p + i);
//		printf("%d ", *p);
//		p++;
//	}
//}
//int main()
//{
//	int arr[10] = { 5,7,9,4,3,6,2,1,10,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//1.sizeof(������)--������û�н��д��Σ���������ʾ�������飬sizeof(������)���������������Ĵ�С����λ���ֽ�
//	int i = 0;
//	//�������ڴ��ݸ�������ʱ�򣬻ή�������Ԫ�ص�ַ
//	bubble_sort(arr, sz);//����---��������Ϊ����--����Ԫ�صĵ�ַ 
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	Print(arr, sz);//���ú������
//	return 0;
//}


//	//2�����⣺ 
//	//1.sizeof(������)--������û�н��д��Σ���������ʾ�������飬sizeof(������)���������������Ĵ�С����λ���ֽ� 
//	//2.&�������������������������飬&��������ȡ��������������ĵ�ַ 
//	//��1��2����������⣬��������������ʾ������Ԫ�صĵ�ַ 
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr);
//
//	printf("----------------------------------\n");
//
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr[0] + 1);
//	printf("%p\n", &arr + 1);
//
//	return 0;
//}



//������A�е����ݺ�����B�е����ݽ��н�����������һ����
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	printf("arr1[] = {%d,%d,%d,%d,%d}\n", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);
//
//	printf("arr2[] = {%d,%d,%d,%d,%d}\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
//	return 0;
//}