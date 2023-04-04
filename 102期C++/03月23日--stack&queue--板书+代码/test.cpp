#include<iostream>
#include <stack>
#include<queue>
using namespace std;

#include "Stack.h"
#include "Queue.h"

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

int main()
{
	bit::test_stack();
	//test_stack();

	bit::test_queue();

	return 0;
}