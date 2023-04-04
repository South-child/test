#include<iostream>
#include<string>
#include <vector>
#include <list>
using namespace std;

#include <assert.h>

void test_string1()
{
	string s1("hello world");

	// 遍历+修改
	// 方式1：下标+[]
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
	}

	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	// 方式2：迭代器
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	cout << endl;

	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 方式3：范围for,自动往后迭代，自动判断结束
	// C++11
	//for (char& e : s1)
	for (auto& e : s1)
	{
		e -= 1;
	}

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void func(const string& s)
{
	//string::const_iterator it = s.begin();
	auto it = s.begin();
	while (it != s.end())
	{
		//*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//auto rit = s.rbegin();
	string::const_reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		//*rit = 'A';
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_string2()
{
	// 反向迭代器
	string s1("hello world");
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// ...
	list<int> lt(10, 5);
	list<int>::iterator ltIt = lt.begin();
	while (ltIt != lt.end())
	{
		cout << *ltIt << " ";
		++ltIt;
	}
	cout << endl;

	string str("hello world");
	func(str);
}

void TestPushBack()
{
	string s;
	s.reserve(1000); // 申请至少能存储1000个字符的空间
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		//s.push_back('c');
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}


void test_string3()
{
	// 反向迭代器
	string s1;
	s1.reserve(100);

	string s2;
	s2.resize(100, 'x');

	string s3("hello world");
	s3.reserve(100);

	string s4("hello world");
	s4.resize(100, 'x');

	string s5("hello world");
	s5.resize(5);
}

void test_string4()
{
	string s("hello world");
	cout << s << endl;
	cout << s.c_str() << endl;

	//string file("test.txt");
	//FILE* fout = fopen(file.c_str(), "w");

	//// 要求你取出文件的后缀名
	//size_t pos = file.find('.');
	//if (pos != string::npos)
	//{
	//	//string suffix = file.substr(pos, file.size() - pos);
	//	string suffix = file.substr(pos);
	//	cout << suffix << endl;
	//}

	string file("test.txt.zip");
	FILE* fout = fopen(file.c_str(), "w");

	// 要求你取出文件的后缀名
	size_t pos = file.rfind('.');
	if (pos != string::npos)
	{
		//string suffix = file.substr(pos, file.size() - pos);
		string suffix = file.substr(pos);
		cout << suffix << endl;
	}

	// http://www.cplusplus.com/reference/string/string/
	// https://translate.google.cn/?sl=zh-CN&tl=en&text=%E5%90%8E%E7%BC%80&op=translate
	string url("http://www.cplusplus.com/reference/string/string/find/");
	size_t pos1 = url.find(':');
	string protocol = url.substr(0, pos1 - 0);
	cout << protocol << endl;

	size_t pos2 = url.find('/', pos1+3);
	string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
	cout << domain << endl;

	string uri = url.substr(pos2 + 1);
	cout << uri << endl;
}

void test_string5()
{
	string s("hello world");
	s += ' ';
	s += "!!!!";
	cout << endl;

	// 头插  效率，O(N),尽量少用
	s.insert(0, 1, 'x');
	s.insert(s.begin(), 'y');
	s.insert(0, "test");
	cout << s << endl;

	// 中间位置插入
	s.insert(4, "&&&&&");
	cout << s << endl;
}


void test_string6()
{
	string s("hello world");
	// 尽量少用头部和中间删除，因为要挪动数据，效率低
	s.erase(0, 1);
	s.erase(s.size() - 1, 1);
	cout << s << endl;

	s.erase(3);
	cout << s << endl;
}

//int main()
//{
//	//TestPushBack();
//	//test_string2();
//	//test_string3();
//	test_string6();
//
//	return 0;
//}

#include<iostream>
using namespace std;

//int main()
//{
//	string s1, s2;
//	//cin >> s1;
//	//cin >> s2;
//	char ch = getchar();
//	//char ch;
//	//cin >> ch;
//	//char ch = cin.get();
//	while (ch != '\n')
//	{
//		s1 += ch;
//		ch = getchar();
//		//cin >> ch;
//	}
//	cout <<s1<<endl;
//
//	/*size_t pos = s.rfind(' ');
//	if (pos == string::npos)
//	{
//	cout << s.size() << endl;
//	}
//	else
//	{
//	cout << s.size() - pos - 1;
//	}*/
//
//	return 0;
//}

void test_string7()
{
	string s1("hello world");
	string s2("string");
	cout << (s1 < s2) << endl;

	// 少用
	cout << ("hhhhh" < s2) << endl;
	cout << (s1 < "ssssss") << endl;
}

void test_string8()
{
	int val = stoi("1234");
	cout << val << endl;

	string str = to_string(3.14);
	cout << str << endl;
}

class Solution {
public:
	bool isLeterOrNumber(char ch)
	{
		if (ch >= '0' && ch <= '9')
			return true;

		if (ch >= 'A' && ch <= 'Z')
			return true;

		if (ch >= 'a' && ch <= 'z')
			return true;

		return false;
	}
	bool isPalindrome(string s) {
		size_t begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isLeterOrNumber(s[begin]))
				++begin;

			while (begin < end && !isLeterOrNumber(s[end]))
				--end;

			if (tolower(s[begin]) != tolower(s[end]))
				return false;

			++begin;
			--end;
		}


		return true;
	}
};

//int main()
//{
//	//test_string8();
//	//Solution s;
//	//s.isPalindrome("A man, a plan, a canal: Panama");
//	//Solution().isPalindrome("A man, a plan, a canal: Panama");
//
//	return 0;
//}

#include "string.h"

int main()
{
	bit::test_string5();
	/*std::string s1("hello world");
	std::string s2("111111");

	s1.swap(s2);
	swap(s1, s2);*/

	/*std::string s1("1111111111111111111111111");
	s1.reserve(10);
	s1.resize(5);*/

	return 0;
}