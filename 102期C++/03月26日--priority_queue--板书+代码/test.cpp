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
	// ����ȳ� -- ��֧�ֵ�����
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
	// Ĭ���Ǵ�����ȼ��� -- Ĭ�ϸ��ķº�����less
	//priority_queue<int> pq;

	// ����С�����ȼ��� -- ��һ��greater�ķº���
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

// ����������ͣ���֧�ֱȽϣ����߱Ƚϵķ�ʽ����������Ҫ��
// ��ô�����Լ�ʵ�ַº����������Լ���Ҫ�ķ�ʽȥ�Ƚϣ����ƱȽ��߼�
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
//	// Less->�º������� less�ͽк�������
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
// ģ�����

//#define N 100

// ������ģ����� -- ���γ���
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
//	// ����array�ļ�ֵ�����ޡ�array����C++11��һЩ���ߵ����
//	array<int, 10> aa1; // C++11
//	int aa2[10]; // C
//	cout << sizeof(aa1) << endl;
//	cout << sizeof(aa2) << endl;
//
//	aa1[4] = 4;
//	aa2[4] = 4;
//
//	// arrayΨһ�����ƾ��Ƕ�Խ����ʼ����ϸ�
//	// array��operator[]�м���Զ��Լ��
//	aa1[20] = 20;
//	aa2[20] = 20;
//
//
//	//A < 100 > aa;
//
//	return 0;
//}

// ����ģ�� -- ����ƥ��
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
//// ����ģ�����档�����ػ��伦��
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
//	// ����ƥ��
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

// �ػ� -- ���⻯��������Ҫ���ĳЩ�������⻯����
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
