// 结构定义和函数声明

//声明和定义分离优势是方便维护
//看xxx.h 了解框架设计个基本功能
//看xxx.cpp 了解具体实现细节

// W
//#pragma once
//// 等价
//#ifndef __VECTOR_H__
//#define __VECTOR_H__
//int a = 0;
//// ...
//#endif
//
//#ifndef __VECTOR_H__
//#define __VECTOR_H__
//int a = 0;
//// ...
//#endif

#include <iostream>
using namespace std;

void F1(int n);

template<class T>
void F2(const T& n);

template<class T>
void F2(const T& n)
{
	cout << "void F1(const T& n)" << endl;
}

template<class T>
class A
{
public:
	A();

	void f();
private:
	int _a;
};

//template<class T>
//A<T>::A()
//	:_a(0)
//{}