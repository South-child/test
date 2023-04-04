#pragma once

class Date
{
	friend struct LessPDate;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

namespace bit
{

	template<class T>
	struct Less
	{
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	// 特化
	template<>
	struct Less<Date*>
	{
		bool operator()(Date* x,Date* y) const
		{
			return *x < *y;
		}
	};

	template<class T>
	struct Greater {
		bool operator()(const T& x, const T& y) const {
			return x > y;
		}
	};

	// 大的优先级高--大堆
	template<class T, class Container = vector<T>, class Compare = Less<T>>
	//template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if(_con[child] > _con[parent]) 等价于 if(_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			Compare com;

			size_t child = (parent * 2) + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

	public:
		priority_queue()
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			// 建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				adjust_down(i);
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			//assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	void test_priority_queue()
	{
		// 默认是大的优先级高 -- 默认给的仿函数是less
		//priority_queue<int> pq;

		// 控制小的优先级高 -- 给一个greater的仿函数
		//priority_queue<int, deque<int>, Greater<int>> pq;
		priority_queue<int, deque<int>, greater<int>> pq;

		pq.push(3);
		pq.push(3);
		pq.push(7);
		pq.push(1);
		pq.push(9);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}