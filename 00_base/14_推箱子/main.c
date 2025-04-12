//
//  main.c
//  14_推箱子
//
//  Created by 黄德宇 on 2025/4/12.
//

/**
 * 操作记录：
 * system("clear"); // 清屏
 * gcc main.c func.c -o my_program
 */

#include <stdio.h>
#include "controller.h"


int main(int argc, const char * argv[]) {
    char (*map)[COLS] = getMap();
    printMap(map);
    int quitFlag = 0;
    while(!quitFlag) {
        char position;
        printf("请输入操作（w/a/s/d/q退出）：");
        rewind(stdin);
        scanf("%c", &position);
        if (position == 'q' || position == 'Q') {
            quitFlag = 1;
            printf("你个菜鸡！\n");
            break;
        }
        move(map, position);
        printMap(map);
        quitFlag = checkQuit(map);
        if (quitFlag) {
            printf("你赢了！\n");
            break;
        }
    }
    
    printf("游戏结束\n");
    return 0;
}
