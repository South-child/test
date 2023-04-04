#include <iostream>
#include <string>
using namespace std;

void test_test1()
{
	string s1;
	string s2("西安市雁塔区");
	string s3 = "西安市雁塔区";

	string s4(10, '*');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	s2 += "莱安中心";

	cout << s2 << endl;

	string s5(s2);
	string s6 = s2;
	cout << s5 << s6 << endl;

	string s7("hello world", 5);
	cout << s7 << endl;

	string s8(s7, 2, 3);
	cout << s8 << endl;

	string s9(s7, 2, 30);
	cout << s9 << endl;

	string s10(s7, 2);
	cout << s10 << endl;
}

//char& operator[](size_t i)
//{
//	return _str[i];
//}

void test_string2()
{
	string s1("1234");
	// 遍历他

	// 1、下标 []
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
	}
	//s1[10];
	cout << s1 << endl;

	// 2、范围for
	for (auto& ch : s1)
	{
		ch--;
	}
	cout << s1 << endl;

	// 反转一下
	size_t begin = 0, end = s1.size() - 1;
	while (begin < end)
	{
		swap(s1[begin++], s1[end--]);
	}
	cout << s1 << endl;

	//reverse(s1.begin(), s1.end());
	cout << s1 << endl;
}

int main()
{
	test_string2();

	return 0;
}