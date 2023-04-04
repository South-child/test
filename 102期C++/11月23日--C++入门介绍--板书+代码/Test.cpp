#include <stdio.h>
#include <stdlib.h>
#include "List.h"
// CPP -> C plus plus

// 命名冲突问题
// 1、我们自己定义的变量、函数可能跟库里面重名冲突
// 2、进入公司项目组以后，做的项目通常比较大。多人协作，两个同事写的代码，命名冲突。
// C语言没有办法很好的解决这个问题
// CPP提出一个新语法，命名空间

// 定义了一个叫bit的命名空间 -- 域
//namespace bit
//{
//	// 他们还是全局变量，放到静态区的
//	int rand = 0;
//	int a = 1;
//}
//
//int a = 0;
//
//int main()
//{
//	printf("hello world\n");
//	printf("%d\n", rand);
//	printf("%d\n", bit::rand);
//
//	int a = 1;
//	printf("%d\n", a);
//
//	printf("%d\n", ::a);
//
//	return 0;
//}

//namespace szy
//{
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//namespace bit
//{
//	// 1、命名空间中可以定义变量/函数/类型
//	int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right + 10;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
////2. 命名空间可以嵌套
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//// 
//int main()
//{
//	bit::rand = 10;
//
//	struct bit::Node node;
//	bit::Add(1, 2);
//	szy::Add(1, 2);
//
//	N1::Add(1, 2);
//	N1::N2::Sub(3, 4);
//
//	struct szy::ListNode ln;
//	szy::ListInit();
//
//	return 0;
//}

// 把整个命名空间展开 -- 展开到全局了
//using namespace szy;

// 单独展开某一个，其他不展开
//using szy::ListNode;
//
//int main()
//{
//	struct ListNode ln;
//	szy::ListInit();
//
//	printf("%d\n", szy::rand);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;  // C++库的实现定义在一个叫std的命名空间中
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

//#include <iostream>
////using namespace std;  // C++库的实现定义在一个叫std的命名空间中
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//	return 0;
//}

//#include <iostream>
////using namespace std;
//// 常用的展开
//using std::cout;
//using std::endl;
//
//int main()
//{
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
	cout << "hello world" << endl;
	cout << "hello world\n";
	printf("hello world\n");

	int i = 10;
	double d = 1.11;
	// 自动识别类型
	cout << i << " " << d << endl;

	cin >> i >> d;

	cout << i << " " << d << endl;

	return 0;
}