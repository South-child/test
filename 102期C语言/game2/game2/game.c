#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("----------------\n");
	for (i = 0; i <= 9; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
			
		}
		printf("\n");
	}
	printf("----------------\n");
}



//统计排查坐标周边八个位置的雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		//生成随机下标(1~9)
		x = rand() % row + 1;
		y = rand() % col + 1;

		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}

	}
}

//第一次安全
void safe(char mine[ROWS][COLS], int row,int col,int x, int y)  
{
	mine[x][y] = '0';
	int count = 1;
	while (count)
	{
		//生成随机下标(1~9)
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if ((mine[i][j] != '1') && i != x && j != y)
		{
			mine[i][j] = '1';
			count--;
		}
	}

}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//统计排雷的个数
	int count = 0;// 统计雷的个数
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)  //输入坐标是否合法
		{
			if (mine[x][y] == '1')
			{
				if (0 == win)//第一次踩到雷，重新布雷
				{
					safe(mine, ROW,COL,x, y);
					//DisplayBoard(mine, ROW, COL);
					count = GetMineCount(mine, x, y);

					if (count == 0)
					{
						show[x][y] = ' ';
						win++;
						OpenMine(mine, show, ROW, COL, x, y,&win);//如果周围没有雷，进行扩展
						DisplayBoard(show, row, col);
					}
					else
					{
						show[x][y] = count + '0';
						DisplayBoard(show, row, col);
					}
				}
				else
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				
			}
			else
			{
				count = GetMineCount(mine, x, y);
				if (count == 0)
				{
					show[x][y] = ' ';
				}
				else
				{
					show[x][y] = count + '0';
				}
				win++;
				OpenMine(mine, show, ROW, COL, x, y,&win);
				DisplayBoard(show, ROW, COL); 
			}
		}
		else
		{
			printf("坐标不在范围内，请重新输入\n");
		}
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
	}
}

//展开函数
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y,int* p)
{
	int i = -1;
	int j = -1;
	for (i = -1; i < 2; i++)//边界
	{
		for (j = -1; j < 2; j++)
		{
			if (i != 0 || j != 0) // 避免排到自己注意此处的逻辑关系
			{
				if (x + i >= 1 && x + i <= row && y + j >= 1 && y + j <= col)
				{
					if (show[x + i][y + j] == '*' && mine[x + i][y + j] != '1')
					{
						int count = GetMineCount(mine, x + i, y + j);
						if (count != '0')
						{
							show[x + i][y + j] = count + '0';
							(*p)++;
						}
						else
						{
							show[x + i][y + j] = ' ';
							(*p)++;
							OpenMine(mine, show,ROW,COL, x + i, y + j, p);
						}
					}
				}
			}
		}
	}
}






