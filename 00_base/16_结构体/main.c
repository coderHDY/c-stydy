//
//  main.c
//  16_结构体
//
//  Created by 黄德宇 on 2025/4/12.
//

#include <stdio.h>

struct Student {
    char *name;
    int gender;
    float height;
};

int main(int argc, const char *argv[]) {
    struct Student fang = {"小芳", 0, 1.65};
    struct Student* pStu = &fang;
    (*pStu).name = "小方";
    pStu -> height = 1.70;

    return 0;
}
