#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		Date::year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 15);
//
//	return 0;
//}

//class Date
//{
//public:
//	//void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	//void Print(Date* const this)
//	void Print()
//	{
//		//this = nullptr;
//		cout << _year << "-" << _month << "-" << _day << endl;
//
//		// 一般情况，我们都不会像下面这样显示写
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 15);// d1.Init(&d1, 2022, 1, 15);
//	d1.Print();          // d1.Print(&d1);
//
//	Date d2;
//	d2.Init(2022, 1, 16); // d2.Init(&d2, 2022, 1, 16);
//	d2.Print();           // d2.Print(&d2);
//
//
//	/*const int* p1 = nullptr;
//	int* p2 = nullptr;
//	p1 = p2;
//	p2 = p1;*/
//
//	return 0;
//}

//class A
//{
//public:
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Show();
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//}

///////////////////////////////////////////////////////////////////////
//int main()
//{
//	Stack st;
//	// 忘记调用初始化
//
//	StackPush(&st, 1);
//	StackPush(&st, 1);
//	StackPush(&st, 1);
//
//	// 忘记调用销毁函数
//
//	return 0;
//}

//class Date
//{
//public:
//	/*Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	
//	// 语法上无参和全缺省的可以同时存在
//	// 但是如果存在无参调用，就会存在二义性
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	// 推荐实现全缺省或者半缺省，因为比较好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1;
//	Date d2(2020);
//	Date d3(2020, 2);
//	Date d4(2022, 1, 15);
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << " A()" << endl;
//		_a = 0;
//	}
//
//	/*A(int a = 0)
//	{
//	cout << " A()" << endl;
//	_a = a;
//	}*/
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//private:
//	// C++里面把类型分为两类：内置类型(基本类型)，自定义类型
//	// 内置类型：int/char/double/指针/内置类型数组 等等
//	// 自定义类型：struct/class定义的类型
//
//	// 我们不写编译器默认生成构造函数，对于内置类型不做初始化处理
//	// 对于自定类型成员变量会去调用它的默认构造函数初始化，如果没有默认构造函数就会报错
//	// 任何一个类的默认构造函数就是--不用参数就可以调用。
//	// 任何一个类的默认构造函数有三个，全缺省、无参、我们不写编译器默认生成的。
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};
//
//int main()
//{
//	Date d1;
//	d1.Date();
//
//	return 0;
//}



//class Date
//{
//public:
//	// 推荐实现全缺省或者半缺省，因为比较好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		// Date类没有资源需要清理，所以Date不实现析构函数都是可以的
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2022, 1, 15);
//
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}


//class Date
//{
//public:
//	// 推荐实现全缺省或者半缺省，因为比较好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		// Date类没有资源需要清理，所以Date不实现析构函数都是可以的
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{}
//
//	// 如果我们不写默认生成析构函数和构造函数类似
//	// 对于内置类型不做处理
//	// 对于自定义类型回去调用它的析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//// 两个栈实现一个队列
//class MyQueue {
//public:
//	// 默认生成构造函数和析构函数会对自定义类型成员调用他的构造和析构
//	void push(int x) {
//
//	}
//private:
//	Stack pushST;
//	Stack popST;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2022, 1, 15);
//
//	Stack s1;
//	Stack s2(20);
//
//	MyQueue mq;
//
//	return 0;
//}

class A
{
public:
	A()
	{}

	A(const A&)
	{
		cout << "A(const A&)" << endl;
	}
};

class Date
{
public:
	// 推荐实现全缺省或者半缺省，因为比较好用
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// Date d2(d1);
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	//d._year = _year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	~Date()
	{
		// Date类没有资源需要清理，所以Date不实现析构函数都是可以的
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	A _aa;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int)*capacity);
		if (_a == nullptr)
		{
			cout << "malloc fail\n" << endl;
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;
	}

	void Push(int x)
	{}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	size_t _top;
	size_t _capacity;
};

void f(Date& d)
{

}

int main()
{
	Date d1(2022, 1, 15);
	f(d1);

	// 拷贝复制
	Date d2(d1);

	Stack st1(10);

	// 拷贝复制
	Stack st2(st1);

	return 0;
}