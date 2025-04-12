//
//  main.c
//  01_多个target
//
//  Created by 黄德宇 on 2025/3/18.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double num1 = 120.88;
    double num2 = 89.9;
    printf("本店衣服%.2lf元一件，裤子%.2lf元一件\n", num1, num2);
    printf("请问顾客需要点什么？\n");
    
    int count1 = 0;
    int count2 = 0;
    printf("衣服：");
    scanf("%d", &count1);
    printf("裤子：");
    scanf("%d", &count2);
    
    double discount = 0.88;
    double rawPrice = num1 * count1 + num2 * count2;
    double price = rawPrice * discount;
    
    printf("顾客，原价：%.2lf元，\n但是今天本店打88折优惠，\n现在只需要付款：%.2lf\n", rawPrice, price);

    return 0;
}
