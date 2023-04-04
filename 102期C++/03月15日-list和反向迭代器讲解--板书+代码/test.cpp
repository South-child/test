#include <iostream>
#include <list>
#include <string>
#include <assert.h>
using namespace std;

#include "List.h"
#include "vector.h"

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(4);
	lt.push_back(3);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.sort();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.reverse();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.unique(); // ÏÈÅÅÐò
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	bit::test_list5();
	bit::test_vector7();

	return 0;
}