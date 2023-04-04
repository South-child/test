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

class Stack
{
public:
	Stack(int capacity = 4)
		:_top(0)
		, _capacity(capacity)
	{
		_a = new int[capacity];
	}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

//int main()
//{
//	Stack st1;  // ջ
//
//	Stack* pst2 = new Stack; // ���ռ� + ���캯����ʼ��
//	//...
//	delete pst2;             // ��������(�����������Դ) + �ͷſռ�  
//
//
//	return 0;
//}

//int main()
//{
//	// ��malloc���÷���һ����
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
	// ��malloc���÷���һ����
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

// ����ListNodeר����operator new
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
		p = allocator<ListNode>().allocate(1); //  STL���ڴ��--�ռ�������
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
//	// �ȼ���
//	A* p3 = (A*)operator new(sizeof(A));
//	new(p3)A(3);
//
//	p3->~A();
//	operator delete(p3);
//}

//
// 1��ʲô���ڴ�й©       -- ��̬������ڴ棬��ʹ���ˣ���û�������ͷţ��ʹ����ڴ�й©
// 2���ڴ�й©��Σ����ʲô��
// a�������ڴ�й©�Ľ����������������̽���ʱ��Щ�ڴ�ỹ��ϵͳ��������ʲô���˺���
// b�������ڴ�й©�Ľ��̷��������������罩ʬ���̡�Σ���ܴ�ϵͳ��Խ��Խ������������崻���
// c����Ҫ�������еĳ��򣬳����ڴ�й©��Σ���ܴ�ϵͳ��Խ��Խ������������崻���--����������
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

// ���ͱ��
// ģ��
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
// ����ģ��
//template<class T1, class T2> // template<typename T> // ģ������б� -- ��������
template<class T>
void Swap(T& x1, T& x2) // ���������б� -- ��������
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

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.2;
	cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;

	cout << Add((double)a1, d2) << endl;

	// ��ʾʵ����
	cout << Add<int>(a1, d2) << endl;
	cout << Add<double>(a1, d2) << endl;

	return 0;
}

