#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("**************************************************\n");
	printf("*******       Welcome to Minesweeper       *******\n");
	printf("**********          1. ��ʼ��Ϸ         **********\n");
	printf("**********          2. �����Ļ         **********\n");
	printf("**********          0. �˳���Ϸ         **********\n");
	printf("**************************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ��һ������
	InitBoard(mine, ROWS,COLS,'0');
	InitBoard(show, ROWS,COLS,'*');

	//������
	SetMine(mine, ROW, COL);
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			system("cls");//����ѡ��
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
			Sleep(1000);
			system("cls");
			break;
		}
	
	} while (input);
	return 0;
}

