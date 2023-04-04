#include<iostream>
using namespace std;

// 多态：多种形态
// 静态的多态：函数重载，看起来调用同一个函数有不同行为。 静态：原理是编译时实现
// 动态的多态：一个父类的引用或指针去调用同一个函数，传递不同的对象，会调用不同的函数。
//  动态：原理运行时实现
// 本质：不同人去做同一件事情，结果不同

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; return 0; }
//};
//
//class Student : public Person {
//public:
//	// 子类中满足三同(函数名、参数、返回值)虚函数，叫做重写(覆盖)
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//// 构成多态，跟p的类型没有关系，传的哪个类型的对象，调用的就是这个类型的虚函数 -- 跟对象有关
//// 不构成多态，调用就是p类型的函数 -- 跟类型有关
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	//int i = 1;
//	//double d = 2.22;
//	//cout << i;  // cout.operator<<(int)
//	//cout << d;  // cout.operator<<(double)
//
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	//st.BuyTicket();
//	//st.Person::BuyTicket();
//
//	return 0;
//}

// 重写要求返回值相同有一个例外：协变--要求返回值是父子关系的指针或者引用
//class A{};
//class B : public A {};
//
//class Person {
//public:
//	//virtual A* BuyTicket() { cout << "买票-全价" << endl; return nullptr; }
//	virtual Person* BuyTicket() { cout << "买票-全价" << endl; return nullptr; }
//};
//
//class Student : public Person {
//public:
//	// 子类中满足三同(函数名、参数、返回值)虚函数，叫做重写(覆盖)
//	//virtual B* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }
//	virtual Student* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }
//};
//
//// 构成多态，跟p的类型没有关系，传的哪个类型的对象，调用的就是这个类型的虚函数 -- 跟对象有关
//// 不构成多态，调用就是p类型的函数 -- 跟类型有关
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	//int i = 1;
//	//double d = 2.22;
//	//cout << i;  // cout.operator<<(int)
//	//cout << d;  // cout.operator<<(double)
//
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	//st.BuyTicket();
//	//st.Person::BuyTicket();
//
//	return 0;
//}

// 析构函数是虚函数，是否构成重写？-- 构成
// 析构函数名被特殊处理了，处理成了destructor
//class Person {
//public:
//	~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	// 普通对象，析构函数是否虚函数,是否完成重写，都正确调用了
//	// Person p;
//	// Student s;
//
//	// 动态申请的对象，如果给了父类指针管理，那么需要析构函数是虚函数
//	Person* p1 = new Person; // operator new + 构造函数
//	Person* p2 = new Student;
//
//	// 析构函数 + operator delete
//	//            p1->destructor()   
//	delete p1; 
//	delete p2;
//	//            p2->destructor()
//
//	return 0;
//}

// 虚函数的重写允许，两个都是虚函数或者父类是虚函数，再满足三同，就构成重写。
// 其实这个是C++不是很规范的地方，当然我们建议两个都写上virtual
// 本质上，子类重写的虚函数，可以不加virtual是因为析构函数，大佬设计初衷
// 父类析构函数加上virtual，那么就不存在不构成太态，没调用子类析构函数，内存泄漏场景
// 建议，我们自己写的时候，都加上virtual，肯定没毛病
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }

	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {

	// 虽然子类没写virtual，但是他是先继承了父类的虚函数的属性，再完成重写。那么他也算是虚函数
	void BuyTicket() { cout << "买票-半价" << endl; }
public:
	~Student() { cout << "~Student()" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	// 普通对象，析构函数是否虚函数,是否完成重写，都正确调用了
	// Person p;
	// Student s;

	// 动态申请的对象，如果给了父类指针管理，那么需要析构函数是虚函数
	Person* p1 = new Person; // operator new + 构造函数
	Person* p2 = new Student;

	// 析构函数 + operator delete
	//            p1->destructor()   
	delete p1;
	delete p2;
	//            p2->destructor()

	Person ps;
	Student st;

	Func(ps);
	Func(st);

	return 0;
}