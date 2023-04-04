#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"
void menu()
{
	printf("**************************************************\n");
	printf("*****       Welcome to the Gobang game       *****\n");
	printf("**********          1. 开始游戏         **********\n");
	printf("**********          0. 退出游戏         **********\n");
	printf("**************************************************\n");

}
void game()
{
	//三子棋过程
	char board[ROW][COL];//棋盘数组
	//初始化棋盘---board的元素都给成空格
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	char ret = 0;
	while (1)
	{
		
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
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
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//打印菜单
		menu();
		printf("请开始你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (input);
	return 0;
} 