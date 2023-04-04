#include "Date.h"

//��ȡĳ��ĳ�µ�����
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


// ==���������
//d1 == d2
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// >���������
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

// >=���������
//d1 >= d2
bool  Date::operator >= (const Date& d) const
{
	return *this == d || *this > d;
}

// <���������
//d1 < d2
bool  Date::operator < (const Date& d) const
{
	return !(*this >= d);
}

// <=���������
//d1 <= d2
bool  Date::operator <= (const Date& d) const
{
	return !(*this > d);
}

// !=���������
//d1 != d2
bool  Date::operator != (const Date& d) const
{
	return !(*this == d);
}

//d1 += 100 -- ע�⣺d1+=100��d1���ˣ����ص���d1�仯֮�������
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

//d1 + 100 -- ע�⣺d1+100��d1�ǲ���ģ����ص��Ǽ���֮��Ľ��
Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}


// ����-=����
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

// ����-����
Date Date::operator-(int day) const
{
	Date ret(*this);

	ret -= day;

	return ret;
}

//ǰ��++ -- ����++֮���ֵ
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//����++ -- ��һ��int������Ҫ��Ϊ�˺�ǰ�����֣����������޸ĳ����������Ͳ��� -- �����﷨�涨���ģ�
//����++֮ǰ��ֵ
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// ����-���� ��������  d1-d2
int Date::operator-(const Date& d) const
{
	Date Max = *this;
	Date Min = d;
	int flag = 1;

	if (*this < d) //��� *thisС�Ļ�������������õ����������Ǹ���
	{
		Max = d;
		Min = *this;
		flag = -1;
	}

	int count = 0;//��¼����
	while (Min != Max)
	{
		++count;
		++Min;
	}

	return count * flag;
}