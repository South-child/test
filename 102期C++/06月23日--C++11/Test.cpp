#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
#include <thread>
using namespace std;

#include <assert.h>

// ������
//class A
//{
//public:
//	//explicit A(int a)
//	//	:_a(a)
//	//{}
//
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};

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
			cout << "string(char* str)" << endl;

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

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- ת����Դ" << endl;
			swap(s);

			return *this;
		}

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

	bit::string to_string(int value)
	{
		bit::string str;
		while (value)
		{
			int val = value % 10;
			str += ('0' + val);
			value /= 10;
		}
		reverse(str.begin(), str.end());

		return str;
	}
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

//int main()
//{
//	bit::string str("hello world");
//	//func1(str);
//	//func2(str);
//
//	/*str += '!';
//	str + '!';*/
//	//func3();
//
//	return 0;
//}

//int main()
//{
//	std::string s("111111111111111111111");
//	std::string s1 = s;
//
//	//std::string s2 = move(s);
//	move(s);
//
//	return 0;
//}


//int main()
//{
//	cout << bit::to_string(1234).c_str() << endl;
//	bit::string ret = bit::to_string(1234);
//
//
//	return 0;
//}

//int main()
//{
//	//bit::string s1("hello world");
//	//bit::string s2("xxxx");
//	////s1 = s2;
//	//s1 = move(s2);
//
//	bit::string ret;
//	ret = bit::to_string(12345);
//
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////
//int main()
//{
//	list<bit::string> lt;
//	bit::string s("111111");
//	lt.push_back(s);
//	cout << endl;
//
//	lt.push_back("222222");
//	cout << endl;
//
//	lt.push_back(bit::to_string(333333));
//	cout << endl;
//}


void Fun(int &x){ cout << "��ֵ����" << endl; }
void Fun(const int &x){ cout << "const ��ֵ����" << endl; }

void Fun(int &&x){ cout << "��ֵ����" << endl; }
void Fun(const int &&x){ cout << "const ��ֵ����" << endl; }

// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
	cout << "-----------------------------" << endl;

	Fun(std::forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);		      // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	return 0;
//}

//void PerfectForward(int&& t)
//{
//	cout << &t << endl;
//	Fun(t);
//}
//
//void PerfectForward(const int& t)
//{
//	Fun(t);
//}
//
//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	//PerfectForward(std::move(a)); // ��ֵ
//
//	//const int b = 8;
//	//PerfectForward(b);		      // const ��ֵ
//	//PerfectForward(std::move(b)); // const ��ֵ
//
//	return 0;
//}

template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(T&& x)
	{
		// ֻҪ��ֵ���ã��ٴ��������������ã�Ҫ������ֵ���ԣ�����������ת��
		//Insert(_head, x);
		Insert(_head, std::forward<T>(x));
	}

	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
	}

	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;

		//Node* newnode = new Node;
		//newnode->_data = std::forward<T>(x); // �ؼ�λ��

		Node* newnode = (Node*)malloc(sizeof(Node));
		//new(&newnode->_data)T(x);
		new(&newnode->_data)T(std::forward<T>(x));

		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}

	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = x; // �ؼ�λ��

		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};

//int main()
//{
//	List<bit::string> lt;
//	lt.PushBack("1111");
//	//lt.PushFront("2222");
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////
// lambda

struct Goods
{
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};


struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2, 3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//}

//int main()
//{
//	// ʵ��һ����������ӵ�lambda
//	//auto add1 = [](int a, int b)->int{return a + b; };
//	// ����ֵ���Ϳ���ʡ��
//	auto add1 = [](int a, int b){return a + b; };
//
//	//auto add2 = add1;
//	//decltype(add1) add3 = add1;
//
//	cout << add1(1, 2) << endl; 
//
//	// û�в�������ʡ�Բ����б�
//	auto func1 = []{cout << "hello world" << endl; };
//	func1();
//
//	return 0;
//}
int a = 0, b = 1;
// ��ȫ���в��ܲ�׽����
//auto func5 = [a, b](){};
auto func5 = [](){};

//int main()
//{
//	// ��׽�б��Ǹ�����أ�
//	int a = 1, b = 2;
//	auto swap1 = [](int& x, int& y) {
//		int z = x;
//		x = y;
//		y = z;
//	};
//
//	swap1(a, b);
//
//	auto swap2 = [a, b]()mutable {
//		int z = a;
//		a = b;
//		b = z;
//	};
//
//	swap2();
//
//	auto swap3 = [&a, &b](){
//		int z = a;
//		a = b;
//		b = z;
//	};
//
//	swap3();
//
//	auto func3 = [=, &a](){
//	};
//	swap3();
//
//
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2, 3 }, { "����", 1.5, 4 } };
//	//auto priceLess = [](const Goods& g1, const Goods& g2){return g1._price < g2._price; };
//	//sort(v.begin(), v.end(), priceLess);
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._evaluate > g2._evaluate; });
//}


