#include<iostream>
#include<string>
#include<time.h>
#include <thread>
#include <vector>
using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func1()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (int errid)
//	{
//		cout << errid << endl;
//	}
//}
//
//void Func2()
//{
//	int len, time;
//	cin >> len >> time;
//	if (time != 0)
//	{
//		throw 1;
//	}
//	else
//	{
//		cout << len << " " << time << endl;
//	}
//}
//
//int main()
//{
//	try 
//	{
//		Func1();
//		Func2();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (int errid) 
//	{
//		cout << errid << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//
//	return 0;
//}

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		string str("除零错误");
//		throw str;
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func1()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func1();
//	}
//	catch (const string& errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//	return 0;
//}


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		string str("除零错误");
//		throw str;
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func2()
//{
//	int len, time;
//	cin >> len >> time;
//	if (time != 0)
//	{
//		throw 3.33;
//	}
//	else
//	{
//		cout << len << " " << time << endl;
//	}
//}
//
//void Func1()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const string& errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//
//	Func2();
//}
//
//
//
//int main()
//{
//	try
//	{
//		Func1();
//	}
//	catch (const string& errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (int errid)
//	{
//		cout << errid << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array = new int[10];
//	int len, time;
//	cin >> len >> time;
//
//	try
//	{
//		cout << Division(len, time) << endl;
//	}
//	catch (...)  // 拦截异常，不是要处理异常，而是要正常释放资源
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;  // 捕获到什么对象就重新抛出什么对象
//	}
//
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//		// 记录日志
//	}
//
//	return 0;
//}


// 服务器开发中通常使用的异常继承体系
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		,_id(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}
protected:
	string _errmsg;
	int _id;
};

class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;

		return str;
	}

private:
	const string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}

	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}

	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;

		return str;
	}

private:
	const string _type;
};

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}

	//throw "xxxxxx";
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	// ...
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}

	CacheMgr();
}

void ServerStart()
{
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));

		try{
			HttpServer();
		}
		catch (const Exception& e) // 这里捕获父类对象就可以
		{
			// 多态
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
}

//int main()
//{
//	ServerStart();
//
//	return 0;
//}

//int main()
//{
//	try{
//		vector<int> v(10, 5);
//		// 这里如果系统内存不够也会抛异常
//		//v.reserve(1000000000);
//
//		// 这里越界会抛异常
//		v.at(10) = 100;
//	}
//	catch (const exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//
//	return 0;
//}

