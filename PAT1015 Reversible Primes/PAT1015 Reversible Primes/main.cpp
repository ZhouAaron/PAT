////
////  main.cpp
////  PAT1015 Reversible Primes
////
////  Created by Aaron on 5/8/19.
////  Copyright © 2019 周杰. All rights reserved.
////
//
#include <iostream>
#include <cmath>
using namespace std;
//判断是否为素数
bool isPrime(int n){
    if (n<=1) {
        return false;
    }
    int sqr = int(sqrt(n*1.0));
    for (int i = 2; i<=sqr; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n,m ;
    while (scanf("%d",&n)!=EOF) {
        if (n<0) {
            break;
        }
        scanf("%d",&m);
        if (isPrime(n) == false) {
            printf("NO\n");
            continue;
        }
        int len = 0,arr[100];
        //m进制转换
        do {
            arr[len++] = n % m;
            n=n/m;
        } while (n!=0);
        for (int i = 0; i<len; i++) {
            n = n*m+arr[i];
        }
        printf("%s",isPrime(n)? "Yes\n" : "No\n");
    }

    return 0;
}
