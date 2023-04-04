#include<iostream>
using namespace std;

#include "SList.h"

//int main()
//{
//	int a = 10;
//	// 引用定义
//	int& b = a;
//
//	// 取地址
//	int* p = &b;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	a = 20;
//	b = 30;
//
//	return 0;
//}

//int main()
//{
//	// 1、引用在**定义时必须初始化**
//	//int a = 10;
//	//int& b;
//
//	// 2、一个变量可以有多个引用
//	//int a = 10;
//	//int& b = a;
//	//int& c = a;
//	//int& d = b;
//	//double d = 1.1;
//
//	// 3、引用一旦引用一个实体，再不能引用其他实体
//	int a = 10;
//	int& b = a;
//
//	int c = 20;
//	// 1、这里是让b变成c的别名呢？ 否
//	// 2、还是把c赋值给b？ 是
//	b = c;
//
//	//int* p1 = &a;
//	//p1 = &c;
//
//	return 0;
//}

// 1、引用做参数
// _Z4swappipi
void swap(int* p1, int* p2) // 传地址
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// _Z4swapriri
void swap(int& r1, int& r2) // 传引用
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

// _Z4swapii
//void swap(int r1, int r2)   // 传值
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// 他们三个构成函数重载
// 但是swap(x, y);调用时存在歧义，他不知道调用，传值还是传引用
// 类似以前讲的这个,他们构成重载，但是存在歧义
// void f();
// void f(int x = 0, int y = 0);

//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	swap(x, y);
//
//	return 0;
//}

int* singleNumbers(int* nums, int numsSize, int& returnSize){
//int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int* a = (int*)malloc(sizeof(int) * 2);

	//...

	//*returnSize = 2;
	returnSize = 2;
	return a;
}

int TestList()
{
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	SListPushFront(plist, 5);
	SListPushFront(plist, 6);
	SListPushFront(plist, 7);

	SListPrint(plist);

	int a = 10;
	int& b = a;

	int* p1 = &a;
	int*& p2 = p1;

	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
};

//struct TreeNode* CreateTree(char* str, int* pi)
struct TreeNode* CreateTree(char* str, int& i)
{
	if (str[i] == '#')
	{
		(i)++;
		return NULL;
	}

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = str[i++];
	root->left = CreateTree(str, i);
	root->right = CreateTree(str, i);

	return root;
}

void InOrder(struct TreeNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

//int main()
//{
//	char str[100];
//	while (scanf("%s", str) != EOF)
//	{
//		int j = 0;
//		struct TreeNode* root = CreateTree(str, j);
//		InOrder(root);
//	}
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
// 传值返回值
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

// 传引用返回
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	//Add(10, 20);
//	printf("11111111111111111111111111111111111111\n");
//	cout << ret << endl;
//
//	return 0;
//}

#include <time.h>
struct A{ int a[10000]; };

A a;
// 值返回 -- 每次拷贝40000byte
A TestFunc1() { return a; }

// 引用返回 -- 没有拷贝
A& TestFunc2(){ return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

void TestFunc1(A a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

//void f(int a);
//void f(int& r);
// 总结一下：引用的作用主要体现在传参和传返回值
// 1、引用传参和传返回值，有些场景下面，可以提高性能。（大对象+深拷贝对象--后面会学）
// 2、引用传参和传返回值，输出型参数和输出型返回值。通俗点说，有些场景下面，形参的改变可以改变实参。
// 有些场景下面,引用返回，可以改变返回对象。--了解一下，后面会学
//
//int main()
//{
//	TestReturnByRefOrValue();
//	TestRefAndValue();
//
//	return 0;
//}

// 假设x是一个大对象或者是后面学习深拷贝的对象
// 那么尽量用引用传参，减少拷贝。如果f函数中不改变x
// 建议尽量用cosnt引用传参
//void f(int& x)
void f(const int& x)
{
	cout << x << endl;
}

// 常引用
int main()
{
	// 权限放大  不可以
	//const int a = 10;
	//int& b = a;

	// 权限不变 可以
	const int a = 10;
	const int& b = a;

	// 权限的缩小 可以
	int c = 10;
	const int& d = c;

	f(a);
	f(c);
	f(10);

	return 0;
}