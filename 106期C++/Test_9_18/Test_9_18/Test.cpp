
// :: 域操作限定符
//#include <stdio.h>
//
//int a = 10;
//
//int main()
//{
//	// 查找原则：现在局部找，局部没有则去全局找
//	
//	//:: 域作用限定符
//	printf("%d\n", ::a);//去全局域找a
//	return 0;
//}

//命名空间--namespace -- 作用： 避免命名冲突

//#include <stdio.h>
//#include <stdlib.h>
//
////命名空间不影响变量的生命周期，只是限定域，编辑查找规则
////默认查找规则：现在局部找，再去全局找
////在函数中定义的变量才是局部变量，在命名空间定义的变量属于全局变量，存放在静态区
//namespace wyt
//{
//	int rand = 10;//属于全局变量，不属于局部变量
//	int x = 1;
//}
//
//void func()
//{
//	int a = 100;//局部变量
//}
//int main()
//{
//	printf("%d\n", rand);//这里打印的是stdlib头文件中的rand库函数的地址；
//
//	//若想打印我们自己定义的rand变量，则需要使用域作用限定符
//	printf("%d\n", wyt::rand);
//	printf("%d\n", wyt::x);
//	return 0;
//}


// 命名空间的定义
//#include <stdio.h>
//一、
//namespace wyt
//{
//	//命名空间中可以定义 变量、函数、类型
//	int rand = 10;
//
//	int add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		int val;
//		struct Node* next;
//	};
//}
//二、
//namespace N1
//{
//	//命名空间可以嵌套定义
//	int a;
//	int b;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N2
//	{
//		int c;
//		int d;
//
//		int Add(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", wyt::add(10, 20));
//
//	//要注意调用命名空间中的类型的用法
//	struct wyt::Node node;
//
//	N1::a = 10;
//	N1::N2::c = 20;
//
//	return 0;
//}

//三
// 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
// 一个工程中的Stack.h和上面Queue.h中两个N1会被合并成一个

//#include "Queue.h"
//#include "Stack.h"
//#include <stdio.h>
//int main()
//{
//	//相同的命名空间，最后会合成同一个命名空间中
//	N1::QueuePush(NULL, 1);
//	N1::StackPush(NULL, 1);
//
//	return 0;
//
//}


//命名空间的使用
//#include <iostream>
//// std C++官方库内容定义的命名空间
//
////一、加命名空间名称及作用域限定符
//int main()
//{
//	//cout存放在iostream头文件下的std的命名空间中
//	std::cout << "Hello World!" << std::endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//// 这句代码的意思就是把整个命名空间展开，这样当我们使用std命名空间下的变量、函数等等就不需要加作用域限定符了
//// 这样用起来方便，但是命名的隔离墙就拆了，失去了隔离的意义
//// 日常练习，小程序，这么用可以，项目最好不要这么用
////二、使用using namespace 命名空间名称 引入
//int main()
//{
//	//cout存放在iostream头文件下的std的命名空间中
//	cout << "Hello World!" << endl;
//	return 0;
//}


//#include <iostream>
////三、使用using将命名空间中某个成员引入
////第三种方法就是指定展开--把常用的展开，自己在定义的时候避免跟常用重名即可
//using std::cout;
//using std::endl;
//int main()
//{
//	//cout存放在iostream头文件下的std的命名空间中
//	cout << "Hello World!" << endl;
//	return 0;
//}


//C++输入与输出
//cout：输出
//cin：输入

//#include<iostream>
//// std是C++标准库的命名空间名，C++将标准库的定义实现都放到这个命名空间中
//using namespace std;
//int main()
//{
//	//C++中的输入输出可以自动识别变量的类型，相比于c的printf\scanf
//	//哪个方便用哪个
//
//	//输出
//	// << 流插入运算符
//	cout << "Hello world!!!" << endl;//endl相当于换行
//	cout << "Hello world!!!" << '\n';
//
//	int a;
//	double b;
//	char c;
//
//	// >> 流提取运算符
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b <<" "<< c << endl;
//
//	printf("%.1f\n", b);//若想控制打印小数的个数，建议使用printf
//	cout <<"int:"<<a <<" "<<" double:"<< b <<" char:" << c << endl;
//	printf("int:%d double:%f char:%c", a, b, c);
//	return 0;
//}


//缺省参数
//#include<iostream>
//using namespace std;
//
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func();//没有传参时，使用参数的默认值
//	Func(10);//传参时，使用指定的实参
//
//	return 0;
//}


//缺省参数分类
#include<iostream>
using namespace std;

////一、全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//
//int main()
//{
//	Func();
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//	//Func(1, , 2);//不支持，传参必须是从左往右传的，而且必须是连续的
//	return 0;
//}

//一、半缺省/部分缺省 -- 必须从右往左连续缺省
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
////半缺省参数必须只能从右向左依次给出，而且必须连续，不能间隔着给
////int Func(int a, int b = 10, int c);//错误，不连续
////int Func(int a = 10, int b = 20, int c);//错误，不是从右往左给出
//
//int main()
//{
//	//Func();//不支持，因为是半缺省，必须得传参
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//	//Func(1, , 2);//不支持，传参必须是从左往右传的，而且必须是连续的
//	return 0;
//}

//注意：缺省值必须是常量或者全局变量


//函数重载 -- 函数名相同，参数必须不同（个数、类型、顺序）

// 1.参数类型不同
int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}
//
//void swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//void swap(double* px, double* py)
//{
//	double tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//	cout << add(1, 2) << endl;
//	cout << add(1.1, 2.2) << endl;
//
//	int a = 0, b = 1;
//	swap(&a, &b);
//
//	double c = 1.1, d = 2.2;
//	swap(&c, &d);
//
//	// 怎么调用到，后面会讲 -- 知道自动识别类型本质函数重载支持的
//	// ostream& operator<< (int val);
//	// ostream& operator<< (double val);
//	cout << a;
//	cout << c;
//
//	return 0;
//}

// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	f();
//	f(1);
//	return 0;
//}

// 3. 顺序不同是形参类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//	//这种顺序不同的情况不属于重载 -- 顺序不同指的是，形参类型的顺序不同
//	/*void f(int a, int b)
//	{
//		cout << "f(int a,char b)" << endl;
//	}
//
//	void f(int b, int a)
//	{
//		cout << "f(int a,char b)" << endl;
//	}*/
//
//int main()
//{
//	f(0, 'A');
//	f('A', 1);
//
//	return 0;
//}

//这两个函数构成重载，但会存在二义性
//f()调用会报错，存在歧义，编译器不知道该调用哪个，因为全缺省也可以这样调用
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0, char b = 1)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//int main()
//{
//	f(10);
//	f(10, 20);
//
//	//f(); // 歧义  二义性
//
//	return 0;
//}

//返回值不同，构成重载吗？？ -- 不构成
int f(int a, int b)
{
	cout << "f(int a,char b)" << endl;
	return 0;
}

char f(int a, int b)
{
	cout << "f(int a,char b)" << endl;
	return 'A';
}
//
//// 返回值不同，不构成重载原因，并不是函数名修饰规则
//// 真正原因是调用时的二义性，无法区分，
//// 因为调用时不指定返回值类型
int main()
{
	f(1, 1);
	f(2, 2);

	return 0;
}

