//
//  main.c
//  07_多文件开发
//
//  Created by 黄德宇 on 2025/4/4.
//

#include <stdio.h>
#include "sum.h"

int main(int argc, const char * argv[]) {
    int ans = sum(3, 4);

    printf("sum = %d\n", ans);
    
    long long a = 2222222;
    printf("%lu\n", sizeof(a));
    
    short int b = 0;
    printf("%lu\n", sizeof(b));
    
    long int c = 0;
    printf("%lu\n", sizeof(c));
    return 0;
}
 
