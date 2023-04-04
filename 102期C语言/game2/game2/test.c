#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("**************************************************\n");
	printf("*******       Welcome to Minesweeper       *******\n");
	printf("**********          1. 开始游戏         **********\n");
	printf("**********          2. 清空屏幕         **********\n");
	printf("**********          0. 退出游戏         **********\n");
	printf("**************************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化一下棋盘
	InitBoard(mine, ROWS,COLS,'0');
	InitBoard(show, ROWS,COLS,'*');

	//布置雷
	SetMine(mine, ROW, COL);
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			system("cls");//清屏选项
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			Sleep(1000);
			system("cls");
			break;
		}
	
	} while (input);
	return 0;
}

