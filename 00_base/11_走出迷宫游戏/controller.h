//
//  controller.h
//  11_走出迷宫游戏
//
//  Created by 黄德宇 on 2025/4/9.
//

#ifndef controller_h
#define controller_h

#define ROWS 9
#define COLS 9
#define START_X 1
#define START_Y 1
#define END_X 8
#define END_Y 7

#include <stdio.h>

/**
 * 初始化地图
 */
int (*getMap(void))[COLS];

/**
 * 打印地图
 */
void printMap(int map[][COLS], int currentX, int currentY);

/**
 * 移动
 * @param movePosition up: 1, down 2 left: 3, right: 4, quit: 5
 * 返回移动后的位置
 */
int moveX(int currentX, char movePosition);
int moveY(int currentY, char movePosition);

/**
 * 判断是否结束
 */
int checkQuit(int currentX, int currentY, char movePosition);



#endif /* controller_h */
