#define _CRT_SECURE_NO_WARNINGS 1
//�����ֵ���Ϸ
//1. ����һ�������
//2. �����֣���С�����ˣ�
//3. ���Է�����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void menu()
//{
//	printf("***************************\n");
//	printf("*******   1. play    ******\n");
//	printf("*******   0. exit    ******\n");
//	printf("***************************\n");
//}
//
//
//void game()
//{
//	int guess = 0;
//	//��������Ϸ���߼�
//	//1. �����������1~100��
//	int ret = rand()%100+1;
//	//printf("%d\n", ret);
//	//2. ������
//
//	while (1)
//	{
//		printf("�������:>");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("��ϲ��¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	//������������������
//	srand((unsigned int)time(NULL));//��ʱ�����Ϊ����
//
//	do
//	{
//		//��ӡ�˵�
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);//1 0 
//		switch (input)
//		{
//		case 1:
//			game();//������Ϸ����
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ���������ѡ��!\n");
//			break;
//		}
//	} while (input);
//
//	//0 ��ʾ�٣���0��ʾ��
//
//	return 0;
//}
//
//




//#include <stdio.h>
//int main() {
//	int x = 3;
//	int y = 3;
//	switch (x % 2) {
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}



//д���뽫�������������Ӵ�С���
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	//����
//	scanf("%d %d %d", &a, &b, &c);
//	//����
//	int tmp = 0;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	//���
//	printf("%d %d %d\n", a, b, c);
//
//	return 0;
//}


//дһ�������ӡ1-100֮������3�ı���������


//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//�ж�i�Ƿ�Ϊ3�ı���
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//
//	for (i = 3; i <= 100; i+=3)
//	{
//		//�ж�i�Ƿ�Ϊ3�ı���
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//���������������������������Լ��
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);//24 18
//	//���������������Լ��
//	//շת�����
//	int r = 0;
//
//	while (r=a % b)
//	{
//		a = b;
//		b = r;
//	}
//	printf("%d\n", b);
//
//	// 
//	//�������
//	//����a��b�Ľ�Сֵ�������Լ��
//	//int m = (a > b ? b : a);//m=18
//	//while (1)
//	//{
//	//	if (a % m == 0 && b % m == 0)
//	//	{
//	//		printf("���Լ���ǣ�%d\n", m);
//	//		break;
//	//	}
//	//	m--;
//	//}
//
//
//
//	return 0;
//}
//

//��ӡ1000�굽2000��֮�������

//
//int main()
//{
//	int y = 0;
//	//1.
//	//for (y = 1000; y <= 2000; y++)
//	//{
//	//	//�ж�y�Ƿ�Ϊ����
//	//	//1. �ܱ�4���������ܱ�100����
//	//	//2. �ܱ�400����������
//	//	if (y % 4 == 0 && y % 100 != 0)
//	//		printf("%d ", y);
//	//	else if (y % 400 == 0)
//	//		printf("%d ", y);
//	//}
//	//2
//	//for (y = 1000; y <= 2000; y++)
//	//{
//	//	//�ж�y�Ƿ�Ϊ����
//	//	//1. �ܱ�4���������ܱ�100����
//	//	//2. �ܱ�400����������
//	//	if (y % 4 == 0 && y % 100 != 0)
//	//		printf("%d ", y);
//	//	if (y % 400 == 0)
//	//		printf("%d ", y);
//	//}
//	//3
//	//for (y = 1000; y <= 2000; y++)
//	//{
//	//	//�ж�y�Ƿ�Ϊ����
//	//	//1. �ܱ�4���������ܱ�100����
//	//	//2. �ܱ�400����������
//	//	// 
//	//	//����ʾ��
//	//	if (y % 4 == 0)
//	//	{
//	//		if(y%100 != 0)
//	//			printf("%d ", y);
//	//	}
//	//	else if (y % 400 == 0)
//	//		printf("%d ", y);
//	//}
//
//	for (y = 1000; y <= 2000; y++)
//	{
//		//�ж�y�Ƿ�Ϊ����
//		//1. �ܱ�4���������ܱ�100����
//		//2. �ܱ�400����������
//		// 
//		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//			printf("%d ", y);
//	}
//	return 0;
//}


//��ӡ100~200֮�������
//���� - ���� - ֻ�ܱ�1������������������
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//�ж�i�Ƿ�Ϊ����
//		//����������ʹ�ӡ
//		//��2~i-1֮�������ȡ�Գ�i
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j < i; j++)
//		{
//			//��j�Գ�i
//			if (i % j == 0)
//			{
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);//������ӡ
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}





//
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//�ж�i�Ƿ�Ϊ����
//		//����������ʹ�ӡ
//		//��2~i-1֮�������ȡ�Գ�i
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			//��j�Գ�i
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);//������ӡ
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//


#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	//ֻ�ṩ����
//	for (i = 101; i <= 200; i+=2)
//	{
//		//�ж�i�Ƿ�Ϊ����
//		//����������ʹ�ӡ
//		//��2~i-1֮�������ȡ�Գ�i
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			//��j�Գ�i
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);//������ӡ
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//

//��������N�־���

//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}



//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//�ҳ�10�����е����ֵ
//	int max = arr[0];//�����һ��Ԫ�ؾ�������
//	//��ʣ�µ�9��Ԫ�غ�max�Ƚ�
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//�ҳ�10�����е����ֵ
//	int max = 0;//����ʾ��
//	//��ʣ�µ�9��Ԫ�غ�max�Ƚ�
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//
//	return 0;
//}


//����Ļ�����9 * 9�˷��ھ���

//1*1=1
//2*1=2 2*2=4
//3*1=3 3*2=6 3*3=9
//....

//9��

int main()
{
	int i = 0;
	//����
	for (i = 1; i <= 9; i++)
	{
		//��ӡһ��
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			//��ӡһ��
			printf("%d*%d=%-2d ", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}