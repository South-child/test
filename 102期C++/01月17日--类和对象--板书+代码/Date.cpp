#include "Date.h"

int Date::GetMonthDay(int year, int month) const
{
	static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = monthDayArray[month];
	// 365天 5小时+
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day += 1;
	}

	return day;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!(_year >= 0 
		&&(month > 0 && month < 13) 
		&& (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "非法日期->";
		// this->Print();
		Print();
	}
}

void Date::Print() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date::operator>(const Date& d)  const
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
	else
	{
		return false;
	}
}

// d1 == d2
bool Date::operator==(const Date& d)  const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// d1 < d2
bool Date::operator<(const Date& d)  const
{
	return !(*this >= d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)  const
{
	return *this > d || *this == d;
}

bool Date::operator<=(const Date& d)  const
{
	return  !(*this > d);
}

bool Date::operator!=(const Date& d)  const
{
	return  !(*this == d);
}

// d1 += 100 
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

// d1 + 100
Date Date::operator+(int day)  const
{
	Date ret(*this);
	//ret.operator+=(day);
	ret += day;

	return ret;
}

// d1 -= 10
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
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

// d1 - 10
Date Date::operator-(int day)  const
{
	Date ret(*this);
	ret -= day;

	return ret;
}

// ++d1;
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

// d1++; 后置为了跟前置++，进行区分
// 增加一下参数占位，跟前置++,构成函数重载
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}

// --d1;
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}

// offerDay - today
int Date::operator-(const Date& d)  const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int count = 0;
	while (min != max)
	{
		++min;
		++count;
	}

	return count*flag;
}


void Date::PrintWeekDay() const
{
	const char* arr[] = { "星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期天" };
	//Date start(1900, 1, 1);
	//int count = *this - start;
	int count = *this - Date(1900, 1, 1);

	cout << arr[count % 7] << endl;
}

//void Date::operator<<(ostream& out)
//{
//	out << _year << "/" << _month << "/" << _day << endl;
//}


ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
