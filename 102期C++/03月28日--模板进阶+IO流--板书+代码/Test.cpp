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
//// ȫ�ػ�
//template<>
//class Data < int, char >
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//};
//
//// ƫ�ػ�
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
//	F1(10); // call _Z2F1I������         // ����ʱȥ�����ļ��ҵ�
//	F2(10); // call _Z2F2I��0x32344244�� // ����ʱ��ȷ����ַ��
//	F2(10.22);
//
//	A<int>* p = nullptr; // ������������������
//	p->f();
//	A<int> aa; // ������ù��캯�����Ӳ���
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
// IO��
//int main()
//{
//	int i = 1;
//	double d = 2.22;
//	// 
//	cout << i; // -> cout.operator<<(i);
//	cout << d; // -> cout.operator<<(d);
//	cout << i << d; // ����operator<<��������
//	printf("%d, %f\n", i, d);
//
//	//cin >> i;
//	//cin >> d;
//	cin >> i >> d;
//	scanf("%d%f", &i, &d);
//	cout << i << d << endl;
//	printf("%d, %f\n", i, d);
//
//	//scanf / printf ��ȱ����ֻ��֧����������
//	// cout<< / cin>> ���������ǣ��Լ������Ժ��Զ������Ͷ�������Ǽ�ʵ��
//	//Date d;
//	//cin >> d;
//	//cout << d;
//
//	return 0;
//}

#include <string>

// OJ�⣺�ַ���ת������
// ������������������
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