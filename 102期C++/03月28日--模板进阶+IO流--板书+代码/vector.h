// �ṹ����ͺ�������

//�����Ͷ�����������Ƿ���ά��
//��xxx.h �˽�����Ƹ���������
//��xxx.cpp �˽����ʵ��ϸ��

// W
//#pragma once
//// �ȼ�
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