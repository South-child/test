#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

namespace wyt
{
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//构造
		string(const char* str = "")
		{
			_size = strlen(str);//字符有效长度，不包括\0
			_capacity = _size;
			_str = new char[_capacity + 1];//多一个空间存放\0
			strcpy(_str, str);
		}

		//拷贝s2(s1) --要进行深拷贝
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			_capacity = s._capacity;
			_size = s._size;

			strcpy(_str, s._str);
		}

		//赋值 s2 = s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);

				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		//析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}


		//获取size
		size_t size() const
		{
			return _size;
		}
		//获取capacity
		size_t capacity() const
		{
			return _capacity;
		}

		//以c形式打印字符串
		const char* c_str() const
		{
			return _str;
		}

		//reserve -- 相当于开辟空间malloc
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		//resize -- 设置空间大小--可以比字符串大，也可以比字符串小
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}

		//在尾部添加字符
		void push_back(char ch)
		{
			//判断是否有空间
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//在尾部追加字符串
		void append(const char* str)
		{
			int len = strlen(str);
			//判断空间是否足够
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);

			_size += len;
		}

		//+=字符运算符重载
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		//+=字符串运算符重载
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//在某个位置插入一个字符
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			//首先判断空间
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
			}

			//挪动数据
			/*size_t end = _size;
			while (end >= pos)//注意：如果这里的pos 位置为0 的话，会报错，end减到-1时，由于时size_t所以永远大于pos，错误
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;*/

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
		//在某个位置插入一个字符串
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			//首先判断空间
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			//挪动数据
			size_t end = _size + len;
			while (end > pos + len -1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
			return *this;

		}
		//删除pos位置len个字符
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size - pos)
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

		//查找某个字符
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			while (pos < _size)
			{
				if (_str[pos] == ch)
					return pos;
				++pos;
			}
			return npos;
		}

		//在主串中查找子串
		size_t fiind(const char* str, size_t pos = 0)const
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		//清空
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//访问string字符 -- 可读可写
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		//只读
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		
		const static size_t npos = -1;
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
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		//char buff[128] = { '\0' };
		//size_t i = 0;
		//char ch = in.get();
		//while (ch != ' ' && ch != '\n')
		//{
		//	if (i == 127)
		//	{
		//		// 满了
		//		s += buff;
		//		i = 0;
		//	}

		//	buff[i++] = ch;

		//	ch = in.get();
		//}

		//if (i > 0)
		//{
		//	buff[i] = '\0';
		//	s += buff;
		//}

		return in;
	}

	void stringTest1()
	{
		string s1("hello world");
		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
	}
	void stringTest2()
	{
		string s1("hello world");
		s1.insert(0, "bit");
		cout << s1.c_str() << endl;

		s1.insert(9, "hello ");
		cout << s1.c_str() << endl;
	}

	void stringTest3()
	{
		string s1("hello world");
		s1 += ' ';
		s1 += 'C';
		s1 += '+';
		s1 += '+';
		cout << s1.c_str() << endl;

		s1 += " hello";
		cout << s1 << endl;

	}
	void stringTest4()
	{
		string s1("hello world");
		s1 += ' ';
		s1 += 'C';
		s1 += '+';
		s1 += '+';
		cout << s1.c_str() << endl;

		s1 += " hello";
		cout << s1 << endl;


		string s2;
		cin >> s2;
		cout << s2 << endl;

	}
}