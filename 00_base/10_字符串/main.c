//
//  main.c
//  10_字符串
//
//  Created by 黄德宇 on 2025/4/9.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str1[10] = "jackk";
    char str2[] = "rose";
//    int equal = strcmp(str1, str2);
//    printf("相等？%d\n",equal);
    
//    strcpy(str1, str2);
//    puts(str2);
    
    strcat(str1, str2);
    puts(str1);
    return 0;
}
