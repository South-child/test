#include<iostream>
#include<functional>
#include <thread>
#include<condition_variable>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;
// 可调用对象类型
// 1、函数指针  void(*p)();
// 2、仿函数/函数对象
// 3、lambda表达式

//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//
//	return f(x);
//}
//
//double f(double i)
//{
//	return i / 2;
//}
//
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};

//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lamber表达式
//	cout << useF([](double d)->double{ return d / 4; }, 11.11) << endl;
//
//	return 0;
//}

//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a * b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b + 1;
//	}
//
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};

//int main()
//{
//	function<int(int, int)> f1 = f;
//	cout << f1(1, 2) << endl;
//
//	function<int(int, int)> f2 = Functor();
//	cout << f2(1, 2) << endl;
//
//	function<int(int, int)> f3 = &Plus::plusi;
//	cout << f3(1, 2) << endl;
//
//	function<double(Plus, double, double)> f4 = &Plus::plusd;
//	cout << f4(Plus(), 1.1, 2.2) << endl;
//
//	return 0;
//}

template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;

	return f(x);
}

double f(double i)
{
	return i / 2;
}

struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

//int main()
//{
//	// 函数名
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//
//	// 函数对象
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	// lamber表达式
//	std::function<double(double)> func3 = [](double d)->double{ return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//
//	return 0;
//}

int SubFunc(int a, int b)
{
	return a - b;
}

class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};

//int main()
//{
//	function<int(int, int)> f1 = SubFunc;
//	cout << f1(10, 3) << endl;
//
//	function<int(int, int)> f2 = bind(SubFunc, placeholders::_1, placeholders::_2);
//	cout << f2(10, 3) << endl;
//
//	// 通过bind调整参数顺序
//	function<int(int, int)> f3 = bind(SubFunc, placeholders::_2, placeholders::_1);
//	cout << f3(10, 3) << endl;
//
//	// 通过bind调整参数个数
//	function<int(Sub, int, int)> f4 = &Sub::sub;
//	cout << f4(Sub(), 10, 3) << endl;
//
//	function<int(int, int)> f5 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
//	cout << f5(10, 3) << endl;
//	
//	auto f6 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
//	cout << f6(10, 3) << endl;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////
// 两个线程对同一个变量x++
//int x = 0;
//mutex mtx;
//
////void Func(int n)
////{
////	// 加锁，加再循环里面还是循环外面？为什么？
////	// 2
////	mtx.lock();
////	for (int i = 0; i < n; ++i)
////	{
////		// 1
////		//cout << std::this_thread::get_id() <<"->"<< x << endl;
////		++x;
////	}
////	mtx.unlock();
////}
//
//void Func(int n)
//{
//	// 加锁，加再循环里面还是循环外面？为什么？
//	// 2
//	for (int i = 0; i < n; ++i)
//	{
//		// 1
//		++x;
//	}
//}
//
////void Func(int n)
////{
////	// 加锁，加再循环里面还是循环外面？为什么？
////	// 2
////	for (int i = 0; i < n; ++i)
////	{
////		mtx.lock();
////		//cout << std::this_thread::get_id() <<"->"<< x << endl;
////		++x;
////		mtx.unlock();
////	}
////}
//
//int main()
//{
//	thread t1(Func, 5000000);
//	thread t2(Func, 5000000);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

/////////////////////////////////////////////////////////
// 原子操作的++
//atomic<int> x = 0;
//void Func(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		++x;
//	}
//}
//
//int main()
//{
//	thread t1(Func, 5000000);
//	thread t2(Func, 5000000);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

//int main()
//{
//	//atomic<int> x = 0;
//	int x = 0;
//	mutex mtx;
//	int N = 10000000;
//	atomic<int> costTime1 = 0;
//
//	thread t1([&]{
//		int begin1 = clock();
//		mtx.lock();
//		for (int i = 0; i < N; ++i)
//		{
//			++x;
//		}
//		mtx.unlock();
//		int end1 = clock();
//
//		costTime1 += (end1 - begin1);
//	});
//
//	thread t2([&]{
//		int begin2 = clock();
//		mtx.lock();
//		for (int i = 0; i < N; ++i)
//		{
//			++x;
//		}
//		mtx.unlock();
//
//		int end2 = clock();
//
//		costTime1 += (end2 - begin2);
//	});
//
//	t1.join();
//	t2.join();
//
//	cout << x <<":"<<costTime1 <<endl;
//
//
//	return 0;
//}

//int main()
//{
//	//atomic<int> x = 0;
//	int x = 0;
//	mutex mtx;
//	int N, M;
//	cin >> N >> M;
//	vector<thread> vthds;
//	vthds.resize(N);
//	atomic<int> costTime = 0;
//
//	for (size_t i = 0; i < vthds.size(); ++i)
//	{
//		vthds[i] = thread([M, &x, &mtx, &costTime]{
//
//			int begin = clock();
//
//			mtx.lock();
//
//			for (int i = 0; i < M; ++i)
//			{
//
//				cout << std::this_thread::get_id() << "->" << x << endl;
//				cout << std::this_thread::get_id() << "->" << x << endl;
//				cout << std::this_thread::get_id() << "->" << x << endl;
//				cout << std::this_thread::get_id() << "->" << x << endl;
//				cout << std::this_thread::get_id() << "->" << x << endl;
//				++x;
//
//			}
//
//			mtx.unlock();
//
//
//
//			int end = clock();
//
//			costTime += (end - begin);
//		});
//	}
//
//	for (auto& e : vthds)
//	{
//		e.join();
//	}
//
//	cout << x << endl;
//	cout << "CostTime:" << costTime << endl;
//
//	return 0;
//}

