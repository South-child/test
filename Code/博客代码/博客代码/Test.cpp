#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	/*Stack(int capacity = 4)
//		:_a((int*)malloc(sizeof(int)*capacity))
//		, _top(0)
//		, _capacity(capacity)
//	{
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//	}*/
//
//	// ��ʼ���б�ͺ������ڳ�ʼ�����Ի�����
//	Stack(int capacity = 4)
//		: _top(0)
//		, _capacity(capacity)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memset(_a, 0, sizeof(int) * capacity);
//	}
//private:
//	int* _a;  // ����
//	int _top;
//	int _capacity;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// ����ÿ����Աʲôʱ�����ʼ���أ�-- ��ʼ���б�
//	// ÿ����Ա��Ҫ�߳�ʼ���б����㲻��ʾ�ڳ�ʼ���б�д��Ҳ����
//	// ����ڳ�ʼ���б���ʾд�˾�����ʾд�ĳ�ʼ��
//	// ���û���ڳ�ʼ���б���ʾ��ʼ��
//	// 1���������ͣ���ȱʡֵ��ȱʡֵ��û�о������ֵ
//	// 2���Զ������ͣ�����Ĭ������Ĭ�Ϲ��캯�������û��Ĭ�Ϲ���ͱ���
//	B( int ref)
//		:_n(10)
//		, _m(2)
//		, _aa(11)
//		, _ref(ref)
//	{
//		// _n = 10;
//	}
//
//private:
//	// const��Ա
//	const int _n;  // ����
//	int _m = 1;    // ȱʡֵ
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	B b(2);
//	return 0;
//}



//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}
//
//
// 
// 
//class Date
//{
//public:
//	//explicit���ι��캯������ֹ����ת��
//	explicit Date(int year = 0) //���������Ĺ��캯��
//		:_year(year)
//	{}
// 
//	void Print()
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year;
//
//};
//int main()
//{
//	//��ʽ����ת��
//	Date d1 = 2022; 
//	d1.Print();
//	return 0;
//}

//class Date
//{
//public:
//	// ���������
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1 = { 2022, 10, 12 };
//	// �ȼ���
//	Date d2(2022, 10, 12 );
//
//	const Date& d3 = { 2022, 10, 12 };
//
//	return 0;
//}




//class A {
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		++_N;
//	}
//	A(const A& aa)
//		: _a(aa._a)
//	{
//		++_N;
//	}
//	// û��thisָ�룬ֻ�ܷ��ʾ�̬��Ա
//	static int GetN()
//	{
//		return _N;
//	}
//private:
//	int _a;
//
//public:
//	static int _N;
//};
//
//// ��̬��Ա�����Ķ����ʼ��
//int A::_N = 0;
//
//void f(A a)
//{}
//
//int main(void)
//{
//	A a1;
//	A a2 = 1;//��ʽ����ת��
//	f(a1);
//
//	cout << a1._N << endl;//1.ͨ��������ó�Ա�������з���
//	cout << A::GetN() << endl; //3.ͨ���������þ�̬��Ա�������з���
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Test
//{
//private:
//	static int _n;
//};
//int main()
//{
//	cout << sizeof(Test) << endl;
//	return 0;
//}


//class Date
//{
//public:
//    Date(int year, int month, int day)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    // d1 << cout; -> d1.operator<<(&d1, cout); �����ϳ������
//    // ��Ϊ��Ա������һ������һ�������ص�this������d1�������<<�����
//    ostream & operator<<(ostream& _cout)
//    {
//        _cout << _year << "-" << _month << "-" << _day << endl;
//        return _cout;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};



//class Date
//{
//    friend ostream& operator<<(ostream& _cout, const Date& d);
//    friend istream& operator>>(istream& _cin, Date& d);
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//    _cout << d._year << "-" << d._month << "-" << d._day;
//    return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//    _cin >> d._year;
//    _cin >> d._month;
//    _cin >> d._day;
//    return _cin;
//}
//int main()
//{
//    Date d;
//    cin >> d;
//    cout << d << endl;
//    return 0;
//}



