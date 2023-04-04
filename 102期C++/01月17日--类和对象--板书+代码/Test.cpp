#include<iostream>
using namespace std;
#include "Date.h"

//class Date
//{
//public:
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
//// 函数名 operator操作符
//// 返回类型 看操作符运算后返回值是什么
//// 参数，操作符有几个操作数，他就有几个参数
////bool operator>(const Date& d1, const Date& d2)
////{
////	if (d1._year > d2._year)
////	{
////		return true;
////	}
////	else if (d1._year == d2._year && d1._month > d2._month)
////	{
////		return true;
////	}
////	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
////	{
////		return true;
////	}
////	else
////	{
////		return false;
////	}
////}
//
////int operator-(const Date& d1, const Date& d2);
//
//int main()
//{
//	Date d1(2022, 1, 16);
//	Date d2(2022, 1, 31);
//	Date d3(2022, 2, 26);
//
//	// 默认情况C++是不支持自定义类型对象使用运算符
//	//d1 > d2; // -》operator>(d1, d2)
//	//cout << operator>(d1, d2) << endl;
//
//	//int day1 = d2 - d1;
//	//int day2 = d3 - d1;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d1.operator>(d2);
//	bool operator>(const Date& d) // bool operator>(Date* const this, const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
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
//	Date d1(2022, 1, 16);
//	Date d2(2022, 1, 31);
//	Date d3(2022, 2, 26);
//
//	d1 > d2; // d1.operator>(d2);
//	d1.operator>(d2);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//*/
//	// d1 = d3;
//	// d1 = d1;
//	//Date& operator=(const Date& d)
//	//{
//	//	// 极端情况下自己给自己赋值就可以不同处理了，直接判断一下跳过
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//
//	//	return *this;
//	//}
//
//	// d1.operator>(d2);
//	bool operator>(const Date& d) // bool operator>(Date* const this, const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
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
//	Date d1(2022, 1, 16);
//	Date d2(2022, 1, 31);
//	Date d3(2022, 2, 26);
//
//	// 一个已经存在的对象拷贝初始化一个马上创建实例化的对象
//	Date d4(d1);  // 拷贝构造
//	Date d5 = d1; // 拷贝构造
//
//	// 两个已经存在的对象之间进行赋值拷贝
//	d2 = d1 = d3; // d1.operator=(d3)
//	//d1 = d3; // d1.operator=(d3)
//
//	d1 = d1;
//
//	int i, j, k;
//	i = j = k = 10;
//
//	return 0;
//}


void TestDate1()
{
	Date d1;
	Date d2(2022, 1, 16);
	d1.Print();
	d2.Print();

	Date d3(2022, 13, 15);
	d3.Print();

	Date d4(2022, 2, 29);
	d4.Print();

	Date d5(2020, 2, 29);
	d5.Print();

	Date d6(2000, 2, 29);
	d6.Print();
}

void TestDate2()
{
	/*Date d1(2022, 1, 16);
	Date ret = d1 + 100;
	ret.Print();

	d1 += 100;
	d1.Print();*/

	//Date ret1 = d1++;  // d1.operator++(&d1, 0);
	//Date ret2 = ++d1;  // d1.operator++(&d1);

	//d1.operator++();
	//d1.operator++(0);
	//d1.operator++(1);

	Date d1(2022, 1, 16);
	d1++;
	//++d1;
}

void TestDate3()
{
	Date d1(2022, 1, 17);

	Date ret1 = d1 - 10;
	ret1.Print();

	Date ret2 = d1 - 17;
	ret2.Print();

	Date ret3 = d1 - 30;
	ret3.Print();
	
	Date ret4 = d1 - 400;
	ret4.Print();

	Date ret5 = d1 - 1500;
	ret5.Print();

	Date ret6= d1 - -100;
	ret6.Print();
}

void TestDate4()
{
	/*Date today(2022, 1, 17);
	Date offerDay(2022, 9, 1);

	cout << (offerDay - today) << endl;
	cout << (today - offerDay) << endl;

	today.PrintWeekDay();*/

	Date today(2022, 1, 17);
	today.PrintWeekDay();

	Date(2022, 1, 17).PrintWeekDay();
}

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C()" << endl;
	}

	~C()
	{
		cout << "~C()" << endl;
	}
};

class D
{
public:
	D()
	{
		cout << "D()" << endl;
	}

	~D()
	{
		cout << "~D()" << endl;
	}
};

//C c;

//int main()
//{
//	//TestDate4();
//
//	A a;
//	B b;
//	static D d;
//
//	return 0;
//}

//class Widget
//{
//public:
//	Widget()
//	{
//		//cout << "Widget()" << endl;
//	}
//
//	Widget(const Widget&)
//	{
//		cout << "Widget(const Widget&)" << endl;
//	}
//
//	Widget& operator=(const Widget&)
//	{
//		cout << "Widget& operator=(const Widget&)" << endl;
//		return *this;
//	}
//};
//
//Widget f(Widget u)
//{
//	return u;
//}
//
//int main()
//{
//	//Widget x;
//	//Widget y = f(x);
//
//	Widget x;
//	Widget y;
//	y = f(x);
//
//	return 0;
//}

class Widget
{
public:
	Widget()
	{
		cout << "Widget()" << endl;
	}

	Widget(const Widget&)
	{
		cout << "Widget(const Widget&)" << endl;
	}

	Widget& operator=(const Widget&)
	{
		cout << "Widget& operator=(const Widget&)" << endl;
		return *this;
	}

	~Widget()
	{
		cout << "~Widget()" << endl;
	}
};

Widget f(Widget u)
{
	Widget v(u);
	Widget w = v;

	return w;
}

// 《深度探索C++对象模型》
//int main()
//{
//	Widget x; //生命周期在当前函数
//	Widget y = f(f(x));
//
//	// 匿名对象
//	//Widget(); //生命周期只在这一行
//	//f(Widget());
//
//	return 0;
//}


//class AA
//{
//public:
//	AA* operator&()
//	{
//		return this;
//		//return nullptr;
//	}
//
//	const AA* operator&() const
//	{
//		return this;
//	}
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	const Date d2;
//	d2.Print();
//
//	AA aa1;
//	cout << &aa1 << endl;
//	const AA aa2;
//	cout << &aa2 << endl;
//
//	return 0;
//}

int main()
{
	Date d1(2022, 1, 17);
	Date d2(2022, 1, 18);

	//d1.Print();
	//d1.operator<<(cout);
	//d1 << cout;

	cout << d1;
	operator<<(cout, d1);
	cout << d1 << d2;


	//cin >> d1;
	//cout << d1;

	return 0;
}