#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
using namespace std;

#include <assert.h>

// ������
class A
{
public:
	//explicit A(int a)
	//	:_a(a)
	//{}

	A(int a)
		:_a(a)
	{}
private:
	int _a;
};

// �����
struct Point
{
	int _x;
	int _y;

	Point(int x, int y)
		:_x(x)
		, _y(y)
	{
		cout << "Point(int x, int y)" << endl;
	}

	//explicit Point(int x, int y)
	//	:_x(x)
	//	, _y(y)
	//{
	//	cout << "Point(int x, int y)" << endl;
	//}
};

//int main()
//{
//	// ���������캯����֧����ʽ����ת��
//	A aa1(1);
//	A aa2 = 2;
//	string s1("hello");
//	string s2 = "world";
//	vector<string> v;
//	v.push_back(s1);
//	v.push_back("world");
//
//	// C++11 
//	Point p1(1, 2);
//	// ��������캯����֧����ʽ����ת��
//	Point p2 = { 1, 2 };
//	Point p3{ 1, 2 };
//
//	int a = 1;
//	int b = { 2 };
//	int c { 3 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//
//	int* ptr1 = new int[5]{1,2,3};
//	Point* ptr2 = new Point[2]{{1, 1}, { 2, 2 } };
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	vector<int> v2 = {1, 2, 3, 4};
//	vector<int> v3 = { 1, 2, 3, 4, 5, 6, 7, 8};
//	list<int> lt1 = { 1, 2, 3, 4, 5 };
//	pair<string, string> kv("left", "���");
//	map<string, string> dict = { { "insert", "����" }, {"sort", "����"}, kv, make_pair("list", "�б�")};
//	v2 = { 10, 20, 30 };
//
//	initializer_list<int> ilt = { 1, 2, 3, 4, 5, 6, 7, 8 };
//
//	return 0;
//}

int func(int a)
{
	cout << "int func(int a)" << endl;
	return a;
}

//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	//cout << typeid(x).name() << endl;
//	decltype(x) z = 2;
//
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p;      // p��������int*
//
//	int(*pfunc1)(int) = func;
//	auto pfunc2 = func;
//	decltype(pfunc2) pfunc3 = func;
//	decltype(&func) pfunc4 = func;
//
//	map<string, string> dict = { { "sort", "����" }, { "insert", "����" } };
//	auto it = dict.begin();
//	// decltype��һ��ʹ�ó���
//	//decltype(it) copyIt = it;
//	auto copyIt = it;
//	vector<decltype(it)> v;
//	v.push_back(it);
//
//	return 0;
//}

// �����﷨
//int main()
//{
//	int a1[10];
//	array<int, 10> a2;
//	cout << sizeof(a2) << endl;
//
//	// 1��֧�ֵ����������ü���STL�����淨
//	// 2������Խ��ļ��
//	a1[14] = 0; // *(a1+14) = 0;  ���
//	a2[14] = 0; // a2.operator[](14) = 0; // �ؼ�
//
//
//	return 0;
//}

// ����ȡ��ַ���󣬾�����ֵ
//int main()
//{
//	int a = 10;
//	int& r1 = a;
//	int* p = &a;
//	int& r2 = *p;
//
//	const int b = 10;
//	const int& r3 = b;
//
//	return 0;
//}

// ����ȡ��ַ���󣬾�����ֵ
//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	//cout << &fmin(x, y) << endl;
//
//	// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//
//	return 0;
//}

// ��������
// ��ֵ�����ܷ�������ֵ
// ��ֵ�����ܷ�������ֵ
//int main()
//{
//	// ���¼������ǳ�������ֵ
//	double x = 1.1, y = 2.2;
//	10;
//	x + y;
//	fmin(x, y);
//
//	// ���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	// ��ֵ�����ܷ�������ֵ -- ����ֱ�����ã�����const ��ֵ���ÿ���������ֵ
//	// void push_back(const T& x)
//	const int& r1 = 10;
//	const double& r2 = x+y;
//	const double& r3 = fmin(x, y);
//
//	// ��ֵ�����ܷ�������ֵ -- ����ֱ�����ã����ǿ�����ֵ���ÿ�������move�Ժ���ֵ
//	int*&& rr1 = move(p);
//	int&& rr2 = move(*p);
//	int&& rr3 = move(b);
//	const int&& rr4 = move(c);
//
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	const double&& rr3 = x + y;
//
//	cout << &rr1 << endl;
//	cout << &rr2 << endl;
//	rr1 = 20;
//	rr2 = 30.33;
//	//rr3 = 1.1;
//
//	return 0;
//}

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- ��Դת��" << endl;

			this->swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			//cout << "~string()" << endl;

			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string operator+(char ch)
		{
			string tmp(*this);
			push_back(ch);

			return tmp;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}

// ����1
// ��ֵ���������������������Ľ����������
void func1(bit::string s)
{}

void func2(const bit::string& s)
{}

// ����2
// ��ֵ����������ֵ��ֻ�ܽ����������
// string& operator+=(char ch) �����
// string operator+(char ch)   û�н��

// ��ֵ���ã���ν��operator+��ֵ���ش��ڿ����������أ�
// C++11 ����ֵ��Ϊ������ֵ������ֵ
bit::string func3()
{
	bit::string str("hello world");
	//cin >> str;

	return str;
}

int main()
{
	bit::string str("hello world");
	//func1(str);
	//func2(str);

	/*str += '!';
	str + '!';*/
	func3();

	return 0;
}