// �ڲ���
// 
// �൱��������������
// B��ķ�����A������ͷ����޶���������
//class A
//{
//private:
//	int _a;
//	static int k;
//
//public: // B��������A����Ԫ
//	class B
//	{
//		int _b;
//
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._a << endl;//OK
//		}
//	};
//};
//
//int A::k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl;//4
//    A aa;
//    cout << sizeof(aa) << endl;
//	A::B bb;
//
//	return 0;
//}



//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//
//A F()
//{
//	//A ret(10);
//	//return ret;
//	return A(10);
//}
//
//int main()
//{
//	// ��������
//	A aa0;
//	A aa1(1);
//	A aa2 = 2;
//
//	//A aa3();
//
//	// �������� --�������ڵ�ǰ��һ��
//	A();
//	A(3);
//
//	//Solution so;
//	//so.Sum_Solution(10);
//
//	Solution().Sum_Solution(10);
//
//	return 0;
//}




//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//void f1(A aa)
//{}
//
//A f2()
//{
//	A aa;
//	return aa;
//}
//
//A f3()
//{
//	/*A aa(10);
//	return aa;*/
//
//	return A(10);
//}


//int main()
//{
//	// �Ż�����1
//	A aa1 = 1;  // A tmp(1) + A aa1(tmp) -> �Ż� A aa1(1)
//
//	// �Ż�����2
//	A aa1(1);
//	f1(aa1);
//
//	f1(A(1));  // ���� + ��������  -> �Ż� ����
//	f1(1);  // ���� + ��������  -> �Ż� ����
//
//	f2();	  // ����+��������
//	A ret = f2(); // ����+��������+�������� ->�Ż� ����+��������
//
//
//	A ret = f3();  //  ����+��������+�������� -> �Ż� -> ����
//
//
//	return 0;
//}
//
//int globalVar               = 1;
//static int staticGlobalVar  = 1;
//
//void Test()
//{
//	static int staticVar = 1;
//
//	int localVar		= 1;
//
//	int num1[10]		= { 1, 2, 3, 4 };
//	char char2[]		= "abcd";
//	const char* pChar3	= "abcd";
//	int* ptr1			= (int*)malloc(sizeof(int) * 4);
//	int* ptr2			= (int*)calloc(4, sizeof(int));
//	int* ptr3			= (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}



//#include <iostream>
//using namespace std;
//int main()
//{
//	//ջ�����ٿռ䣬�ȿ��ٵĿռ��ַ��
//	int a = 10;
//	int b = 20;
//	cout << &a << endl;
//	cout << &b << endl;
//
//	cout << endl;
//
//	//�������ٿռ䣬�ȿ��ٵĿռ��ַ��
//	int* c = (int*)malloc(sizeof(int) * 10);
//	int* d = (int*)malloc(sizeof(int) * 10);
//	cout << c << endl;
//	cout << d << endl;
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    // calloc
//    int* p = (int*)calloc(10, sizeof(int)); // ����10����СΪint�Ŀռ䣬40
//    if (p == NULL)
//        return 1;
//    int i = 0;
//    for (i = 0; i < 10; i++)
//        printf("%d ", *(p + i));
//    free(p);
//    p = NULL;
//
//    return 0;
//}

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
//
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


//int main()
//{
//	//size_t sz = 2;
//	int* p1 = (int*)malloc(1024 * 1024 * 1024 * 2);
//	if (p1 == nullptr)
//	{
//		printf("%d\n", errno);// errno-������
//		perror("malloc fail");
//		exit(-1);
//	}
//
//	printf("%p", p1);
//	free(p1);
//
//	return 0;
//}


//int main()
//{
//	size_t sz = 2;
//
//	char* p1 = nullptr;
//	try
//	{
//		// ���м�� �д���ͽ���catch���̻�try�д���������Ҳ��ִ��
//		p1 = new char[1024 * 1024 * 1024 * sz];
//		cout << "�������" << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	printf("%p", p1);
//	delete[] p1;
//	return 0;
//}





