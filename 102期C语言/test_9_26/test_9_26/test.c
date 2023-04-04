#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//打开文件
//fopen
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("C:\\Users\\wyt\\Desktop\\data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//读文件
//	// 
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("C:\\Users\\wyt\\Desktop\\data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//写文件
//	// 
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//


//int main()
//{
//	FILE* pf = fopen("C:\\Users\\wyt\\Desktop\\data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//写文件
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('t', pf);
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//int main()
//{
//	fputc('b', stdout);//putchar  printf("%c", ch);
//	fputc('i', stdout);
//	fputc('t', stdout);
//	//打印到屏幕上
//	return 0;
//}



//int main()
//{
//	FILE* pf = fopen("C:\\Users\\wyt\\Desktop\\data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//b
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//c
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	
//	return 0;
//}


//
//int main()
//{
//
//	int ch = fgetc(stdin);//getchar scanf("%c")
//	printf("%c\n", ch);//a
//
//	ch = fgetc(stdin);
//	printf("%c\n", ch);//b
//
//	ch = fgetc(stdin);
//	printf("%c\n", ch);//c
//	//从键盘上输入
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//写文件
//	//写一行数据
//	fputs("hello world\n", pf);
//	fputs("hello bit\n", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}

//
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//读文件
//	//读一行数据
//	char arr[20] = { 0 };
//	fgets(arr, 20, pf);
//	printf("%s\n", arr);
//
//	fgets(arr, 20, pf);
//	printf("%s\n", arr);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}


//struct S
//{
//	int n;
//	double d;
//};
//
//int main()
//{
//	struct S s = { 100, 3.14 };
//
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//写文件
//	fprintf(pf, "%d %lf", s.n, s.d);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}



//struct S
//{
//	int n;
//	double d;
//};
//int main()
//{
//	struct S s = {0};
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//读文件
//	fscanf(pf, "%d %lf", &(s.n), &(s.d));
//
//	printf("%d %lf\n", s.n, s.d);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}




//二进制的形式写
//struct S
//{
//	int n;
//	double d;
//	char name[10];
//};
//
//int main()
//{
//	struct S s = {100, 3.14, "zhangsan"};
//
//	FILE* pf = fopen("data.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//写文件 - 二进制的方式写
//	fwrite(&s, sizeof(s), 1, pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}


//二进制的形式读
//struct S
//{
//	int n;
//	double d;
//	char name[10];
//};
//
//int main()
//{
//	struct S s = {0};
//
//	FILE* pf = fopen("data.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//读文件 - 二进制的方式读
//	fread(&s, sizeof(struct S), 1, pf);
//
//	//打印
//	printf("%d %lf %s\n", s.n, s.d, s.name);
//	//100 3.140000 zhangsan
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}



struct S
{
	int n;
	double d;
	char name[10];
};

int main()
{
	char arr[100] = { 0 };

	struct S tmp = { 0 };
	struct S s = { 100, 3.14, "zhangsan" };
	//把一个格式化的数据转换成字符串
	sprintf(arr, "%d %lf %s", s.n, s.d, s.name);
	//打印
	printf("%s\n", arr);
	
	//从arr中的字符串中提取出一个格式化的数据
	sscanf(arr, "%d %lf %s", &(tmp.n), &(tmp.d), tmp.name);
	//打印
	printf("%d %lf %s\n", tmp.n, tmp.d, tmp.name);

	return 0;
}