#include<iostream>
using namespace std;

// ��̬��������̬
// ��̬�Ķ�̬���������أ�����������ͬһ�������в�ͬ��Ϊ�� ��̬��ԭ���Ǳ���ʱʵ��
// ��̬�Ķ�̬��һ����������û�ָ��ȥ����ͬһ�����������ݲ�ͬ�Ķ��󣬻���ò�ͬ�ĺ�����
//  ��̬��ԭ������ʱʵ��
// ���ʣ���ͬ��ȥ��ͬһ�����飬�����ͬ

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; return 0; }
//};
//
//class Student : public Person {
//public:
//	// ������������ͬ(������������������ֵ)�麯����������д(����)
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//// ���ɶ�̬����p������û�й�ϵ�������ĸ����͵Ķ��󣬵��õľ���������͵��麯�� -- �������й�
//// �����ɶ�̬�����þ���p���͵ĺ��� -- �������й�
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

// ��дҪ�󷵻�ֵ��ͬ��һ�����⣺Э��--Ҫ�󷵻�ֵ�Ǹ��ӹ�ϵ��ָ���������
//class A{};
//class B : public A {};
//
//class Person {
//public:
//	//virtual A* BuyTicket() { cout << "��Ʊ-ȫ��" << endl; return nullptr; }
//	virtual Person* BuyTicket() { cout << "��Ʊ-ȫ��" << endl; return nullptr; }
//};
//
//class Student : public Person {
//public:
//	// ������������ͬ(������������������ֵ)�麯����������д(����)
//	//virtual B* BuyTicket() { cout << "��Ʊ-���" << endl; return nullptr; }
//	virtual Student* BuyTicket() { cout << "��Ʊ-���" << endl; return nullptr; }
//};
//
//// ���ɶ�̬����p������û�й�ϵ�������ĸ����͵Ķ��󣬵��õľ���������͵��麯�� -- �������й�
//// �����ɶ�̬�����þ���p���͵ĺ��� -- �������й�
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

// �����������麯�����Ƿ񹹳���д��-- ����
// ���������������⴦���ˣ��������destructor
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
//	// ��ͨ�������������Ƿ��麯��,�Ƿ������д������ȷ������
//	// Person p;
//	// Student s;
//
//	// ��̬����Ķ���������˸���ָ�������ô��Ҫ�����������麯��
//	Person* p1 = new Person; // operator new + ���캯��
//	Person* p2 = new Student;
//
//	// �������� + operator delete
//	//            p1->destructor()   
//	delete p1; 
//	delete p2;
//	//            p2->destructor()
//
//	return 0;
//}

// �麯������д�������������麯�����߸������麯������������ͬ���͹�����д��
// ��ʵ�����C++���Ǻܹ淶�ĵط�����Ȼ���ǽ���������д��virtual
// �����ϣ�������д���麯�������Բ���virtual����Ϊ����������������Ƴ���
// ����������������virtual����ô�Ͳ����ڲ�����̫̬��û�������������������ڴ�й©����
// ���飬�����Լ�д��ʱ�򣬶�����virtual���϶�ûë��
class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }

	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {

	// ��Ȼ����ûдvirtual�����������ȼ̳��˸�����麯�������ԣ��������д����ô��Ҳ�����麯��
	void BuyTicket() { cout << "��Ʊ-���" << endl; }
public:
	~Student() { cout << "~Student()" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	// ��ͨ�������������Ƿ��麯��,�Ƿ������д������ȷ������
	// Person p;
	// Student s;

	// ��̬����Ķ���������˸���ָ�������ô��Ҫ�����������麯��
	Person* p1 = new Person; // operator new + ���캯��
	Person* p2 = new Student;

	// �������� + operator delete
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