////��λnew
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
//	p3->~A();
//	//free(p3);
//	//delete p3;
//
//
//
//	return 0;
//}



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
//
//void Swap(char& left, char& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//template<typename T> 
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//
//	double c = 1.1;
//	double d = 2.2;
//	Swap(c, d);
//
//	char e = 'a';
//	char f = 'b';
//	Swap(e, f);
//
//	return 0;
//}

//
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
//
//	// ��ʾʵ����
//	cout << Add<double>(a1, d2) << endl;
//	cout << Add<int>(a1, d2) << endl;
//
//	return 0;
//}

//template<class T1, class T2>//��������ģ�壬���Դ���ͬ���͵Ĳ���  //����дtypenameҲ����дclass
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	cout << Add(a1, d2) << endl;
//	cout << Add(d1, a2) << endl;
//
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ��,���÷�ģ�庯��������������Ҫʵ����
//	Add<int>(1, 2); // ���ñ�����ʵ������Add�汾
//}
//
//
//#include <iostream>
//using namespace std;
//ר������int���ͼӷ��ķ�ģ�庯��
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////ͨ�����ͼӷ��ĺ���ģ��
//template<typename T1, typename T2>
//T1 Add(const T1& x, const T2& y)
//{
//	return x + y;
//}
//int main()
//{
//	Add(10, 20); //���ģ�庯����ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(2.2, 2); //����ģ��������ɸ���ƥ��İ汾�������������ʵ�����ɸ���ƥ���Add����
//	return 0;
//}

//template<typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	Add(2, 2.2); //ģ�庯���������Զ�����ת��������ͨ������
//	//��Ϊֻ��һ������ģ�壬ֻ���ڴ���ʱ���Լ�ȥǿת��һ��������
//	return 0;
//}


//template<class T1, class T2, ..., class Tn>
//class ��ģ����
//{
//	// ���ڳ�Ա����
//};


//template<class T>
//class Scores
//{
//public:
//	void Print();
//private:
//	T _Math;
//	T _Chinese;
//	T _English;
//};
//template<class T>
//void Scores<T>::Print()
//{
//	cout << "��ѧ:" << _Math << endl;
//	cout << "����:" << _Chinese << endl;
//	cout << "Ӣ��:" << _English << endl;
//}
//
//
//int main()
//{
//	Scores<int> s1;
//	Scores<double> s1;
//
//	return 0;
//}


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
//	// ��ģ��ֻ����ʾʵ����
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



//void test_string1()
//{
//	string s1("1234");
//	// ����
//	// 1���±� []
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		s1[i]++;
//	}
//	cout << s1 << endl;
//}
//
//
//void test_string2()
//{
//	string s1("1234");
//	// 2����Χfor
//	for (auto& ch : s1)
//	{
//		ch++;//ÿ���ַ��Ӽ�
//	}
//
//	for (auto e : s1)
//	{
//		cout << e ;//������ӡ
//	}
//	cout << endl;
//	//cout << s1 << endl;//Ҳ����ֱ�Ӵ�ӡ��
//}

//void test_string2()
//{
//	string s1("1234");
//	// ��תһ��
//	size_t begin = 0, end = s1.size() - 1;//size()�����ַ�����Ч�ַ�����
//	while (begin < end)
//	{
//		swap(s1[begin++], s1[end--]);
//	}
//	cout << s1 << endl;
//
//}


