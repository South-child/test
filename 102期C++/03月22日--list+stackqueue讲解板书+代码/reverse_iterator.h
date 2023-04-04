#pragma once

namespace bit
{
	// 适配器

	// Iterator是哪个容器的迭代器，reverse_iterator<Iterator>就可以
	// 适配出哪个容器的反向迭代器。复用的体现
	template <class Iterator, class Ref, class Ptr>
	//template <class Iterator>
	class reverse_iterator
	{
		//typedef reverse_iterator<Iterator, Ref, Ptr> self;
		typedef reverse_iterator<Iterator> self;

		//typedef typename Iterator::Ref Ref;
		//typedef typename Iterator::Ptr Ptr;

	public:
		reverse_iterator(Iterator it)
			:_it(it)
		{}`

		typename Iterator::reference operator*()
		{
			//return *_it;
			Iterator prev = _it;
			return *--prev;
		}

		typename Iterator::pointer operator->()
		{
			return &operator*();
		}

		self& operator++()
		{
			--_it;
			return *this;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!= (const self & rit) const
		{
			return _it != rit._it;
		}

	private:
		Iterator _it;
	};
}