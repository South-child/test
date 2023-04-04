#pragma once
#include <iostream>

using namespace std;

class Date
{
	// 友元声明（类的任意位置）
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//获取某年某月的天数
	int GetMonthDay(int year, int month);

	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		,_day(day)
	{
		if (!(year > 1
			&& (month >= 1 && month <= 12)
			&& (day >= 1 && day <= GetMonthDay(year, month))))
		{
			cout << "非法日期" << endl;
		}
	}
	//拷贝构造函数 -- 因为日期类的成员变量都是内置类型，我们可以不写，编译器默认生成的就可以完成这项工作了
	//d1(d2)
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	void print() const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//赋值运算符重载 --  -- 因为日期类的成员变量都是内置类型，我们可以不写，编译器默认生成的就可以完成这项工作了
	//d1 = d2
	//Date& operator=(const Date& d)
	//{
	//	if (&d != this)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this;
	//}

	//比较运算符重载 
	// ==运算符重载
	bool operator==(const Date& d) const;
	
	// >运算符重载
	bool operator>(const Date& d)  const;

	// >=运算符重载
	bool operator >= (const Date& d) const;

	// <运算符重载
	bool operator < (const Date& d) const;

	// <=运算符重载
	bool operator <= (const Date& d) const;

	// !=运算符重载
	bool operator != (const Date& d) const;

	//算数运算符
	//日期+天数：+、+=、-、-=、++、--
	//日期减日期 == 相隔天数（日期+日期无意义，因为日期+日期还是日期）

	//d1 += 100 -- 注意：d1+=100，d1变了，返回的是d1变化之后的日期
	Date& operator+=(int day);

	//d1 + 100 -- 注意：d1+100，d1是不变的，返回的是加了之后的结果
	Date operator+(int day) const;

	// 日期-=天数
	Date& operator-=(int day);

	// 日期-天数
	Date operator-(int day) const;

	//前置++
	Date& operator++();

	//后置++ -- 多一个int参数主要是为了和前置区分（不能擅自修改成其他的类型参数 -- 这是语法规定死的）
	Date operator++(int);

	// 前置--
	Date& operator--();

	// 后置--
	Date operator--(int);

	// 日期-日期 返回天数
	int operator-(const Date& d) const;

	// d1.operator<<(cout); // d1 << cout
	/*void operator<<(ostream& out)
	{
	out << _year << "年" << _month << "月" << _day << "日" << endl;
	}*/

private:
	int _year;
	int _month;
	int _day;
};


//不能写在类里面 -- 写在类里面会造成相反的情况
//由于输入输出会经常使用，可以定义成内联函数 -- 自动展开
//cout<<d1
inline ostream& operator<<(ostream& out, const Date& d) 
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

// cin >> d1  operator(cin, d1)
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//2. 第二个方法就是声明和定义分离，注意：不能都写在头文件中，因为头文件会在两个源文件中都展开，会导致定义不明确，重复定义
//ostream& operator<<(ostream& out, const Date& d);
//istream& operator>>(istream& in, Date& d);