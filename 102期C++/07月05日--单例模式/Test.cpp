#include<iostream>
using namespace std;

// 请设计一个类，只能在堆上创建对象
class HeapOnly
{
public:
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

	HeapOnly(const HeapOnly& ho) = delete;
private:
	HeapOnly()
		:_a(0)
	{}
private:
	int _a;
};

class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();
	}

	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	StackOnly()  
		:_a(0)
	{}

private:
	int _a;
};

//int main()
//{
//	//HeapOnly ho1;
//	//HeapOnly* pho = new HeapOnly;
//	HeapOnly* ptr1 = HeapOnly::CreateObj();
//	//HeapOnly copy(*ptr);
//
//	//StackOnly* ptr2 = new StackOnly;
//	StackOnly obj = StackOnly::CreateObj();
//	//StackOnly* ptr3 = new StackOnly(obj);
//
//	return 0;
//}
#include"Singleton.h"

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	int* a7 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
	}

	int begin5 = clock();
	QuickSort(a1, 0, N - 1);
	int end5 = clock();

	printf("QuickSort:%d\n", end5 - begin5);

	//cout << &callCount << endl;
	//printf("QuickSort Call Time:%d\n", callCount);
	printf("QuickSort Call Time:%d\n", CallInfo::GetInstance().GetCallCount());

	free(a1);

}

int main()
{
	//TestOP();

	thread t1([]{cout << &CallInfo::GetInstance() << endl; });
	thread t2([]{cout << &CallInfo::GetInstance() << endl; });

	t1.join();
	t2.join();

	cout << &CallInfo::GetInstance() << endl;
	cout << &CallInfo::GetInstance() << endl;
	cout << &CallInfo::GetInstance() << endl;
	cout << &CallInfo::GetInstance() << endl;
	cout << &CallInfo::GetInstance() << endl;


	return 0;
}