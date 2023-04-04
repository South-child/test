#include<iostream>
#include <stack>
#include <queue>
#include <array>
#include <functional>
using namespace std;

#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

void test_stack()
{
	// 后进先出 -- 不支持迭代器
	//stack<int, vector<int>> s;
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priority_queue1()
{
	// 默认是大的优先级高 -- 默认给的仿函数是less
	//priority_queue<int> pq;

	// 控制小的优先级高 -- 给一个greater的仿函数
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(3);
	pq.push(3);
	pq.push(7);
	pq.push(1);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//void test_priority_queue2()
//{
//	//priority_queue<Date> pq;
//	priority_queue<Date, vector<Date>, greater<Date>> pq;
//
//	pq.push(Date(2022, 3, 26));
//	pq.push(Date(2021, 10, 26));
//	pq.push(Date(2023, 3, 26));
//
//	while (!pq.empty())
//	{
//		cout << pq.top();
//		pq.pop();
//	}
//	cout << endl;
//}

struct LessPDate
{
	bool operator()(const Date* d1, const Date* d2) const
	{
		//return *d1 < *d2;
		return (d1->_year < d2->_year) ||
			(d1->_year == d2->_year && d1->_month < d2->_month) ||
			(d1->_year == d2->_year && d1->_month == d2->_month && d1->_day < d2->_day);
	}
};

// 如果数据类型，不支持比较，或者比较的方式，不是你想要的
// 那么可以自己实现仿函数，按照自己想要的方式去比较，控制比较逻辑
void test_priority_queue2()
{
	priority_queue<Date*, vector<Date*>, LessPDate> pq;

	pq.push(new Date(2022, 3, 26));
	pq.push(new Date(2021, 10, 26));
	pq.push(new Date(2023, 3, 26));

	while (!pq.empty())
	{
		cout << *pq.top();
		pq.pop();
	}
	cout << endl;
}

//struct Less
//{
//	bool operator()(int x, int y)
//	{
//		return x < y;
//	}
//};
//
//struct Greater
//{
//	bool operator()(int x, int y)
//	{
//		return x > y;
//	}
//};

//int main()
//{
//	//bit::test_stack();
//	//test_stack();
//
//	//bit::test_queue();
//	//test_priority_queue();
//	test_priority_queue2();
//
//	//bit::test_priority_queue();
//
//	// Less->仿函数类型 less就叫函数对象
//	/*Less less;
//	cout << less(1, 2) << endl;
//
//	Greater gt;
//	cout << gt.operator()(1, 2) << endl;
//	cout << gt(1, 2) << endl;*/
//
//	/*Less<int> lessi;
//	cout << lessi(1, 2) << endl;
//	cout << Less<int>()(1, 2) << endl;
//	cout << Less<double>()(1.1, 2.2) << endl;*/
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 模板进阶

//#define N 100

// 非类型模板参数 -- 整形常量
template<class T, size_t N = 10>
class MyStack
{
public:
	void Push(const T& x)
	{}
private:
	T _a[N];
	size_t _top;
};

//C++98 C++11
//template<size_t N, double D, string S>
template<size_t N>
class A
{};

//int main()
//{
//	MyStack<int, 100> st1; // 100;
//	MyStack<int, 200> st2; // 200;
//	MyStack<int> st3;
//
//	vector<int> v;
//	v.resize(10);
//
//	// 所以array的价值很有限。array算是C++11中一些鸡肋的设计
//	array<int, 10> aa1; // C++11
//	int aa2[10]; // C
//	cout << sizeof(aa1) << endl;
//	cout << sizeof(aa2) << endl;
//
//	aa1[4] = 4;
//	aa2[4] = 4;
//
//	// array唯一的优势就是对越界访问检查更严格
//	// array的operator[]中间可以断言检查
//	aa1[20] = 20;
//	aa2[20] = 20;
//
//
//	//A < 100 > aa;
//
//	return 0;
//}

// 函数模板 -- 参数匹配
//template<class T>
//bool ObjLess(T left, T right)
//{
//	return left < right;
//}
//
//bool ObjLess(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//// 函数模板里面。这种特化佷鸡肋
////template<>
////bool ObjLess<Date*>(Date* left, Date* right)
////{
////	return *left < *right;
////}
//
//int main()
//{
//	cout << ObjLess(1, 2) << endl;
//	Date* p1 = new Date(2022, 3, 26);
//	Date* p2 = new Date(2022, 4, 26);
//
//	// 参数匹配
//	cout << ObjLess(p1, p2) << endl;
//
//	return 0;
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 特化 -- 特殊化，比如需要针对某些类型特殊化处理
template<>
class Data < int, char >
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

int main()
{
	//Data<int, int> d1;
	//Data<int, char> d2;

	bit::priority_queue<Date*> pq;

	pq.push(new Date(2022, 3, 26));
	pq.push(new Date(2021, 10, 26));
	pq.push(new Date(2023, 3, 26));

	while (!pq.empty())
	{
		cout << *pq.top();
		pq.pop();
	}
	cout << endl;

	return 0;
}
