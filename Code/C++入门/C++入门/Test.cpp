#include<iostream>
using namespace std;

//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====定义引用类型
//
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//
//	//int& rra; //“rra”: 必须初始化引用s
//	int b = 20;
//
//	ra = b;
//}
//
//int main()
//{
//	TestRef();
//
//	return 0;
//}

//int& Count()
//{
//	int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	return 0;
//}

//int& Count()
//{
//	int n = 0;
//	cout << &n << endl;
//
//	n++;
//	// ...
//	return n;
//}
//
//void Func()
//{
//	int x = 100;
//	cout << &x << endl;
//}
//
//int main()
//{
//	int& ret = Count();
//
//	cout << ret << endl;
//	cout << ret << endl;
//
//	Func();
//	cout << ret << endl;
//
//	cout << &ret << endl;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////
// 正确玩法
//int Count1()
//{
//	int n = 0;
//	cout << &n << endl;
//
//	n++;
//	// ...
//	return n;
//}
//
//int& Count2()
//{
//	static int n = 0;
//	cout << &n << endl;
//
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret1 = Count1();
//	int ret2 = Count2();
//
//
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//
//	return 0;
//}

//#include <time.h>
//// 4w byte
//struct A{ int a[10000]; };
//
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//#include "SeqList.h"
//
//int main()
//{
//	SL sl;
//	SLInit(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//
//	// 偶数*2;
//	for (size_t i = 0; i < SLSize(&sl); ++i)
//	{
//		if (SlAt(&sl, i) % 2 == 0)
//		{
//			SlAt(&sl, i) *= 2;
//		}
//	}
//
//	for (size_t i = 0; i < SLSize(&sl); ++i)
//	{
//		cout << SlAt(&sl, i) << endl;
//	}
//
//
//	SLDestory(&sl);
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(int left, int right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//#include <time.h>
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//
//void TestFunc2(A& a){}
//
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	//Swap(a, b);
//	//Swap(a, b);
//	TestRefAndValue();
//
//	return 0;
//}

// 减少拷贝,提高效率、
// 一般用引用做参数都是用const 引用
void Func(const int& x)
{

}

//int main()
//{
//	int a = 0;
//	// 权限平移
//	int& ra = a;
//
//	// 指针和引用赋值中，权限可以缩小，但是不能放大
//	const int b = 1;
//
//	// 拷贝
//	//a = b;
//
//	// 我引用你，权限放大 不行
//	//int& rb = b;
//
//	// 我引用你，我的权限的缩小 可以
//	const int& rra = a;
//	//rra++;
//	a++;
//
//	// 权限平移
//	const int& rb = b;
//
//	Func(a);
//	Func(b);
//	Func(rra);
//  Func(10);
//
//	return 0;
//}

//void func(const int& N = 10)
//{
//
//}
//
//int Count()
//{
//	int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	const int& b = 10;
//
//	double d = 12.34;
//
//	cout << (int)d << endl;
//
//	int i = (int)d; // 可以
//
//	//int& ri = d; // 不可以
//
//	const int& ri = d; // 可以
//	cout << ri << endl;
//
//	//int& ret = Count();
//	const int& ret = Count();
//
//	return 0;
//}

// 语法上面，ra是a的别名，不开空间
// 底层实现，引用是使用指针实现的
//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 30;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////
#include <map>

// C++11 小语法 -- 语法糖
int main()
{
	int a = 10;
	// 根据a的类型推导b的类型
	auto b = a;

	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "orange", "橙子" },
	{ "pear", "梨" } };

	// auto是方便类型下面的地方
	//std::map<std::string, std::string>::iterator it = m.begin();
	auto it = m.begin();

	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";

	cout << endl;

	// 范围for遍历
	// 依次取array中数据赋值给e 自动判断结束，自动迭代
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}