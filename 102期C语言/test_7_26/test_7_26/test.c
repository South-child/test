#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//getchar - ���� - �Ӽ��̶�ȡ�ַ���

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}

//
//int main()
//{
//	char password[20] = {0};
//
//	printf("����������:>");
//	scanf("%s", password);
//
//	//�ѻ������е�����
//	int tmp = 0;
//	while ((tmp = getchar()) != '\n')
//	{
//		;
//	}
//
//	printf("��ȷ������(Y/N):>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr[20] = "xxxxxxxxxxx";
//
//	scanf("%s", arr);
//
//	return 0;
//}
//
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//
//		putchar(ch);
//	}
//	return 0;
//}


//int test()
//{
//	int a = 10;
//	int b = 20;
//	return a, b;//err
//}
//int main()
//{
//	int ret = test();
//	printf("%d\n", ret);
//
//	return 0;
//}


//void test(int arr[])
//{
//	int a = 10;
//	int b = 20;
//
//	arr[0] = a;
//	arr[1] = b;
//}
//
//int main()
//{
//	int arr[2] = {0};
//	test(arr);
//	
//	printf("%d %d\n", arr[0], arr[1]);
//
//	return 0;
//}
//
//void test(int* px, int* py)
//{
//	int a = 10;
//	int b = 20;
//	*px = a;
//	*py = b;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	test(&x, &y);
//	
//	printf("%d %d\n", x, y);//10 20
//
//	return 0;
//}
//


//
//int x = 0;
//int y = 0;
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	x = a;
//	y = b;
//}
//
//int main()
//{
//	test();
//	printf("%d %d\n", x, y);//10 20
//
//	return 0;
//}

////��������
//int Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);
//	printf("%d\n", ret);
//
//	return 0;
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}

//exec((vl��v2)��(v3��v4)��v5��v6);

//��һ�������ڸ�������ж���ı����ڱ�������Χ����Ч���������ָ�����еĳɶ����Ź��ɵĴ��룩 - err

//void test()
//{
//	{
//		int a = 10;
//	}
//	printf("a=%d\n", a);//err
//}
//int main()
//{
//	return 0;
//}

//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//1*1=1
//2*1=2 2*2=4
//3*1=3 3*3=6 3*3=9
//...
//void print_table(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		//��ӡһ��
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_table(n);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
#include <string.h>

//�����ַ���
//void reverse_string(char* str)
//{
//	int len = strlen(str);
//
//	//char* left = str;
//	//char* right = str + len - 1;
//	int left = 0;//'a'
//	int right = len - 1;//'f'
//
//	while (left<right)
//	{
//		char tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
////�ݹ�汾
//void reverse_string(char str[])
//{
//	int len = my_strlen(str);
//	char tmp = str[0];
//	str[0] = str[len - 1];
//	str[len - 1] = '\0';
//
//	if(my_strlen(str+1) >= 2)
//		reverse_string(str+1);
//	str[len - 1] = tmp;
//}
//
//int main()
//{
//	char arr[20] = "abcdef";
//	//const char* arr = "abcdef";//err
//	//����������Ԫ�صĵ�ַ
//	//��Ԫ�ؾ���char����
//	//char*
//	reverse_string(arr);
//	printf("%s\n", arr);//��������ǣ�fedcba
//
//	return 0;
//}
//
//int DigitSum(unsigned int n)//1234
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	unsigned int num = 1729;
//	int ret = DigitSum(num);
//
//	printf("%d\n", ret);
//	return 0;
//}

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��


//double Pow(int n, int k)
//{
//	if (k > 0)
//		return n * Pow(n, k - 1);
//	else if (k == 0)
//		return 1.0;
//	else
//		return 1.0 / Pow(n, -k);
//}
//
//
//int main()
//{
//	int n = 2;
//	int k = -3;
//	double ret = Pow(n, k);//�⺯���е�pow���Ǽ���η��� - ��Ҫͬ��
//	printf("%lf\n", ret);
//	return 0;
//}
//
//int arr[5];
//
//int main()
//{
//	//��ʼ��
//	int arr6[5];
//
//	int arr1[20] = {1,2,3};//����ȫ��ʼ����ʣ���Ĭ�ϳ�ʼ��Ϊ0
//	int arr2[] = { 1,2,3};
//	char arr3[] = "abc";
//	char arr4[] = { 'a', 'b', 'c' };
//	char arr5[] = { 'a', 98, 'c' };
//	
//	return 0;
//}
//
//int main()
//{
//	float sc[5] = {0.0f, 3.0f};
//	//�ṹ������Ҳ���Դ���
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13};
//	//0~9
//	//printf("%d\n", arr[4]);
//	int i = 0;
//	//��������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//
//	//��������Ԫ�ظ���
//	int a = 10;
//	int* p = &a;
//	printf("%p\n", p);
//	printf("%p\n", p+1);
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%p\n", &arr[i]);
//	//}
//	return 0;
//}


