// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���

// ����͸������ͬ����Ա������/�ض���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//
//int a = 0;
//// 1��A��B��func���캯������
//// 2�����뱨��
//// 3�����б���
//// 4��A��B��func���캯������
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
//	//b.fun(); // �������ˣ����Ե�����
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
//	string _name; // ����
//	//int* _ptr = new int[10];
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "����", int num = 1)
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
//	// �����������ֻᱻͳһ�����destructor()����ps������Ϊʲô��ͳһ������̬�½ڻὲ�⣩
//	// ��ô�����������������������������͹�������
//	~Student()
//	{
//		//Person::~Person();
//		// delete[] _ptr;
//	}
//	// ����������������ʱ�����Զ����ø������������
//	// ���������Լ�ʵ��������������ʱ������Ҫ��ʾ���ø�����������
//	// �������ܱ�֤�����������Ա�������������Ա
//
//protected:
//	int _num = 1; //ѧ��
//	//string _s = "hello world1111111111111111";
//	//int* _ptr = new int[10];
//};
//
//// 1����������ص���ĸ�Ĭ�ϳ�Ա���������ǲ�д����������Ĭ�����ɵĻ��Щʲô�����أ�
//// 2���������Ҫд��Ҫ��Щʲô�����أ�
//
//// ���ǲ�дĬ�����ɵ������Ĺ���������� 
//// a������̳������� (���ø���Ĭ�Ϲ������������)  b���Լ��ģ��������ͺ��Զ������ͳ�Ա��(����ͨ��һ��)
//// ���ǲ�дĬ�����ɵĿ��������operator=��
//// a������̳������� (���ø��࿽�������operator=) b���Լ��ģ��������ͺ��Զ������ͳ�Ա��(����ͨ��һ��)
//
//// �ܽ᣺ԭ�򣬼̳��������ø��ദ���Լ��İ���ͨ���������
//
//// ʲô����±����Լ�д��
//// 1������û��Ĭ�Ϲ��죬��Ҫ�����Լ���ʾд����
//// 2�������������Դ��Ҫ�ͷţ�����Ҫ�Լ���ʾд����
//// 3������������ǳ�������⣬����Ҫ�Լ�ʵ�ֿ�������͸�ֵ���ǳ��������
//
//// �������Ҫ�Լ�д��ô�죿����Լ�д��
//// �����Ա���ø���Ķ�Ӧ���졢�������졢operator=����������
//// �Լ���Ա����ͨ�ദ��
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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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
//	string _name; // ����
//	int _a[10000];
//};
//
//class Student : public Person
//{
//public:
//	int _num; //ѧ��
//};
//
//class Teacher : public Person
//{
//public:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	// �����ԡ���������
//	Assistant a;
//	a._id = 1;
//	a._num = 2;
//	a.Student::_name = "С��";
//	a.Teacher::_name = "����ʦ";
//
//	cout << sizeof(a) << endl;
//
//	return 0;
//}

// ��̳н����������Ͷ�����
class Person
{
public:
	string _name; // ����
	int _a[10000];
};

class Student : virtual public Person
{
public:
	int _num; //ѧ��
};

class Teacher : virtual public Person
{
public:
	int _id; // ְ�����
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};

//int main()
//{
//	// �����ԡ���������
//	Assistant a;
//	a._id = 1;
//	a._num = 2;
//	a.Student::_name = "С��";
//	a.Teacher::_name = "����ʦ";
//	a._name = "����";
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