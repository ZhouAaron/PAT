//
//  main.cpp
//  大整数的四则运算
//
//  Created by Aaron on 5/24/19.
//  Copyright © 2019 周杰. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
struct bigN{
    int d[1000];
    int len;
    bigN(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
//将整数转换为bign
bigN change(char str[]){
    bigN a;
    a.len = strlen(str);
    for (int i = 0; i<a.len; i++) {
        a.d[i] = str[a.len -i -1] - '0';
    }
    return a;
}

bigN add(bigN a,bigN b){
    bigN c;
    int carry = 0;//进位
    for (int i = 0; i<a.len||i<b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}
void print(bigN a){
    for (int i = a.len - 1; i>=0; i--) {
        printf("%d",a.d[i]);
    }
}
//减法
bigN sub(bigN a, bigN b){
    bigN c;
    for (int i = 0; i<a.len || i<b.len; i++) {
        if (a.d[i] < b.d[i]) {//如果不够减
            a.d[i+1]--;//向高位借位
            a.d[i] += 10;//当前为加10
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1>= 1&& c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}


bigN divide(bigN a,int b,int &r){
    bigN c;
    c.len = a.len;//被除数的每一位和商的每一位是一一对应的，因此先令长度相等
    for (int i = a.len - 1; i >= 0; i--) {//从高位开始
        r = r * 10 + a.d[i];//和上一位遗留的余数组合
        if (r<b) {//不够除，该为位0
            c.d[i] = 0;
        }else{
            c.d[i] = r/b;//商
            r =r % b;//获得新的余数
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len -1] == 0) {
        c.len--;//去除高位0 同时至少保留一位最低位
    }
    return c;
}
//高精度与低精度的乘法
bigN multipleAB(bigN a, int b){
    bigN c;
    int carry = 0;//进位
    for (int i = 0; i<a.len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;//个位作为该位结果
        carry = temp /10;//高位部分作为新的进位
    }
    while (carry != 0) {//和加法不一样，乘法的进位可能不止一位
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
int main(int argc, const char * argv[]) {
    char str1[1000],str2[1000];
    scanf("%s%s",str1,str2);
    bigN a = change(str1);
    bigN b = change(str2);
//    print(multipleAB(a, 35));
//    print(add(a, b));
    int h = 0;
    print(divide(a, 7,h));
    
    return 0;
}
