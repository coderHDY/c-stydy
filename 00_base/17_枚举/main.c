//
//  main.c
//  17_枚举
//
//  Created by 黄德宇 on 2025/4/12.
//

#include <stdio.h>

enum Position {
    East,
    West,
    North,
    South
};

int main(int argc, const char * argv[]) {
    enum Position p = East;
    printf( "Position: %d\n", p);
    
    return 0;
}
