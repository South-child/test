#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//strcat返回的是目标空间的起始地址
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//
//	char* ret = dest;
//	//1. 找到目标字符串的末尾\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2. 追加源字符串直到\0
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//int main()
//{
//	//strcpy - 字符串拷贝
//	//strcat - 字符串连接-字符串追加
//	char arr1[20] = "abc";
//	//[a b c \0]
//	char arr2[] = { 'd', 'e', 'f' ,'\0'};
//
//	printf("%s\n", my_strcat(arr1, arr2));//abcdef
//
//	return 0;
//}


//void set(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*(p + i) = 0;
//	}
//}

//void set(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	set(arr, 10);
//
//	return 0;
//}

//
//int main()
//{
//	//strcmp 是比较字符串的，比较的是字符串的内容，不是长度
//
//	char arr1[] = "abcq";
//	char arr2[] = "abc";
//	int ret = strcmp(arr1, arr2);
//
//	if (ret == 0)
//	{
//		printf("=\n");
//	}
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf(">\n");
//	}
//
//	printf("%d\n", ret);
//
//	return 0;
//}

//
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//
//	return *s1 - *s2;
//}
//
//int main()
//{
//	//strcmp 是比较字符串的，比较的是字符串的内容，不是长度
//
//	char arr1[] = "abcq";
//	char arr2[] = "abcwq";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret < 0)
//		printf("<\n");
//	else if (ret == 0)
//		printf("=\n");
//	else
//		printf(">\n");
//
//	return 0;
//}

//int main()
//{
//	char arr1[20] = "abcdefghi";
//	char arr2[] = "xxxx";
//	//模拟实现
//	strncpy(arr1, arr2, 6);
//
//	printf("%s\n", arr1);
//	return 0;
//}

//int main()
//{
//	char arr1[20] = "abc\0xxxxxxx";
//	char arr2[] = "def";
//	//模拟实现？
//	strncat(arr1, arr2, 6);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "aqcwef";
//	char arr2[] = "abcqw";
//
//	//模拟实现
//	int ret = strncmp(arr1, arr2, 4);
//
//	printf("%d\n", ret);
//	return 0;
//}
//

//
//strstr - 字符串查找函数
//在一个字符串中查找子字符串
//
//char* my_strstr(const char*str1, const char* str2)
//{
//	assert(str1 && str2);
//	//
//	char* s1;
//	char* s2;
//	char* cp = str1;
//	
//	if (*str2 == '\0')
//		return str1;
//
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//
//		//while (*s1!='\0'  && *s2 != '\0' && *s1 == *s2)
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//
//	//找不到
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "i am good student, hehe student";
//	char arr2[] = "student";
//	//查找arr1中arr2第一次出现的位置
//	char *ret = my_strstr(arr1, arr2);
//
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//
//192.168.2.121
//.
// 
//192
//168
//2
//121
//
//zpw@bitedu.tech
//@.
//zpw
//bitedu
//tech
//

//strtok(, "@.");
//zpw\0bitedu.tech
//
//int main()
//{
//	char arr1[] = "zpw@bitedu.tech";
//
//	char arr2[100] = { 0 };//临时数据
//	//zpw\0bitedu.tech\0
//
//	char sep[] = "@.";
//	strcpy(arr2, arr1);
//	char* ret = NULL;
//	//分割字符串
//
//	for (ret=strtok(arr2, sep); ret!=NULL; ret=strtok(NULL, sep))
//	{
//		printf("%s\n", ret);
//	}
//
//	//strtok(arr2, sep);
//	//strtok(NULL, sep);
//
//	return 0;
//}
//

void* my_memcpy(void* dest, const void*src, size_t count)
{
	void* ret = dest;
	assert(dest && src);

	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t count)
{
	//重叠拷贝+不重叠拷贝
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//            1,2,1,2,3,4,7,8,9,10
	//memcpy(arr+2, arr, 16);
	//memcpy - 只要完成了不重叠的内存拷贝就完成任务
	my_memmove(arr + 2, arr, 16);
	//内存拷贝时，出现内存重叠的现象，应该使用memmove

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//
//	//拷贝的是整型数据
//	my_memcpy(arr2, arr1, 10*sizeof(int));
//
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}
