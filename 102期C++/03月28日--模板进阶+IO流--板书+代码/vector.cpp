// ��������
#include "vector.h"

//#include <iostream>
//using namespace std;
//
//void F1(int n);
//
//template<class T>
//void F2(const T& n);
//
void F1(int n)
{
	// ����ջָ֡��
	++n; //   mov eax  [n]
	     //   add eax 1
		 //   mov [n] eax
	cout << "void F1(int n)" << endl; // call 0x313131 [cout.operator<<(char*)]
}

//// ������û��ʵ������Ҳû�취�������ɻ�����
//template<class T>
//void F2(const T& n)
//{
//	cout << "void F1(const T& n)" << endl;
//}
//
//// 1����ʾʵ����
//// ��һ���͵���ʾʵ����һ�����ǳ��鷳
//template
//void F2<int>(const int& n);
//
//template
//void F2<double>(const double& n);

template<class T>
A<T>::A()
	:_a(0)
{}

template<class T>
void A<T>::f()
{}

//template
//class A < int > ;

//template
//A<int>::A();