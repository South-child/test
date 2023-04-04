#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，可以左旋字符串中的k个字符。

#include <string.h>
#include <stdio.h>
#include <assert.h>

//void left_move(char arr[], int k)
//void left_move(char* arr, int k)
//{
//	int i = 0;
//	assert(arr);
//
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//左旋转1个字符
//		//1. 保存第一个字符
//		char tmp = *arr;
//		//2. 把后续的字符一次往前移动
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3. 把保存好的第一个字符存放在最后
//		*(arr + len - 1) = tmp;
//	}
//}

//
//void reverse(char* l, char* r)
//{
//	assert(l && r);
//
//	while (l < r)
//	{
//		char tmp = *l;
//		*l = *r;
//		*r = tmp;
//
//		l++;
//		r--;
//	}
//}
//
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	k %= len;
//
//	reverse(arr, arr+k-1);//逆序左边
//	reverse(arr+k, arr+len-1);//逆序右边
//	reverse(arr, arr+len-1);//逆序整个字符串
//}
//
//int main()
//{
//	//char* p = "abcd";//err
//
//	char arr[] = "abcdef";
//	//bafedc
//
//	//左旋转字符串
//	left_move(arr, 31);
//
//	printf("%s\n", arr);//打印字符串
//	//cdab
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
// 
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//
//void reverse(char* l, char* r)
//{
//	assert(l && r);
//
//	while (l < r)
//	{
//		char tmp = *l;
//		*l = *r;
//		*r = tmp;
//
//		l++;
//		r--;
//	}
//}
//
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	k %= len;
//
//	reverse(arr, arr+k-1);//逆序左边
//	reverse(arr+k, arr+len-1);//逆序右边
//	reverse(arr, arr+len-1);//逆序整个字符串
//}
//
////判断arr2是否是arr1旋转得到的？
//int is_left_move(char arr1[], char arr2[])
//{
//	int len = strlen(arr1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(arr1, 1);
//		if (strcmp(arr1, arr2) == 0)
//			return 1;//是
//	}
//
//	return 0;//不是
//}
//
//
//int is_left_move(char arr1[], char arr2[])
//{
//	assert(arr1);
//	assert(arr2);
//
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//
//	if (len1 != len2)
//		return 0;
//
//	//1. 给arr1的后边追加一个arr1中的字符串
//	strncat(arr1, arr1, len1);
//
//	//2. 判断arr2是否是arr1的字串
//	if (NULL == strstr(arr1, arr2))
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//
//int main()
//{
//	char arr1[20] = "AABCD";
//	//
//	//AABCDAABCD
//	//
//	char arr2[] = "BCD";
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//
//	return 0;
//}
//
//int main()
//{
//	//char arr1[20] = "abc";
//	////strcat(arr1, "def");
//	//strncat(arr1, arr1, 3);
//
//	//printf("%s\n", arr1);
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "def";
//	char*ret = strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}

//有一个数字矩阵，矩阵的每行从左到右是递增的，
//矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。

//1 2 3
//4 5 6
//7 8 9

//
//void find_k(int arr[3][3], int k, int r, int c)
//{
//	//右上角的坐标
//	int x = 0;
//	int y = c - 1;
//
//	while (x<r && y>=0) 
//	{
//		if (arr[x][y] < k)
//			x++;
//		else if (arr[x][y] > k)
//			y--;
//		else
//		{
//			printf("找到了，下标是：%d %d\n", x, y);
//			return;
//		}
//	}
//	printf("找不到\n");
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//N
//	//< O(N)
//	//
//	int k = 17;
//	find_k(arr, k, 3, 3);
//
//	return 0;
//}


//
//void find_k(int arr[3][3], int k, int *px, int *py)
//{
//	//右上角的坐标
//	int x = 0;
//	int y = *py - 1;
//
//	while (x < *px && y >= 0)
//	{
//		if (arr[x][y] < k)
//			x++;
//		else if (arr[x][y] > k)
//			y--;
//		else
//		{
//			*px = x;
//			*py = y;
//			return;
//		}
//	}
//
//	*px = -1;
//	*py = -1;
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 17;
//
//	int x = 3;
//	int y = 3;
//	//&x, &y
//	//返回形参数
//	find_k(arr, k, &x, &y);
//	if(x == -1 && y == -1)
//		printf("No\n");
//	else
//		printf("Yes: %d %d\n", x, y);
//
//	return 0;
//}
//
//int main()
//{
//	//size_t - unsigned int
//	//char arr[] = "abcdef";
//	//size_t sz = strlen("abcdef");
//
//	char arr[] = { 'a', 'b', 'c' };
//	
//	size_t sz = strlen(arr);
//
//	printf("%u\n", sz);
//
//	return 0;
//}
//
//int main()
//{
//	//3-6 - -3
//	//size_t
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "xxx";
//	//const char* p = "xxxxxxxxxxxxxx";
//	char arr2[] = "hello\0abc";
//	//char arr2[] = { 'a', 'b', 'c' };
//
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//
//scanf
//strcpy
//strcat
//

char* my_strcpy(char*dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;

	while (*dest++ = *src++)
	{
		;
	}

	return ret;
}


int main()
{
	char arr1[] = "xxxxxxxx";
	char arr2[] = "abc";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}