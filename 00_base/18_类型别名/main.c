//
//  main.c
//  18_类型别名
//
//  Created by 黄德宇 on 2025/4/12.
//

#include <stdio.h>

typedef struct {
    int age;
    char* name;
} Student;
Student xiaoming = {19, "小明"};

typedef enum {
    DirectionEast,
    DirectionWest
} Direction;


int main(int argc, const char * argv[]) {
    Direction d1 = DirectionEast;
    
    return 0;
}