//int main()
//{
//	cout << "**********" << endl;
//
//	this_thread::sleep_for(std::chrono::seconds(3));
//	cout << "**********" << endl;
//	this_thread::sleep_for(std::chrono::milliseconds(500));
//
//
//	cout << "**********" << endl;
//	return 0;
//}

//void func(int& x)
//{
//	cout <<"x:"<<&x << endl;
//	x += 10;
//}
//
////int main()
////{
////	int n = 0;
////	cout <<"n:"<<&n << endl;
////	// 严格来说thread可执行函数参数不能是左值引用
////	// 可以13支持C++11的bug
////	thread t1(func, std::ref(n));
////	t1.join();
////
////	cout << n << endl;
////
////	return 0;
////}

//void func(vector<int>& v, int n, int base, mutex& mtx)
//{
//	try
//	{
//		// 死锁
//		for (int i = 0; i < n; ++i)
//		{
//			mtx.lock();
//			cout << this_thread::get_id() << ":" << base + i << endl;
//
//			// 失败了 抛异常 -- 异常安全的问题
//			v.push_back(base+i);
//			// 模拟push_back失败抛异常
//			if (base == 1000 && i == 888)
//				throw bad_alloc();
//
//			mtx.unlock();
//		}
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//		mtx.unlock();
//	}
//}
//
//int main()
//{
//	thread t1, t2;
//	vector<int> vec;
//	mutex mtx;
//
//	try
//	{	
//		t1 = thread(func, std::ref(vec), 1000, 1000, std::ref(mtx));
//		t2 = thread(func, std::ref(vec), 1000, 2000, std::ref(mtx));
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	t1.join();
//	t2.join();
//
//	for (auto e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl << endl;
//	cout << vec.size() << endl;
//
//
//	return 0;
//}
//

// RAII

// 休息：20：30继续
template<class Lock>
class LockGuard // 锁的守卫
{
public:
	LockGuard(Lock& lock)
		:_lock(lock)
	{
		_lock.lock();
	}

	~LockGuard()
	{
		_lock.unlock();
	}
private:
	Lock& _lock;
};


void func(vector<int>& v, int n, int base, mutex& mtx)
{
	try
	{
		// 死锁
		for (int i = 0; i < n; ++i)
		{
			//mtx.lock();
			//LockGuard<mutex> lock(mtx);
			//lock_guard<mutex> lock(mtx);
			unique_lock<mutex> lock(mtx);

			cout << this_thread::get_id() << ":" << base + i << endl;

			// 失败了 抛异常 -- 异常安全的问题
			v.push_back(base + i);

			// 模拟push_back失败抛异常
			if (base == 1000 && i == 888)
				throw bad_alloc();


			// mtx.unlock();
		}
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

//int main()
//{
//	thread t1, t2;
//	vector<int> vec;
//	mutex mtx;
//
//	try
//	{
//		t1 = thread(func, std::ref(vec), 1000, 1000, std::ref(mtx));
//		t2 = thread(func, std::ref(vec), 1000, 2000, std::ref(mtx));
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	t1.join();
//	t2.join();
//
//	for (auto e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl << endl;
//	cout << vec.size() << endl;
//
//
//	return 0;
//}
//

// 两个线程交替打印，一个打印奇数 一个打印偶数
//int main()
//{
//	int n = 100;
//	int i = 0;
//	mutex mtx;
//
//	// 偶数-先打印
//	thread t1([n, &i, &mtx]{
//		while (i < n)
//		{
//			unique_lock<mutex> lock(mtx);
//
//			cout <<this_thread::get_id()<<":"<<i << endl;
//			++i;
//		}
//	});
//
//	// 奇数-后打印
//	thread t2([n, &i, &mtx]{
//		while (i < n)
//		{
//			// 模拟中间某次t2时间片用完了，竞争大，排队很，多休眠了一会
//			if (i == 50)
//				this_thread::sleep_for(chrono::nanoseconds(100));
//
//			unique_lock<mutex> lock(mtx);
//
//			cout << this_thread::get_id() << ":" << i << endl;
//			++i;
//		}
//	});
//
//	// 交替走
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

int main()
{
	int n = 100;
	int i = 0;
	mutex mtx;
	condition_variable cv;
	bool flag = false;

	// 奇数-后打印
	thread t2([n, &i, &mtx, &cv, &flag]{
		while (i < n)
		{
			// 模拟中间某次t2时间片用完了，竞争大，排队很，多休眠了一会
			/*if (i == 50)
			{
			cout << this_thread::get_id() << "休眠3s" << endl;
			this_thread::sleep_for(chrono::seconds(3));
			}*/

			unique_lock<mutex> lock(mtx);
			// flag是false的时候，这里会一直阻塞，知道flag变成true
			cv.wait(lock, [&flag](){return flag; });

			cout << this_thread::get_id() << ":->" << i << endl;
			++i;

			flag = false;

			cv.notify_one();
		}
	});

	// 偶数-先打印
	thread t1([n, &i, &mtx, &cv, &flag]{
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			// !flag是true,那么这里获取侯不会阻塞，优先运行了
			cv.wait(lock, [&flag](){return !flag; });

			cout << this_thread::get_id() << "->:" << i <<endl;
			++i;

			// 保证下一个打印运行一定是t1，也可以防止t1连续打印运行
			flag = true;

			cv.notify_one();
		}
	});

	// 交替走

	t1.join();
	t2.join();

	return 0;
}