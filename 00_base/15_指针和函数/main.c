//
//  main.c
//  15_指针和函数
//
//  Created by 黄德宇 on 2025/4/12.
//

#include <stdio.h>

char *getWeekDay(int weekDayNum);

int main(int argc, const char *argv[]) {
    /** 获取星期值*/
     //    指向外部函数的指针
    char* (*getWeekDayFn)(int weekDayNum) = getWeekDay;
     //    通过指针调用函数
    char* weekDay = getWeekDayFn(4);
    printf("%s\n", weekDay);
     
    return 0;
}

char *getWeekDay(int weekDayNum) {
    switch (weekDayNum) {
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 7:
        return "Sunday";
    default:
        return "错误值";
    }
}
