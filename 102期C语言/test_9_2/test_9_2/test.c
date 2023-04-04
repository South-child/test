#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//
//	printf("%d\n", strlen(arr));//随机值
//	printf("%d\n", strlen(arr + 0));//随机值
//	//printf("%d\n", strlen(*arr));//*arr - 'a' - 97 - err
//	//strlen就以为传进来的'a'的ascii码值97就是地址
//	//printf("%d\n", strlen(arr[1]));//'b' - 98 - err
//
//	printf("%d\n", strlen(&arr));//随机值
//	//char(*)[6]
//	//char*
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//随机值
//
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	return 0;
//}
//
//
//
//int main()
//{
//	//char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; //6
//	//[a b c d e f]
//
//	char arr[] = "abcdef";//7
//	//[a b c d e f \0]
//
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//5
//
//
//	//printf("%d\n", sizeof(arr));//7 字节
//	//printf("%d\n", sizeof(arr + 0));//arr是首元素的地址 4/8
//	//printf("%d\n", sizeof(*arr));//arr是首元素的地址,*arr就是首元素 1
//	//printf("%d\n", sizeof(arr[1]));//arr[1]就是第二个元素  1
//	//printf("%d\n", sizeof(&arr));//&arr 是数组的地址，数组的地址也是地址，就是4/8字节
//	//printf("%d\n", sizeof(&arr + 1));//&arr 是数组的地址,&arr+1 是跳过整个数组后的地址 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));//&arr[0] + 1 是第二个元素的地址，4/8
//
//	return 0;
//}
//
//int main()
//{
//	const char* p = "abcdef";
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	printf("%d\n", strlen(&p));//随机值
//	printf("%d\n", strlen(&p + 1));//随机值
//	printf("%d\n", strlen(&p[0] + 1));//5
//
//	//printf("%d\n", sizeof(p));//p是一个指针变量 4/8
//	//printf("%d\n", sizeof(p + 1));//p+1 是字符b的地址 4/8
//	//printf("%d\n", sizeof(*p));//1
//	//printf("%d\n", sizeof(p[0]));//p[0]-->*(p+0) --> *p 1
//	//printf("%d\n", sizeof(&p));//4/8
//	//printf("%d\n", sizeof(&p + 1));
//	//printf("%d\n", sizeof(&p[0] + 1));
//
//	return 0;
//}
//
//int main()
//{
//	int a[3][4] = { 0 };
//	//printf("%p\n", &a[0][0]);
//	//printf("%p\n", a[0]+1);
//
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));//a[0]是第一行的数组名，数组名单独放在sizeof内部
//	printf("%d\n", sizeof(a[0] + 1));//4/8
//	//arr[0]是第一行的数组的数组名，并没有单独放在sizeof内部，也没有&，所以arr[0]表示首元素的地址
//	//就是第一行这个数组第一个元素的地址
//	//所以a[0] + 1就是第一行，第二个元素的地址
//
//	printf("%d\n", sizeof(*(a[0] + 1)));//*(a[0] + 1)就是第一行第二个元素 4
//	printf("%d\n", sizeof(a + 1));//4/8
//	//数组名a，并没有单独放在sizeof内部，也没有&，所以a表示首元素（第一行）的地址
//	//所以a+1，就是第二行的地址
//	//int(*)[4]
//	//a+1 -> &a[1]
//
//	printf("%d\n", sizeof(*(a + 1)));//*(a+1)就是第二行 - 16
//	//*(a + 1) --> a[1]
//
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	//a[0]是第一行的数组名
//	//&a[0] 拿到的是第一行的地址
//	//&a[0]+1,就是第二行的地址
//	//int(*)[4]
//
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	//*(&a[0] + 1) - 第二行 -- a[1]
//	//*(&a[0]+1) --> *(&a[1]) --> a[1]
//
//	printf("%d\n", sizeof(*a));
//	//a表示首元素（第一行）的地址
//	//*a - 第一行 - 第一行的数组名
//	//*a -> *(a+0) ->a[0]
//
//	printf("%d\n", sizeof(a[3]));
//	//a[3]假设存在，就是第四行的数组名，sizeof(a[3])，就相当于把第四行的数组名单独放在sizeof内部
//
//	printf("%d\n", sizeof(int));
//	return 0;
//}

//int main()
//{
//    int a[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = (int*)(&a + 1);
//
//    printf("%d,%d", *(a + 1), *(ptr - 1));
//
//    return 0;
//}


struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节

int main()
{
	//struct Test*      --  int
	p = (struct Test*)0x100000;//

	//printf("0x%p\n", p + 0x1);
	//printf("0x%p\n", (unsigned long)p + 0x1);
	//printf("0x%p\n", (unsigned int*)p + 0x1);

	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);

	return 0;
}