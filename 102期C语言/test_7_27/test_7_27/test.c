#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//一维数组的定义
//一维数组 
//int main()
//{
//	//创建一个数组--存放整型-10个 
//	int arr[10]={1,2,3};//不完全初始化,剩下的元素默认初始化为0 
////	char arr2[10]={'a','b'};
////	char arr3[10]="ab";
//	char arr4[]="abcdef"; 
//	printf("%d\n",sizeof(arr4));//7 
//	//sizeof 计算arr4所占空间的大小 
//	printf("%d\n",strlen(arr4));//6
//	//strlen 计算字符串的长度 --'\0'之前的字符个数 
//	return 0;
//}
//1.strlen 和sizeof没有什么关联
//2.strlen 是求字符串长度的--只能针对字符串求长度--库函数-使用得引头文件
//3.sizeof 计算变量、数组、类型大小--单位是字节--操作符 

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a','b','c'};
//	printf("%d\n",sizeof(arr1));//4
//	printf("%d\n",sizeof(arr2));//3
//	printf("%d\n",strlen(arr1));//3
//	printf("%d\n",strlen(arr2));//随机值 ---arr2里没有'\0'
//	return 0;
//}


//一维数组的使用
//数组是使用下标来访问的，下标是从0开始的
//数组大小可以通过计算得到 
//int sz = sizeof(arr)/sizeof(arr[0]); 

//int main()
//{
//	char arr[] = "abcdef";//[a][b][c][d][e][f][\0]
//	//printf("%c\n",arr[3]);
//	int i = 0;
//	int len = strlen(arr);
//	for(i=0;i<len;i++)
//	{
//		printf("%c\n",arr[i]);
//	}
//	return 0;
// } 

//int main()
//{
//	char arr[] = {1,2,3,4,5,6,7,8,9,0};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for(i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
// }

//一维数组在内存中的存储--连续存放的--每个元素之间相差4个字节  
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		printf("&arr[%d] = %p\n",i,&arr[i]); 
//	}
//	return 0; 
//} 

//二维数组的定义
//int main()
//{
//	//二维数组的创建
//	int arr1[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
//	int arr2[3][5] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
//	int arr3[][5] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
//	//二维数组的初始化可以省略行下标，但不能省略列下标
//
//	char ch1[4][6] = {'a', 'b'};
//	char ch2[4][6] = { {'a'},{ 'b'} };
//	char ch3[4][6] = {"abc", "def", "qwe"};
//	return 0;
//}


//二维数组的使用
//二维数组的使用也是通过下标的方式。
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9, 0 } };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//二维数组在内存中的存储
//二维数组在内存中的存储--连续存放的--每个元素之间相差4个字节 
//int main()
//{
//	/*int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr[0]);
//
//	//int arr[3][5] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9, 0 } };
//	//int* p = &arr[0][0];
//	//int i = 0;
//	//for (i = 0; i < 15; i++)
//	//{
//	//	printf("%d ", *p);
//	//	p++;
//	//}
//
//	//int arr[3][5] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9, 0 } };
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	int j = 0;
//	//	for (j = 0; j < 5; j++)
//	//	{
//	//		printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//	return 0;
//}

//数组越界
//数组的下标是有范围限制的。
//数组的下标规定从0开始的，如果有n个元素，最后一个元素的下标就是n-1。
//所以数组的下标如果小于0，或者大于n-1，就是数组越界访问了，超出了数组合法空间的访问。



//数组作为函数参数
//排序方法：冒泡、选择、插入、快速排序等等
//实现一个对整形数组的冒泡排序
//void bubble_sort(int* arr,int sz)//本质
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		//每趟要进行对比的对数
//		int flag = 1;//假设每趟已经有序
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//本趟不完全有序
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//void Print(int* p,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", p[i]);
//		//printf("%d ", p + i);
//		printf("%d ", *p);
//		p++;
//	}
//}
//int main()
//{
//	int arr[10] = { 5,7,9,4,3,6,2,1,10,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//1.sizeof(数组名)--数组名没有进行传参，数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小，单位是字节
//	int i = 0;
//	//数组名在传递给函数的时候，会降级变成首元素地址
//	bubble_sort(arr, sz);//排序---数组名作为参数--是首元素的地址 
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	Print(arr, sz);//利用函数输出
//	return 0;
//}


//	//2个例外： 
//	//1.sizeof(数组名)--数组名没有进行传参，数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小，单位是字节 
//	//2.&数组名，数组名代表整个数组，&数组名，取出的是整个数组的地址 
//	//除1，2两种情况以外，所有数组名都表示数组首元素的地址 
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr);
//
//	printf("----------------------------------\n");
//
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr[0] + 1);
//	printf("%p\n", &arr + 1);
//
//	return 0;
//}



//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	printf("arr1[] = {%d,%d,%d,%d,%d}\n", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);
//
//	printf("arr2[] = {%d,%d,%d,%d,%d}\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
//	return 0;
//}