#pragma once

#include "reverse_iterator.h"

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		//typedef __list_iterator
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}

		// it2 = it1 浅拷贝
		// 拷贝构造和赋值重载是否需要我们自己实现
		// 析构呢？-> 迭代器是借助节点的指针访问修改链表
		// 节点属于链表，不属于迭代器，所以他不管释放
		// 都不需要自己实现，默认生成的即可
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		// ++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// --it
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		// it--
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const self& it) const
		{
			return _node != it._node;
		}
	};

	//template<class T>
	//struct __const_list_iterator
	//{
	//	typedef ListNode<T> Node;
	//	//typedef __list_iterator
	//	Node* _node;

	//	__const_list_iterator(Node* x)
	//		:_node(x)
	//	{}

	//	// it2 = it1 浅拷贝
	//	// 拷贝构造和赋值重载是否需要我们自己实现
	//	// 析构呢？-> 迭代器是借助节点的指针访问修改链表
	//	// 节点属于链表，不属于迭代器，所以他不管释放
	//	// 都不需要自己实现，默认生成的即可
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	// ++it
	//	__const_list_iterator<T>& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	// it++
	//	__const_list_iterator<T> operator++(int)
	//	{
	//		__const_list_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	// --it
	//	__const_list_iterator<T>& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	// it--
	//	__const_list_iterator<T> operator--(int)
	//	{
	//		__list_iterator<T> tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const __const_list_iterator<T>& it) const
	//	{
	//		return _node != it._node;
	//	}

	//	bool operator==(const __const_list_iterator<T>& it) const
	//	{
	//		return _node != it._node;
	//	}
	//};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		typedef reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
	
		// list<Date> lt1(5, Date(2022, 3, 15));
		// list<int> lt2(5, 1);
		list(int n, const T& val = T())
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		list(size_t n, const T& val = T())
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// lt2(lt1)
		list(const list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;

			list<T> tmp(lt.begin(), lt.end());
			std::swap(_head, tmp._head);
		}

		// lt2 = lt1
		list<T>& operator=(list<T> lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}

		// lt2(lt1)
		//list(const list<T>& lt)
		//{
		//	_head = new Node();
		//	_head->_next = _head;
		//	_head->_prev = _head;

		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}

		//// lt2 = lt1
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}

		//	return *this;
		//}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			/*iterator it = begin();
			while (it != end())
			{
				iterator del = it++;
				delete del._node;
			}

			_head->_next = _head;
			_head->_prev = _head;*/
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		// 这里insert以后，pos是否失效？不失效
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		// 这里erase以后，pos是否失效？一定失效
		iterator erase(iterator pos)
		{
			assert(pos != end());
			
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			delete pos._node;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}
	private:
		Node* _head;
	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		//lt.f();

		// 访问修改容器
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2; // 修改
			cout << *it << " ";
			++it;
		}
		cout << endl;

		print_list(lt);
	}

	struct Date
	{
		int _year;
		int _month;
		int _day;

		Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			, _month(month)
			, _day(day)
		{}
	};

	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date(2022, 3, 12));
		lt.push_back(Date(2022, 3, 13));
		lt.push_back(Date(2022, 3, 14));

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;
			cout << it->_year << "/" << it->_month << "/" << it->_day << endl;

			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);

		//lt1.clear();

		list<int> lt2(lt1);
		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(10);
		lt3.push_back(10);
		lt3.push_back(10);

		lt1 = lt3;
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list4()
	{
		list<Date> lt1(5, Date(2022, 3, 15));
		for (auto e : lt1)
		{
			cout << e._year << "/" << e._month << "/" << e._day << endl;
		}
		cout << endl;

		list<int> lt2(5, 1);
		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list5()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			//*it *= 2; // 修改
			cout << *it << " ";
			++it;
		}
		cout << endl;
		
		list<int>::reverse_iterator rit = lt1.rbegin();
		while (rit != lt1.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}