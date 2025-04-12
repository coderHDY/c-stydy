//
//  main.c
//  02_算数符
//
//  Created by 黄德宇 on 2025/3/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int d = 0;
    int h = 0;
    int m = 0;
    int s = 0;
    printf("请输入秒数：");
    scanf("%d", &s);
    
//    d = s / 60 / 60 / 12;
//    h = (s - d * 60 * 60 * 12) / 60 / 60;
//    m = (s - d * 60 * 60 * 12 - h * 60 * 60) / 60;
//    s = (s - d * 60 * 60 * 12 - h * 60 * 60 - m * 60);
    
    d = s / (60 * 60 * 24);
    h = s % (60 * 60 * 24) / (60 * 60);
    m = s %  (60 * 60 * 24) % (60 * 60) / 60;
    s = s %  (60 * 60 * 24) % (60 * 60) % 60;
    
    printf("你输入的是：%d天%d:%d:%d\n", d, h, m, s);
    
    return 0;
}
