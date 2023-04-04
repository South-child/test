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

		//����
		string(const char* str = "")
		{
			_size = strlen(str);//�ַ���Ч���ȣ�������\0
			_capacity = _size;
			_str = new char[_capacity + 1];//��һ���ռ���\0
			strcpy(_str, str);
		}

		//����s2(s1) --Ҫ�������
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			_capacity = s._capacity;
			_size = s._size;

			strcpy(_str, s._str);
		}

		//��ֵ s2 = s1
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

		//����
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}


		//��ȡsize
		size_t size() const
		{
			return _size;
		}
		//��ȡcapacity
		size_t capacity() const
		{
			return _capacity;
		}

		//��c��ʽ��ӡ�ַ���
		const char* c_str() const
		{
			return _str;
		}

		//reserve -- �൱�ڿ��ٿռ�malloc
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

		//resize -- ���ÿռ��С--���Ա��ַ�����Ҳ���Ա��ַ���С
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

		//��β������ַ�
		void push_back(char ch)
		{
			//�ж��Ƿ��пռ�
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//��β��׷���ַ���
		void append(const char* str)
		{
			int len = strlen(str);
			//�жϿռ��Ƿ��㹻
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);

			_size += len;
		}

		//+=�ַ����������
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		//+=�ַ������������
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//��ĳ��λ�ò���һ���ַ�
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			//�����жϿռ�
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
			}

			//Ų������
			/*size_t end = _size;
			while (end >= pos)//ע�⣺��������pos λ��Ϊ0 �Ļ����ᱨ��end����-1ʱ������ʱsize_t������Զ����pos������
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
		//��ĳ��λ�ò���һ���ַ���
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			//�����жϿռ�
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			//Ų������
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
		//ɾ��posλ��len���ַ�
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

		//����ĳ���ַ�
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

		//�������в����Ӵ�
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

		//���
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//����string�ַ� -- �ɶ���д
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		//ֻ��
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
		//		// ����
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