//void test_string3()
//{
//	string s1("1234");
//	
//	cout << "const_iterator" << endl;
//	//const���������
//	string::const_iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		//�������
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//
//
//
//void test_string6()
//{
//	string s1("hello world");
//	cout << "ԭ�����ַ���" << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl << endl;
//
//
//	string s2("hello world");
//	//resize(n)nС�ڶ���ǰ��sizeʱ����size��С��n
//	s2.resize(5);
//	cout << "resize < �ַ�������" << endl;
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	cout << s2 << endl << endl;
//
//	string s3("hello world");
//	//resize(n, char)n���ڶ���ǰ��sizeʱ����size����n��������ַ�Ϊchar
//	s3.resize(15, 'x');
//	cout << "�ַ������� < resize < capacity" << endl;
//	cout << s3.size() << endl;
//	cout << s3.capacity() << endl;
//	cout << s3 << endl << endl;
//
//	string s4("hello world");
//	//resize(n, char)n���ڶ���ǰ��sizeʱ����size����n��������ַ�Ĭ��Ϊ'\0'
//	s4.resize(20);
//	cout << "resize > capacity" << endl;
//	cout << s4.size() << endl;
//	cout << s4.capacity() << endl;
//	cout << s4 << endl << endl;
//}
//
//void test_string7()
//{
//	//����100���ַ�x���ַ���
//	string s1(100, 'x');
//	cout <<"s1.size��" << s1.size() << endl;
//	cout <<"s1.capacity��"<< s1.capacity() << endl << endl;
//
//	//��resize���ַ�����Ϊ10���ַ�x
//	s1.resize(10);
//	cout << "s1.size��" << s1.size() << endl;
//	cout << "s1.capacity��" << s1.capacity() << endl << endl;
//
//	//ͨ��shrink_to_fit()��s1��capacity
//	//��Ϊ�ʺϴ�ʱs1��size�Ĵ�С���������˷ѿռ�
//	s1.shrink_to_fit();
//	cout << "s1.size��" << s1.size() << endl;
//	cout << "s1.capacity��" << s1.capacity() << endl;
//}
//
//int main()
//{
//	test_string7();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//
//	//clear()ɾ����������ݣ��ö��󽫱�Ϊ���ַ���
//	s.clear();
//	cout << s << endl; //���ַ���
//	return 0;
//}




//#include "string.h"
//int main()
//{
//	wyt::test_string6();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("I like C++!!!");
//
//	//erase(pos, n)ɾ��posλ�ÿ�ʼ��n���ַ�
//	s.erase(8, 5); //I like C
//	cout << s << endl; //I like C
//
//	//erase(pos)ɾ��posλ�õ��ַ�
//	string s1("hello world");
//	s1.erase(3); //I like
//	cout << s1 << endl; //I like
//
//	//erase(pos1, pos2)ɾ��[pos1pos2)�������ַ�
//	s.erase(s.begin() + 1, s.end()); //I
//	cout << s << endl; //I
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//void test_string()
//{
//	string s1("hello world hello world");
//	string s2("CSDN");
//
//	//��s1��գ��滻ָ��string����
//	s1.assign(s2);
//	cout << s1 << endl;//CSDN
//
//	//��s1��գ��滻ָ���ַ���
//	s1.assign("hello C++");
//	cout << s1 << endl;//hello C++
//
//	//��s1��գ��滻ָ���ַ�����һ����
//	s1.assign("hello C++", 5);
//	cout << s1 << endl;//hello
//
//	//��s1��գ��滻n��ָ�����ַ�
//	s1.assign(5, '!');
//	cout << s1 << endl;//����������
//}
//int main()
//{
//	test_string();
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;

//void test_string()
//{
//	string s1("hello world hello world");
//	string s2("CSDN");
//
//	//�ӵ������±�λ�ÿ�ʼ��������ַ��滻��s2����
//	s1.replace(6, 5, s2);
//	cout << s1 << endl;//hello CSDN hello world
//
//	//�ӵ������±�λ�ÿ�ʼ��������ַ��滻��ָ���ַ���
//	s1.replace(6, 5, "C++");
//	cout << s1 << endl;//hello C++hello world
//}

void test_string()
{
	// "Test.cpp"
	// "Test.cpp.tar"
	string file;
	cin >> file;
	// Ҫ��ȡ��׺
	size_t pos = file.rfind('.');
	if (pos != string::npos)
	{
		//string suffix = file.substr(pos, file.size() - pos);
		string suffix = file.substr(pos);
		cout << suffix << endl;
	}
}
void TestString()
{
	//��ȡ�ַ������׵�ַ����C�ַ�������ʽ����
	string s1("hello world");
	const char* str = s1.c_str();
	while (*str)
	{
		cout << *str << " ";
		str++;
	}
	cout << endl;
	s1 += '\0';
	s1 += " hello";
	cout << s1 << endl;           //���õ�string����operator<<  �����������������ַ������
	cout << s1.c_str() << endl;   //ֱ�����const char* ����\0����
}
int main()
{
	TestString();
	return 0;
}
