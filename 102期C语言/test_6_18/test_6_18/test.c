#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//int main()
//{
//	int i = 1;//1.��ʼ��
//
//	while (i <= 10)//2.�ж�
//	{
//		printf("%d ", i);
//
//		i++;//3.����
//	}
//
//	return 0;
//}

//forѭ������
//
//int main()
//{
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (5 == i)
//	//		break;
//	//	printf("%d ", i);
//	//}
//	
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (5 == i)
//	//		continue;
//	//	printf("%d ", i);
//	//}
//
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	printf("%d ", i);
//
//	//	i++;
//	//}
//
//	return 0;
//}


//
//F10 - ����ִ�У�����̣�
//F11 - ����ִ�У�����䣩 - �����Զ�����������뺯��������԰�F11
//


//int main()
//{
//	int arr[10] = { 0 };//0~9
//	int i = 0;
//	for (i = 0; i <10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	//��ʼ�����жϣ����� �������ֶ�ʡ����
//	//1. ����ʡ��
//	//2. �жϲ���ֻҪʡ���ˣ�����ζ���жϺ�Ϊ���桱
//	//3. ������Ҫʡ��
//	/*for (i=0; ; i++)
//	{
//		printf("hehe\n");
//	}*/
//
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//		//j=10
//	}
//
//	return 0;
//}


//int main()
//{
//	int i = 1;
//
//	do
//	{
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);
//		i++;
//	}while (i <= 10);
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//8
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}

//1��+2��+3�� = 
//1 + 2 + 6 = 9
//4!
//5! = 4!*5
//6! = 5!*6
//7! = 6!*7
//n! = (n-1)!*n
//
//int main()
//{
//	int n = 0;
//
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//
//	for (n = 1; n <= 5; n++)
//	{
//		ret = 1; //���ڴ˲����г�ʼ����retֵ������һ�μ���Ľ��������ʱ��������ý������
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//
//	printf("%d\n", sum);
//
//	//����������У����ǽ���Ǵ���� - ����ʱ����
//	//���� - һ��һ����ִ�д��룬�۲�����ǲ��ǰ�������������Ч�����ߵģ�������ֲ����ǰ���������Ч������
//	//bug�ͳ����ˣ�
//
//
//	return 0;
//}

//
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}


//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//0~9
//	//����������arr����7
//	//�ҵ��˴�ӡ�±꣬�Ҳ�����ӡ���Ҳ���
//	int i = 0;
//	int k = 17;
//	//�����ݵ�Ԫ�ظ���
//	//          40      /   4
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d\n", i);
//			break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("�Ҳ���\n");
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//0~9
//	//����������arr����7
//	//�ҵ��˴�ӡ�±꣬�Ҳ�����ӡ���Ҳ���
//	//�۰����(���ֲ���)
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int k = 17;//�����ҵ�����
//
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//
//	return 0;
//}

//hello world!!!!!!!
//##################
//h################!
//he##############!!
//..
//hello world!!!!!!!
#include <windows.h>
#include <string.h>
#include <stdlib.h>
//
//int main()
//{
//	char arr1[] = "hello world!!!!!!!";
//	char arr2[] = "##################";
//	int len = strlen(arr1);
//	
//	int left = 0;
//	int right = len - 1;
//
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//1000���� - 1��
//		system("cls");
//		//system�ǿ⺯��������ִ��ϵͳ�����
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}
//
//


#include <string.h>
//
//int main()
//{
//	int i = 0;
//	char password[20] = {0};
//	//���������ǣ�abcdef
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:>");
//		scanf("%s", password);
//		//�����ַ����Ƚϣ�����ʹ��==
//
//		if (strcmp(password, "abcdef") == 0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("����������������˳�����\n");
//	}
//
//	return 0;
//}

//
//
//int main()
//{
//	//
//	//C99
//	//C++
//	//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	int a = 10;
//
//	a = a + 10;
//	printf("a = %d\n", a);
//
//	int b = 20;
//	//
//	//C���Թ涨������Ҫ��������ǰ��������ǰ��
//	//missing ; before type
//	//...
//
//	return 0;
//}
//


//void test()
//{
//
//}
//int main()
//{
//again:
//
//	printf("hehe\n");
//	goto again;
//
//	return 0;
//}

//�ػ�����
//�������������͵���ʱ�ػ���1�����ڣ����룺��������ȡ���ػ�
//
#include <string.h>
#include <stdlib.h>

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//again:
//	printf("��ע�⣬��ĵ�����1�����ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//



//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("��ע�⣬��ĵ�����1�����ڹػ���������룺��������ȡ���ػ�\n");
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}