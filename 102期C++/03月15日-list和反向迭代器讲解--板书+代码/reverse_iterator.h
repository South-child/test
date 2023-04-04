#pragma once

namespace bit
{
	// Iterator���ĸ������ĵ�������reverse_iterator<Iterator>�Ϳ���
	// ������ĸ������ķ�������������õ�����
	template <class Iterator, class Ref, class Ptr>
	class reverse_iterator
	{
		typedef reverse_iterator<Iterator, Ref, Ptr> self;
	public:
		reverse_iterator(Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			//return *_it;
			Iterator prev = _it;
			return *--prev;
		}

		Ptr operator->()
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