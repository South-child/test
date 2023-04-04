#include<iostream>
#include<string>
#include<time.h>
#include <thread>
#include <vector>
using namespace std;

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
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
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		string str("�������");
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
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		string str("�������");
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
//		cout << "δ֪�쳣" << endl;
//	}
//
//	return 0;
//}

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//	// �����׳�ȥ��
//	int* array = new int[10];
//	int len, time;
//	cin >> len >> time;
//
//	try
//	{
//		cout << Division(len, time) << endl;
//	}
//	catch (...)  // �����쳣������Ҫ�����쳣������Ҫ�����ͷ���Դ
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;  // ����ʲô����������׳�ʲô����
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
//		// ��¼��־
//	}
//
//	return 0;
//}


// ������������ͨ��ʹ�õ��쳣�̳���ϵ
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
		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
	}

	//throw "xxxxxx";
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	// ...
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("������Դ������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
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
		catch (const Exception& e) // ���ﲶ�������Ϳ���
		{
			// ��̬
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
//		// �������ϵͳ�ڴ治��Ҳ�����쳣
//		//v.reserve(1000000000);
//
//		// ����Խ������쳣
//		v.at(10) = 100;
//	}
//	catch (const exception& e) // ���ﲶ�������Ϳ���
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

