#pragma once
#include<iostream>
using namespace std;

class Date
{
	// 友元函数
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1);
	void Print() const ;
	int GetMonthDay(int year, int month) const;

	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;

	//	cout<<"Date(const Date& d)"<<endl;
	//}

	// 实现 > 或 < 和 == 其他的复用
	// 不仅仅是Date类可以这样子，所有的类要实现比较，都可以用这种方式
	bool operator>(const Date& d) const;
	bool operator<(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	// d1 += 100
	Date& operator+=(int day);
	// d1 + 100
	Date operator+(int day)const;

	Date& operator-=(int day);
	// d - 100
	Date operator-(int day)const;

	// ++d1;
	Date& operator++();

	// d1++; 后置为了跟前置++，进行区分
	// 增加一下int参数占位，跟前置++,构成函数重载
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	// offerDay - today
	int operator-(const Date& d) const;
	void PrintWeekDay() const;

	//void operator<<(ostream& out);
	//operator>>
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);

