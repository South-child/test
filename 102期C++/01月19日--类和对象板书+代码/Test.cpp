#include<iostream>
//using namespace std;
using std::cout;
using std::endl;

//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int i)
//		:_N(10)
//		, _ref(i)
//		, _aa(-1)
//	{
//		//  error C2166: 左值指定 const 对象
//		// 这里报错说明到构造函数体内时，成员变量已经定义出来了
//		//_N = 10;
//
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 初始化列表 - 成员变量定义的地方 
//	/*Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _N(10)
//	{}*/
//
//private:
//	int _year;  // 声明
//	int _month;
//	int _day;
//
//	const int _N;  // const
//	int& _ref;     // 引用
//	A _aa;         // 没有默认构造函数的自定义类型成员变量
//	// 总结一下：
//	// 1、初始化列表 - 成员变量定义的地方
//	// 2、const、引用、没有默认构造函数的自定义类型成员变量必须在初始化列表初始化，因为他们都必须在定义的时候初始化
//	// 3、对于像其他类型成员变量，如int year、int _month,在哪初始化都可以
//};
//
//int main()
//{
//	int i = 0;
//	Date d1(2022, 1, 19, i); // 对象定义/对象实例化
//
//	Date d2(2021, 1, 19, i); // 对象定义/对象实例化
//
//	// int i;
//	// 常量必须在定义的时候初始化
//	// const int j = 0;
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//	{
//		cout << "A(int a = 0)" << endl;
//		_a = a;
//	}
//
//	A(const A& aa)
//	{
//		cout << "A(const A& aa)" << endl;
//		_a = aa._a;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		_a = aa._a;
//
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	// 不使用初始化列表
//	//Date(int year, int month, int day, const A& aa)
//	//{
//	//	_aa = aa;
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	// 使用初始化列表
//	Date(int year, int month, int day, const A& aa)
//		:_aa(aa)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;  // 声明
//	int _month;
//	int _day;
//
//	A _aa;
//};
//
//int main()
//{
//	//A aa(10);
//	//Date d1(2022, 1, 19, aa); // 对象定义/对象实例化
//	Date d1(2022, 1, 19, A(10)); // 对象定义/对象实例化
//
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
//
//int main() {
//	A aa(1);
//	aa.Print();
//}

//class Date
//{
//public:
//	/*explicit Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}*/
//	Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//
//	Date(const Date& dd)
//	{
//		cout << "Date(const Date& dd)" << endl;
//	}
//
//	/*explicit Date(int year)
//		:_year(year)
//	{}*/
//
//private:
//	int _year;
//};
//
////class string
////{
////	string(const char* str)
////	{}
////};
//
//int main()
//{
//	// 虽然他们两都是直接构造，但是过程是不一样的
//	Date d1(2022);
//	Date d2 = 2022; // 隐式类型转换
//	// 本来用2022构造一个临时对象Date(2022)，再用这个对象拷贝构造d2
//	// 但是C++编译器在连续的一个过程中，多个构造会被优化，合二为一。
//	// 所以这里被优化为直接就是一个构造
//
//	// 隐式类型转换 - 相近类型 -- 表示意义相似的类型
//	double d = 1.1;
//	int i = d;
//	const int& i = d;
//
//	// 强制类型转换 - 无关类型
//	int* p = &i;
//	int j = (int)p;
//
//	//string s1("hello world");
//	//string s2 = "hello";
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_sCount;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		++_sCount;
//	}
//
//	// 没有this指针，只能访问静态成员变量和成员函数
//	static int GetCount()
//	{
//		//_a;
//		return _sCount;
//	}
//private:
//	int _a;
//
////public:
//	// 静态成员变量属于整个类，所有对象，生命周期在整个程序运行期间
//	// 类成员函数中，可以随便访问
//	static int _sCount; // 声明
//};
//
//int A::_sCount = 0; // 定义初始化
//
//void f(A a)
//{
//
//}

//int main()
//{
//	A a1;
//	A a2 = 1;
//	f(a1);
//
//	// 类外面访问的方式。 ->public
//	/*cout << A::_sCount << endl;
//	cout << a1._sCount << endl;
//	cout << a2._sCount << endl;*/
//
//	cout << a1.GetCount() << endl;
//	cout << A::GetCount() << endl;
//
//	return 0;
//}

class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}

	static int GetRet()
	{
		return _ret;
	}

	static void Init()
	{
		_i = 1;
		_ret = 0;
	}

private:
	static int _i;
	static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		//Sum a[n]; // Sum* p = new Sun[n];
		//return Sum().GetRet() - (n+1);

		//Sum a[n-1]; // Sum* p = new Sun[n];
		//return Sum().GetRet();

		//Sum a[n]; //
		Sum::Init();
		Sum* p = new Sum[n];
		delete[] p;
		return Sum::GetRet();
	}
};

//int main()
//{
//	Solution st;
//	cout << st.Sum_Solution(10) << endl;
//
//	cout << Solution().Sum_Solution(10) << endl;
//
//	return 0;
//}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//
//// C++11 -- 打补丁
//class A
//{
//public:
//	// 如果你再初始化列表阶段，没有对成员变量初始化，它就会使用缺省值初始化
//	A()
//	{}
//private:           // 要注意的是这里不是初始化，因为这里是声明，不能初始化
//	int _a1 = 0;  // 这个里是给成员变量缺省值
//	B _bb1 = 10;
//	B _bb2 = B(20);
//	int* p = (int*)malloc(4*10);
//	// vs2019支持
//	//int arr[10] = { 1, 2, 3, 4, 5 };
//
//	// 静态的不能这样给缺省值，必须在类外面全局位置定义初始化
//	// static int _sCount = 0;
//};

//int main()
//{
//	A aa;
//
//	return 0;
//}

class Time
{
	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	void f(Date d);

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
	friend class Time;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_t._hour = 0;
		_t._minute = 0;
		_t._second = 0;
	}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

void Time::f(Date d)
{
	d._year;
}


class A
{
private:
	static int k;
	int h;
public:
	// 内部类
	// 1、内部类B和在全局定义是基本一样的，只是他的受外部类A类域限制,定义在A的类域中
	// 2、内部类B天生就是外部类A的友元，也就是B中可以访问A的私有，A不能访问B的私有
	class B
	{
		// friend class A;
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}

	private:
		int _b;
	};
	
	void f(B bb)
	{
		// A不是B的友元，不能访问B
		bb._b;
	}
};

int A::k = 1;

int main()
{
	cout << sizeof(A) << endl;
	A aa;
	A::B bb;

	return 0;
}
