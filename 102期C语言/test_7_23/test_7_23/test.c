#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//����������----����������һ��Ҫ����ͷ�ļ���

//����һ���̿����ϵķ�ʽ
//int Add(int x, int y);
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);//����Ҫ��������ʹ��
//
//	printf("%d\n", ret);
//	return 0;
//}
//int Add(int x, int y)  //��������
//{
//	int z = x + y;
//	return z;
//}

//������---һ���ڹ�����
//#include <stdio.h>
//#include "add.h"
//
////���뾲̬��
//#pragma comment(lib,"add.lib")//��װ�����ص�Ч��
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);//����Ҫ��������ʹ��
//
//	printf("%d\n", ret);
//	return 0;
//}




//�����ݹ�

//��ϰ
//1.����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�����磺����1234�����1 2 3 4
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	print(num);
//	return 0;
//}

//2.��д��������������ʱ���������ַ����ĳ��ȡ�
//#include <stdio.h>
//int my_strlen(char* s)
//{
//	//����һ��ѭ��
//	//int count = 0;
//	//while (*s != '\0')
//	//{
//	//	count++;
//	//	s++;
//	//}
//	//return count;
//
//	//���������ݹ�
//	if (*s != '\0')
//	{
//		return 1 + my_strlen(s + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	//���ַ�������
//	char arr[10] = "abcdef";
//	//������arr��������Ԫ�صĵ�ַ---char*
//	int len = my_strlen(arr);//6
//	printf("%d\n", len);
//	return 0;
//}

//�ַ�ָ��+1�������1���ֽ�
//char* p;
//p+1 -->�����һ���ֽ�

//����ָ��+1�������4���ֽ�
//int* p;
//p+1 -->������ĸ��ֽ�



//3.��n�Ľ׳�
//int Fac1(int n)//����һ��ѭ����������
//{
//	int i = 0;
//	int ret1 = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret1 *= i;
//	}
//	return ret1;
//}
//int Fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//��n�Ľ׳�
//	int ret1 = Fac1(n);
//	int ret = Fac(n);
//
//	printf("ret1 = %d\n", ret1);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}


//4.���n��쳲�������
int Fib1(int n)//����һ���ݹ飨�����飩
{
	if (n <= 2)
		return 1;
	else
		return  Fib1(n - 1) + Fib1(n - 2);
}
int Fib(n)//��������ѭ����������
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret1 = Fib1(n);//����һ���ݹ飨�����飩
	int ret = Fib(n);//��������ѭ����������

	printf("ret1 = %d\n", ret1);
	printf("ret = %d\n", ret);
	return 0;
}