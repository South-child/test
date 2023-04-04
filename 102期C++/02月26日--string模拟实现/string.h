#pragma once

//namespace bit  //名字
//{
//	class string
//	{
//	public:
//		string(const char* str)
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//
//		// s2(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s3;
//		// s3 = s3
//		string& operator=(const string& s)
//		{
//		/*	if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}*/
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello world");
//		string s2(s1);
//
//		string s3("sort");
//		s1 = s3;
//
//		s3 = s3;
//	}
//}

namespace bit  //名字
{
	// 增删查改
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str+_size;
		}

		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}*/

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}

		// s2(s1)
		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		// s1 = s3;
		// s3 = s3
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

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				// 增容
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{

		}

		//operator+=(char ch)
		//operator+=(const char* str)
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 有效
	};

	void f(const string& s)
	{
		//s[0] = 'x';
		cout << s[0]<<endl;
	}

	void test_string1()
	{
		string s1("hello world");
		string s2;
		cout<<s1.c_str()<<endl;
		cout << s2.c_str() << endl;

		s1[0] = 'x';
		//s1[30];
		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout<<endl;

		f(s1);
	}

	void test_string2()
	{
		string s1("hello world");

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			*it += 1;
			++it;
		}

		it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		// 编译时被替换成迭代器
		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}