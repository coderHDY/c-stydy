//
//  main.c
//  04_switch
//
//  Created by 黄德宇 on 2025/3/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int score = 6;
    
    switch(score * 10) {
        case 60: {
            printf("刚好及格\n");
            break;
        }
        case 70:
            printf("及格\n");
            break;
        default:
            printf("不懂\n");
    }
    
    
    int year = 200;
    
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        printf("闰年");
    }
    
    return 0;
}
