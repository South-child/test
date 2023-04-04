#pragma once

#include<iostream>
#include <vector>
#include <time.h>
#include <mutex>
#include <thread>

using namespace std;

//static int callCount = 0;
//extern int callCount;
//vector<pair<int, int>> v;

// 单例模式 -- 任意一个类都可以设计成单例模式
// 饿汉模式
//class CallInfo
//{
//public:
//	static CallInfo& GetInstance()
//	{
//		return _inst;
//	}
//
//	int GetCallCount()
//	{
//		return _callCount;
//	}
//
//	void AddCallCount(int n)
//	{
//		_callCount += n;
//	}
//
//	void Push(const pair<int, int>& kv)
//	{
//		_v.push_back(kv);
//	}
//
//	CallInfo(const CallInfo&) = delete;
//private:
//	CallInfo()
//		:_callCount(0)
//	{}
//
//private:
//	int _callCount;
//	vector<pair<int, int>> _v;
//
//	static CallInfo _inst;
//};

// 懒汉模式
//class CallInfo
//{
//public:
//	static CallInfo& GetInstance()
//	{
//		// 双检查加锁
//		if (_pInst == nullptr)
//		{
//			std::unique_lock<mutex> lock(_mtx);
//			if (_pInst == nullptr)
//			{
//				_pInst = new CallInfo;
//			}
//		}
//
//		return *_pInst;
//	}
//
//	// 实现一个内嵌垃圾回收类 
//	// 一般懒汉的单例对象，不需要回收，因为进程正常结束，资源都会还给系统，这个对象只有一个
//	// 系统自动回收也没什么问题
//	// 但是如果你在单例对象释放析构时，有一些要完成的动作，比如要记录日志等等。那么可以考虑搞
//	// 一个类似下面的回收类帮助去完成这个事情
//	class CGarbo {
//	public:
//		~CGarbo()
//		{
//			if (_pInst)
//			{
//				delete _pInst;
//				_pInst = nullptr;
//			}
//		}
//	};
//
//	static CGarbo gc;
//
//	int GetCallCount()
//	{
//		return _callCount;
//	}
//
//	void AddCallCount(int n)
//	{
//		_callCount += n;
//	}
//
//	void Push(const pair<int, int>& kv)
//	{
//		_v.push_back(kv);
//	}
//
//	CallInfo(const CallInfo&) = delete;
//private:
//	CallInfo()
//		:_callCount(0)
//	{
//		cout << "CallInfo()" << endl;
//	}
//
//private:
//	int _callCount;
//	vector<pair<int, int>> _v;
//
//	static mutex _mtx;
//	static CallInfo* _pInst;
//};


// 懒汉
class CallInfo
{
public:
	static CallInfo& GetInstance()
	{
		// C++98 中多线程调用时，static sInst对象构造初始化并不能保证下线程安全
		// C++11 优化了这个问题，C++11中static sInst对象构造初始化是线程安全的
		static CallInfo sInst;

		return sInst;
	}

	int GetCallCount()
	{
		return _callCount;
	}

	void AddCallCount(int n)
	{
		_callCount += n;
	}

	void Push(const pair<int, int>& kv)
	{
		_v.push_back(kv);
	}

	CallInfo(const CallInfo&) = delete;
private:
	CallInfo()
		:_callCount(0)
	{
		cout << "CallInfo()" << endl;
	}

private:
	int _callCount;
	vector<pair<int, int>> _v;
};



// 统计快速排序递归调用次数
void QuickSort(int* a, int left, int right);