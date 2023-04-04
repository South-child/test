#include<iostream>
using namespace std;

//void Test()
//{
//	int i = 1;
//	// 隐式类型转换
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// 显示的强制类型转换
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
//	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
//	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
//	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
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
//	// 常变量
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

// 1、pa指向父类对象
// 2、pa指向子类对象
void func(A* pa)
{
	// 如果pa是指向父类对象，那么不做任何处理
	// 如果pa是指向子类对象，那么请转回子类，并访问子类对象中_b成员
	// dynamic_cast--如果pa指向的父类对象，那么则转换不成功，返回nullptr
	//               如果pa指向的子类对象，那么则转换成功，返回对象指针
	/*B* pb1 = dynamic_cast<B*>(pa);
	if (pb1 == nullptr)
	{
		cout << "转换失败" << endl;
	}
	else
	{
		cout << "pb1:" << pb1 << endl;
		pb1->_b++;
	}*/

	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
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
	//bb = reinterpret_cast<B>(aa); // 不允许
}