//����һ��������n(1 �� n �� 10^9)
//���һ�У�Ϊ������n��ʾΪ�����ƵĽ��
#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[20] = { 0 };
//	while (n != 0)
//	{
//		int r = 0;
//		r = n % 6;
//		n = n / 6;
//		
//		arr[i] = r;
//		i++;
//	
//	}
//	int j = 0;
//	for (j = i-1; j >=0; j--)
//	{
//		printf("%d", arr[j]);
//	}
//	return 0;
//}

//С����ѧУ��ѧ¥�ĵ���ǰ���˺ܶ��ˣ�����ǰ����n�����ڵȵ��ݡ�
//����ÿ�ο��Գ���12�ˣ�ÿ��������Ҫ��ʱ��Ϊ4���ӣ�����Ҫ2���ӣ�����Ҫ2���ӣ���
//�����С���ּ��㻹��Ҫ���ٷ��Ӳ��ܳ˵��ݵ���¥�ϡ�
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	printf("%d", 4 * (n / 12) + 2);
//	return 0;
//}


//ÿ�������������������n��m��(1 �� n �� 109��1 �� m �� 109)
//���������
//����ÿ�����룬���һ����������Ϊn��m�����Լ������С������֮�͡�
//int main()
//{
//	long int n = 0;
//	long int m = 0;
//	scanf("%d %d", &n, &m);
//	long int a = n * m;
//	long int t = 0;
//	while (t = n % m)
//	{
//		n = m;
//		m = t;
//	}
//	long int k = m;//���Լ��
//	long int ret = a / k;//��С������
//	printf("%ld\n", k + ret);
//	return 0;
//}


//�������룬ÿ���������һ���ַ���
//���������
//���ÿ�����룬������ַ�����ĸ��YES�����ǣ�NO��
//int main()
//{
//	char ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))
//			printf("YES\n");
//		else
//			printf("NO\n");
//		getchar();
//	}
//	return 0;
//}


//�������룬һ��������3~20������ʾ�����������Ҳ��ʾ��������αߵġ�*����������
//���������
//���ÿ�����룬����á�*����ɵġ����ġ������Σ�ÿ����*��������һ���ո�
//* * * *
//*     *
//*     *
//* * * *
//����һ
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		int i = 0;
//		//1. ��ϸ�۲�ͼ��  ���Կ���  ��һ��  ���һ��  �Լ���һ��  ���һ�ж���*�ź����һ���ո�
//		//2. ����λ�ö���2���ո�
//		for (i = 0; i < n; i++)//����
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)//����
//			{
//				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//					printf("* ");
//				else
//					printf("  ");//�����ո�
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//������
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)//����
//		{
//			int j = 0;
//			if (i == 0 || i == n - 1)//��һ�������һ��
//			{
//				//��һ�������һ�д�ӡ*�ĸ���
//				for (j = 0; j < n; j++)
//				{
//					printf("* ");
//				}
//			}
//			else
//			{
//				printf("*");
//				for (j = 0; j < 2 * n - 3; j++)
//				{
//					printf(" ");
//				}
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//}



//����������һ�У�����7��������0~100��������7���ɼ����ÿո�ָ���
//���������һ�У����ȥ����߷ֺ���ͷֵ�ƽ���ɼ���С�������2λ��ÿ��������С�
//int main()
//{
//	int arr[8] = { 0 };
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum = sum + arr[i];
//	}
//	int max = arr[0];
//	int min = arr[0];
//	for (i = 0; i < 7; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//		if (min>arr[i])
//			min = arr[i];
//	}
//	double ret = (sum - max - min) / 5.0;
//	printf("%.2lf\n", ret);
//	return 0;
//}



//��Ŀ�ж����������ݣ�ÿһ����������a��b��c(0<a, b, c<1000)����Ϊ�����ε������ߣ��ÿո�ָ���
//������������ÿ���������ݣ����ռһ�У�����ܹ��������Σ��ȱ��������������Equilateral triangle!����
//�����������������Isosceles triangle!����������������������Ordinary triangle!������֮�����Not a triangle!��
//int main()
//{
//	int a, b, c;
//	while ((scanf("%d %d %d", &a, &b, &c)) != EOF)
//	{
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if (a == b && b == c && a == c)
//				printf("Equilateral triangle!\n");
//			else if (a == b || a == c || b == c)
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//			printf("Not a triangle!\n");
//
//	}
//	return 0;
//}