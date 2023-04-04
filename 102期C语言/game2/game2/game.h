#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<Windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2


//�׵ĸ���
#define EASY_COUNT 10

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);

//������
void SetMine(char board[ROWS][COLS], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//��һ�ΰ�ȫ
void safe(char mine[ROWS][COLS], int row, int col, int x, int y);

//ͳ���Ų������ܱ߰˸�λ�õ��׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y);

//������Χչ������
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y,int* p); 


