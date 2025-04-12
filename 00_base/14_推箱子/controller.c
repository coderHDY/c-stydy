//
//  controller.c
//  14_推箱子
//
//  Created by 黄德宇 on 2025/4/12.
//

#include "controller.h"

char (*getMap(void))[COLS] {
    static char map[ROWS][COLS] = {
        "##########",
        "#@ #     #",
        "# $#     #",
        "#  ##  # #",
        "#  #   # #",
        "#  #  #  #",
        "#     #   ",
        "#     #  #",
        "##########"
    };
    return map;
}

void printMap(const char map[][COLS]) {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}
void move(char (*map)[COLS], char position) {
    int meX, meY, boxX, boxY;
    getpositions(map, &meX, &meY, &boxX, &boxY);
    switch (position) {
        case 'w':
        case 'W':
            if (boxX > 0 && map[boxX - 1][boxY] != '#' && map[boxX + 1][boxY] == ME_SYMBOL) {
                map[boxX - 1][boxY] = BOX_SYMBOL;
                map[boxX][boxY] = ' ';
            }
            if (meX > 0 && map[meX - 1][meY] != '#' && map[meX - 1][meY] != BOX_SYMBOL) {
                map[meX - 1][meY] = ME_SYMBOL;
                map[meX][meY] = ' ';
            }
            break;
        case 's':
        case 'S':
            if (boxX < ROWS - 1 && map[boxX + 1][boxY] != '#' && map[boxX - 1][boxY] == ME_SYMBOL) {
                map[boxX + 1][boxY] = BOX_SYMBOL;
                map[boxX][boxY] = ' ';
            }
            if (meX < ROWS - 1 && map[meX + 1][meY] != '#' && map[meX + 1][meY] != BOX_SYMBOL) {
                map[meX + 1][meY] = ME_SYMBOL;
                map[meX][meY] = ' ';
            }
            break;
        case 'a':
        case 'A':
            if (boxY > 0 && map[boxX][boxY - 1] != '#' && map[boxX][boxY + 1] == ME_SYMBOL) {
                map[boxX][boxY - 1] = BOX_SYMBOL;
                map[boxX][boxY] = ' ';
            }
            if (meY > 0 && map[meX][meY - 1] != '#' && map[meX][meY - 1] != BOX_SYMBOL) {
                map[meX][meY - 1] = ME_SYMBOL;
                map[meX][meY] = ' ';
            }
            break;
        case 'd':
        case 'D':
            if (boxY < COLS - 1 && map[boxX][boxY + 1] != '#' && map[boxX][boxY - 1] == ME_SYMBOL) {
                map[boxX][boxY + 1] = BOX_SYMBOL;
                map[boxX][boxY] = ' ';
            }
            if (meY < COLS - 1 && map[meX][meY + 1] != '#' && map[meX][meY + 1] != BOX_SYMBOL) {
                map[meX][meY + 1] = ME_SYMBOL;
                map[meX][meY] = ' ';
            }
            break;
        default:
            break;
    }
    
}
void getpositions(const char (*map)[COLS], int* meX, int* meY, int* boxX, int* boxY) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == ME_SYMBOL) {
                *meX = i;
                *meY = j;
            }
            if (map[i][j] == BOX_SYMBOL) {
                *boxX = i;
                *boxY = j;
            }
        }
    }
}
int checkQuit(const char (*map)[COLS]) {
    int meX, meY, boxX, boxY;
    getpositions(map, &meX, &meY, &boxX, &boxY);
    if (boxX == 0 || boxX == ROWS - 1 || boxY == 0 || boxY == COLS - 1) {
        return 1; // 游戏结束
    }
    return 0;
}
