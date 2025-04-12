//
//  controller.h
//  14_推箱子
//
//  Created by 黄德宇 on 2025/4/12.
//

#ifndef controller_h
#define controller_h
#define ROWS 10
#define COLS 10
#define ME_SYMBOL '@'
#define BOX_SYMBOL '$'
#include <stdio.h>
#include <stdlib.h>

char (*getMap(void))[COLS]; // 返回二维数组的指针
void printMap(const char map[][COLS]);
void move(char (*map)[COLS], char position);
int checkQuit(const char (*map)[COLS]);
void getpositions(const char (*map)[COLS], int* meX, int* meY, int* boxX, int* boxY);

#endif /* controller_h */
