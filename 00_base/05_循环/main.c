//
//  main.c
//  05_循环
//
//  Created by 黄德宇 on 2025/4/3.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j <= i; j++) {
            int ans = i * j;
            printf("%d*%d=%d ", j, i, ans);
        }
        printf("\n");
    }

    return 0;
}
