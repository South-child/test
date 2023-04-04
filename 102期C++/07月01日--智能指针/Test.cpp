#include <iostream>
#include <memory>
using namespace std;

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
//void func()
//{
//	int* p1 = new int;
//	int* p2 = nullptr, *p3 = nullptr;
//	try
//	{
//		p2 = new int;
//		p3 = new int;
//
//		cout << div() << endl; // 异常安全的问题
//	}
//	catch (...)
//	{
//
//	}
//
//	cout <<"delete:"<<p1 << endl;
//
//	delete p1;
//	delete p2;
//	delete p3;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// RAII
// 用起来像指针一样
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	// 像指针一样使用
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
//void func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//	SmartPtr<int> sp3(new int);
//
//	*sp1 = 10;
//	cout << *sp1 << endl;
//	(*sp1)++;
//	(*sp1)++;
//	cout << *sp1 << endl;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// 如何解决呢？
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1);
//
//
//	return 0;
//}

// 智能指针的发展历史
// C++98  管理权转移  auto_ptr
namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			// 管理权转移
			sp._ptr = nullptr;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}

// 结论：auto_ptr是一个失败设计，很多公司明确要求不能使用auto_ptr
//int main()
//{
//	std::auto_ptr<int> sp1(new int);
//	std::auto_ptr<int> sp2(sp1); // 管理权转移
//
//	// sp1悬空
//	*sp2 = 10;
//	cout << *sp2 << endl;
//	cout << *sp1 << endl;
//
//	return 0;
//}

// boost->scoped_ptr/shared_ptr/weak_ptr

// C++11库才更新智能指针实现
// C++11将boost库中智能指针精华部分吸收了过来
// C++11->unique_ptr/shared_ptr/weak_ptr

// unique_ptr/scoped_ptr
// 原理：简单粗暴 -- 防拷贝
namespace bit
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		unique_ptr(const unique_ptr<T>& sp) = delete;

	private:
		T* _ptr;
	};
}

//int main()
//{
//	/*bit::unique_ptr<int> sp1(new int);
//	bit::unique_ptr<int> sp2(sp1);*/
//
//	std::unique_ptr<int> sp1(new int);
//	//std::unique_ptr<int> sp2(sp1);
//
//	return 0;
//}

// 需要拷贝场景怎么办？
//namespace bit
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr)
//			:_ptr(ptr)
//		{
//			_refCount = 1;
//		}
//
//		shared_ptr(shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//		{
//			++_refCount;
//		}
//
//		~shared_ptr()
//		{
//			if (--_refCount == 0 && _ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//		// 像指针一样使用
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//		static int _refCount;
//	};
//
//	template<class T>
//	int shared_ptr<T>::_refCount = 0;
//}
//
//
//int main()
//{
//	bit::shared_ptr<int> sp1(new int);
//	bit::shared_ptr<int> sp2(sp1);
//	bit::shared_ptr<int> sp3(sp1);
//
//	bit::shared_ptr<int> sp4(new int);
//
//	//std::unique_ptr<int> sp1(new int);
//	//std::unique_ptr<int> sp2(sp1);
//
//	return 0;
//}

namespace bit
{
	// 休息到20：32继续
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pRefCount(sp._pRefCount)
		{
			++(*_pRefCount);
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp);

		~shared_ptr()
		{
			if (--(*_pRefCount) == 0 && _ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pRefCount;

				//_ptr = nullptr;
				//_pRefCount = nullptr;
			}
		}

		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pRefCount;
	};
}


int main()
{
	bit::shared_ptr<int> sp1(new int);
 	bit::shared_ptr<int> sp2(sp1);
	bit::shared_ptr<int> sp3(sp1);

	bit::shared_ptr<int> sp4(new int);

	return 0;
}