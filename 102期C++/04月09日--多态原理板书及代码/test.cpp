#include <iostream>
using namespace std;

// “看人下菜”
// 什么是多态：不同类型的对象，去完成同一件事情，结果不同(多种形态)

// C++11 final  override
// final

// 设计一个不能被继承的类？
// C++98
//class A
//{
//private:
//	A(int a = 0)
//		:_a(a)
//	{}
//
//public:
//	static A CreateOBj(int a = 0)
//	{
//		//new A;
//		return A(a);
//	}
//protected:
//	int _a;
//};
//
//// 间接限制，子类构成函数无法调用父类构造函数初始化成员，没办法实例化对象
//class B : public A
//{
//
//};
//
//int main()
//{
//	A aa = A::CreateOBj(10);
//
//	//B bb;
//
//	return 0;
//}

// C++11 直接限制
class A final
{
protected:
	int _a;
};

// 直接限制
//class B : public A
//{
//
//};

// C++ final 修饰虚函数，限制他不能被子类中的虚函数重写
//class C
//{
//public:
//	virtual void f() final
//	{
//		cout << "C::f()" << endl;
//	}
//};
//
//class D : public C
//{
//public:
//	/*virtual void f()
//	{
//		cout << "D::f()" << endl;
//	}*/
//};
//
//int main()
//{
//	return 0;
//}

// override放在子类重写的虚函数的后面，检查是否完成重写
// 没有重写的就会报错
//class Car{
//public:
//	void Drive()
//	{}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive() override
//	{ cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//	return 0;
//}

//class Car
//{
//public:
//	// 纯虚函数一般只声明，不实现
//	// 实现没有价值
//	//virtual void Drive() = 0;
//	virtual void Drive() = 0
//	{
//		cout << "virtual void Drive() = 0" << endl;
//	}
//
//	void f()
//	{
//		cout << "void f();" << endl;
//	}
//};
//
//int main()
//{
//	Car* p = nullptr;
//	p->Drive();
//	p->f();
//
//	return 0;
//}
//

// 抽象--在现实世界中没有对应的实物
// 一个类型，如果一般在现实世界中，没有具体的对应实物就定义成抽象类比较好
//class Car
//{
//public:
//	// 纯虚函数一般只声明，不实现
//	// 实现没有价值
//	virtual void Drive() = 0;
//	/*virtual void Drive() = 0
//	{
//		cout << "virtual void Drive() = 0" << endl;
//	}*/
//};

//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//int main()
//{
//	Car* p = new Benz;
//	p->Drive();
//
//	return 0;
//}

// 这里常考一道笔试题：sizeof(Base)是多少？-- 12
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch = 'A';
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base bb;
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket()
//	{ cout << "买票-全价" << endl; }
//
//	void f()
//	{
//		cout << "f()" << endl;
//	}
//protected:
//	int _a = 0;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket()
//	{ cout << "买票-半价" << endl; }
//protected:
//	int _b = 0;
//};
//
//void Func(Person& p)
//{
//	// 多态调用，在编译时，不能确定调用的是哪个函数
//	// 运行时，去p指向对象的虚表中
//	// 找到虚函数的地址。
//	p.BuyTicket();
//	p.f();
//}
//
//// 普通函数和虚函数存储的位置是否一样？
//// 他们是一样的，都在代码段。只是虚函数要把地址存一到虚表，方便实现多态
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//
//	//Person& r1 = Johnson;
//	//Person p = Johnson;
//
//	//Person p1 = Mike;
//	//Person p2 = Johnson;
//	//// 不是多态，编译时确定地址
//	//p1.BuyTicket();
//	//p2.BuyTicket();
//
//	//Person p1;
//	//Person p2;
//
//	//Student s1;
//	//Student s2;
//
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};

//int main()
//{
//	Base b;
//	Derive d;
//
//	Base* p1 = &b;
//	p1->Func1();
//
//	p1 = &d;
//	p1->Func1();
//
//
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(4);
//	printf("堆:%p\n", p);
//
//	int a = 0;
//	printf("栈:%p\n", &a);
//
//	static int b = 0;
//	printf("数据段:%p\n", &b);
//
//	const char* str = "aaaaaaa";
//	printf("常量区:%p\n", str);
//
//	printf("代码段:%p\n", &Base::Func1);
//
//	Base bs;
//	printf("虚函数表:%p\n", *((int*)&bs));
//
//	return 0;
//}

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//int main()
//{
//	Base b;
//
//	Derive d;
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

int main()
{
	Derive d;
	Base1* p1 = &d;
	p1->func1();

	Base2* p2 = &d;
	p2->func1();

	return 0;
}