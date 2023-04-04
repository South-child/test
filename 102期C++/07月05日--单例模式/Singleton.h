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

// ����ģʽ -- ����һ���඼������Ƴɵ���ģʽ
// ����ģʽ
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

// ����ģʽ
//class CallInfo
//{
//public:
//	static CallInfo& GetInstance()
//	{
//		// ˫������
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
//	// ʵ��һ����Ƕ���������� 
//	// һ�������ĵ������󣬲���Ҫ���գ���Ϊ����������������Դ���ỹ��ϵͳ���������ֻ��һ��
//	// ϵͳ�Զ�����Ҳûʲô����
//	// ����������ڵ��������ͷ�����ʱ����һЩҪ��ɵĶ���������Ҫ��¼��־�ȵȡ���ô���Կ��Ǹ�
//	// һ����������Ļ��������ȥ����������
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


// ����
class CallInfo
{
public:
	static CallInfo& GetInstance()
	{
		// C++98 �ж��̵߳���ʱ��static sInst�������ʼ�������ܱ�֤���̰߳�ȫ
		// C++11 �Ż���������⣬C++11��static sInst�������ʼ�����̰߳�ȫ��
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



// ͳ�ƿ�������ݹ���ô���
void QuickSort(int* a, int left, int right);