// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆

// 子类和父类出现同名成员：隐藏/重定义
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int a = 0;
//// 1：A和B的func构造函数重载
//// 2：编译报错
//// 3：运行报错
//// 4：A和B的func构造函数隐藏
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void Test()
//{
//	B b;
//	b.fun(1);
//	//b.fun(); // 被隐藏了，所以调不动
//	b.A::fun();
//};

//int main()
//{
//	int a = 1;
//	cout << ::a << endl;
//
//	Student s;
//	s.Print();
//
//	Test();
//
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//		//delete[] _ptr;
//	}
//protected:
//	string _name; // 姓名
//	//int* _ptr = new int[10];
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "张三", int num = 1)
//		:Person(name)
//		, _num(num)
//	{}
//
//	// s2(s1)
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//	{}
//
//	// s2 = s1
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//
//			_num = s._num;
//		}
//
//		return *this;
//	}
//
//	// 析构函数名字会被统一处理成destructor()。（ps：至于为什么会统一处理，多态章节会讲解）
//	// 那么子类的析构函数跟父类的析构函数就构成隐藏
//	~Student()
//	{
//		//Person::~Person();
//		// delete[] _ptr;
//	}
//	// 子类析构函数结束时，会自动调用父类的析构函数
//	// 所以我们自己实现子类析构函数时，不需要显示调用父类析构函数
//	// 这样才能保证先析构子类成员，再析构父类成员
//
//protected:
//	int _num = 1; //学号
//	//string _s = "hello world1111111111111111";
//	//int* _ptr = new int[10];
//};
//
//// 1、派生类的重点的四个默认成员函数，我们不写，编译器会默认生成的会干些什么事情呢！
//// 2、如果我们要写，要做些什么事情呢？
//
//// 我们不写默认生成的派生的构造和析构？ 
//// a、父类继承下来得 (调用父类默认构造和析构处理)  b、自己的（内置类型和自定义类型成员）(跟普通类一样)
//// 我们不写默认生成的拷贝构造和operator=？
//// a、父类继承下来得 (调用父类拷贝构造和operator=) b、自己的（内置类型和自定义类型成员）(跟普通类一样)
//
//// 总结：原则，继承下来调用父类处理，自己的按普通类基本规则。
//
//// 什么情况下必须自己写？
//// 1、父类没有默认构造，需要我们自己显示写构造
//// 2、如果子类有资源需要释放，就需要自己显示写析构
//// 3、如果子类存在浅拷贝问题，就需要自己实现拷贝构造和赋值解决浅拷贝问题
//
//// 如果我们要自己写怎么办？如何自己写？
//// 父类成员调用父类的对应构造、拷贝构造、operator=和析构处理
//// 自己成员按普通类处理。
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//	//Student s3("jack", 18);
//
//	//s1 = s3;
//
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Graduate g;
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	cout << Graduate::_count << endl;
//
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//	cout << &Graduate::_count << endl;
//}


//class Person
//{
//public:
//	string _name; // 姓名
//	int _a[10000];
//};
//
//class Student : public Person
//{
//public:
//	int _num; //学号
//};
//
//class Teacher : public Person
//{
//public:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 二义性、数据冗余
//	Assistant a;
//	a._id = 1;
//	a._num = 2;
//	a.Student::_name = "小张";
//	a.Teacher::_name = "张老师";
//
//	cout << sizeof(a) << endl;
//
//	return 0;
//}

// 虚继承解决数据冗余和二义性
class Person
{
public:
	string _name; // 姓名
	int _a[10000];
};

class Student : virtual public Person
{
public:
	int _num; //学号
};

class Teacher : virtual public Person
{
public:
	int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};

//int main()
//{
//	// 二义性、数据冗余
//	Assistant a;
//	a._id = 1;
//	a._num = 2;
//	a.Student::_name = "小张";
//	a.Teacher::_name = "张老师";
//	a._name = "张三";
//
//	cout << sizeof(a) << endl;
//
//	return 0;
//}

//int main()
//{
//	return 0;
//}

class A
{
public:
	int _a;
};

//class B : public A
class B : virtual public A
{
public:
	int _b;
};

//class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;

	return 0;
}