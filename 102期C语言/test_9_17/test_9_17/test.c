#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//12
//#pragma pack(1)
//struct S1
//{
//	char c1;//1 1 1
//	int i;  //4 1 1
//	char c2;//1 1 1
//};
//#pragma pack()

//8
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};

#include <stddef.h>

struct S1
{
	char c1;
	int i; 
	char c2;
};

//offsetof 是一个宏

int main()
{
	printf("%u\n", offsetof(struct S1, c1));
	printf("%u\n", offsetof(struct S1, i));
	printf("%u\n", offsetof(struct S1, c2));

	return 0;
}
//
//
//struct S
//{
//	int data[1000];
//	int num;
//};
//
//void print1(struct S tmp)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", tmp.data[i]);
//	}
//	printf("\nnum = %d\n", tmp.num);
//}
//
//void print2(const struct S* ps)
//{
//	//->
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->data[i]);
//	}
//	printf("\nnum = %d\n", ps->num);
//}
//
//int main()
//{
//	struct S s = { {1,2,3,4,5,6,7,8,9,10}, 100 };
//	//print1(s);
//	print2(&s);
//	return 0;
//}
//

//位段是可以节省空间的！
//位段 - 二进制位
//
//性别
//男 - 女 - 保密
//00   01  10    11
//
//struct A
//{
//	int _a : 2;//_a 2个bit位
//	int _b : 5;//_b 5个bit位
//	int _c : 10;//
//	int _d : 30;//
//};
//
////47bit -6byte
////      -8byte
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//
//	return 0;
//}

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//
//	return 0;
//}
//
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	//err
//	printf("%d\n", offsetof(struct S, a));
//	return 0;
//}

//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//16 位机器 - int 2byte = 16bit

//枚举

//#define RED 2
//#define GREEN 4
//#define BLUE 8
//
//enum Color
//{
//	RED=2,
//	GREEN=4,
//	BLUE=8
//};
//
//
//int main()
//{
//	//printf("%d\n", RED);  //0
//	//printf("%d\n", GREEN);//1
//	//printf("%d\n", BLUE); //2
//	//RED = 6;
//	/*enum Color c = GREEN;
//
//	if (c == GREEN)
//	{
//		printf("绿色\n");
//	}*/
//	
//	return 0;
//}
//
//enum Option
//{
//	EXIT,//0
//	ADD,//1
//	SUB,//2
//	MUL,//3
//	DIV//4
//};
//
//void menu()
//{
//	printf("******************************\n");
//	printf("**** 1. add     2. sub    ****\n");
//	printf("**** 3. mul     4. div    ****\n");
//	printf("**** 0. exit              ****\n");
//	printf("******************************\n");
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			//加法
//			break;
//		case SUB:
//
//			break;
//		case MUL:
//
//			break;
//		case DIV:
//
//			break;
//		case EXIT:
//
//			break;
//		}
//	} while ();
//	return 0;
//}


//
//union Un
//{
//	char c;//1
//	int i;//4
//};
//
//int main()
//{
//	union Un u = {0};
//	//printf("%d\n", sizeof(u));
//
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}

//判断当前计算机的大小端存储
//
//int check_sys()
//{
//	union U
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	//返回1 - 小端
//	//返回0 - 大端
//	return u.c;
//}
//
//int main()
//{
//	int a = 1;//0x 00 00 00 01
//	//低---------------------> 高
//	//01 00 00 00 - 小端存储
//	//00 00 00 01 - 大端存储
//	//
//	//char* pc = (char*)&a;
//	//if (*pc == 1)
//	//{
//	//	printf("小端\n");
//	//}
//	//else
//	//{
//	//	printf("大端\n");
//	//}
//
//	/*union U
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	if (u.c == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{ 
//		printf("大端\n");
//	}*/
//	if (check_sys() == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
//
//union Un1
//{
//	char c[5];//5 1
//	int i;//4     4
//};
//
//union Un2
//{
//	short c[7];//14 2
//	int i;//4 8     4
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));//8
//	printf("%d\n", sizeof(union Un2));//16
//
//	return 0;
//}