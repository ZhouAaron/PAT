//
//  main.cpp
//  PAT A1108 Find Average
//
//  Created by Aaron on 2019/6/20.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string.h>
int main(int argc, const char * argv[]) {
    int n,cnt = 0;
    scanf("%d",&n);
    char a[50],b[50];
    double temp = 0.0 ,sum = 0.0;
    for (int i = 0; i<n; i++) {
        scanf("%s",a);
        //将a转化为double类型并赋值给temp
        sscanf(a,"%lf", &temp);
        //将temp转化为2。f类型的值并赋值给b;
        sprintf(b, "%.2f",temp);
        int flag = 0;
        //a为原始的字符串，b为转化后的字符串，如果原始字符串符合要求格式，那么a与b的格式将会一样
        for (int j = 0; j<strlen(a); j++) {
            if (a[j] != b[j]) {
                flag = 1;
            }
        }
        if (flag |(temp<-1000)|temp>1000) {
            printf("ERROR: %s is not a legal number\n",a);
        }else{
            cnt++;
            sum += temp;
        }
    }
    if (cnt == 1) {
        printf("The average of 1 number is %.2f",sum);
    }else if (cnt>1){
        printf("The average of %d numbers is %.2f",cnt,sum/cnt);
    }else{
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}
