#include<iostream>
using namespace std;

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//};

//int main()
//{
//	// c
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->_next = nullptr;
//	n1->_prev = nullptr;
//	n1->_val = 0;
//
//	// cpp
//	ListNode* n2 = new ListNode(0);
//  delete n2;
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//int main()
//{
//	Stack st1;  // 栈
//
//	Stack* pst2 = new Stack; // 开空间 + 构造函数初始化
//	//...
//	delete pst2;             // 析构函数(清理对象中资源) + 释放空间  
//
//
//	return 0;
//}

//int main()
//{
//	// 跟malloc的用法是一样的
//	// Stack* pst1 = (Stack*)operator new(sizeof(Stack));
//
//	char* p1 = (char*)malloc(0x7fffffff);
//	if (p1 == nullptr)
//	{
//		printf("malloc fail\n");
//	}
//
//	try
//	{
//		char* p2 = new char[0x7fffffff];
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

void f()
{
	// 跟malloc的用法是一样的
	// Stack* pst1 = (Stack*)operator new(sizeof(Stack));

	char* p1 = (char*)malloc(0x7fffffff);
	if (p1 == nullptr)
	{
		printf("malloc fail\n");
	}

	char* p2 = new char[0x7fffffff];

	cout << "hello" << endl;
}

#include <vector>

//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	/*std::vector<int> v;
//	v.push_back(1);*/
//
//	return 0;
//}

//int main()
//{
//	Stack* p1 = new Stack[10];
//	Stack* p2 = (Stack*)operator new[](sizeof(Stack)*10);
//
//	return 0;
//}

// 定义ListNode专属的operator new
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;
	
	ListNode(int val)
		:_next(nullptr)
		, _prev(nullptr)
		, _data(val)
	{}

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1); //  STL中内存池--空间配置器
		cout << "memory pool allocate ListNode" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate ListNode" << endl;

	}
};

class List
{
public:
	List()
	{
		_head = new ListNode(-1);
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(int val)
	{
		ListNode* newnode = new ListNode(val);
		ListNode* tail = _head->_prev;
		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;
	}

	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}

		delete _head;
		_head = nullptr;
	}

private:
	ListNode* _head;
};

//int main()
//{
//	List l;
//	l.PushBack(1);
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//	l.PushBack(5);
//	l.PushBack(5);
//	l.PushBack(5);
//
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	//new(p)A;
//	new(p1)A(1);
//
//	A* p2 = new A(2);
//	delete p2;
//
//	// 等价于
//	A* p3 = (A*)operator new(sizeof(A));
//	new(p3)A(3);
//
//	p3->~A();
//	operator delete(p3);
//}

//
// 1、什么是内存泄漏       -- 动态申请的内存，不使用了，又没有主动释放，就存在内存泄漏
// 2、内存泄漏的危害是什么？
// a、出现内存泄漏的进程正常结束，进程结束时这些内存会还给系统，不会有什么大伤害！
// b、出现内存泄漏的进程非正常结束，比如僵尸进程。危害很大，系统会越来越慢，甚至卡死宕机。
// c、需要长期运行的程序，出现内存泄漏。危害很大，系统会越来越慢，甚至卡死宕机。--服务器程序
// 

//int main()
//{
//	//int* p = new int[10];
//	char* p = new char[1024 * 1024 * 1024];
//	//cout << p << endl;
//	printf("%p\n", p);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	//void* p = new char[1024u*1024u*1024u*2u-1];
//	cout << sizeof(void*) << endl;
//	//void* p = new char[0xfffffffful];
//	//cout << "new:" << p << endl;
//
//	return 0;
//}

// 泛型编程
// 模板
//void Swap(int& x1, int& x2)
//{
//	int x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//void Swap(double& x1, double& x2)
//{
//	double x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//void Swap(char& x1, char& x2)
//{
//	char x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.22;
//	Swap(a, b);
//	Swap(c, d);
//
//	char e = 'A', f = 'B';
//	Swap(e, f);
//
//	return 0;
//}

// Type
// 函数模板
//template<class T1, class T2> // template<typename T> // 模板参数列表 -- 参数类型
template<class T>
void Swap(T& x1, T& x2) // 函数参数列表 -- 参数对象
{
	T x = x1;
	x1 = x2;
	x2 = x;
}

