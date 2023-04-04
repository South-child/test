#include <iostream>
#include <assert.h>

using namespace std;

//�������
//C���Խṹ����ֻ�ܶ����������C++�У��ṹ���ڲ������Զ��������Ҳ���Զ��庯�������磺
//֮ǰ�����ݽṹ�����У���C���Է�ʽʵ�ֵ�ջ���ṹ����ֻ�ܶ��������������C++��ʽʵ�֣�
//�ᷢ��struct��Ҳ���Զ��庯����

// ���� + ����
// struct ����
// 1������c��struct �������÷�
// 2������������
//typedef int DataType;
//struct Stack
//{
//	// ��Ա����/��Ա����
//	void Init(size_t capacity)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)* capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(const DataType& data)
//	{
//		// ����
//		_array[_size] = data;
//		++_size;
//	}
//
//	DataType Top()
//	{
//		return _array[_size - 1];
//	}
//
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//	// ��Ա����
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//};
// 
//����ṹ��Ķ��壬��C++�и�ϲ����class�����档 


//��Ķ���
//��Ķ��������ַ�ʽ
//1. �����Ͷ���ȫ�����������У���ע�⣺��Ա������������ж��壬���������ܻὫ�䵱��������������
//class person
//{
//public:
//	void showinfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};

//2.����������.h�ļ��У���Ա�����������.cpp�ļ��У�ע�⣺��Ա������ǰ��Ҫ������::
//#include "person.h"
//void person::showinfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}


//��Ա������������Ľ��飺
//�����ڳ�Ա������ǰ��� _
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		year = year; //-- ���ﲢû�иı��Ա������ֵ�����ݾͽ�ԭ����������βθ��βθ�ֵ��û���κθı�
//		month = month;
//		day = day;
//	}
//private:
//	int year;
//	int month;
//	int day;
//};
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // year_  m_year  mYear
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 9, 19);
//
//	return 0;
//}



//�����޶���
//1. public���εĳ�Ա���������ֱ�ӱ�����
//2. protected��private���εĳ�Ա�����ⲻ��ֱ�ӱ�����(�˴�protected��private�����Ƶ�)
//3. ����Ȩ��������Ӹ÷����޶������ֵ�λ�ÿ�ʼֱ����һ�������޶�������ʱΪֹ
//4. �������û�з����޶�����������͵� } ���������
//5. class��Ĭ�Ϸ���Ȩ��Ϊprivate��structΪpublic(��ΪstructҪ����C)

//ע�⣺�����޶���ֻ�ڱ���ʱ���ã�������ӳ�䵽�ڴ��û���κη����޶����ϵ�����

//struct Stack//Ĭ�Ϸ���Ȩ��Ϊpublic
//class Stack//Ĭ�Ϸ���Ȩ��Ϊprivate
//{
//private:
//	int* a;
//	int top;
//	int capacity;
//
//public:
//	void Init(int N = 4)
//	{
//		// ...
//		top = 0;
//		capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//};
//
//int main()
//{
//	Stack st;
//	//��Ա����Ϊ���еģ����������ֱ�ӱ�����
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//
//	//��Ա������˽�еģ��޷���������� private ��Ա
//	//st.top;//err
//	return 0;
//}

//���ʵ����
//�������ʹ�������Ĺ��̣���Ϊ���ʵ����
//1. ���Ƕ� ���� ���������ģ���һ��ģ��һ���Ķ������޶���������Щ��Ա��
//�����һ���ಢû�з���ʵ�ʵ��ڴ�ռ����洢���� -- �൱��ֻ��һ������

//��û��Ϊ����࿪�ٿռ䣬ֻ���൱��һ������ ���� int i;--��û��Ϊ�俪�ٿռ�
//class Stack // ����
//{
//public:
//	void Push(int x)
//	{
//		// Init();
//		//...
//	}
//
//	void Init(int N = 4)
//	{
//		// ...
//		top = 0;
//		capacity = 0;
//	}
//private:
//	int* a;  // ����
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack st;//ʵ����һ������� -- ���Ϊ�俪���˿ռ�
//
//	//����ʵ�����������
//	Stack st2;
//	Stack st3;
// 
//	return 0;
//}




class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);

	// �������캯��
	// d2(d1)
	Date(const Date& d);

	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);

	// ��������
	~Date();

	// ����+=����
	Date& operator+=(int day);

	// ����+����
	Date operator+(int day) const;

	// ����-����
	Date operator-(int day) const;

	// ����-=����
	Date& operator-=(int day);

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);

	// ǰ��--
	Date& operator--();

	// ����--
	Date operator--(int);


	// >���������
	bool operator>(const Date& d)  const;

	// ==���������
	bool operator==(const Date& d) const;

	// >=���������
	bool operator >= (const Date& d) const;

	// <���������
	bool operator < (const Date& d) const;

	// <=���������
	bool operator <= (const Date& d) const;

	// !=���������
	bool operator != (const Date& d) const;

	// ����-���� ��������
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;

};


bool Date::operator==(const Date& d)  const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// d1 > d2
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

	return false;
}

bool Date::operator>=(const Date& d)  const
{
	return *this > d || *this == d;
}

bool Date::operator<=(const Date& d)  const
{
	return !(*this > d);
}

bool Date::operator<(const Date& d)  const
{
	return !(*this >= d);
}

bool Date::operator!=(const Date& d)  const
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		//return *this -= -day;
		return *this -= abs(day);
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

// d1 + 100
Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}

// d1 -= 100
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		//return *this -= -day;
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

// d1 - 100
Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;

	return ret;
}

// ǰ��
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ���� -- ��һ��int������Ҫ��Ϊ�˸�ǰ������
// ���ɺ�������
Date Date::operator++(int)
{
	Date tmp(*this);

	*this += 1;

	return tmp;
}

// ���������
// ��������

// ǰ��
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// ����
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

// d1 - d2
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
		//if (d > *this)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++n;
		++min;
	}

	return n * flag;
}