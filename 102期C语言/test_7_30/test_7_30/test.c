#define _CRT_SECURE_NO_WARNINGS 1
//С���������ת��
// 
#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	int arr[50] = { 0 };
//	//����
//	scanf("%d", &num);
//	//ת��
//	int i = 0;
//	while (num)
//	{
//		arr[i] = num % 6;
//		i++;
//		num = num / 6;
//	}
//	//���
//	for (i--; i >= 0; i--)
//	{
//		printf("%d", arr[i]);
//	}
//
//	return 0;
//}

//С�����ŵ���
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	//����
//	scanf("%d", &n);
//	//����
//	int t = n / 12 * 4 + 2;
//	//���
//	printf("%d\n", t);
//
//	return 0;
//}

//С������ŷ�����
//#include <stdio.h>
//
///*
//int main()
//{
//long long n = 0;
//long long m = 0;
////����
//scanf("%d %d", &n, &m);
////����
////1. �������Լ��
//long long max = (m>n)?(n):(m);
//while(1)
//{
//if((m%max==0) && (n%max==0))
//break;
//max--;
//}
//
////2. ������С������
//long long min = (m>n)?(m):(n);
//while(1)
//{
//if((min%m==0)&&(min%n==0))
//{
//break;
//}
//min++;
//}
//
////3. ���
//long long sum = min+max;
////��ӡ
//printf("%lld\n", sum);
//
//return 0;
//}
//*/
//
//int main()
//{
//	long long n = 0;
//	long long m = 0;
//	//����
//	scanf("%d %d", &n, &m);
//	//����
//	long long n2 = n;
//	long long m2 = m;
//
//	//1. �������Լ��
//	long long c = 0;
//	while (c = m2 % n2)
//	{
//		m2 = n2;
//		n2 = c;
//	}
//
//	//2. ��С������
//	long long min = m * n / n2;
//	printf("%lld", min + n2);
//
//	return 0;
//}


//BC35-�ж���ĸ
//#include <stdio.h>
//
//int main()
//{
//	//��������
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//		getchar();//����\n
//	}
//
//	return 0;
//}

//����������ͼ��

#include <stdio.h>

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 1; i <= n; i++)
		{
			//��ӡһ��
			int j = 0;
			for (j = 1; j <= n; j++)
			{
				if (i == 1 || i == n || j == 1 || j == n)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}


//����Ա����

//#include <stdio.h>
//
//int main()
//{
//	//����
//	int i = 0;
//	int sc = 0;
//	int sum = 0;
//	int max = 0;//����0������߷�
//	int min = 100;//����100������ͷ�
//
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &sc);
//		sum += sc;
//
//		if (sc > max)
//			max = sc;
//
//		if (sc < min)
//			min = sc;
//	}
//
//	//����
//	double avg = (sum - max - min) / 5.0;
//	//���
//	printf("%.2lf\n", avg);
//
//	return 0;
//}


//�������ж�

//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	//while(scanf("%d %d %d",&a, &b, &c) != EOF)
//
//	while (~scanf("%d %d %d", &a, &b, &c))
//	{
//		if ((a + b > c) && (a + c > b) && (b + c > a))
//		{
//			//�ǲ��ǵȱ�
//			if (a == b && b == c)
//			{
//				printf("Equilateral triangle!\n");
//			}
//			else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
//			{
//				printf("Isosceles triangle!\n");
//			}
//			else
//			{
//				printf("Ordinary triangle!\n");
//			}
//		}
//		else
//		{
//			printf("Not a triangle!\n");
//		}
//	}
//
//	return 0;
//}





//#include <stdio.h>
//int main()
//{
//    char str[] = "hello bit";
//    //[h e l l o _ b i t \0]
//
//    printf("%d %d\n", sizeof(str), strlen(str));
//    //10 9
//    return 0;
//}




//void test(int arr[], int sz)
//void test(int * arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", arr[i]); //arr[i] --> *(arr+i)
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	test(arr, sz);//���鴫�δ���ȥ����������Ԫ�صĵ�ַ
//	return 0;
//}



//������A�е����ݺ�����B�е����ݽ��н�����
//
//void exchange(int a[], int b[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;
//	}
//}
//
//int main()
//{
//	int a[] = { 1,3,5,7,9 };
//	int b[] = { 2,4,6,8,0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	exchange(a, b, sz);
//
//	return 0;
//}


//����һ���������飬��ɶ�����Ĳ���
//
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
//
//void Init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*(arr + i) = i;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[], int sz)
//{
//	int l = 0;
//	int r = sz - 1;
//
//	while (l<r)
//	{
//		int tmp = arr[l];
//		arr[l] = arr[r];
//		arr[r] = tmp;
//		l++;
//		r--;
//	}
//}
//
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz);//��ʼ�� 0~9
//	Print(arr, sz);//��ӡ
//	Reverse(arr, sz);//����
//	Print(arr, sz);//��ӡ 9~0
//
//	return 0;
//}



////�±����ò�����[]
//int main()
//{
//	int a[10] = { 0 };
//	a[4] = 10;
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int i = 0;
//	printf("%d\n", arr[4]);
//	printf("%d\n", 4[arr]);
//
//
//	//a + b;
//	//b + a;
//	//arr[4] -- > *(arr+4) --> *(4+arr) --> 4[arr]
//	//arr[4];  *(arr+4)
//
//	//for (i = 0; i < 5; i++)
//	//{
//	//	printf("%p --- %p\n", &arr[i], arr+i);//arr+i - ��������arr�У��±�Ϊi��Ԫ�صĵ�ַ
//	//}
//
//	return 0;
//}

//��������--()
//#include <string.h>
//
//void test()
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	//printf("%d\n", strlen("abc"));
//	//printf("%u\n", strlen("abc"));
//	test();
//	return 0;
//}

//�ṹ�������
//.
//->
//�Զ�������
//
//#include <string.h>
//
//struct Book
//{
//	char name[20];
//	float price;
//	char id[10];
//};
//
//
//void print1(struct Book b)
//{
//	printf("����: %s\n", b.name);
//	printf("�۸�: %f\n", b.price);
//	printf("���: %s\n", b.id);
//
//	//*(b.name);
//}
//
//void print2(struct Book* pb)
//{
//	/*printf("����: %s\n", (*pb).name);
//	printf("�۸�: %f\n", (*pb).price);
//	printf("���: %s\n", (*pb).id);*/
//
//	printf("����: %s\n", pb->name);
//	printf("�۸�: %f\n", pb->price);
//	printf("���: %s\n", pb->id);
//}
//
//int main()
//{
//	struct Book b = {"C���Գ������", 55.5f, "C20190201"};
//	print2(&b);
//
//	//print1(b);
//
//	//b.price = 100.0f;
//	////�ַ������� -strcpy - �⺯�� - string.h
//	//strcpy(b.name, "���ݽṹ");
//	//print1(b);
//
//	//�ṹ��Ա���ʲ�����
//	//�ṹ����.��Ա��
//	//�ṹ��ָ��->��Ա��
//	// 
//	//(*�ṹ��ָ��).��Ա��
//
//	return 0;
//}