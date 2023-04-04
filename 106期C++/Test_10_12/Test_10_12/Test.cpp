#include <iostream>
#include <assert.h>

using namespace std;

//类的引入
//C语言结构体中只能定义变量，在C++中，结构体内不仅可以定义变量，也可以定义函数。比如：
//之前在数据结构初阶中，用C语言方式实现的栈，结构体中只能定义变量；现在以C++方式实现，
//会发现struct中也可以定义函数。

// 属性 + 方法
// struct 升级
// 1、兼容c中struct 的所有用法
// 2、升级成了类
//typedef int DataType;
//struct Stack
//{
//	// 成员函数/成员方法
//	void Init(size_t capacity)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)* capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(const DataType& data)
//	{
//		// 扩容
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
//	// 成员变量
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//};
// 
//上面结构体的定义，在C++中更喜欢用class来代替。 


//类的定义
//类的定义有两种方式
//1. 声明和定义全部放在类体中，需注意：成员函数如果在类中定义，编译器可能会将其当成内联函数处理。
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

//2.类声明放在.h文件中，成员函数定义放在.cpp文件中，注意：成员函数名前需要加类名::
//#include "person.h"
//void person::showinfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}


//成员变量命名规则的建议：
//建议在成员变量名前面加 _
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		year = year; //-- 这里并没有改变成员变量的值，根据就近原则，这里就是形参给形参赋值，没有任何改变
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



//访问限定符
//1. public修饰的成员在类外可以直接被访问
//2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
//3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
//4. 如果后面没有访问限定符，作用域就到 } 即类结束。
//5. class的默认访问权限为private，struct为public(因为struct要兼容C)

//注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别

//struct Stack//默认访问权限为public
//class Stack//默认访问权限为private
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
//	//成员函数为公有的，在类外可以直接被访问
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//
//	//成员变量是私有的，无法在类外访问 private 成员
//	//st.top;//err
//	return 0;
//}

//类的实例化
//用类类型创建对象的过程，称为类的实例化
//1. 类是对 对象 进行描述的，是一个模型一样的东西，限定了类有哪些成员，
//定义出一个类并没有分配实际的内存空间来存储它； -- 相当于只是一个声明

//并没有为这个类开辟空间，只是相当于一个声明 例如 int i;--并没有为其开辟空间
//class Stack // 类型
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
//	int* a;  // 声明
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack st;//实例化一个类对象 -- 这才为其开辟了空间
//
//	//可以实例化多个对象
//	Stack st2;
//	Stack st3;
// 
//	return 0;
//}




class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d);

	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);

	// 析构函数
	~Date();

	// 日期+=天数
	Date& operator+=(int day);

	// 日期+天数
	Date operator+(int day) const;

	// 日期-天数
	Date operator-(int day) const;

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 前置--
	Date& operator--();

	// 后置--
	Date operator--(int);


	// >运算符重载
	bool operator>(const Date& d)  const;

	// ==运算符重载
	bool operator==(const Date& d) const;

	// >=运算符重载
	bool operator >= (const Date& d) const;

	// <运算符重载
	bool operator < (const Date& d) const;

	// <=运算符重载
	bool operator <= (const Date& d) const;

	// !=运算符重载
	bool operator != (const Date& d) const;

	// 日期-日期 返回天数
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

// 前置
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置 -- 多一个int参数主要是为了根前置区分
// 构成函数重载
Date Date::operator++(int)
{
	Date tmp(*this);

	*this += 1;

	return tmp;
}

// 运算符重载
// 函数重载

// 前置
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 后置
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