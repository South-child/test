#include <iostream>

using namespace std;


//int main()
//{
//	// 内置类型
//	// 相比malloc/free，除了用法的区别没有其他区别
//	int* p1 = new int;
//	delete p1;
//
//	int* p2 = new int(0);
//	delete p2;
//
//	int* p3 = new int[10];
//	delete[] p3;
//
//	int* p4 = new int[10]{1,2,3,4};
//	delete[] p4;
//
//	return 0;
//}

//
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	//~A()
//	//{
//	//	cout << "~A():" << this << endl;
//	//}
//
//private:
//	int _a;
//};
//
//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val = 0)
//		:_next(nullptr)
//		, _val(val)
//	{}
//};


//int main()
//{
//	// 自定义类型
//	// new和delete相比malloc，除了空间管理，还会调用构造函数和析构函数
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//
//	delete p1;
//	free(p2);
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	n1->_next = n2;
//	//...
//
//	return 0;
//}

//int main()
//{
//	// 一定要匹配使用，否则可能会出现各种情况
//	//A* p3 = new A[10];
//	//delete p3;
//
//	A* p4 = new A;
//	delete[] p4;
//
//	return 0;
//}



//void Test()
//{
//	while (1)
//	{
//		// new失败 抛异常 -- 不需要检查返回值
//		char* p1 = new char[1024 * 1024 * 1024];
//		//char* p1 = (char*)operator new(1024 * 1024 * 1024);
//		cout << (void*)p1 << endl;
//	}
//}
//
//int main()
//{
//	//while (1)
//	//{
//	//	// malloc失败 返回空指针
//	//	int* p1 = (int*)malloc(1024*100);
//	//	if (p1)
//	//	{
//	//		cout << p1 << endl;
//	//	}
//	//	else
//	//	{
//	//		cout << "申请失败" << endl;
//	//		break;
//	//	}
//	//}
//
//	//try
//	//{
//	//	Test();	
//	//}
//	//catch (exception& e)
//	//{
//	//	cout << e.what() << endl;
//	//}
//
//	A* p1 = new A[10];
//	//delete[] p1;
//
//	free(p1);
//
//	return 0;
//}


//定位new
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//int main()
//{
//	A* p1 = new A;
//	//A* p2 = new A[10];
//
//	A* p3 = (A*)malloc(sizeof(A));
//	if (p3 == nullptr)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	// 定位new -- 对p3指向空间，显示调用构造函数初始化
//	//在已分配的原始内存空间中调用构造函数初始化一个对象。
//	new(p3)A(1);
//
//	//p3->~A();
//	//free(p3);
//	delete p3;
//
//	delete p1;
//
//
//	return 0;
//}

//////////////////////////////////////////////////
//模板初阶
// 在C语言中，对不同的参数类型，必须写一个专门的函数，哪怕内部逻辑是一致的
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}

//template模板关键字
//template<class/typename T>
//template<class/typename Tp>
//template<class/typename K>

// 函数模板
//template<typename T> //一个参数模板，只能传同类型的参数 //template范围是最近的一个花括号
//void Swap(T& left, T& right)//会根据传参类型自动推到形参参数类型
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	int x = 1, y = 2;
//	Swap(x, y);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	char e = 'a', f = 'b';
//	Swap(e, f);
//
//	//Swap(x, c);
//
//	return 0;
//}

//template<class T>//一个参数模板，只能传同类型的参数
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	// 自动推演实例化
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	//对于只有一个参数模板，只能在传参时，自己去强转成一样的类型
//	cout << Add((double)a1, d2) << endl;
//	cout << Add(a1, (int)d2) << endl;
//
//	// 显示实例化
//	cout << Add<double>(a1, d2) << endl;
//	cout << Add<int>(a1, d2) << endl;
//
//	return 0;
//}

//
//template<class T1, class T2>//两个参数模板，可以传不同类型的参数
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}

//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	// 自动推演实例化
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	cout << Add(a1, d2) << endl;
//	cout << Add(d1, a2) << endl;
//
//	return 0;
//}


// 专门处理int的加法函数
//int Add(int left, int right) // _Z3Addii
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right) // _Z3TAddii
//{
//	return left + right;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Add(a, b);//有专门处理int的加法函数，则会去调用显示写了的加法函数
//	Add<int>(a, b);
// 
//	double d = 2.2;
//	Add(a, d); //对于类型不匹配的，会自动去调用函数模板
//	
//	return 0;
//}

/////////////////////////////
// 类模板
//typedef int STDataType;
//typedef double STDataType;

//template<typename T>
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = )" <<capacity<<endl;
//
//		_a = (T*)malloc(sizeof(T)*capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//	
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(const T& x)
//	{
//		// ....
//		// 扩容
//		_a[_top++] = x;
//	}
//
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//
//int main()
//{
//	// 类模板一般没有推演时机，函数模板实参传递形参，推演模板参数
//	// 显示实例化
//	// 他们是同一个类模板实例化出来的
//	// 但是模板参数不同，他们就是不同类型
//	Stack<double> st1; // double
//	st1.Push(1.1);
//
//	Stack<int> st2; // int
//	st2.Push(1);
//
//	return 0;
//}

#define N  10

namespace bit
{
	template<class T>
	class array
	{
	public:
		T& operator[](size_t i)//[]运算符重载
		{
			assert(i < N);
			return _a[i];
		}
	private:
		T _a[N];
	};
}

int main()
{
	//int a2[10];
	//a2[20] = 0;//越界不会检查
	//a2[10];

	bit::array<int> a1;
	for (size_t i = 0; i < N; ++i)
	{
		// a1.operator[](i)= i;
		a1[i] = i;
	}

	for (size_t i = 0; i < N; ++i)
	{
		// a1.operator[](i)
		cout << a1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < N; ++i)
	{
		a1[i]++;
	}

	for (size_t i = 0; i < N; ++i)
	{
		cout << a1[i] << " ";
	}
	cout << endl;

	//a1[20];//一定会进行越界检查
	//a1[10];


	return 0;
}
