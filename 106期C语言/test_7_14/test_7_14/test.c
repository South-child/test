#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//ָ��
//int main()
//{
//	int a = 10;//���ڴ�������4���ֽڵĿռ䣬��ߴ��10
//	printf("%p\n", &a);//%p --��ӡ��ַ��ʽ
//	//& -- ȡ��ַ������
//    //&a -- ȡ������a�ĵ�һ���ֽڵĵ�ַ��Ҳ����a�Ľ�С��һ����ַ
//
//	int* pa = &a;
//	//pa ��һ����ŵ�ַ�ı����������ı����ͱ���Ϊָ�����
//	// * ��ʾpa��һ��ָ�����
//	//int ��ʾpaָ��Ķ�����һ��int���͵ı���
//
//	char ch = 'w';
//	char* pc = &ch;
//	//* ��ʾpc��һ��ָ�����
//	//char ˵��pcָ����Ǹ�������char���͵ı���
//
//	*pa = 20;//* -- �����ò�����
//	printf("%d\n", a);
//
//	*pc = 'b';
//	printf("%c\n", ch);
//	
//	return 0;
//}


//ָ������Ĵ�С
//
//int main()
//{
//	//printf("%d\n", sizeof(char*));
//	//printf("%d\n", sizeof(short*));
//	//printf("%d\n", sizeof(int*));
//	//printf("%d\n", sizeof(double*));
//
//	//ָ���С��32Ϊƽ̨��4���ֽڣ���64λƽ̨��8���ֽ�;
//
//	char ch = 'w';
//
//	char* pc = &ch;
//
//	printf("%d\n", sizeof(pc));//4
// //pc��һ��ָ�����
//	return 0;
//}


//�ṹ�� --��������
//���������������Ӷ��������

//struct -- �ṹ��ؼ���

//����һ��ѧ������
struct Student
{
	char name[20];
	int age;
	char sex[5];
	char id[12];
};
int main()
{
	//�����Ľṹ�����
	struct Student s1 = {"����",20,"��","2022717"};//��ʼ��
	struct Student s2 = {"����",18,"Ů","1234567"};


	//��ӡ��ʽ-- . / ->   �ṹ����ʳ�Ա������
	printf("���֣�%s \n���䣺%d \n�Ա�%s \nѧ�ţ�%s\n", s1.name, s1.age, s1.sex, s1.id);//.-- �ṹ����� . ��Ա��

	struct Student* ps = &s1;
	printf("���֣�%s \n���䣺%d \n�Ա�%s \nѧ�ţ�%s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);

	printf("���֣�%s \n���䣺%d \n�Ա�%s \nѧ�ţ�%s\n", ps->name, ps->age, ps->sex, ps->id);//-> -- �ṹ��ָ��->��Ա��

	return 0;
}










