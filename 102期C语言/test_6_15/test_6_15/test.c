#define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	1 + 2;//��� 3 
//	;//�����
//
//	return 0;
//}
#include <stdio.h>
//
//int main()
//{
//	/*int age = 10;
//	if (age > 18)
//	{
//		printf("����\n");
//		printf("����̸����\n");
//	}*/
//
//	//int age = 10;
//	//if (18 <= age < 30)//err
//	//{
//	//	printf("����\n");
//	//}
//
//
//	//if (age < 18)
//	//	printf("������\n");
//	//else if (age >= 18 && age < 30)
//	//	printf("����\n");
//	//else if (age >= 30 && age < 50)
//	//	printf("����\n");
//	//else if (age >= 50 && age < 80)
//	//	printf("����\n");
//	//else
//	//	printf("������\n");
//
//
//	//if (age >= 18)
//	//	printf("����\n");
//	//else
//	//	printf("δ����\n");
//
//	/*if (age >= 18)
//		printf("����\n");*/
//
//	return 0;
//}

//��0 ������
//0  ���Ǽ�


#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 2;
//    if (a == 1)
//    {
//        if (b == 2)
//            printf("hehe\n");
//        else
//            printf("haha\n");
//    }
//    return 0;
//}

//������ǳ���Ҫ
//Ҫ�������õı�����
//
//int main()
//{
//	//int a=10;
//	//int a = 10;//
//	//int i = 0;
//	//for(i=0;i<10;i++)
//	//{
//	//}
//	//for (i = 0; i < 10; i++)
//	//{
//
//	//}
//
//	Add(10, 20);
//	char firstname[20];
//	char first_name[20];
//	char FirstName[20];
//
//	return 0;
//}

//
//int test()
//{
//	if (0)
//	{
//		printf("hehe\n");
//		return 3;
//	}
//	printf("haha\n");
//	return -3;
//}
//
//int main()
//{
//	int ret = test();
//	return 0;
//}
//
//

//
//int main()
//{
//	int num = 3;
//	//�����ͱ����Ƚ���ȵ�ʱ��
//	//����������� ����һЩ
//
//	if (5 == num)
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}




//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	//�ж�
//	if (num % 2 == 1)
//	{
//		printf("%d������\n", num);
//	}
//	else
//	{
//		printf("%d��������\n", num);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		printf("%d ", i);
//		i += 2;
//	}
//
//	//while (i <= 100)
//	//{
//	//	//�ж�i�Ƿ�Ϊ����
//	//	//�������ʹ�ӡ
//	//	if (i % 2 == 1)
//	//		printf("%d ", i);
//
//	//	i++;
//	//}
//
//	return 0;
//}
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//
//	int n = 1;
//	switch (day)
//	{
//	case 1:
//		printf("����1\n");
//		break;
//	case 2:
//		printf("����2\n");
//		break;
//	case 3:
//		printf("����3\n");
//		break;
//	case 4:
//		printf("����4\n");
//		break;
//	case 5:
//		printf("����5\n");
//		break;
//	case 6:
//		printf("����6\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	}
//
//
//	/*if (1 == day)
//	{
//		printf("����1\n");
//	}
//	else if (2 == day)
//	{
//		printf("����2\n");
//	}
//	else if (3 == day)
//	{
//		printf("����3\n");
//	}*/
//	//...
//	return 0;
//}


//1-5 ������
//6-7 ��Ϣ��
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//
//	int n = 1;
//	switch (day)
//	{
//	default:
//		printf("������������������1-7������\n");
//		break;
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//		break;
//
//	}
//	return 0;
//}


#include <stdio.h>
//
//int main()
//{
//    int n = 1;
//    int m = 2;
//    switch (n)
//    {
//    case 1:m++;
//    case 2:n++;
//    case 3:
//        switch (n)
//        {//switch����Ƕ��ʹ��
//        case 1:n++;
//        case 2:
//            m++;n++;
//            break;
//        }
//    case 4:
//        m++;
//        break;
//    default:
//        break;
//    }
//    printf("m = %d, n = %d\n", m, n);
//    return 0;
//}

//
//int main()
//{
//	while (1)
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}
//
//int main()
//{
//
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	i++;
//	//	if (5 == i)
//	//		continue;
//	//	printf("%d ", i);//2 3 4 6...
//	//}
//
//
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	if (5 == i)
//	//		continue;
//	//	printf("%d ", i);
//	//	i++;
//	//}
//	//continue �������ǣ���������ѭ��continue��ߵĴ���
//	//ֱ�ӵ�whileѭ�����жϲ���
//
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	if (5 == i)
//	//		break;
//
//	//	printf("%d ", i);
//	//	i++;
//	//}
//	//1 2 3 4
//	//break�����õ���ֹѭ����
//
//	return 0;
//}
//

//gets(password);
//printf("%s\n", password);
//
//int main()
//{
//	int ch = 0;
//	char password[20] = {0};
//	printf("����������>:");
//	//scanf("%s", password);
//
//
//	//����\n
//	//getchar(); //����ȡ
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//
//	printf("��ȷ������(Y/N)>:");
//	ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//
//	//EOF - end of file - �ļ������ı�־
//	//getchar��ȡʧ�ܵ�ʱ��ͻ᷵��EOF
//	//1. ���ص��ַ����������ַ�Ҳ��ASCII��ֵ��������
//	//2. getchar �����������Ƿ��������ַ������᷵��EOF ��-1�����Է������α�����
//
//	/*while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}*/
//
//	//ch = getchar();
//	//putchar(ch);
//	
//	//scanf("%c", &ch);
//	//printf("%c\n", ch);
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 4;
//	int c = (b = 5);
//	printf("%d\n", c);
//	printf("%d\n", b);
//
//
//	return 0;
//}

int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch>'9')
		{
			continue;
		}
		putchar(ch);
	}
	return 0;
}