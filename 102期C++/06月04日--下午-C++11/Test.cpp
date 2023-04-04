#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
using namespace std;

#include <assert.h>

// 单参数
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

// 多参数
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
//	// 单参数构造函数，支持隐式类型转换
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
//	// 多参数构造函数，支持隐式类型转换
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
//	pair<string, string> kv("left", "左边");
//	map<string, string> dict = { { "insert", "插入" }, {"sort", "排序"}, kv, make_pair("list", "列表")};
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
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p;      // p的类型是int*
//
//	int(*pfunc1)(int) = func;
//	auto pfunc2 = func;
//	decltype(pfunc2) pfunc3 = func;
//	decltype(&func) pfunc4 = func;
//
//	map<string, string> dict = { { "sort", "排序" }, { "insert", "插入" } };
//	auto it = dict.begin();
//	// decltype的一个使用场景
//	//decltype(it) copyIt = it;
//	auto copyIt = it;
//	vector<decltype(it)> v;
//	v.push_back(it);
//
//	return 0;
//}

// 鸡肋语法
//int main()
//{
//	int a1[10];
//	array<int, 10> a2;
//	cout << sizeof(a2) << endl;
//
//	// 1、支持迭代器，更好兼容STL容器玩法
//	// 2、对于越界的检查
//	a1[14] = 0; // *(a1+14) = 0;  抽查
//	a2[14] = 0; // a2.operator[](14) = 0; // 必检
//
//
//	return 0;
//}

// 可以取地址对象，就是左值
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

// 不能取地址对象，就是右值
//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	//cout << &fmin(x, y) << endl;
//
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//
//	return 0;
//}

// 交叉引用
// 左值引用能否引用右值
// 右值引用能否引用左值
//int main()
//{
//	// 以下几个都是常见的右值
//	double x = 1.1, y = 2.2;
//	10;
//	x + y;
//	fmin(x, y);
//
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	// 左值引用能否引用右值 -- 不能直接引用，但是const 左值引用可以引用右值
//	// void push_back(const T& x)
//	const int& r1 = 10;
//	const double& r2 = x+y;
//	const double& r3 = fmin(x, y);
//
//	// 右值引用能否引用左值 -- 不能直接引用，但是可以右值引用可以引用move以后左值
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

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 资源转移" << endl;

			this->swap(s);
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 转移资源" << endl;
			swap(s);

			return *this;
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
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

// 场景1
// 左值引用做参数，基本完美的解决所有问题
void func1(bit::string s)
{}

void func2(const bit::string& s)
{}

// 场景2
// 左值引用做返回值，只能解决部分问题
// string& operator+=(char ch) 解决了
// string operator+(char ch)   没有解决

// 右值引用，如何解决operator+传值返回存在拷贝的问题呢？
// C++11 将右值分为：纯右值，将亡值
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


void Fun(int &x){ cout << "左值引用" << endl; }
void Fun(const int &x){ cout << "const 左值引用" << endl; }

void Fun(int &&x){ cout << "右值引用" << endl; }
void Fun(const int &&x){ cout << "const 右值引用" << endl; }

// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
	cout << "-----------------------------" << endl;

	Fun(std::forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
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
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	//PerfectForward(std::move(a)); // 右值
//
//	//const int b = 8;
//	//PerfectForward(b);		      // const 左值
//	//PerfectForward(std::move(b)); // const 右值
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
		// 只要右值引用，再传递其他函数调用，要保持右值属性，必须用完美转发
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
		//newnode->_data = std::forward<T>(x); // 关键位置

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
		newnode->_data = x; // 关键位置

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
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价

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
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//}

//int main()
//{
//	// 实现一个两个数相加的lambda
//	//auto add1 = [](int a, int b)->int{return a + b; };
//	// 返回值类型可以省略
//	auto add1 = [](int a, int b){return a + b; };
//
//	//auto add2 = add1;
//	//decltype(add1) add3 = add1;
//
//	cout << add1(1, 2) << endl; 
//
//	// 没有参数可以省略参数列表
//	auto func1 = []{cout << "hello world" << endl; };
//	func1();
//
//	return 0;
//}
int a = 0, b = 1;
// 在全局中不能捕捉对象
//auto func5 = [a, b](){};
auto func5 = [](){};

//int main()
//{
//	// 捕捉列表是干嘛的呢？
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
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
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

int main()
{
	// 函数对象
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);

	// lamber  底层原理，其实是被处理成一个lambda_uuid的一个仿函数类
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);
	return 0;

	// lamber
	auto r3 = [=](double monty, int year)->double{return monty*rate*year; };
	r3(10000, 2);
	return 0;
}

//int main()
//{
//	// 捕捉列表是干嘛的呢？
//	int a = 1, b = 2;
//	auto swap1 = [](int& x, int& y) {
//		int z = x;
//		x = y;
//		y = z;
//	};
//
//	cout << typeid(swap1).name() << endl;
//};