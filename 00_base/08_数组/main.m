//
//  main.m
//  08_数组
//
//  Created by 黄德宇 on 2025/4/8.
//

#import <stdio.h>
#include <stdlib.h>

#define LEN 3

void printArr(int arr[], int len);
void printDoubleBall(void);
void maopaoSort(void);
void resortArr(int *arr, int len);

int main(int argc, const char * argv[]) {
/* 多次输入
    double scores[3];
    
    for (int i = 0; i < 3; i++) {
        printf("请输入成绩：");
        rewind(stdin);
        scanf("%lf", &scores[i]);
        
        if (scores[i] < 60) {
            scores[i] += 5;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        printf("第%d名的成绩是%.2f\n", i, scores[i]);
    }
 
*/
/* 求最大值
    int arr[] = { 1, 2, 4, 44, 22, 452, 445, 22 };
    int max = INT32_MIN;
    int len = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("最大值是：%d\n", max);
*/
    
/* 打印数组
    int arr[] = { 1, 2, 3, 4 };
    printArr(arr, 4);
 */

/* 打印双色球
    printDoubleBall();
*/
    
/* 冒泡排序
    maopaoSort();
*/
    /* 翻转数组 */
    int arr[] = { 1, 2, 3, 4, 5 };
    resortArr(arr, 5);
    printArr(arr, 5);
    
    
    return 0;
}

/**
 * 打印数组
 * @param arr 数组
 * @param len 数组长度
 */
void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}

/**
 * 生成双色球
 */
int getUnicRandomNum(int range, int *arr, int len) {
    
    int exit, num;
    do {
        exit = 0;
        num = arc4random_uniform(range) + 1;
        for (int i = 0; i < len; i++) {
            if (arr[i] == num) {
                exit = 1;
                printf("exit!!! %d", num);
                break;
            }
        }
    } while (exit);
    return num;
}

void printDoubleBall(void) {
    int arr[6] = {};
    int bounusNum = arc4random_uniform(16) + 1;
    for (int i = 0; i < 6; i++) {
        arr[i] = getUnicRandomNum(33, arr, 6);
    }
    for (int i = 0; i < 6; i++) {
        printf("%d\n", arr[i]);
    }
    
    printf("bounus: %d\n", bounusNum);
}

void maopaoSort(void) {
    int arr[] = {12,12,324,5452455,256,456,367,36,25,15,1,623,562,562};
    
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("长度是：%d\n\n", len);
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printArr(arr, len);
}

void resortArr(int *arr, int len) {  
    for (int i = 0; i < len / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
