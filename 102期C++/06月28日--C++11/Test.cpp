#include<iostream>
#include<functional>
#include <thread>
#include<condition_variable>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;
// �ɵ��ö�������
// 1������ָ��  void(*p)();
// 2���º���/��������
// 3��lambda���ʽ

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
//	// ������
//	cout << useF(f, 11.11) << endl;
//
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lamber���ʽ
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
//	// ������
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//
//	// ��������
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	// lamber���ʽ
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
//	// ͨ��bind��������˳��
//	function<int(int, int)> f3 = bind(SubFunc, placeholders::_2, placeholders::_1);
//	cout << f3(10, 3) << endl;
//
//	// ͨ��bind������������
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
// �����̶߳�ͬһ������x++
//int x = 0;
//mutex mtx;
//
////void Func(int n)
////{
////	// ����������ѭ�����滹��ѭ�����棿Ϊʲô��
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
//	// ����������ѭ�����滹��ѭ�����棿Ϊʲô��
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
////	// ����������ѭ�����滹��ѭ�����棿Ϊʲô��
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
// ԭ�Ӳ�����++
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
////	// �ϸ���˵thread��ִ�к���������������ֵ����
////	// ����13֧��C++11��bug
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
//		// ����
//		for (int i = 0; i < n; ++i)
//		{
//			mtx.lock();
//			cout << this_thread::get_id() << ":" << base + i << endl;
//
//			// ʧ���� ���쳣 -- �쳣��ȫ������
//			v.push_back(base+i);
//			// ģ��push_backʧ�����쳣
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

// ��Ϣ��20��30����
template<class Lock>
class LockGuard // ��������
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
		// ����
		for (int i = 0; i < n; ++i)
		{
			//mtx.lock();
			//LockGuard<mutex> lock(mtx);
			//lock_guard<mutex> lock(mtx);
			unique_lock<mutex> lock(mtx);

			cout << this_thread::get_id() << ":" << base + i << endl;

			// ʧ���� ���쳣 -- �쳣��ȫ������
			v.push_back(base + i);

			// ģ��push_backʧ�����쳣
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

// �����߳̽����ӡ��һ����ӡ���� һ����ӡż��
//int main()
//{
//	int n = 100;
//	int i = 0;
//	mutex mtx;
//
//	// ż��-�ȴ�ӡ
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
//	// ����-���ӡ
//	thread t2([n, &i, &mtx]{
//		while (i < n)
//		{
//			// ģ���м�ĳ��t2ʱ��Ƭ�����ˣ��������ŶӺܣ���������һ��
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
//	// ������
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

	// ����-���ӡ
	thread t2([n, &i, &mtx, &cv, &flag]{
		while (i < n)
		{
			// ģ���м�ĳ��t2ʱ��Ƭ�����ˣ��������ŶӺܣ���������һ��
			/*if (i == 50)
			{
			cout << this_thread::get_id() << "����3s" << endl;
			this_thread::sleep_for(chrono::seconds(3));
			}*/

			unique_lock<mutex> lock(mtx);
			// flag��false��ʱ�������һֱ������֪��flag���true
			cv.wait(lock, [&flag](){return flag; });

			cout << this_thread::get_id() << ":->" << i << endl;
			++i;

			flag = false;

			cv.notify_one();
		}
	});

	// ż��-�ȴ�ӡ
	thread t1([n, &i, &mtx, &cv, &flag]{
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			// !flag��true,��ô�����ȡ�������������������
			cv.wait(lock, [&flag](){return !flag; });

			cout << this_thread::get_id() << "->:" << i <<endl;
			++i;

			// ��֤��һ����ӡ����һ����t1��Ҳ���Է�ֹt1������ӡ����
			flag = true;

			cv.notify_one();
		}
	});

	// ������

	t1.join();
	t2.join();

	return 0;
}