//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.22;
//	Swap(a, b);
//	Swap(c, d);
//
//	char e = 'A', f = 'B';
//	Swap(e, f);
//
//	//auto x = 1;
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	cout << Add((double)a1, d2) << endl;
//
//	// 显示实例化
//	cout << Add<int>(a1, d2) << endl;
//	cout << Add<double>(a1, d2) << endl;
//
//	return 0;
//}

//template<class T1, class T2>
//T2 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	cout << Add(a1, d2) << endl;
//
//	return 0;
//}


// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}

// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	cout << Add(a1, d2) << endl;
//
//	return 0;
//}

////typedef int STDataType;
//typedef double STDataType;
//
//class StackInt
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new STDataType[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//
//class StackDouble
//{
//public:
//	StackDouble(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new STDataType[capacity];
//	}
//
//	~StackDouble()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	double* _a;
//	int _top;
//	int _capacity;
//};

// 类模板
// Stack 类名
// Stack<T> 类型
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_top(0)
		, _capacity(capacity)
	{
		_a = new T[capacity];
	}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

	void Push(const T& x);

private:
	T* _a;
	int _top;
	int _capacity;
};

template<class T>
void Stack<T>::Push(const T& x)
{
	// ...
}

//int main()
//{
//	Stack<int> st1;     // 存储int
//	Stack<double> st2;  // 存储double
//	Stack<char> st3;
//	Stack<int*> st4;
//
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	return 0;
//}
// char
// wchar_t
template<class T>
class basic_string
{
private:
	T* _str;
	// ...
};

//
// 编码 - 值--符号建议映射关系 -- 编码表
// ascii编码表 -- 表示英文编码表
// unicode    -- 表示全世界文字编码表  utf-8  utf-16  utf-32
// gbk    -- 中文自己量身定做都编码表
// 
// typedef basic_string<char> string;
// 
// 256 * 256
// 2 ^ 16

// wocao
//int main()
//{
//	//string s1("hello");
//	char str1[] = "hello";
//	cout << str1 << endl;
//	char str2[] = "吃饭";
//	str2[1] += 1;
//	str2[3] += 1;
//
//	str2[1] += 1;
//	str2[3] += 1;
//
//	str2[1] += 1;
//	str2[3] += 1;
//
//	cout << sizeof(char) << endl;
//	cout << sizeof(wchar_t) << endl;
//
//	return 0;
//}

#include <string>

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//
//	//cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 2, 6);
//	cout << s4 << endl;
//
//	string s5(s2, 2);
//	cout << s5 << endl;
//
//	string s6(s2, 2, 100);
//	cout << s6 << endl;
//
//	string s7("hello world", 3);
//	cout << s7 << endl;
//
//	string s8(10, '!');
//	cout << s8 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//
//	//cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 2, 6);
//	cout << s4 << endl;
//
//	string s5(s2, 2);
//	cout << s5 << endl;
//
//	string s6(s2, 2, 100);
//	cout << s6 << endl;
//
//	string s7("hello world", 3);
//	cout << s7 << endl;
//
//	string s8(10, '!');
//	cout << s8 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	cin >> s1;
//	// 不包含最后作为结尾标识符的\0 , 有效字符的长度
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.max_size() << endl;
//	cout << s1 << endl;
//
//	cout << s1.capacity() << endl;
//	s1.clear();
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;
//
//
//	return 0;
//}

//char& operator[] (size_t pos)
//{
//  assert(pos < _size);
//	return _str[pos];
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1.operator[](i) << " ";
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		s1[i] += 1;
//	}
//	cout << endl;
//
//	cout << s1 << endl;
//
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		s1.at(i) -= 1;
//	}
//	cout << endl;
//	cout << s1 << endl;
//
//	//s1[100];
//	try
//	{
//		s1.at(100);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//
//	return 0;
//}

int main()
{
	string s1;
	s1.push_back('a');
	s1.append("bcde");
	cout << s1 << endl;

	s1 += ':';
	s1 += "hello world";
	cout << s1 << endl;


	return 0;
}