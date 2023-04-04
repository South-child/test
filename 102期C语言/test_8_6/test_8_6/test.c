#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int count_diff_bit(int n1, int n2)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n1 >> i) & 1) != ((n2 >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}

//
//int NumberOf1(int n) 
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
//int count_diff_bit(int n1, int n2)
//{
//	int count = 0;
//	int t = n1 ^ n2;
//	count = NumberOf1(t);
//	return count;
//}
//
//int main()
//{
//	int n1 = 0;
//	int n2 = 0;
//	scanf("%d%d", &n1, &n2);
//
//	int count = count_diff_bit(n1, n2);
//
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	printf("偶数位:");
//	for (i = 31; i >= 1; i-=2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//
//	printf("奇数位:");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//
//	return 0;
//}
//

//
//
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//    int a = 0x11223344;
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%x\n", a);
//    return 0;
//}
//
//
//#include <stdio.h>
//int i;//0
//int main()
//{
//    i--;//-1
//    //sizeof - 返回的是无符号整数
//    //算术转换
//    //int --> size_t
//    //
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
//

#include <assert.h>

//void print(const int*p, int sz)
//{
//	int i = 0;
//	assert(p);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//
//	return 0;
//}

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int sum = 0;
//	int k = 0;
//	scanf("%d %d", &a, &n);
//
//	for (i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}

//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，
//则153是一个“水仙花数”。

//
//自幂数
//
#include <math.h>
//
//int count(int tmp)
//{
//	int cnt = 1;
//	while (tmp /= 10)
//	{
//		cnt++;
//	}
//	return cnt;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断i是否是自幂数
//		int tmp = i;
//		int sum = 0;
//
//		//1. 计算i的位数 - n
//		int cnt = count(i);
//		//2. 再计算i的每一位的n次方之后
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, cnt);
//			tmp /= 10;
//		}
//		//3. 判断
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//


#include <stdio.h>

//
//strstr
//查找字符串的函数
//

//BC46 判断是元音还是辅音


int main()
{
	int ch = 0;
	//循环判断部分其实在读取字符
	char vowel[] = "aeiouAEIOU";

	while ((ch = getchar()) != EOF)
	{
		//判断是否为元音字母
		int i = 0;
		int flag = 0;
		for (i = 0; i < 10; i++)
		{
			if (ch == vowel[i])
			{
				flag = 1;//是元音字母
				break;
			}
		}
		if (flag == 1)
		{
			printf("Vowel\n");
		}
		else
		{
			printf("Consonant\n");
		}

		getchar();// 清理 \n
	}

	return 0;
}




//int main()
//{
//
//	int ch = 0;
//	//循环判断部分其实在读取字符
//
//	while((ch=getchar()) != EOF)
//	{
//		//判断是否为元音字母
//		if((ch=='A')||(ch=='a')||(ch=='E')||(ch=='e')||(ch=='I')||(ch=='i') || (ch=='O')||(ch=='o')||(ch=='U')||(ch=='u'))
//		{
//			printf("Vowel\n");
//		}
//		else
//		{
//			printf("Consonant\n");
//		}
//		getchar();// 清理 \n
//	}
//	return 0;
//}





////BC105 矩阵相等判定
//#include <stdio.h>
//
//int main()
//{
//	int arr1[10][10] = { 0 };
//	int arr2[10][10] = { 0 };
//	int n = 0;
//	int m = 0;
//
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	int j = 0;
//
//	//输入了矩阵1
//	//n行
//	for (i = 0; i < n; i++)
//	{
//		//m列
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//	int flag = 1;//默认相同
//	//输入了矩阵2
//	//n行
//	for (i = 0; i < n; i++)
//	{
//		//m列
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr2[i][j]);
//			if (arr1[i][j] != arr2[i][j])
//			{
//				flag = 0;
//				break;
//			}
//		}
//	}
//	//
//	if (flag == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}





//BC107 矩阵转置
#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	int arr[10][10] = { 0 };

	scanf("%d %d", &n, &m);
	int i = 0;
	int j = 0;
	//输入
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	//转置输出
	for (i = 0; i < m; i++)//3
	{
		for (j = 0; j < n; j++)//2
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}