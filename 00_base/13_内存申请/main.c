//
//  main.c
//  13_内存申请
//
//  Created by 黄德宇 on 2025/4/12.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
//    calloc使用
    int *p = calloc(10, sizeof(int));
    int *p1 = realloc(p, 11);
    if (p1 == NULL) {
        printf("内存申请失败");
        return 1;
    }
    for (int i = 0; i < 11; i++) {
        p1[i] = i + 1;
    }
    for (int i = 0; i < 11; i++) {
        printf("%d\n", p1[i]);
    }
    //释放
    free(p1);
    
    return 0;
}
