//
//  main.cpp
//  PAT A1069数字黑洞
//
//  Created by Aaron on 5/9/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
bool cmp(int a, int b){
    return a>b;//从大到小排序
}
//将每一位存储在num数组中
void spileNum (int n, int num[]){
    for (int i = 0; i<4; i++) {
        num[i] = n%10;
        n = n/10;
    }
}
//将num转换为数字
int to_array(int array[]){
    int sum = 0;
    for (int i = 0 ; i<4; i++) {
        sum  = sum*10+array[i];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int n,MIN,MAX;
    int array[5] = {0};
    scanf("%d",&n);
    while (1) {
        spileNum(n, array);
        sort(array, array+4, cmp);
        MAX = to_array(array);
        sort(array, array+4);
        MIN = to_array(array);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n",MAX,MIN,n);
        if (n == 0||n==6174) {
            break;
        }
        
    }
    
    return 0;
}
