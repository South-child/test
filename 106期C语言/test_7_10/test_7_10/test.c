#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ�
#include <stdio.h>
//stdio -- ��׼�������

//������
//int -- ���� -- ����������
//main�����ǳ�������
//һ�������� main��������ֻ��һ��
//int main()
//{
//	//�⺯�� -- ��ӡ���� -- �������
//	printf("hello world\n");
//	return 0;
//}

//��������
//int main()
//{
//	//����
//	int age = 10;
//	int price = 50;
//  //�ַ���
//	char ch = 'w';
//	//������
//	double weight = 55.5;//˫���ȸ�����
//
//	//����һ�����ʹ����ı�����ռ�ռ�Ĵ�С -- sizeof()
//	printf("char��%d\n", sizeof(char));      // 1
//	printf("short��%d\n", sizeof(short));	   // 2
//	printf("int��%d\n", sizeof(int));       // 4
//	printf("long��%d\n", sizeof(long));      // 4
//	printf("long long��%d\n", sizeof(long long)); // 8
//	printf("float��%d\n", sizeof(float));     // 4
//	printf("double��%d\n", sizeof(double));    // 8
//
//
//	return 0;
//}


//����������

//int main()
//{
//	//���� -- �� age
//	short age = 10;
//	age = 11;
//	float weight;
//	char sex = 'm';
//
//	return 0;
//}

//int a = 100; //ȫ�ֱ���
//int main()
//{
//	int a = 20;//�ֲ�����
//	printf("%d\n", a);//�ͽ�ԭ�򣬴�ӡ�ֲ�����
//	//�ֲ�������ȫ�ֱ��������ֿ�����ͬ����ͬʱ���ֲ����ȴ�ӡ��(��������ͬ)
//	return 0;
//}

//������ʹ��
//int main()
//{
//	//2���������
//	int num1 = 0;
//	int num2 = 0;
//	//���� -- scanf()
//	scanf("%d%d", &num1, &num2);
//	//���ӷ�
//	int sum = num1 + num2;
//	//���
//	printf("%d\n", sum);
//	return 0;
//}


//����������������

//�ֲ������������� -- �������ڵľֲ���Χ
//int main()
//{
//	{
//		int a = 10;
//	}
//	//a����������С������
//	//printf("%d\n", a);
//
//	return 0;
//}

//ȫ�ֱ����������� -- ��������

//int a = 100;
//
//void test()
//{
//	printf("test: a = %d\n", a);
//}
//int main()
//{
//	test();
//	printf("main: a = % d\n", a);
//	return 0;
//}

//�����ⲿ����
//extern int g_val;
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}


//����
//���泣��
//const���εĳ�����
// #define����ı�ʶ������
// ö�ٳ���
//int main()
//{
//	//���泣��
//	3.14;
//	100;
//
//	//const���εĳ�����
//	//һ���������ܱ��ı䣬���Ǿ�˵���г����� -- ���ܱ��ı������
//	//const int a = 10;
//	//a = 20;
//
//	//const���εĳ�����
//	const int n = 100;//n���ǳ��������ʻ��Ǳ�����ֻ�Ǿ��г����ԣ����ܱ��޸Ķ���
//	//int arr[n] = { 0 };//����
//	return 0;
//}

//#define����ı�ʶ������

//#define MAX 100
//
//int main()
//{
//	int a = MAX;
//	printf("a = %d\n", a);
//	//MAX = 200;�����޸�
//	int arr[MAX] = { 0 };
//	return 0;
//}


//ö�ٳ���
//enum sex -- ö������
//enum -- ö�ٹؼ���
enum Sex
{
	//ö�ٵĿ���ȡֵ - ö�ٳ���
	//ö�ٳ�����ȡֵ��Ĭ���ǵ�һ�����㿪ʼ���������µ�����
	//ö�ٳ������Ը���ֵ
	MALE = 3,
	FEMALE,
	SECRET
};
int main()
{
	enum Sex s = MALE;//ö�����Ͷ���ı���
	//MALE = 4;����ö�ٳ������Ը���ֵ�������ɱ��޸�
	printf("%d\n", MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);

	return 0;
}

