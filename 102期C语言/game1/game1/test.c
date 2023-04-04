#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"
void menu()
{
	printf("**************************************************\n");
	printf("*****       Welcome to the Gobang game       *****\n");
	printf("**********          1. ��ʼ��Ϸ         **********\n");
	printf("**********          0. �˳���Ϸ         **********\n");
	printf("**************************************************\n");

}
void game()
{
	//���������
	char board[ROW][COL];//��������
	//��ʼ������---board��Ԫ�ض����ɿո�
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	char ret = 0;
	while (1)
	{
		
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//��ӡ�˵�
		menu();
		printf("�뿪ʼ���ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��");
			break;
		}
	} while (input);
	return 0;
} 