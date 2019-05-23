//
//  main.cpp
//  PAT A1008 Elevator
//
//  Created by Aaron on 5/22/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int maxn = 1000;
int main(int argc, const char * argv[]) {
    int total = 0,now = 0,n;
    int a[maxn]  ;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&a[i]);
        if (a[i] > now) {
            total = total + (a[i]-now)*6;
        }
        else{
            total = total + (now-a[i]) * 4;
        }
        total += 5;
        now = a[i];
    }
    printf("%d",total);
    return 0;
}
