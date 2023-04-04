#pragma once
#include <iostream>

using namespace std;

class Date
{
	// ��Ԫ�������������λ�ã�
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	//���캯��
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		,_day(day)
	{
		if (!(year > 1
			&& (month >= 1 && month <= 12)
			&& (day >= 1 && day <= GetMonthDay(year, month))))
		{
			cout << "�Ƿ�����" << endl;
		}
	}
	//�������캯�� -- ��Ϊ������ĳ�Ա���������������ͣ����ǿ��Բ�д��������Ĭ�����ɵľͿ�������������
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

	//��ֵ��������� --  -- ��Ϊ������ĳ�Ա���������������ͣ����ǿ��Բ�д��������Ĭ�����ɵľͿ�������������
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

	//�Ƚ���������� 
	// ==���������
	bool operator==(const Date& d) const;
	
	// >���������
	bool operator>(const Date& d)  const;

	// >=���������
	bool operator >= (const Date& d) const;

	// <���������
	bool operator < (const Date& d) const;

	// <=���������
	bool operator <= (const Date& d) const;

	// !=���������
	bool operator != (const Date& d) const;

	//���������
	//����+������+��+=��-��-=��++��--
	//���ڼ����� == �������������+���������壬��Ϊ����+���ڻ������ڣ�

	//d1 += 100 -- ע�⣺d1+=100��d1���ˣ����ص���d1�仯֮�������
	Date& operator+=(int day);

	//d1 + 100 -- ע�⣺d1+100��d1�ǲ���ģ����ص��Ǽ���֮��Ľ��
	Date operator+(int day) const;

	// ����-=����
	Date& operator-=(int day);

	// ����-����
	Date operator-(int day) const;

	//ǰ��++
	Date& operator++();

	//����++ -- ��һ��int������Ҫ��Ϊ�˺�ǰ�����֣����������޸ĳ����������Ͳ��� -- �����﷨�涨���ģ�
	Date operator++(int);

	// ǰ��--
	Date& operator--();

	// ����--
	Date operator--(int);

	// ����-���� ��������
	int operator-(const Date& d) const;

	// d1.operator<<(cout); // d1 << cout
	/*void operator<<(ostream& out)
	{
	out << _year << "��" << _month << "��" << _day << "��" << endl;
	}*/

private:
	int _year;
	int _month;
	int _day;
};


//����д�������� -- д�������������෴�����
//������������ᾭ��ʹ�ã����Զ������������ -- �Զ�չ��
//cout<<d1
inline ostream& operator<<(ostream& out, const Date& d) 
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

// cin >> d1  operator(cin, d1)
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//2. �ڶ����������������Ͷ�����룬ע�⣺���ܶ�д��ͷ�ļ��У���Ϊͷ�ļ���������Դ�ļ��ж�չ�����ᵼ�¶��岻��ȷ���ظ�����
//ostream& operator<<(ostream& out, const Date& d);
//istream& operator>>(istream& in, Date& d);