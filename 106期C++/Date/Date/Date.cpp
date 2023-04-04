#include "Date.h"

//获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	static int monthDayArry[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return monthDayArry[month];
	}
}


// ==运算符重载
//d1 == d2
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// >运算符重载
//d1 > d2
bool  Date::operator>(const Date& d)  const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}

	return false;
}

// >=运算符重载
//d1 >= d2
bool  Date::operator >= (const Date& d) const
{
	return *this == d || *this > d;
}

// <运算符重载
//d1 < d2
bool  Date::operator < (const Date& d) const
{
	return !(*this >= d);
}

// <=运算符重载
//d1 <= d2
bool  Date::operator <= (const Date& d) const
{
	return !(*this > d);
}

// !=运算符重载
//d1 != d2
bool  Date::operator != (const Date& d) const
{
	return !(*this == d);
}

//d1 += 100 -- 注意：d1+=100，d1变了，返回的是d1变化之后的日期
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= abs(day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

//d1 + 100 -- 注意：d1+100，d1是不变的，返回的是加了之后的结果
Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}


// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += abs(day);
	}

	_day -= day;

	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

// 日期-天数
Date Date::operator-(int day) const
{
	Date ret(*this);

	ret -= day;

	return ret;
}

//前置++ -- 返回++之后的值
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//后置++ -- 多一个int参数主要是为了和前置区分（不能擅自修改成其他的类型参数 -- 这是语法规定死的）
//返回++之前的值
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// 日期-日期 返回天数  d1-d2
int Date::operator-(const Date& d) const
{
	Date Max = *this;
	Date Min = d;
	int flag = 1;

	if (*this < d) //如果 *this小的话，两者相减，得到的天数就是负数
	{
		Max = d;
		Min = *this;
		flag = -1;
	}

	int count = 0;//记录天数
	while (Min != Max)
	{
		++count;
		++Min;
	}

	return count * flag;
}