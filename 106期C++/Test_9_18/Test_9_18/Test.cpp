
// :: ������޶���
//#include <stdio.h>
//
//int a = 10;
//
//int main()
//{
//	// ����ԭ�����ھֲ��ң��ֲ�û����ȥȫ����
//	
//	//:: �������޶���
//	printf("%d\n", ::a);//ȥȫ������a
//	return 0;
//}

//�����ռ�--namespace -- ���ã� ����������ͻ

//#include <stdio.h>
//#include <stdlib.h>
//
////�����ռ䲻Ӱ��������������ڣ�ֻ���޶��򣬱༭���ҹ���
////Ĭ�ϲ��ҹ������ھֲ��ң���ȥȫ����
////�ں����ж���ı������Ǿֲ��������������ռ䶨��ı�������ȫ�ֱ���������ھ�̬��
//namespace wyt
//{
//	int rand = 10;//����ȫ�ֱ����������ھֲ�����
//	int x = 1;
//}
//
//void func()
//{
//	int a = 100;//�ֲ�����
//}
//int main()
//{
//	printf("%d\n", rand);//�����ӡ����stdlibͷ�ļ��е�rand�⺯���ĵ�ַ��
//
//	//�����ӡ�����Լ������rand����������Ҫʹ���������޶���
//	printf("%d\n", wyt::rand);
//	printf("%d\n", wyt::x);
//	return 0;
//}


// �����ռ�Ķ���
//#include <stdio.h>
//һ��
//namespace wyt
//{
//	//�����ռ��п��Զ��� ����������������
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
//����
//namespace N1
//{
//	//�����ռ����Ƕ�׶���
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
//	//Ҫע����������ռ��е����͵��÷�
//	struct wyt::Node node;
//
//	N1::a = 10;
//	N1::N2::c = 20;
//
//	return 0;
//}

//��
// ͬһ��������������ڶ����ͬ���Ƶ������ռ�,����������ϳ�ͬһ�������ռ��С�
// һ�������е�Stack.h������Queue.h������N1�ᱻ�ϲ���һ��

//#include "Queue.h"
//#include "Stack.h"
//#include <stdio.h>
//int main()
//{
//	//��ͬ�������ռ䣬����ϳ�ͬһ�������ռ���
//	N1::QueuePush(NULL, 1);
//	N1::StackPush(NULL, 1);
//
//	return 0;
//
//}


//�����ռ��ʹ��
//#include <iostream>
//// std C++�ٷ������ݶ���������ռ�
//
////һ���������ռ����Ƽ��������޶���
//int main()
//{
//	//cout�����iostreamͷ�ļ��µ�std�������ռ���
//	std::cout << "Hello World!" << std::endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//// ���������˼���ǰ����������ռ�չ��������������ʹ��std�����ռ��µı����������ȵȾͲ���Ҫ���������޶�����
//// �������������㣬���������ĸ���ǽ�Ͳ��ˣ�ʧȥ�˸��������
//// �ճ���ϰ��С������ô�ÿ��ԣ���Ŀ��ò�Ҫ��ô��
////����ʹ��using namespace �����ռ����� ����
//int main()
//{
//	//cout�����iostreamͷ�ļ��µ�std�������ռ���
//	cout << "Hello World!" << endl;
//	return 0;
//}


//#include <iostream>
////����ʹ��using�������ռ���ĳ����Ա����
////�����ַ�������ָ��չ��--�ѳ��õ�չ�����Լ��ڶ����ʱ������������������
//using std::cout;
//using std::endl;
//int main()
//{
//	//cout�����iostreamͷ�ļ��µ�std�������ռ���
//	cout << "Hello World!" << endl;
//	return 0;
//}


//C++���������
//cout�����
//cin������

//#include<iostream>
//// std��C++��׼��������ռ�����C++����׼��Ķ���ʵ�ֶ��ŵ���������ռ���
//using namespace std;
//int main()
//{
//	//C++�е�������������Զ�ʶ����������ͣ������c��printf\scanf
//	//�ĸ��������ĸ�
//
//	//���
//	// << �����������
//	cout << "Hello world!!!" << endl;//endl�൱�ڻ���
//	cout << "Hello world!!!" << '\n';
//
//	int a;
//	double b;
//	char c;
//
//	// >> ����ȡ�����
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b <<" "<< c << endl;
//
//	printf("%.1f\n", b);//������ƴ�ӡС���ĸ���������ʹ��printf
//	cout <<"int:"<<a <<" "<<" double:"<< b <<" char:" << c << endl;
//	printf("int:%d double:%f char:%c", a, b, c);
//	return 0;
//}


//ȱʡ����
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
//	Func();//û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10);//����ʱ��ʹ��ָ����ʵ��
//
//	return 0;
//}


//ȱʡ��������
#include<iostream>
using namespace std;

////һ��ȫȱʡ
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
//	//Func(1, , 2);//��֧�֣����α����Ǵ������Ҵ��ģ����ұ�����������
//	return 0;
//}

//һ����ȱʡ/����ȱʡ -- ���������������ȱʡ
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
////��ȱʡ��������ֻ�ܴ����������θ��������ұ������������ܼ���Ÿ�
////int Func(int a, int b = 10, int c);//���󣬲�����
////int Func(int a = 10, int b = 20, int c);//���󣬲��Ǵ����������
//
//int main()
//{
//	//Func();//��֧�֣���Ϊ�ǰ�ȱʡ������ô���
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//	//Func(1, , 2);//��֧�֣����α����Ǵ������Ҵ��ģ����ұ�����������
//	return 0;
//}

//ע�⣺ȱʡֵ�����ǳ�������ȫ�ֱ���


//�������� -- ��������ͬ���������벻ͬ�����������͡�˳��

// 1.�������Ͳ�ͬ
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
//	// ��ô���õ�������ὲ -- ֪���Զ�ʶ�����ͱ��ʺ�������֧�ֵ�
//	// ostream& operator<< (int val);
//	// ostream& operator<< (double val);
//	cout << a;
//	cout << c;
//
//	return 0;
//}

// 2������������ͬ
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

// 3. ˳��ͬ���β�����˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//	//����˳��ͬ��������������� -- ˳��ָͬ���ǣ��β����͵�˳��ͬ
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

//�����������������أ�������ڶ�����
//f()���ûᱨ���������壬��������֪���õ����ĸ�����ΪȫȱʡҲ������������
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
//	//f(); // ����  ������
//
//	return 0;
//}

//����ֵ��ͬ�����������𣿣� -- ������
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
//// ����ֵ��ͬ������������ԭ�򣬲����Ǻ��������ι���
//// ����ԭ���ǵ���ʱ�Ķ����ԣ��޷����֣�
//// ��Ϊ����ʱ��ָ������ֵ����
int main()
{
	f(1, 1);
	f(2, 2);

	return 0;
}

