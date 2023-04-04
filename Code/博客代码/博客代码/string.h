#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

namespace wyt
{
	class string
	{
	public:
		//构造
		//string(const char* str)
		//	//:_str(str)//为什么不能？？，不是权限放大的问题,如果是权限的问题，那我们可以直接在成员变量上
		//	//添加const修饰,这样虽然语法上过的过去，但是如果我们str指向的是一个常量字符串，那_str也是指向的常量字符串
		//	//而常量字符串是不允许修改的，之后若是我们需要对其进行修改，那就不允许操作了，所以不能这样赋值，而是要重新开辟一块空间。
		//{}

		//構造函數 --- 传参
		//string(const char* str)
		//{
		//	_size = strlen(str);//初始时，字符串大小设置为字符串长度
		//	_capacity = _size;//初始时，字符串容量设置为字符串长度
		//	_str = new char[_capacity + 1];//为存储字符串开辟空间（多开一个用于存放'\0'）

		//	strcpy(_str, str);//将C字符串拷贝到已开好的空间
		//}
		//不用传参 -- 默认构造
		//string()
		//{
		//	_str = new char[1];
		//	_str[0] = '\0';
		//	_capacity = _size = 0;
		//}
		// 
		//全缺省构造函数 
		string(const char* str = "")
		{
			_size = strlen(str);//初始时，字符串大小设置为字符串长度
			_capacity = _size;//初始时，字符串容量设置为字符串长度
			_str = new char[_capacity + 1];//为存储字符串开辟空间（多开一个用于存放'\0'）

			strcpy(_str, str);//将C字符串拷贝到已开好的空间
		}
		//拷贝构造
		string(const string& str)
		{
			_str = new char[str._capacity + 1];
			_capacity = str._capacity;
			_size = str._size;

			strcpy(_str, str._str);
		}

		//赋值运算符重载
		string& operator=(const string& str)
		{
			if (this != &str)
			{
				char* tmp = new char[str._capacity + 1];
				strcpy(tmp, str._str);

				delete[] _str;
				_str = tmp;

				_size = str._size;
				_capacity = str._capacity;
			}
			return *this;
		}
		 
		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		//目前沒有實現流插入運算符重載，打印時先用c形式打印
		const char* c_str()
		{
			return _str;
		}

		//[]運算符重載,支持以數組的形式修改查詢字符
		//普通对象：可读可写
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		//const对象：只读 ---可用于cout运算符重在中
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t size() const
		{
			return _size; 
		}
		size_t capacity() const 
		{
			return _capacity;
		}

		//迭代器
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//+1是为了预留一个给\0
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;

				_capacity = n;
			}

		}
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{				
				reserve(n);//如果大于_capacity扩容，不大于就不会扩容
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}

				_size = n;//会将_size的大小改为n
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}
		//添加 -- 在字符串后面插入一个字符
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : (_capacity * 2);
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//在字符串后面添加一个字符串
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(len + _size);
			}
			//for (size_t i = 0; i < strlen(str); i++)
			//{
			//	_str[_size] = str[i];
			//	++_size;
			//}
			//_str[_size] = '\0';

			strcpy(_str + _size, str);
			_size += len;
		}
		//+=运算符重载，+=一个字符
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		//+=一个字符串
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//在pos位置插入一个字符
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : (_capacity * 2);
				reserve(newcapacity);
			}

			//挪动数据

			/*size_t end = _size;
			while (end >= pos)//会陷入死循环，因为当进行头插时，end由于是无符号整形，当end再次--，就会变成一个超大的数字，从而陷入死循环
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//方法一：
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//方法二：
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}
		//在pos位置插入一个字符串
		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(len + _size);
			}
			//挪动数据
			//方法一：
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}*/

			//方法二：
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			
			//插入数据
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;

		}
		//删除
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}
		//查找
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);

			while (pos < _size)
			{
				if (_str[pos] == ch)
					return pos;
				++pos;
			}
		}

		size_t find(const char* str, size_t pos = 0)
		{
			//方法一：
			//const char* ptr = strstr(_str + pos, str);
			//if (ptr == nullptr)
			//{
			//	return npos;
			//}
			//else
			//{
			//	return ptr - _str;
			//}
			//方法二：
			//BF算法 -- 暴力
			assert(_str != nullptr && str != nullptr);

			size_t len = strlen(str);

			int i = pos;
			int j = 0;

			while (i < _size && j < len)
			{
				if (_str[i] == str[j])//相等，两指针都++，继续比较
				{
					++i;
					++j;
				}
				else//不相等，指向主串的指针回退到上一次开始比较的字符的下一个字符（i = i - j + 1），指向子串的指针重新回退到首字符的位置
				{
					i = i - j + 1;
					j = 0;
				}
			}
			if (j >= len)//比较完成，找到了
			{
				return i - j;
			}
			return npos;
		}

		//清楚
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
	private:
		//const char* _str;
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos = -1;//特例--因为const修饰的成员变量必须在初始化列表初始化，而且静态成员变量必须在类外初始化，但是整形是特殊的，可以直接声明缺省值
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		//char ch = in.get();
		//while (ch != ' ' && ch != '\n')
		//{
		//	s += ch;
		//	//in >> ch;
		//	ch = in.get();
		//}

		//优化 -- 防止多次扩容
		char buff[128] = { '\0' };
		size_t i = 0;
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			if (i == 127)
			{
				// 满了
				s += buff;
				i = 0;
			}

			buff[i++] = ch;

			ch = in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	void test_string1()
	{

		string s1("hello world");

		cout << s1.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
		}
		cout << s1.c_str() << endl;


		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)--;
			it++;
		}
		cout << s1.c_str() << endl;


		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	//检测尾插添加
	void test_string2()
	{
		string s1("hello");
		
		s1.push_back(' ');
		s1.push_back('w');
		s1.push_back('t');
		s1.push_back('y');
		
		cout << s1.c_str() << endl;

		s1.append(" string");
		cout << s1.c_str() << endl;

		s1 += " abcd";
		cout << s1.c_str() << endl;

	}
	void test_string3()
	{

		string s1("hello world");
		size_t flag = s1.find("world");
		cout << flag << endl;
	}

	void test_string4()
	{

		string s1("hello world");
		string s2(s1);

		cout << s1 << endl;
		cout << s2 << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		cin >> s1;
		cout << s1 << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		s1.insert(5, "wyt");
		cout << s1 << endl;

		s1.insert(0, "hello ");
		cout << s1 << endl;

		s1.erase(0,6);
		cout << s1 << endl;
	}

}
