#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//
int main()
{
	char a = 3;//a��1byte - 8bit
	//00000000000000000000000000000011
	//00000011 - a
	char b = 127;//b��1byte - 8bit
	//00000000000000000000000001111111
	//01111111 - b
	
	//
	//a��b����char���ͣ������С�Ķ���1byte��������������ʱ��Ҫ������������
	//
	//00000000000000000000000000000011
	//00000000000000000000000001111111
	//00000000000000000000000010000010
	//
	char c = a + b;
	//10000010 - c
	//11111111111111111111111110000010
	//11111111111111111111111110000001
	//10000000000000000000000001111110
	//-126
	
	
	printf("%d\n", c);
	//

	return 0;
}


//int main()
//{
//	char a = 0xb6;//11111111111111111111111111010110
//	short b = 0xb600;
//	int c = 0xb6000000;
//
//	if (a == 0xb6)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//
//	if (c == 0xb6000000)
//		printf("c");
//
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));//1
//	printf("%u\n", sizeof(+c));//4
//	printf("%u\n", sizeof(-c));//4
//
//	return 0;
//}

//int main()
//{
//	int a = 4;
//	float f = 4.5f;
//	float r = a + f;
//
//	return 0;
//}

//int main()
//{
//	//int a = 2;
//	//int b = 4;
//	//int c = a + b + 3;
//
//	//int c = 3;
//	//int e = --c;
//	//int d = c + e;
//
//	return 0;
//}


//
//int main()
//{
//	int a = 1;
//	int d = 0;
//	d = (++a) + (++a) + (++a);//�������
//
//	printf("%d\n", d);
//
//	return 0;
//}
//
//

//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun() * fun();
//	printf("%d\n", answer);//������٣�
//	return 0;
//}
//

//
//int main()
//{
//	int a = 10;
//	int * pa = &a;
//
//	char c = 'w';
//	char * pc = &c;
//
//
//
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int*  pa = &a;
//	char* pc = &a;
//	
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//
//	printf("%p\n", pa+2);
//	printf("%p\n", pc+2);
//
//	//ָ�����͵�����2��
//	//ָ�����;����ˣ�ָ��+-������ʱ��Ĳ���(ָ��+-������ʱ�����������ֽ�)
//	//int* ָ�� +1 ����4���ֽ�
//	//char* ָ��+1 ����1���ֽ�
//	
//	//int a = 0x11223344;
//	//char* pc = &a;//int*
//	//*pc = 0;
//
//	//int*pa = &a;
//	//*pa = 0;
//	//ָ�����͵�����1��
//	//ָ�����;�����ָ������ò�����ʱ��һ�η��ʼ����ֽڣ������ڴ�Ĵ�С��
//	//char* ָ������÷���1���ֽ�
//	//int* ָ������÷���4���ֽ�
//
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 0 };//40���ֽ�
//
//	char* pa = arr;//int*
//	int i = 0;
//	for (i = 0; i < 40; i++)
//	{
//		*(pa + i) = 1;
//	}
//
//	//int* p = arr;//&arr[0] - int*
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = 1;//0x00 00 00 01
//	//}
//
//
//	return 0;
//}
//
//int main()
//{
//	//int* p;//û�г�ʼ��-��߷ŵ������ֵ
//
//	//*p = 20;//ͨ��p�д�����ֵ��Ϊ��ַ���ҵ�һ���ռ䣬����ռ䲻�������ǵ�ǰ�ĳ���
//	////������˷Ƿ����ʣ�p����Ұָ��
//
//	//ָ��Խ�����Ұָ�������
//	int arr[10] = 0;
//	int i = 0;
//	int* p = arr;
//
//	for (i = 0; i <= 10; i++)
//	{
//		*p = i;
//		p++;
//	}
//
//	return 0;
//}


//
//int* test()
//{
//	int a = 10;
//	return &a;//int*
//}
//
//int main()
//{
//	int* p = test();
//
//	//printf("hehe\n");
//
//	printf("%d\n", *p);
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	printf("%p\n", &a);
//	printf("%p\n", &b);
//
//
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//int* p = &a;//��ȷ�س�ʼ����ȷ��ָ��
//
//	int* p2 = NULL;//��֪��һ��ָ�뵱ǰӦ��ָ������ʱ�����Գ�ʼ��ΪNULL
//	//*p2 = 100;//err
//
//	if (p2 != NULL)
//	{
//		*p2 = 100;
//	}
//
//
//	return 0;
//}




//ʹ��ָ���ӡ��������
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int*p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a,&n);
//	int sum = 0;
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//
//	}
//	printf("%d", sum);
//	return 0;
//}


//���0��100000֮������С�ˮ�ɻ������������
//
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100000; i++)
//	{
//		int tmp = i;
//		int count = 0;
//		int sum = 0;
//		while (tmp)
//		{
//			tmp = tmp / 10;
//			count++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow((tmp % 10), count);
//			tmp = tmp / 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}


