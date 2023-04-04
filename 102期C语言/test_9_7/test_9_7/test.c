#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//    int a[4] = { 1, 2, 3, 4 };
//    int* ptr1 = (int*)(&a + 1);
//    int* ptr2 = (int*)((int)a + 1);
//    printf("%x,%x", ptr1[-1], *ptr2);
//    return 0;
//}
//
//

//#include <stdio.h>
//int main()
//{
//    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//    // = {{1,2}, {3,4},{5,6}};
//
//    int* p;
//    p = a[0];
//    printf("%d", p[0]);
//    return 0;
//}
//

//
//int main()
//{
//    int a[5][5];
//    int(*p)[4];
//    p = a;
//    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//    return 0;
//}

//int main()
//{
//    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    //1 2 3 4 5
//    //6 7 8 9 10
//
//    int* ptr1 = (int*)(&aa + 1);
//    int* ptr2 = (int*)(*(aa + 1));
//    printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//    return 0;
//}
//

//#include <stdio.h>
//
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
//
//
//
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}
//
//
//#include <stdio.h>
//
//int main()
//{
//    int y = 0;
//    int m = 0;
//    //scanf的返回值是读取到完整数据的个数
//    //EOF end of file
//    //EOF --> -1
//    //31 28 31 30 31 30 31 31 30 31 30 31
//    //   29
//    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//    while (scanf("%d %d", &y, &m) != EOF)
//    {
//        int day = days[m - 1];
//        //判断闰年
//        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//        {
//            if (m == 2)
//                day++;
//        }
//
//        printf("%d\n", day);
//
//    }
//    return 0;
//}
//
//
//


//int main()
//{
//	unsigned int a = 0x1234;
//	unsigned char b = *(unsigned char*)&a;
//	return 0;
//}

//在32位大端模式处理器上变量b等于（ ）


//
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//
//int main()
//{
//	int arr[10][10] = {0};
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i == j)
//				arr[i][j] = 1;
//
//			//计算
//			if (i >= 2 && j >= 1)
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//题目名称：
//猜凶手
//题目内容：
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			break;
//		}	
//	}
//	printf("%c\n", killer);
//
//	return 0;
//}


//智力题
//
//int main()
//{
//	//0~255
//	//存储到a和b中是发生截断
//	unsigned char a = 200;
//	unsigned char b = 100;
//
//	unsigned char c = 0;
//
//	c = a + b;//300
//	//计算的时候要发生整形提升
//	//00000000000000000000000011001000 - a
//	//00000000000000000000000001100100 - b
//	//00000000000000000000000100101100
//	//00000000000000000000000000101100 - 44
//
//	//00000000000000000000000011001000
//	//11001000 - a
//	//00000000000000000000000001100100
//	//01100100 - b
//	//
//	printf("%d %d", a + b, c);
//	//300 44
//	return 0;
//}

//
//题目名称：
//猜名次
//题目内容：
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2) + (a == 3) == 1) &&
							((b == 2) + (e == 4) == 1) &&
							((c == 1) + (d == 2) == 1) &&
							((c == 5) + (d == 3) == 1) &&
							((e == 4) + (a == 1) == 1))
						{
							if (a*b*c*d*e == 120)//1*2*3*4*5
							{
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);

								return 0;
							}
						}
					}
				}
			}
		}
	}


	return 0;
}