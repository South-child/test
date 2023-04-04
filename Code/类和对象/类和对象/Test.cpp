#include <iostream>
using namespace std;

//class Person
//{
//public:
//	void PrintPersonInfo()
//	{}
////private:
//	char _name[20];  // 声明
//	char _gender[3];
//	int  _age;
//};
//
//
//int main()
//{
//	// 不能
//	// Person::_age = 1;
//	// Person::PrintPersonInfo(); // this指针
//
//	Person p1;
//	p1._age = 1;
//
//	Person p2;
//	Person* ptr = &p2;
//	ptr->_age = 2;
//
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
////private:
//	char _a;
//	int _b;
//};
//
//class A2 {
//public:
//	void f2() {}
//};
//
//class A3
//{};
//int main()
//{
//	A aa1;
//	A aa2;
//	//A aa3;
//	cout << sizeof(aa1) << endl;
//
//	// 1 不存储有效数据，占位，标识对象存在
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	A2 aaa2;
//	A2 aaaa2;
//	cout << &aaa2 << endl;
//	cout << &aaaa2 << endl;
//
//	aa1._a = 'A';
//	aa1.PrintA();
//
//	aa2._a = 'a';
//	aa2.PrintA();
//
//
//	return 0;
//}

//int main()
//{
//	A aa;
//	cout << sizeof(A) << endl;
//	cout << sizeof(aa) << endl;
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 但是我们可以再类里面用this指针
//	void Print()
//	{
//		// this = nullptr;
//		cout << this << endl;
//		//cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	// Print(&d1)
//	// Print(&d2)
//	// this指针的定义和传递，都是编译器的活，我们不能去抢
//	// 但是我们可以再类里面用this指针
//	/*void Print(Date* this)
//	{
//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}*/
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 9, 21);
//
//	Date d2;
//	d2.Init(2022, 9, 22);
//
//	d1.Print();
//	d2.Print();
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//
//	return 0;
//}


//class Date
//{
//public:
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	// 初始化
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
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
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		// ....
//		// 扩容
//		_a[_top++] = x;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//

//int main()
//{
//	Date d1(2022, 9, 21);
//	Date d2(2022, 9, 21);
//	Date d3;
//	
//	// 无参的不要像下面这样写
//	//Date d4();
//	//Date func();
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	Stack st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////

class A
{
public:
	A()
	{
		_a = 0;
		cout << "A()构造函数" << endl;
	}
private:
	int _a;
};

class Date
{
public:
	// 初始化
	//Date(int year = 1, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	// 内置类型
	int _year;     // 年
	int _month;    // 月
	int _day;      // 日

	// 自定义类型
	A _aa;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;

		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

	void Push(int x)
	{
		// ....
		// 扩容
		_a[_top++] = x;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

class MyQueue {
public:
	void push(int x)
	{
		_pushST.Push(x);
	}

	Stack _pushST;
	Stack _popST;

	//size_t _size;
};


int main()
{
	Date d1;
	d1.Print();

	MyQueue mq;
	mq.push(1);
	mq.push(2);

	return 0;
}