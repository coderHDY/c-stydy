//
//  main.c
//  06_函数
//
//  Created by 黄德宇 on 2025/4/4.
//

#include <stdio.h>
#include <stdlib.h>

int getMaxNum(int num1, int num2, int num3);
int add(int a, int b);
void isRunNian(int year);


int main(int argc, const char * argv[]) {
    int max = getMaxNum(2000, 1002, 3000);
    printf("%d", max);

    return 0;
}





int getMaxNum(int num1, int num2, int num3) {
    int max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }
    return max;
}

int add(int a, int b) {
    return a + b;
}

void isRunNian(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        printf("闰年");
        return;
    }

    printf("非闰年");
    return;
}
