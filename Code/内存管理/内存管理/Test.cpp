#include <iostream>

using namespace std;


//int main()
//{
//	// ��������
//	// ���malloc/free�������÷�������û����������
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
//	// �Զ�������
//	// new��delete���malloc�����˿ռ����������ù��캯������������
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
//	// һ��Ҫƥ��ʹ�ã�������ܻ���ָ������
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
//		// newʧ�� ���쳣 -- ����Ҫ��鷵��ֵ
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
//	//	// mallocʧ�� ���ؿ�ָ��
//	//	int* p1 = (int*)malloc(1024*100);
//	//	if (p1)
//	//	{
//	//		cout << p1 << endl;
//	//	}
//	//	else
//	//	{
//	//		cout << "����ʧ��" << endl;
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


//��λnew
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
//	// ��λnew -- ��p3ָ��ռ䣬��ʾ���ù��캯����ʼ��
//	//���ѷ����ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
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
//ģ�����
// ��C�����У��Բ�ͬ�Ĳ������ͣ�����дһ��ר�ŵĺ����������ڲ��߼���һ�µ�
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

//templateģ��ؼ���
//template<class/typename T>
//template<class/typename Tp>
//template<class/typename K>

// ����ģ��
//template<typename T> //һ������ģ�壬ֻ�ܴ�ͬ���͵Ĳ��� //template��Χ�������һ��������
//void Swap(T& left, T& right)//����ݴ��������Զ��Ƶ��ββ�������
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

//template<class T>//һ������ģ�壬ֻ�ܴ�ͬ���͵Ĳ���
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	// �Զ�����ʵ����
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	//����ֻ��һ������ģ�壬ֻ���ڴ���ʱ���Լ�ȥǿת��һ��������
//	cout << Add((double)a1, d2) << endl;
//	cout << Add(a1, (int)d2) << endl;
//
//	// ��ʾʵ����
//	cout << Add<double>(a1, d2) << endl;
//	cout << Add<int>(a1, d2) << endl;
//
//	return 0;
//}

//
//template<class T1, class T2>//��������ģ�壬���Դ���ͬ���͵Ĳ���
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}

//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	// �Զ�����ʵ����
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	cout << Add(a1, d2) << endl;
//	cout << Add(d1, a2) << endl;
//
//	return 0;
//}


// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right) // _Z3Addii
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right) // _Z3TAddii
//{
//	return left + right;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Add(a, b);//��ר�Ŵ���int�ļӷ����������ȥ������ʾд�˵ļӷ�����
//	Add<int>(a, b);
// 
//	double d = 2.2;
//	Add(a, d); //�������Ͳ�ƥ��ģ����Զ�ȥ���ú���ģ��
//	
//	return 0;
//}

/////////////////////////////
// ��ģ��
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
//		// ����
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
//	// ��ģ��һ��û������ʱ��������ģ��ʵ�δ����βΣ�����ģ�����
//	// ��ʾʵ����
//	// ������ͬһ����ģ��ʵ����������
//	// ����ģ�������ͬ�����Ǿ��ǲ�ͬ����
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
		T& operator[](size_t i)//[]���������
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
	//a2[20] = 0;//Խ�粻����
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

	//a1[20];//һ�������Խ����
	//a1[10];


	return 0;
}
