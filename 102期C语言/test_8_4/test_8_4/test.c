#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>

//dest ��ָ��Ŀ��ռ��
//src  ��ָ��Դ�ַ�����

//1
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;//\0
//}

//2
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;//\0
//}

//3
//void my_strcpy(char* dest, char* src)
//{
//	//1. �����ַ�
//	//2. ����\0 ѭ��ֹͣ
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
// 

#include <assert.h>

//4
//void my_strcpy(char* dest, char* src)
//{
//	/*if (src == NULL || dest == NULL)
//	{
//		return;
//	}*/
//
//	assert(src != NULL);//���� - release�汾�����Ż���
//	assert(dest != NULL);
//	//assert(src && dest);
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//��׳��
//³����

//5
//void my_strcpy(char* dest, const char* src)
//{
//	assert(src != NULL);//���� - release�汾�����Ż���
//	assert(dest != NULL);
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(src != NULL);//���� - release�汾�����Ż���
//	assert(dest != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	//strcpy - string copy - �ַ�������
//	//1
//	//char arr1[] = "abcdef";//[a b c d e f \0]
//	//char arr2[10] = "xxxxxxxxx";// [                        ]
//
//	//2 - Դ�ַ�����һ��Ҫ��\0
//	//char arr1[] = { 'a', 'b', 'c' };
//	//char arr2[10] = "xxxxxxxx";
//
//	//3 - Ŀ��ռ�����㹻��
//	//char arr1[] = "abcdef";
//	//char arr2[3] = { 0 };
//
//	//4. Ŀ��ռ䣬������޸�
//	char arr1[] = "abcdef";
//	const char* arr2 = "xxxxxxxxxxx";
//
//	char*ret = my_strcpy(arr2, arr1);
//
//	printf("%s\n", ret);
//
//	return 0;
//}

//
//int main()
//{
//	const int num = 10;//num�ǳ�����
//	const int* p = &num;
//	//*(p + 1) = 0;//
//
//	//num = 20; //err
//
//	//const ����ָ��
//	//const ����*�����
//	//���ε���ָ��ָ�������(*p),ָ��ָ������ݣ�����ͨ��ָ�����ı���
//	//����ָ����������ǿ��Ըı��
//	//int n = 100;
//	//const int*  p = &num;  //int const*  p = &num;
//	//*p = 20;//err
//	//p = &n;
//	//printf("%d\n", num);
//
//	//const ����*���ұ�
//	//���ε���ָ���������(p),ָ���������p�������޸��� 
//	//����ָ��ָ�������(*p)�����޸�
//	//
//	//int n = 100;
//	//int* const p = &num;
//	//*p = 20;//ok
//	//p = &n;//err
//
//	//printf("%d\n", num);
//	return 0;
////}
//
//int main()
//{
//	//char arr[] = "abcdef";
//	//const char* str = "qwer";
//	//printf("%s\n", arr);
//	//printf("%s\n", str);
//	//*arr
//	//*str
//
//	const char* str = "abcdef";
//	//�ѳ����ַ������ַ�a�ĵ�ַ�����str��
//	printf("%s\n", str);
//	printf("%c\n", *str);
//
//	//4
//
//	return 0;
//}


//int test()
//{
//	int a = 10;
//	return a;
//}
//int main()
//{
//	int ret = test();
//
//	return 0;
//}

//
//int* test()
//{
//	int a = 10;
//	return &a;//0x0012ff40
//}
//int main()
//{
//	int* ret = test();
//	//0x0012ff40
//	*ret = 0;
//
//	return 0;
//}


//
//size_t  - unsigned int
//size_t my_strlen(const char* str)
//
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}



//int main()
//{
//	//3-6 = -3
//	//10000000000000000000000000000011
//	//11111111111111111111111111111100
//	//11111111111111111111111111111101
//
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//

//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;//
//	c = ++a;//c=6 a=6
//	b = ++c, c++, ++a, a++;//c=8 b=7 a=8
//
//	b += a++ + c;//a=9 b=23 c=8
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}
//


//ͳ�ƶ�������1�ĸ���
//��Ŀ���ݣ�
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1

//size_t count_bit_one(int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//
//-1
//10000000000000000000000000000001
//11111111111111111111111111111110
//11111111111111111111111111111111
//
//
//size_t count_bit_one(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}


//size_t count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//
//	size_t ret = count_bit_one(num);
//
//	printf("%u\n", ret);
//
//	return 0;
//}

//дһ�����룬�ж�һ�����ǲ���2�Ĵη���


size_t count_bit_one(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	if ((n & (n - 1)) == 0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}