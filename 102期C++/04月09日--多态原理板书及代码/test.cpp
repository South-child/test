#include <iostream>
using namespace std;

// �������²ˡ�
// ʲô�Ƕ�̬����ͬ���͵Ķ���ȥ���ͬһ�����飬�����ͬ(������̬)

// C++11 final  override
// final

// ���һ�����ܱ��̳е��ࣿ
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
//// ������ƣ����๹�ɺ����޷����ø��๹�캯����ʼ����Ա��û�취ʵ��������
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

// C++11 ֱ������
class A final
{
protected:
	int _a;
};

// ֱ������
//class B : public A
//{
//
//};

// C++ final �����麯�������������ܱ������е��麯����д
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

// override����������д���麯���ĺ��棬����Ƿ������д
// û����д�ľͻᱨ��
//class Car{
//public:
//	void Drive()
//	{}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive() override
//	{ cout << "Benz-����" << endl; }
//};
//
//int main()
//{
//	return 0;
//}

//class Car
//{
//public:
//	// ���麯��һ��ֻ��������ʵ��
//	// ʵ��û�м�ֵ
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

// ����--����ʵ������û�ж�Ӧ��ʵ��
// һ�����ͣ����һ������ʵ�����У�û�о���Ķ�Ӧʵ��Ͷ���ɳ�����ȽϺ�
//class Car
//{
//public:
//	// ���麯��һ��ֻ��������ʵ��
//	// ʵ��û�м�ֵ
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
//		cout << "Benz-����" << endl;
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

// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�-- 12
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
//	{ cout << "��Ʊ-ȫ��" << endl; }
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
//	{ cout << "��Ʊ-���" << endl; }
//protected:
//	int _b = 0;
//};
//
//void Func(Person& p)
//{
//	// ��̬���ã��ڱ���ʱ������ȷ�����õ����ĸ�����
//	// ����ʱ��ȥpָ�����������
//	// �ҵ��麯���ĵ�ַ��
//	p.BuyTicket();
//	p.f();
//}
//
//// ��ͨ�������麯���洢��λ���Ƿ�һ����
//// ������һ���ģ����ڴ���Ρ�ֻ���麯��Ҫ�ѵ�ַ��һ���������ʵ�ֶ�̬
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
//	//// ���Ƕ�̬������ʱȷ����ַ
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
//	printf("��:%p\n", p);
//
//	int a = 0;
//	printf("ջ:%p\n", &a);
//
//	static int b = 0;
//	printf("���ݶ�:%p\n", &b);
//
//	const char* str = "aaaaaaa";
//	printf("������:%p\n", str);
//
//	printf("�����:%p\n", &Base::Func1);
//
//	Base bs;
//	printf("�麯����:%p\n", *((int*)&bs));
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