#include<iostream>
using namespace std;

//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====������������
//
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//
//	//int& rra; //��rra��: �����ʼ������s
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
// ��ȷ�淨
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
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
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
//	// ż��*2;
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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
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

// ���ٿ���,���Ч�ʡ�
// һ��������������������const ����
void Func(const int& x)
{

}

//int main()
//{
//	int a = 0;
//	// Ȩ��ƽ��
//	int& ra = a;
//
//	// ָ������ø�ֵ�У�Ȩ�޿�����С�����ǲ��ܷŴ�
//	const int b = 1;
//
//	// ����
//	//a = b;
//
//	// �������㣬Ȩ�޷Ŵ� ����
//	//int& rb = b;
//
//	// �������㣬�ҵ�Ȩ�޵���С ����
//	const int& rra = a;
//	//rra++;
//	a++;
//
//	// Ȩ��ƽ��
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
//	int i = (int)d; // ����
//
//	//int& ri = d; // ������
//
//	const int& ri = d; // ����
//	cout << ri << endl;
//
//	//int& ret = Count();
//	const int& ret = Count();
//
//	return 0;
//}

// �﷨���棬ra��a�ı����������ռ�
// �ײ�ʵ�֣�������ʹ��ָ��ʵ�ֵ�
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

// C++11 С�﷨ -- �﷨��
int main()
{
	int a = 10;
	// ����a�������Ƶ�b������
	auto b = a;

	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "orange", "����" },
	{ "pear", "��" } };

	// auto�Ƿ�����������ĵط�
	//std::map<std::string, std::string>::iterator it = m.begin();
	auto it = m.begin();

	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";

	cout << endl;

	// ��Χfor����
	// ����ȡarray�����ݸ�ֵ��e �Զ��жϽ������Զ�����
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}