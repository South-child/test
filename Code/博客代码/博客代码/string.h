#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

namespace wyt
{
	class string
	{
	public:
		//����
		//string(const char* str)
		//	//:_str(str)//Ϊʲô���ܣ���������Ȩ�޷Ŵ������,�����Ȩ�޵����⣬�����ǿ���ֱ���ڳ�Ա������
		//	//���const����,������Ȼ�﷨�Ϲ��Ĺ�ȥ�������������strָ�����һ�������ַ�������_strҲ��ָ��ĳ����ַ���
		//	//�������ַ����ǲ������޸ĵģ�֮������������Ҫ��������޸ģ��ǾͲ���������ˣ����Բ���������ֵ������Ҫ���¿���һ��ռ䡣
		//{}

		//���캯�� --- ����
		//string(const char* str)
		//{
		//	_size = strlen(str);//��ʼʱ���ַ�����С����Ϊ�ַ�������
		//	_capacity = _size;//��ʼʱ���ַ�����������Ϊ�ַ�������
		//	_str = new char[_capacity + 1];//Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��

		//	strcpy(_str, str);//��C�ַ����������ѿ��õĿռ�
		//}
		//���ô��� -- Ĭ�Ϲ���
		//string()
		//{
		//	_str = new char[1];
		//	_str[0] = '\0';
		//	_capacity = _size = 0;
		//}
		// 
		//ȫȱʡ���캯�� 
		string(const char* str = "")
		{
			_size = strlen(str);//��ʼʱ���ַ�����С����Ϊ�ַ�������
			_capacity = _size;//��ʼʱ���ַ�����������Ϊ�ַ�������
			_str = new char[_capacity + 1];//Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��

			strcpy(_str, str);//��C�ַ����������ѿ��õĿռ�
		}
		//��������
		string(const string& str)
		{
			_str = new char[str._capacity + 1];
			_capacity = str._capacity;
			_size = str._size;

			strcpy(_str, str._str);
		}

		//��ֵ���������
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
		 
		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		//Ŀǰ�]�Ќ��F�������\������d����ӡ�r����c��ʽ��ӡ
		const char* c_str()
		{
			return _str;
		}

		//[]�\������d,֧���Ԕ��M����ʽ�޸Ĳ�ԃ�ַ�
		//��ͨ���󣺿ɶ���д
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		//const����ֻ�� ---������cout�����������
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

		//������
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
				char* tmp = new char[n + 1];//+1��Ϊ��Ԥ��һ����\0
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
				reserve(n);//�������_capacity���ݣ������ھͲ�������
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}

				_size = n;//�Ὣ_size�Ĵ�С��Ϊn
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}
		//��� -- ���ַ����������һ���ַ�
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
		//���ַ����������һ���ַ���
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
		//+=��������أ�+=һ���ַ�
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		//+=һ���ַ���
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//��posλ�ò���һ���ַ�
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : (_capacity * 2);
				reserve(newcapacity);
			}

			//Ų������

			/*size_t end = _size;
			while (end >= pos)//��������ѭ������Ϊ������ͷ��ʱ��end�������޷������Σ���end�ٴ�--���ͻ���һ����������֣��Ӷ�������ѭ��
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//����һ��
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//��������
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
		//��posλ�ò���һ���ַ���
		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(len + _size);
			}
			//Ų������
			//����һ��
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}*/

			//��������
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			
			//��������
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;

		}
		//ɾ��
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
		//����
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
			//����һ��
			//const char* ptr = strstr(_str + pos, str);
			//if (ptr == nullptr)
			//{
			//	return npos;
			//}
			//else
			//{
			//	return ptr - _str;
			//}
			//��������
			//BF�㷨 -- ����
			assert(_str != nullptr && str != nullptr);

			size_t len = strlen(str);

			int i = pos;
			int j = 0;

			while (i < _size && j < len)
			{
				if (_str[i] == str[j])//��ȣ���ָ�붼++�������Ƚ�
				{
					++i;
					++j;
				}
				else//����ȣ�ָ��������ָ����˵���һ�ο�ʼ�Ƚϵ��ַ�����һ���ַ���i = i - j + 1����ָ���Ӵ���ָ�����»��˵����ַ���λ��
				{
					i = i - j + 1;
					j = 0;
				}
			}
			if (j >= len)//�Ƚ���ɣ��ҵ���
			{
				return i - j;
			}
			return npos;
		}

		//���
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
		const static size_t npos = -1;//����--��Ϊconst���εĳ�Ա���������ڳ�ʼ���б��ʼ�������Ҿ�̬��Ա���������������ʼ������������������ģ�����ֱ������ȱʡֵ
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

		//�Ż� -- ��ֹ�������
		char buff[128] = { '\0' };
		size_t i = 0;
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			if (i == 127)
			{
				// ����
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

	//���β�����
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
