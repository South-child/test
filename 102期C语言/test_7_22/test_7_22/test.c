#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//strcpy--�ַ����������ƺ���('\0'Ҳ�´����ȥ)
//strlen--�����ַ�������
//int main()
//{
//	char arr1[20] = "xxxxxxxxx";//Ŀ��ռ�
//	char arr2[] = "hello";
//
//	char* ret = strcpy(arr1, arr2);
//
//	printf("%s\n", arr1);
//	printf("%s\n", ret);
//	return 0;
//}
//

//memset---�ڴ��������
//void* memset ( void * ptr, int value, size_t num );
//��ptrָ����ڴ��ĵ�һ���ֽڿ�ʼ����Ϊָ��ֵ
// value--- ��Ϊʲô(�������ַ���)    size_t num---�Ķ��ٸ��ֽ�
//int main()
//{
//	char arr[] = "hello bit";//xxxxx bit
//	int n = 5;
//	char *ret = (char*)memset(arr, 'x', n);
//	printf("%s\n", ret);
//
//	return 0;
//}



//���� - �Զ��庯��
//
//int get_max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//
//	//��2�����Ľϴ�ֵ
//	//int max = get_max(a, 20+1);
//	int max = get_max(a, get_max(4, 5));
//
//	//printf("max = %d\n", max);
//
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("������a=%d b=%d\n", a, b);
//
//	return 0;
//}
//
//

//void Swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	//����
//	Swap(a, b);
//	//ʵ��a��b�������β�x,y��ʱ���βν���ʵ�ε�һ����ʱ����
//	//�ı��βα���x,y���ǲ���Ӱ��ʵ��a��b��
//
//	printf("������a=%d b=%d\n", a, b);
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//
//	int* pa = &a;
//	*pa = 20;  //�����ò���
//
//	printf("%d\n", a);
//	return 0;
//}
//
//void Swap1(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//
//void Swap2(int* px, int* py)
//{
//	int z = 0;
//
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	Swap2(&a, &b); //��ַ����---��Ҫ�Ա���������б仯ʱ
//	Swap1(a, b); //��ֵ����---����Ա���������б仯ʱ
//	printf("������a=%d b=%d\n", a, b);
//
//	return 0;
//}


//��ϰ
//1.дһ�����������ж�һ�����ǲ�������
#include <math.h>
//�ж�n�Ƿ�Ϊ����
//int is_prime(int n)
//{
//	//�Գ���
//	//2~n-1
//	//2~sqrt(n)
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	//100-200֮�������
//	int i = 0;
//	int cnt = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//�ж�i�Ƿ�Ϊ����
//     //is_prime
//     //��������� ����1
//     //���������� ����0
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//			cnt++;
//		}
//	}
//	printf("\ncount = %d\n", cnt);
//
//	return 0;
//}



//2.дһ�������ж�1000--2000��֮������� 
//int is_leap_year(int y)
//{
////	//��ʽ1
////	//if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
////	//	return 1;
////	//else
////	//	return 0;
////	
////	//��ʽ2
////	return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
//
//	//��ʽ3
//	//	if (y % 4 == 0)
//	//	{
//	//		if (y % 100 != 0)
//	//		{
//	//			return 1;
//	//		}
//	//	}
//	//	if (y % 400 == 0)
//	//		return 1;
//	//	return 0;
//}

//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		//�ж�y�Ƿ�Ϊ����
//		//����
//		//�����꣬����1
//		//�������꣬����0
//		if (is_leap_year(y) == 1)
//		{
//			printf("%d ", y);
//		}
//	}
//
//	return 0;
//}


//дһ��������ʵ��һ��������������Ķ��ֲ���
//��ʽ1
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	//�Ҳ���
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 17;
//	//���������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//�ҵ��ˣ������±�
//	//�Ҳ���������-1
//	int ret = binary_search(arr, k, sz);//TDD - ������������
//	
//	if (ret == -1)
//		printf("�Ҳ���\n");
//	else
//		printf("�ҵ���,�±��ǣ�%d\n", ret);
//
//	return 0;
//}

//��ʽ2
//int binary_search(int arr[], int k, int left, int right) //ֱ�ӽ����±�����±괫�ݹ���
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	//�Ҳ���
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 3;
//	//���������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//�ҵ��ˣ������±�
//	//�Ҳ���������-1
//	int ret = binary_search(arr, k, 0, 9);//TDD - ������������
//
//	if (ret == -1)
//		printf("�Ҳ���\n");
//	else
//		printf("�ҵ���,�±��ǣ�%d\n", ret);
//
//	return 0;
//}
//


//4.дһ��������ÿ����һ������������ͻὫnum��ֵ����1
//void Add(int* p)
//{
//	*p = *p + 1;
//}
//
//int main()
//{
//	int num = 0;
//
//	Add(&num);
//	printf("%d\n", num);//1
//	Add(&num);
//	printf("%d\n", num);//2
//	Add(&num);
//	printf("%d\n", num);//3
//
//	return 0;
//}
//
//
//int Add(int n)
//{
//	return n + 1;
//}
//
//int main()
//{
//	int num = 0;
//
//	num = Add(num);
//	printf("%d\n", num);//1
//
//	num = Add(num);
//	printf("%d\n", num);//2
//	
//	num = Add(num);
//	printf("%d\n", num);//3
//
//	return 0;
//}
//

//������Ƕ�׵��ú���ʽ����

//int main()
//{
//	//Ƕ�׶����ǲ�֧�ֵ� - err
//	void test()
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//int main()
//{
//	//int len = strlen("abc");
//	//printf("%d\n", len);
//
//	//printf("%d\n", strlen("abc"));//��ʽ����
//
//	//char arr1[20] = "xxxxxx";
//	//char arr2[20] = "abc";
//
//	//printf("%s\n", strcpy(arr1, arr2));
//
//printf�������ص��Ǵ�ӡ����Ļ�ϵ��ַ��ĸ���������������󣬽����ظ���
//	printf("%d", printf("%d", printf("%d", 43)));  //4321

 /*printf("%d", 43)����Ļ�ϴ�ӡ43�������ַ���Ȼ�󷵻�2��Ȼ������ʽ�ӱ��printf("%d", 2)��
��������Ļ�ϴ�ӡ2��һ���ַ���Ȼ�󷵻�1��Ȼ������ʽ�ӱ��printf("%d",1)��Ȼ���ӡ1��
������Ļ�ϴ�ӡ4321*/
//	return 0;
//}