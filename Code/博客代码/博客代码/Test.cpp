#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	/*Stack(int capacity = 4)
//		:_a((int*)malloc(sizeof(int)*capacity))
//		, _top(0)
//		, _capacity(capacity)
//	{
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//	}*/
//
//	// 初始化列表和函数体内初始化可以混着来
//	Stack(int capacity = 4)
//		: _top(0)
//		, _capacity(capacity)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memset(_a, 0, sizeof(int) * capacity);
//	}
//private:
//	int* _a;  // 声明
//	int _top;
//	int _capacity;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 对象每个成员什么时候定义初始化呢？-- 初始化列表
//	// 每个成员都要走初始化列表，就算不显示在初始化列表写，也会走
//	// 如果在初始化列表显示写了就用显示写的初始化
//	// 如果没有在初始化列表显示初始化
//	// 1、内置类型，有缺省值用缺省值，没有就用随机值
//	// 2、自定义类型，调用默认它的默认构造函数，如果没有默认构造就报错
//	B( int ref)
//		:_n(10)
//		, _m(2)
//		, _aa(11)
//		, _ref(ref)
//	{
//		// _n = 10;
//	}
//
//private:
//	// const成员
//	const int _n;  // 声明
//	int _m = 1;    // 缺省值
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	B b(2);
//	return 0;
//}



//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}
//
//
// 
// 
//class Date
//{
//public:
//	//explicit修饰构造函数，禁止类型转换
//	explicit Date(int year = 0) //单个参数的构造函数
//		:_year(year)
//	{}
// 
//	void Print()
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year;
//
//};
//int main()
//{
//	//隐式类型转换
//	Date d1 = 2022; 
//	d1.Print();
//	return 0;
//}

//class Date
//{
//public:
//	// 多参数构造
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1 = { 2022, 10, 12 };
//	// 等价于
//	Date d2(2022, 10, 12 );
//
//	const Date& d3 = { 2022, 10, 12 };
//
//	return 0;
//}




//class A {
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		++_N;
//	}
//	A(const A& aa)
//		: _a(aa._a)
//	{
//		++_N;
//	}
//	// 没有this指针，只能访问静态成员
//	static int GetN()
//	{
//		return _N;
//	}
//private:
//	int _a;
//
//public:
//	static int _N;
//};
//
//// 静态成员变量的定义初始化
//int A::_N = 0;
//
//void f(A a)
//{}
//
//int main(void)
//{
//	A a1;
//	A a2 = 1;//隐式类型转换
//	f(a1);
//
//	cout << a1._N << endl;//1.通过对象调用成员函数进行访问
//	cout << A::GetN() << endl; //3.通过类名调用静态成员函数进行访问
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Test
//{
//private:
//	static int _n;
//};
//int main()
//{
//	cout << sizeof(Test) << endl;
//	return 0;
//}


//class Date
//{
//public:
//    Date(int year, int month, int day)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    // d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
//    // 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//    ostream & operator<<(ostream& _cout)
//    {
//        _cout << _year << "-" << _month << "-" << _day << endl;
//        return _cout;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};



//class Date
//{
//    friend ostream& operator<<(ostream& _cout, const Date& d);
//    friend istream& operator>>(istream& _cin, Date& d);
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//    _cout << d._year << "-" << d._month << "-" << d._day;
//    return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//    _cin >> d._year;
//    _cin >> d._month;
//    _cin >> d._day;
//    return _cin;
//}
//int main()
//{
//    Date d;
//    cin >> d;
//    cout << d << endl;
//    return 0;
//}



// 内部类
// 
// 相当于两个独立的类
// B类的访问受A的类域和访问限定符的限制
//class A
//{
//private:
//	int _a;
//	static int k;
//
//public: // B天生就是A的友元
//	class B
//	{
//		int _b;
//
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._a << endl;//OK
//		}
//	};
//};
//
//int A::k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl;//4
//    A aa;
//    cout << sizeof(aa) << endl;
//	A::B bb;
//
//	return 0;
//}



