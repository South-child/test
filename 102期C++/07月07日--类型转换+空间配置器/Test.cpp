#include<iostream>
using namespace std;

//void Test()
//{
//	int i = 1;
//	// ��ʽ����ת��
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// ��ʾ��ǿ������ת��
//	int address = (int)p;
//
//	printf("%x, %d\n", p, address);
//}

//int main()
//{
//	Test();
//
//	return 0;
//}

//typedef void(*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething" <<i<<endl;
//	return 0;
//}
//
//void Test()
//{
//	//
//	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
//	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
//	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
//	//
//	FUNC f = reinterpret_cast<FUNC>(DoSomething);
//	f();
//}

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//	Test();
//
//	return 0;
//}

//volatile const int a = 2;
//int b = 3;
//void Test()
//{
//	// ������
//	volatile const int a = 2;
//	//a = 10;
//
//	const char* str = "hello world";
//	int* p = const_cast<int*>(&a);
//
//	//int* p = (int*)&a;
//
//	*p = 3;
//
//	cout << a << endl;
//	cout << *p << endl;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

class A
{
	virtual void f(){}
public:
};

class B : public A
{
public:
	int _b = 0;
};

// 1��paָ�������
// 2��paָ���������
void func(A* pa)
{
	// ���pa��ָ���������ô�����κδ���
	// ���pa��ָ�����������ô��ת�����࣬���������������_b��Ա
	// dynamic_cast--���paָ��ĸ��������ô��ת�����ɹ�������nullptr
	//               ���paָ������������ô��ת���ɹ������ض���ָ��
	/*B* pb1 = dynamic_cast<B*>(pa);
	if (pb1 == nullptr)
	{
		cout << "ת��ʧ��" << endl;
	}
	else
	{
		cout << "pb1:" << pb1 << endl;
		pb1->_b++;
	}*/

	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	A aa;
	B bb;
	func(&aa);
	func(&bb);

	//aa = bb;
	//bb = reinterpret_cast<B>(aa); // ������
}