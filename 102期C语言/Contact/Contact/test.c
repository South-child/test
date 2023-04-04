#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("*********************************\n");
	printf("****  1. add     2. del      ****\n");
	printf("****  3. search  4. modify   ****\n");
	printf("****  5. show    6. sort     ****\n");
	printf("****  0. exit                ****\n");
	printf("*********************************\n");
}

enum Option
{
	EXIT,//�˳� 0
	ADD,//������ϵ�� 1
	DEL,//ɾ����ϵ�� 2
	SEARCH,//������ϵ�� 3
	MODIFY,//�޸���ϵ�� 4
	SHOW,//��ӡ��Ϣ 5
	SORT//���� 6
};

int main()
{
	int input = 0;

	//����һ��ͨѶ¼
	struct Contact con;
	
	//��ʼ��ͨѶ¼
	InitContact(&con);
	//�����Է�3���˵���Ϣ��
	//�ռ䲻����������

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//������ϵ��
			break;
		case DEL:
			DelContact(&con);//ɾ��ָ����ϵ��
			break;
		case SEARCH:
			SearchContact(&con);//����ָ����ϵ��
			break;
		case MODIFY:
			ModifyContact(&con);//�޸�ָ����ϵ��
			break;
		case SHOW:
			ShowContact(&con);//��ʾ���е���ϵ��
			break;
		case EXIT:
			//����ͨѶ¼
			SaveContact(&con);
			//����ͨѶ¼
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}