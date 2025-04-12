//
//  main.c
//  11_走出迷宫游戏
//
//  Created by 黄德宇 on 2025/4/9.
//

#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    int(*map)[COLS] = getMap();
    int currentX = START_X;
    int currentY = START_Y;

    int quickFlag = 0;
    printMap(map, currentX, currentY);
    while (!quickFlag) {
        char movePosiotn;
        rewind(stdin);
        scanf("%c", &movePosiotn);
        int targetX = moveX(currentX, movePosiotn);
        int targetY = moveY(currentY, movePosiotn);
        if (map[targetX][targetY] != 1) {
            currentX = targetX;
            currentY = targetY;
        }
        system("clear");
        printMap(map, currentX, currentY);
        quickFlag = checkQuit(currentX, currentY, movePosiotn);
    }
    return 0;
}