//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//
//A F()
//{
//	//A ret(10);
//	//return ret;
//	return A(10);
//}
//
//int main()
//{
//	// 有名对象
//	A aa0;
//	A aa1(1);
//	A aa2 = 2;
//
//	//A aa3();
//
//	// 匿名对象 --声明周期当前这一行
//	A();
//	A(3);
//
//	//Solution so;
//	//so.Sum_Solution(10);
//
//	Solution().Sum_Solution(10);
//
//	return 0;
//}




//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//void f1(A aa)
//{}
//
//A f2()
//{
//	A aa;
//	return aa;
//}
//
//A f3()
//{
//	/*A aa(10);
//	return aa;*/
//
//	return A(10);
//}


//int main()
//{
//	// 优化场景1
//	A aa1 = 1;  // A tmp(1) + A aa1(tmp) -> 优化 A aa1(1)
//
//	// 优化场景2
//	A aa1(1);
//	f1(aa1);
//
//	f1(A(1));  // 构造 + 拷贝构造  -> 优化 构造
//	f1(1);  // 构造 + 拷贝构造  -> 优化 构造
//
//	f2();	  // 构造+拷贝构造
//	A ret = f2(); // 构造+拷贝构造+拷贝构造 ->优化 构造+拷贝构造
//
//
//	A ret = f3();  //  构造+拷贝构造+拷贝构造 -> 优化 -> 构造
//
//
//	return 0;
//}
//
//int globalVar               = 1;
//static int staticGlobalVar  = 1;
//
//void Test()
//{
//	static int staticVar = 1;
//
//	int localVar		= 1;
//
//	int num1[10]		= { 1, 2, 3, 4 };
//	char char2[]		= "abcd";
//	const char* pChar3	= "abcd";
//	int* ptr1			= (int*)malloc(sizeof(int) * 4);
//	int* ptr2			= (int*)calloc(4, sizeof(int));
//	int* ptr3			= (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}



//#include <iostream>
//using namespace std;
//int main()
//{
//	//栈区开辟空间，先开辟的空间地址高
//	int a = 10;
//	int b = 20;
//	cout << &a << endl;
//	cout << &b << endl;
//
//	cout << endl;
//
//	//堆区开辟空间，先开辟的空间地址低
//	int* c = (int*)malloc(sizeof(int) * 10);
//	int* d = (int*)malloc(sizeof(int) * 10);
//	cout << c << endl;
//	cout << d << endl;
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    // calloc
//    int* p = (int*)calloc(10, sizeof(int)); // 开辟10个大小为int的空间，40
//    if (p == NULL)
//        return 1;
//    int i = 0;
//    for (i = 0; i < 10; i++)
//        printf("%d ", *(p + i));
//    free(p);
//    p = NULL;
//
//    return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// 一定要匹配使用，否则可能会出现各种情况
//	//A* p3 = new A[10];
//	//delete p3;
//
//	A* p4 = new A;
//	delete[] p4;
//
//	return 0;
//}


//int main()
//{
//	//size_t sz = 2;
//	int* p1 = (int*)malloc(1024 * 1024 * 1024 * 2);
//	if (p1 == nullptr)
//	{
//		printf("%d\n", errno);// errno-错误码
//		perror("malloc fail");
//		exit(-1);
//	}
//
//	printf("%p", p1);
//	free(p1);
//
//	return 0;
//}


//int main()
//{
//	size_t sz = 2;
//
//	char* p1 = nullptr;
//	try
//	{
//		// 进行检测 有错误就进入catch被铺获，try中错误代码后面也不执行
//		p1 = new char[1024 * 1024 * 1024 * sz];
//		cout << "检测无误" << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	printf("%p", p1);
//	delete[] p1;
//	return 0;
//}





////定位new
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//int main()
//{
//	A* p3 = (A*)malloc(sizeof(A));
//	if (p3 == nullptr)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	// 定位new -- 对p3指向空间，显示调用构造函数初始化
//	//在已分配的原始内存空间中调用构造函数初始化一个对象。
//	new(p3)A(1);
//
//	p3->~A();
//	//free(p3);
//	//delete p3;
//
//
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
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//template<typename T> 
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//
//	double c = 1.1;
//	double d = 2.2;
//	Swap(c, d);
//
//	char e = 'a';
//	char f = 'b';
//	Swap(e, f);
//
//	return 0;
//}

