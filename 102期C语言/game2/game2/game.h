#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<Windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2


//雷的个数
#define EASY_COUNT 10

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//第一次安全
void safe(char mine[ROWS][COLS], int row, int col, int x, int y);

//统计排查坐标周边八个位置的雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y);

//坐标周围展开函数
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y,int* p); 