class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// lamber  �ײ�ԭ����ʵ�Ǳ������һ��lambda_uuid��һ���º�����
//	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
//	r2(10000, 2);
//	return 0;
//
//	// lamber
//	auto r3 = [=](double monty, int year)->double{return monty*rate*year; };
//	r3(10000, 2);
//	return 0;
//}

//int main()
//{
//	// ��׽�б��Ǹ�����أ�
//	int a = 1, b = 2;
//	auto swap1 = [](int& x, int& y) {
//		int z = x;
//		x = y;
//		y = z;
//	};
//
//	cout << typeid(swap1).name() << endl;
//};

//class Person
//{
//public:
//	Person() = default;
//
//	Person(const char* name, int age)
//		:_name(name)
//		, _age(age)
//	{}
//
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{}
//private:
//	bit::string _name;
//	int _age = 0;
//};

// ����A�Ķ���������
//class A
//{
//public:
//	A() = default;
//
//	void f()
//	{
//		A copy = *this;
//	}
//private:
//	// C++98 ��������1��ֻ������ʵ�� 2��������˽��
//	A(const A& a);
//};
//
//A::A(const A& a)
//{}
//
//int main()
//{
//	//Person p;
//	A a1;
//	//A a2 = a1;
//	a1.f();
//
//	return 0;
//}

//class A
//{
//public:
//	A() = default;
//
//	void f()
//	{
//		A copy = *this;
//	}
//
//	A(const A& a) = delete;
//};
//
//A::A(const A& a)
//{}
//
//int main()
//{
//	//Person p;
//	A a1;
//	A a2 = a1;
//	a1.f();
//
//	return 0;
//}

// ���´�����vs2013�в������֣���vs2019�²�����ʾ������������ԡ�
class Person
{
public:
	/*Person(const char* name = "����", int age = 0)
		:_name(name)
		, _age(age)
	{}*/

	/*Person(const Person& p)
	:_name(p._name)
	,_age(p._age)
	{}*/

	/*Person& operator=(const Person& p)
	{
	if(this != &p)
	{
	_name = p._name;
	_age = p._age;
	}
	return *this;
	}*/

	/*~Person()
	{}*/

private:
	bit::string _name;
	int _age = 0;
};


//int main()
//{
//	Person s1;
//	//Person s2 = s1;
//	Person s3 = std::move(s1);
//	//Person s4;
//	//s4 = std::move(s2);
//
//	return 0;
//}

//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(Args) << endl;
//	cout << sizeof...(args) << endl << endl;
//	for (size_t i = 0; i < sizeof...(Args); ++i)
//	{
//		// �޷����룬�������޷�����
//		cout << args[i] << "-";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

// �ݹ���ֹ����
//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl << endl;
//}
//
//// ��������ӡ��������ÿ�����������ͼ�ֵ
//template <class T, class ...Args>
//void ShowList(T val, Args... args)
//{
//	cout << typeid(val).name() << ":" << val << endl;
//	ShowList(args...);
//}
//
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

//template <class T>
//void PrintArg(T val)
//{
//	T copy(val);
//	cout << typeid(T).name() << ":" << val << endl;
//}
//
////չ������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}

template <class T>
int PrintArg(T val)
{
	T copy(val);
	cout << typeid(T).name() << ":" << val << endl;

	return 0;
}

//չ������
template <class ...Args>
void ShowList(Args... args)
{
	int arr[] = { PrintArg(args)... };
	cout << endl;
}

//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

//int main()
//{
//	vector<bit::string> v;
//	bit::string s("111111");
//	v.push_back(s);
//	v.push_back(std::move(s));
//	v.push_back("22222222");
//
//	return 0;
//}
//
//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//	mylist.push_back(make_pair(1, 'A'));
//	mylist.emplace_back(make_pair(1, 'A'));
//	mylist.emplace_back(1, 'A');
//
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//}

//int main()
//{
//	std::list< std::pair<int, bit::string> > mylist;
//	mylist.emplace_back(10, "sort");
//	mylist.emplace_ba(make_pair(20, "sort"));
//	cout << endl << endl;
//	mylist.push_back(make_pair(30, "sort"));
//	mylist.push_back({ 40, "sort" });
//
//	return 0;
//}

void Print(int n, int x)
{
	for (int i = 0; i < n; ++i)
	{
		cout << i * x << endl;
	}
}

int main()
{
	//thread t1;

	/*thread t2(Print, 10, 2);
	t2.join();*/
	
	int n;
	cin >> n;
	vector<thread> vthds;
	vthds.resize(n);

	for (auto& t : vthds)
	{
		t = thread(Print, 100, 2);
	}

	for (auto& t : vthds)
	{
		t.join();
	}

	return 0;
}


