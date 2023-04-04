#include<iostream>
#include<windows.h>
using namespace std;

class Person {
public:
	virtual void BuyTicket() { cout << "Person::��Ʊ-ȫ��" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "Student::��Ʊ-���" << endl; }
};

// ���ɶ�̬������ʱ���飬����ʱ��������˭
// �����ɶ�̬������ʱ���飬����ʱ��������˭
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//
//	return 0;
//}

typedef void(*VF_PTR)();

//void PrintVFTable(VF_PTR table[])
// ��ӡ�麯����������
void PrintVFTable(VF_PTR* table)
{
	for (int i = 0; table[i] != nullptr; ++i)
	{
		printf("vft[%d]:%p->", i, table[i]);
		VF_PTR f = table[i];
		f();
	}
	cout << endl << endl;
}

///////////////////////////////////////////////////////////////////////////////////
// ���̳�
//class Base {
//public:
//	Base()
//	{
//		a = 0;
//	}
////private:
//	virtual void func1() { cout << "Base::func1" <<endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a = -1;
//};
//
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
////int main()
////{
////	Base b;
////	//cout << &b << endl;
////	//b.func1();
////
////#ifdef _WIN64
////	PrintVFTable((VF_PTR*)(*(long long*)&b));
////#else
////	PrintVFTable((VF_PTR*)(*(int*)&b));
////#endif // _WIN64
////
////	//
////	PrintVFTable((VF_PTR*)(*(void**)&b));
////	//PrintVFTable((VF_PTR*)(*(char**)&b));
////
////	// PrintVFTable((VF_PTR*)(b));
////	// cout << sizeof(long long) << endl;
////
////	Derive d;
////
////	return 0;
////}
//
//// ������������ͣ�����ת��
//// int char ����
//// int double ��ʾ���ݴ�С
//// ���� ָ��
//int main()
//{
//	Base b;
//	PrintVFTable((VF_PTR*)(*(void**)&b));
//
//	Derive d;
//	PrintVFTable((VF_PTR*)(*(void**)&d));
//
//	return 0;
//}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};


class A
{
public:
	virtual void f1()
	{}
public:
	int _a;
};

// class B : public A
class B : virtual public A
{
public:
	virtual void f1()
	{}

	virtual void f2()
	{}
public:
	int _b;
};

// class C : public A
class C : virtual public A
{
public:
	virtual void f1()
	{}

	virtual void f2()
	{}
public:
	int _c;
};

class D : public B, public C
{
public:
	virtual void f1()
	{}
public:
	int _d;
};

//int main()
//{
//	//Base1 b1;
//	//Base2 b2;
//
//	//Derive d;
//
//	//PrintVFTable((VF_PTR*)*((void**)&d));
//	////PrintVFTable((VF_PTR*)*((void**)((char*)&d+sizeof(Base1))));
//
//	//Base1* p1 = &d;
//	//Base2* p2 = &d;
//	//PrintVFTable((VF_PTR*)*((void**)(p2)));
//
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}

#include "BinarySearchTree.h"

int main()
{
	TestBSTree();

	return 0;
}