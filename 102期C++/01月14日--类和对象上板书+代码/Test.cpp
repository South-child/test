#include<iostream>
#include<map>
#include <string>
#include<assert.h>
//using namespace std;
// 1、日常练习，不太在乎命名污染，using namespace std;全部展开
// 2、项目中，不要全部展开。 指定访问或者展开常用
using std::cout;
using std::endl;

//int main()
//{
//	// IO流
//	int i = 0;
//	double d;
//	std::cin >> i;  // 流提取
//	std::cin >> d;
//	cout << i << d << endl; // 流插入
//	cout << "hello world" << endl;
//
//	return 0;
//}

//
//int main()
//{
//	int a = 0;
//
//	// 一个符号两用
//	int& b = a;   // 引用
//	int* p = &b;  // 取地址
//
//	// 引用取别名的过程中，权限可以缩小或者不变，但是不能放大
//	const int c = 10;
//	// int& d = c;    // 放大
//	const int& d = c; // 放大
//	const int& f = a; // 缩小
//
//	double dd = 1.1;
//	int ii = dd; // 类型转换 -- 中间产生临时变量
//	const int& rii = dd;
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int& b = a;
//
//	int* p = &a;
//
//	b = 2;
//	*p = 3;
//
//	char ch = 'a';
//	char& rch = ch;
//	cout << sizeof(rch) << endl;
//
//	return 0;
//}

//int main()
//{
//	const int a = 0;
//	int b = 0;
//	// 自动推到c的类型
//	auto c = a;
//	auto d = 'A';
//	auto e = 10.11;
//
//	// typeid打印变量的类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//
//	// 实际中，我们不会像上面那样去用auto
//	// 实际中使用场景
//	std::map<std::string, std::string> dict = {{ "sort", "排序" }, { "insert", "插入" }
//};
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	// 根据右边的值去自动推导it的类型，写起来就方便了
//	auto it = dict.begin();
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;  // int*
//	auto* b = &x; // int*
//	auto& c = x;  // int
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	 c = 40;
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	const auto y = x;
//	//y = x;
//	//cout << typeid(y).name() << endl;
//
//	return 0;
//}

// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
//void TestAuto(auto a)
//{}

//int main()
//{
//	int i = 0;
//	auto j = i;
//	//auto b[3] = { 4, 5, 6 };
//
//	return 0;
//}

//void TestFor(int a[])
//{
//	// 范围必须是数组名
//	for (auto& e : a)
//		cout << e << endl;
//}

//int main()
//{
//
//	// 语法糖 -- 范围for
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	TestFor(array);
//
//	// C/C++ 遍历数组
//	/*for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		cout << array[i] << endl;
//	}*/
//
//	// C++11 范围for
//	// 自动依次取数组array中的每个元素赋值给e
//	/*for (auto e : array)
//	{
//	cout << e << endl;
//	}
//
//	for (int x : array)
//	{
//	cout << x << endl;
//	}*/
//
//	// 范围for 把数组中每个值+1
//	for (auto& e : array)
//	{
//		e++;
//	}
//
//	for (auto e : array)
//	{
//		cout << e << endl;
//	}
//
//	return 0;
//}
//

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	// C++98/03
//	int* p1 = NULL;
//	int* p2 = 0;
//
//	// C++11 初始化空指针推荐用他nullptr
//	int* p3 = nullptr;
//
//	f(NULL);
//	f(0);
//	f(nullptr);
//
//	return 0;
//}

//struct/class
// C++ 兼容C里面结构体的用法
// 同时struct在C++中也升级成了类
//struct Student
//{
//	char name[10];
//	int  age;
//	int  id;
//};
//
//struct ListNode
//{
//
//};
//
//int main()
//{
//	// ListNode* node;
//	// struct ListNode* node;
//
//	struct Student s1; // 兼容c
//	Student s2;        // 升级到类，Student类名，也是类型
//
//	strcpy(s1.name, "张三");
//	s1.id = 1;
//	s1.age = 18;
//
//	strcpy(s2.name, "李四");
//	s2.id = 2;
//	s2.age = 19;
//
//
//	return 0;
//}


// struct/class
// C++ 兼容C里面结构体的用法
// 同时struct在C++中也升级成了类
// C++类跟结构体不同是除了可以定义变量，还是可以定方法/函数
//struct Student
//{
//	// 成员变量
//	char _name[10];
//	int  _age;
//	int  _id;
//
//	// 成员方法/成员函数
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//int main()
//{
//	// ListNode* node;
//	// struct ListNode* node;
//
//	struct Student s1; // 兼容c
//	Student s2;        // 升级到类，Student类名，也是类型
//
//	s1.Init("张三", 18, 1);
//	s2.Init("李四", 19, 2);
//
//	s1.Print();
//	s2.Print();
//
//	return 0;
//}

// 兼容c struct的用法本质
//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void StackInit(ST* ps);
//void StackDestroy(ST* ps);
//void StackPush(ST* ps, STDataType x);
//void StackPop(ST* ps);
//STDataType StackTop(ST* ps);
//int StackSize(ST* ps);
//bool StackEmpty(ST* ps);
//
//// C的库
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0; // ps->top = -1;
//	ps->capacity = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType)*newCapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	ps->top--;
//}
//
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//
//	/*if (ps->top == 0)
//	{
//	return true;
//	}
//	else
//	{
//	return false;
//	}*/
//	return ps->top == 0;
//}
//
//int main()
//{
//	//ST st;
//	//struct Stack st;
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//
//	return 0;
//}

// 面向对象三大特性：封装、继承、多态
// 封装: 1、数据和方法都放到了一起在类里面 2、访问限定符
// 一般在定义类的时候，建议明确定义访问限定符，不要用class/struct默认限定
//class Student
//{
//private:
//	// 成员变量
//	char _name[10];
//	int  _age;
//	int  _id;
//
//public:
//	// 成员方法/成员函数
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//class Stack
//{
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		
//	}
//
//	int Top()
//	{
//		assert(_top > 0);
//		return _a[_top - 1];
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	// ListNode* node;
//	// struct ListNode* node;
//
//	struct Student s1; // 兼容c
//	Student s2;        // 升级到类，Student类名，也是类型
//
//	s1.Init("张三", 18, 1);
//	s2.Init("李四", 19, 2);
//
//	s1.Print();
//	s2.Print();
//
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	int top = st.Top();
//
//	return 0;
//}

#include "Stack.h"

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};

// 类中什么都没有---空类
class A3
{};

// 结论：计算类或者类对象大小，只看成员变量，考虑内存对齐，C++内存对齐规则跟c结构体一致
int main()
{
	// 对象中存了成员变量，是否存了成员函数呢？没存成员函数
	//Stack s;
	////s._a
	//s.Init();

	//cout << sizeof(Stack) << endl;
	//cout << sizeof(s) << endl;

	Stack s1;
	Stack s2;
	// 每个对象中都有独立的成员变量
	s1._top = 0;
	s2._top = -1;

	// 不同对象调用成员函数，调是同一个
	s1.Init();
	s2.Init();

	// 空类会给1byte，这1byte不存储有效数据，只是为了占位，表示对象存在
	A2 aa;
	A2 bb;
	cout << &aa << endl;
	cout << &bb << endl;

	return 0;
}