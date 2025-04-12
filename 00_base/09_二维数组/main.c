//
//  main.c
//  09_二维数组
//
//  Created by 黄德宇 on 2025/4/9.
//

#include <stdio.h>

void func(int rows, int cols, int arr[][cols]);

int main(int argc, const char *argv[]) {
    int arr[3][4] = {0};
    int rows = sizeof(arr) / sizeof(arr[0]);
    int columns = sizeof(arr[0]) / sizeof(arr[0][0]);
    int cells = sizeof(arr) / sizeof(arr[0][0]);

    printf("行数是：%d\n列数是：%d\n总元素个数是：%d\n", rows, columns, cells);

    func(3, 4, arr);
    return 0;
}

void func(int rows, int cols, int arr[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
