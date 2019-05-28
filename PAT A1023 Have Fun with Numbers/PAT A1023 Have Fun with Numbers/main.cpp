//
//  main.cpp
//  PAT A1023 Have Fun with Numbers
//
//  Created by Aaron on 5/25/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string.h>
struct bigN{
    int len;
    int a[21];
    bigN(){
        len = 0;
        memset(a, 0, sizeof(a));
    }
};
bigN change(char a[]){
    bigN b;
    b.len = strlen(a);
    for (int i = 0; i<b.len; i++) {
        b.a[i] =a[b.len - i - 1] - '0';
    }
    return b;
}
bigN multipleAB(bigN h,int n){
    bigN c;
    int carry = 0;
    for (int i = 0; i<h.len; i++) {
        int temp = h.a[i] * n + carry;
        c.a[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        c.a[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bool judge(bigN a,bigN b){
    if (a.len != b.len) {
        return false;
    }
    int count1[10] = {0};
    for (int i = 0; i<a.len; i++) {
        count1[a.a[i]]++;
        count1[b.a[i]]--;
    }
    for (int i = 0; i<10; i++) {
        if (count1[i] != 0) {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    char str[21];
    int n = 2;
    scanf("%s",str);
//    gets(str);
    bigN K = change(str);
    bigN L = multipleAB(K, n);
    if (judge(K, L)) {
        printf("Yes\n");
        
    }else{
        printf("No\n");
    }
    for (int i = L.len - 1; i>=0; i--) {
        printf("%d",L.a[i]);
    }
    return 0;
}