//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	// 显示实例化
//	cout << Add<double>(a1, d2) << endl;
//	cout << Add<int>(a1, d2) << endl;
//
//	return 0;
//}

//template<class T1, class T2>//两个参数模板，可以传不同类型的参数  //可以写typename也可以写class
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	cout << Add(a1, d2) << endl;
//	cout << Add(d1, a2) << endl;
//
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配,调用非模板函数，编译器不需要实例化
//	Add<int>(1, 2); // 调用编译器实例化的Add版本
//}
//
//
//#include <iostream>
//using namespace std;
//专门用于int类型加法的非模板函数
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////通用类型加法的函数模板
//template<typename T1, typename T2>
//T1 Add(const T1& x, const T2& y)
//{
//	return x + y;
//}
//int main()
//{
//	Add(10, 20); //与非模板函数完全匹配，不需要函数模板实例化
//	Add(2.2, 2); //函数模板可以生成更加匹配的版本，编译器会根据实参生成更加匹配的Add函数
//	return 0;
//}

//template<typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	Add(2, 2.2); //模板函数不允许自动类型转换，不能通过编译
//	//因为只有一个参数模板，只能在传参时，自己去强转成一样的类型
//	return 0;
//}


//template<class T1, class T2, ..., class Tn>
//class 类模板名
//{
//	// 类内成员定义
//};


//template<class T>
//class Scores
//{
//public:
//	void Print();
//private:
//	T _Math;
//	T _Chinese;
//	T _English;
//};
//template<class T>
//void Scores<T>::Print()
//{
//	cout << "数学:" << _Math << endl;
//	cout << "语文:" << _Chinese << endl;
//	cout << "英语:" << _English << endl;
//}
//
//
//int main()
//{
//	Scores<int> s1;
//	Scores<double> s1;
//
//	return 0;
//}


//template<typename T>
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = )" <<capacity<<endl;
//
//		_a = (T*)malloc(sizeof(T)*capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//	
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(const T& x)
//	{
//		// ....
//		// 扩容
//		_a[_top++] = x;
//	}
//
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//
//int main()
//{
//	// 类模板一般没有推演时机，函数模板实参传递形参，推演模板参数
//	// 类模板只能显示实例化
//	// 他们是同一个类模板实例化出来的
//	// 但是模板参数不同，他们就是不同类型
//	Stack<double> st1; // double
//	st1.Push(1.1);
//
//	Stack<int> st2; // int
//	st2.Push(1);
//
//	return 0;
//}



//void test_string1()
//{
//	string s1("1234");
//	// 遍历
//	// 1、下标 []
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		s1[i]++;
//	}
//	cout << s1 << endl;
//}
//
//
//void test_string2()
//{
//	string s1("1234");
//	// 2、范围for
//	for (auto& ch : s1)
//	{
//		ch++;//每个字符加加
//	}
//
//	for (auto e : s1)
//	{
//		cout << e ;//遍历打印
//	}
//	cout << endl;
//	//cout << s1 << endl;//也可以直接打印，
//}

//void test_string2()
//{
//	string s1("1234");
//	// 反转一下
//	size_t begin = 0, end = s1.size() - 1;//size()计算字符串有效字符个数
//	while (begin < end)
//	{
//		swap(s1[begin++], s1[end--]);
//	}
//	cout << s1 << endl;
//
//}


