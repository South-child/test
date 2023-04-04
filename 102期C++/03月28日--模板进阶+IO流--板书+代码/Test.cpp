//
//
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//// 全特化
//template<>
//class Data < int, char >
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//};
//
//// 偏特化
//template<class T1>
//class Data < T1, char >
//{
//public:
//	Data() { cout << "Data<T1, char>" << endl; }
//private:
//};
//
//template<class T1, class T2>
//class Data < T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//};
//
//template<class T1, class T2>
//class Data < T1&, T2& >
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//private:
//};
//
//
//template<size_t N>
//class A
//{
//public:
//	A(){ cout << "A<N>" << endl; }
//};
//
//template<>
//class A<10>
//{
//public:
//	A(){ cout << "A<10>" << endl; }
//
//};
//
////int main()
////{
////	Data<int, int> d1;
////	Data<int, char> d2;
////
////	Data<char, char> d3;
////	Data<double, char> d4;
////
////	Data<double*, char*> d5;
////	Data<char*, char*> d6;
////
////	Data<char&, char&> d7;
////
////	A<100> aa1;
////	A<10> aa2;
////
////	return 0;
////}
//

#include "vector.h"

//#include <iostream>
//using namespace std;
//
//void F1(int n);
//
//template<class T>
//void F2(const T& n);
//
//template<class T>
//void F2(const T& n)
//{
//	cout << "void F1(const T& n)" << endl;
//}

//template<class T>
//class A
//{
//public:
//	A();
//private:
//	int _a;
//};

//int main()
//{
//	F1(10); // call _Z2F1I（？）         // 链接时去其他文件找的
//	F2(10); // call _Z2F2I（0x32344244） // 编译时就确定地址了
//	F2(10.22);
//
//	A<int>* p = nullptr; // 有声明，可以用类型
//	p->f();
//	A<int> aa; // 这里调用构造函数链接不上
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
// IO流
//int main()
//{
//	int i = 1;
//	double d = 2.22;
//	// 
//	cout << i; // -> cout.operator<<(i);
//	cout << d; // -> cout.operator<<(d);
//	cout << i << d; // 两个operator<<函数调用
//	printf("%d, %f\n", i, d);
//
//	//cin >> i;
//	//cin >> d;
//	cin >> i >> d;
//	scanf("%d%f", &i, &d);
//	cout << i << d << endl;
//	printf("%d, %f\n", i, d);
//
//	//scanf / printf 的缺点是只能支持内置类型
//	// cout<< / cin>> 真正优势是，自己重载以后，自定义类型对象可以是简单实用
//	//Date d;
//	//cin >> d;
//	//cout << d;
//
//	return 0;
//}

#include <string>

// OJ题：字符串转成整形
// 假设多组输入测试用例
//int main()
//{
//	string str;
//	//cin >> str;
//	// ...
//	while (cin>>str) // operator<<(cin, str)
//	{
//		// ...
//		cout << str << endl;
//	}
//
//	char a[128];
//	while (scanf("%s", a) != EOF)
//	{
//		cout << a << endl;
//	}
//
//	return 0;
//}

class B
{
public:
	operator bool()
	{
		return _a != 0;
	}
//private:
	int _a;
};

int main()
{
	B b;
	while (b) // while (b.operator bool())
	{
		cin >> b._a;
	}

	return 0;
}