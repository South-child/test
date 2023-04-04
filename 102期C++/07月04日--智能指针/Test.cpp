#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
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
	class default_delete
	{
	public:
		void operator()(const T* ptr)
		{
			cout << "delete:" << ptr << endl;
			delete ptr;
		}
	};

	// 释放方式有D删除器决定
	template<class T, class D = default_delete<T>>
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
				//cout << "delete:" << _ptr << endl;
				//delete _ptr;
				D del;
				del(_ptr);
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
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;

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

// 引用计数支持多个拷贝管理同一个资源，最后一个析构对象释放资源
namespace bit
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
			, _pmtx(new mutex)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pRefCount(sp._pRefCount)
			, _pmtx(sp._pmtx)
		{
			AddRef();
		}

		void Release()
		{
			_pmtx->lock();

			bool flag = false;
			if (--(*_pRefCount) == 0 && _ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pRefCount;

				flag = true;
			}

			_pmtx->unlock();

			if (flag == true)
			{
				delete _pmtx;
			}
		}

		void AddRef()
		{
			_pmtx->lock();

			++(*_pRefCount);

			_pmtx->unlock();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp)
			if (_ptr != sp._ptr)
			{
				Release();

				_ptr = sp._ptr;
				_pRefCount = sp._pRefCount;
				_pmtx = sp._pmtx;
				AddRef();
			}

			return *this;
		}

		int use_count()
		{
			return *_pRefCount;
		}

		~shared_ptr()
		{
			Release();
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

		T* get() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pRefCount;
		mutex* _pmtx;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();

			return *this;
		}

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

// shared_ptr智能指针是线程安全的吗？
// 是的，引用计数的加减是加锁保护的。但是指向资源不是线程安全的

// 指向堆上资源的线程安全问题是访问的人处理的，智能指针不管，也管不了
// 引用计数的线程安全问题，是智能指针要处理的
//int main()
//{
//	bit::shared_ptr<int> sp1(new int);
// 	bit::shared_ptr<int> sp2(sp1);
//	bit::shared_ptr<int> sp3(sp1);
//
//	bit::shared_ptr<int> sp4(new int);
//	bit::shared_ptr<int> sp5(sp4);
//
//	//sp1 = sp1;
//	//sp1 = sp2;
//
//	//sp1 = sp4;
//	//sp2 = sp4;
//	//sp3 = sp4;
//
//	*sp1 = 2;
//	*sp2 = 3;
//
//	return 0;
//}

struct Date
{
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

void SharePtrFunc(bit::shared_ptr<Date>& sp, size_t n, mutex& mtx)
{
	cout << sp.get() << endl;

	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		bit::shared_ptr<Date> copy(sp);

		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n

		{
			unique_lock<mutex> lk(mtx);
			copy->_year++;
			copy->_month++;
			copy->_day++;
		}

		//...
		//cout<<"hello"<<endl;
	}
}

// 休息到20:22继续

//int main()
//{
//	bit::shared_ptr<Date> p(new Date);
//	cout << p.get() << endl;
//	const size_t n = 100000;
//	mutex mtx;
//	thread t1(SharePtrFunc, std::ref(p), n, std::ref(mtx));
//	thread t2(SharePtrFunc, std::ref(p), n, std::ref(mtx));
//
//	t1.join();
//	t2.join();
//
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//
//	cout << p.use_count() << endl;
//
//	return 0;
//}

//struct ListNode
//{
//	int _val;
//	std::shared_ptr<ListNode> _next;
//	std::shared_ptr<ListNode> _prev;
//	//std::weak_ptr<ListNode> _next;
//	//std::weak_ptr<ListNode> _prev;
//
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//int main()
//{
//	std::shared_ptr<ListNode> n1(new ListNode);
//	std::shared_ptr<ListNode> n2(new ListNode);
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	// 循环引用
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////
struct ListNode
{
	int _val;
	//bit::shared_ptr<ListNode> _next;
	//bit::shared_ptr<ListNode> _prev;
	bit::weak_ptr<ListNode> _next;
	bit::weak_ptr<ListNode> _prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

//int main()
//{
//	bit::shared_ptr<ListNode> n1(new ListNode);
//	bit::shared_ptr<ListNode> n2(new ListNode);
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	// 循环引用
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	//n1->_next->_val++;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	return 0;
//}

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1 = 0;
	int _a2 = 0;
};

//////////////////////////////////////////////////////////////////
// 定制删除器 考试基本不考，实际使用有价值
// 默认情况，智能指针底层都是delete资源
// 那么如果你的资源不是new出来的呢？比如：new[]、malloc、fopen
// 定制删除器 -- 可调用对象

template<class T>
struct DeleteArray
{
	void operator()(const T* ptr)
	{
		cout << "delete[]:" << ptr << endl;
		delete[] ptr;
	}
};

//int main()
//{
//	std::unique_ptr<A> sp1(new A);
//	std::unique_ptr<A, DeleteArray<A>> sp2(new A[10]);
//
//	return 0;
//}

struct DeleteFile
{
	void operator()(FILE* ptr)
	{
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
	}
};

int main()
{
	// 删除器在类模板参数给 -- 类型
	bit::unique_ptr<A> up1(new A);
	bit::unique_ptr<A, DeleteArray<A>> up2(new A[10]);
	bit::unique_ptr<FILE, DeleteFile> up3(fopen("test.txt", "w"));

	// 删除器在构造函数的参数给 -- 对象
	std::shared_ptr<A> sp1(new A);
	std::shared_ptr<A> sp2(new A[10], DeleteArray<A>());
	std::shared_ptr<FILE> sp3(fopen("test.txt", "w"), DeleteFile());

	std::shared_ptr<A> sp4(new A[10], [](A* p){delete[] p; });
	std::shared_ptr<FILE> sp5(fopen("test.txt", "w"), [](FILE* p){fclose(p); });

	return 0;
}