//void test_string3()
//{
//	string s1("1234");
//	
//	cout << "const_iterator" << endl;
//	//const正向迭代器
//	string::const_iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		//正向遍历
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//
//
//
//void test_string6()
//{
//	string s1("hello world");
//	cout << "原来的字符串" << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl << endl;
//
//
//	string s2("hello world");
//	//resize(n)n小于对象当前的size时，将size缩小到n
//	s2.resize(5);
//	cout << "resize < 字符串长度" << endl;
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	cout << s2 << endl << endl;
//
//	string s3("hello world");
//	//resize(n, char)n大于对象当前的size时，将size扩大到n，扩大的字符为char
//	s3.resize(15, 'x');
//	cout << "字符串长度 < resize < capacity" << endl;
//	cout << s3.size() << endl;
//	cout << s3.capacity() << endl;
//	cout << s3 << endl << endl;
//
//	string s4("hello world");
//	//resize(n, char)n大于对象当前的size时，将size扩大到n，扩大的字符默认为'\0'
//	s4.resize(20);
//	cout << "resize > capacity" << endl;
//	cout << s4.size() << endl;
//	cout << s4.capacity() << endl;
//	cout << s4 << endl << endl;
//}
//
//void test_string7()
//{
//	//创建100个字符x的字符串
//	string s1(100, 'x');
//	cout <<"s1.size：" << s1.size() << endl;
//	cout <<"s1.capacity："<< s1.capacity() << endl << endl;
//
//	//用resize把字符串制为10个字符x
//	s1.resize(10);
//	cout << "s1.size：" << s1.size() << endl;
//	cout << "s1.capacity：" << s1.capacity() << endl << endl;
//
//	//通过shrink_to_fit()把s1的capacity
//	//改为适合此时s1的size的大小，不至于浪费空间
//	s1.shrink_to_fit();
//	cout << "s1.size：" << s1.size() << endl;
//	cout << "s1.capacity：" << s1.capacity() << endl;
//}
//
//int main()
//{
//	test_string7();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//
//	//clear()删除对象的内容，该对象将变为空字符串
//	s.clear();
//	cout << s << endl; //空字符串
//	return 0;
//}




//#include "string.h"
//int main()
//{
//	wyt::test_string6();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("I like C++!!!");
//
//	//erase(pos, n)删除pos位置开始的n个字符
//	s.erase(8, 5); //I like C
//	cout << s << endl; //I like C
//
//	//erase(pos)删除pos位置的字符
//	string s1("hello world");
//	s1.erase(3); //I like
//	cout << s1 << endl; //I like
//
//	//erase(pos1, pos2)删除[pos1pos2)上所有字符
//	s.erase(s.begin() + 1, s.end()); //I
//	cout << s << endl; //I
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//void test_string()
//{
//	string s1("hello world hello world");
//	string s2("CSDN");
//
//	//将s1清空，替换指定string对象
//	s1.assign(s2);
//	cout << s1 << endl;//CSDN
//
//	//将s1清空，替换指定字符串
//	s1.assign("hello C++");
//	cout << s1 << endl;//hello C++
//
//	//将s1清空，替换指定字符串的一部分
//	s1.assign("hello C++", 5);
//	cout << s1 << endl;//hello
//
//	//将s1清空，替换n个指定的字符
//	s1.assign(5, '!');
//	cout << s1 << endl;//！！！！！
//}
//int main()
//{
//	test_string();
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;

//void test_string()
//{
//	string s1("hello world hello world");
//	string s2("CSDN");
//
//	//从第六个下标位置开始，将五个字符替换成s2对象
//	s1.replace(6, 5, s2);
//	cout << s1 << endl;//hello CSDN hello world
//
//	//从第六个下标位置开始，将五个字符替换成指定字符串
//	s1.replace(6, 5, "C++");
//	cout << s1 << endl;//hello C++hello world
//}

void test_string()
{
	// "Test.cpp"
	// "Test.cpp.tar"
	string file;
	cin >> file;
	// 要求取后缀
	size_t pos = file.rfind('.');
	if (pos != string::npos)
	{
		//string suffix = file.substr(pos, file.size() - pos);
		string suffix = file.substr(pos);
		cout << suffix << endl;
	}
}
void TestString()
{
	//获取字符数组首地址，用C字符串的形式遍历
	string s1("hello world");
	const char* str = s1.c_str();
	while (*str)
	{
		cout << *str << " ";
		str++;
	}
	cout << endl;
	s1 += '\0';
	s1 += " hello";
	cout << s1 << endl;           //调用的string重载operator<<  将对象数组中所有字符都输出
	cout << s1.c_str() << endl;   //直接输出const char* 遇到\0结束
}
int main()
{
	TestString();
	return 0;
}
