//
//  controller.c
//  11_走出迷宫游戏
//
//  Created by 黄德宇 on 2025/4/9.
//

#include "controller.h"

/**
 * 初始化地图
 */
int (*getMap(void))[COLS] {
    static int map[][COLS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1},
    };
    return map;
}

/**
 * 打印地图
 */
void printMap(int map[][COLS], int currentX, int currentY) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (currentX == i && currentY == j) {
                printf("O");
            } else if (map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("请输入指令：w:上，s: 下，a: 左，d: 右，q: 退出\n");
}

/**
 * 移动
 * @param movePosition up: 1, down 2 left: 3, right: 4
 */
int moveX(int currentX, char movePosition) {
    int targetX = currentX;
    switch (movePosition) {
        case 'w':
        case 'W':
            targetX -= 1;
            break;
        case 's':
        case 'S':
            targetX += 1;
            break;
        default:
            break;
    }
    return targetX;
}


int moveY(int currentY, char movePosition) {
    int targetY = currentY;
    switch (movePosition) {
        case 'a':
        case 'A':
            targetY -= 1;
            break;
        case 'd':
        case 'D':
            targetY += 1;
            break;
        default:
            break;
    }
    return targetY;
}

/**
 * 判断是否结束
 */
int checkQuit(int currentX, int currentY, char movePosition) {
    if (movePosition == 'q') {
        printf("你真菜！拜拜！");
        return 1;
    }
    if (currentX == END_X && currentY == END_Y) {
        printf("牛逼！通关！\n");
        return 1;
    }
    return 0;
}
