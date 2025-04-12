//
//  main.c
//  12_指针
//
//  Created by 黄德宇 on 2025/4/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int *pNum1, int *pNum2);
void getMaxAndMin(int *max, int *min, int arr[], int len);
void writeFile(void);
void readStdio(void);
void readFile(void);

int main(int argc, const char *argv[]) {
    /* 两数相加
        int num1 = 1;
        int num2 = 2;
        add(&num1, &num2);
        printf("num1 = %d\n", num1);
     */

    /* 获取最大最小值
        int max = 0;
        int min = 0;
        int arr[] =
       {13,134,234,234,24,523,62,5,25,234532,542,45,2345,3245,2345,2,345};
        getMaxAndMin(&max, &min, arr, sizeof(arr) / sizeof(arr[0]));
        printf("最大值：%d, 最小值：%d\n", max, min);
     */

    /* 多级指针
        int a = 1;
        int *p1 = &a;
        int **p2 = &p1;
        **p2 = 100;
        printf("%d\n", **p2);
     */

    /* 指针遍历
        int arr[] = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++) {
            printf("第%d个元素是：%d\n", i, *(arr + i));
        }
     */

    /* 指针运算
        int arr[6]  = {1, 2, 3, 4, 5, 6};
        int* p1 = &arr[2];
        int* p2 = &arr[4];
        long diff = p2 - p1;
        printf("%ld\n", diff);
     */

    /* 指针和字符串
        char* str1 = "hello";
        char* str2 = "hello";
        char* str3 = "hello";
        str3 = "rose";


        printf("str1 = %p \n", str1); // 相同地址
        printf("str1 = %p \n", str2); // 相同地址
        printf("str1 = %p \n", str3); // 相同地址


        printf("str1 = %s \n", str1); // hello
        printf("str1 = %s \n", str2); // hello
        printf("str1 = %s \n", str3); // hello
     */

    /* 指针字符串计数
        char* str = "asdfghasdfgasdfgh";
        int count = 0;

        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == 'a') {
                count++;
            }
            i++;
        }

        printf("a的个数是：%d\n", count);
     */

    /* 指针数组
        char* str[] = {"hello", "world", "rose"};
        for (int i = 0; i < 3; i++) {
            printf("%s\n", str[i]);
        }
    */

    /* fputs
     writeFile();
     */

    /**读控制台
    readStdio();
     */

    /**读文件*
     readFile();
     */

    int a = 1;
    int b = 2;
    const int * p = &a;
    *p = 5; // 报错

    return 0;
}

void add(int *pNum1, int *pNum2) { *pNum1 += *pNum2; }

void getMaxAndMin(int *max, int *min, int arr[], int len) {
    *max = INT32_MIN;
    *min = INT32_MAX;
    for (int i = 0; i < len; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

void writeFile(void) {
    char *str = "hello world";

    /**
     * fopen第二个参数
     * w: 写入
     * r: 读取
     * a: 追加
     */
    FILE *fp = fopen(
        "/Users/dreamarts/Documents/coderhdy/c-study/00_base/12_指针/test.txt",
        "a");
    if (fp == NULL) {
        printf("文件打开失败\n");
        return;
    }
    fputs(str, fp);
    fclose(fp);
}

void readStdio(void) {
    char str[5];
    printf("请输入：\n");
    fgets(str, sizeof(str), stdin);

    // 输入的最后一位可能是\n，在字符串长度不够的时候（5 - 1 = 4）
    unsigned long len = strlen(str);
    if (str[len] == '\n') {
        str[len] = '\0';
    }

    printf("%s\n", str);
}

void readFile(void) {
    FILE *fp = fopen(
        "/Users/dreamarts/Documents/coderhdy/c-study/00_base/12_指针/test.txt",
        "r");
    char str[100];
    fgets(str, sizeof(str), fp);
    printf("%s\n", str);
    fclose(fp);
}
