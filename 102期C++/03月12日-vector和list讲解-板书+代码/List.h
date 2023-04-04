#pragma once

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
			__list_iterator<T> tmp(*this);
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
			__list_iterator<T> tmp(*this);
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


		/*void f()
		{
			Node* pnode = _head->_next;
			iterator it = _head->_next;

			*pnode;
			*it;

			++pnode;
			++it;
		}*/

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

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void insert(iterator pos, const T& x);
		void erase(iterator pos);
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
}