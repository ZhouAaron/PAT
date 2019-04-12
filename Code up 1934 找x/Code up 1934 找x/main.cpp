//
//  main.cpp
//  Code up 1934 找x
//
//  Created by 周杰 on 2019/4/12.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int maxn = 210;
int array[maxn];
int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d",&n);
    for (int i = 0;  i<n; i++) {
        scanf("%d",&array[i]);
    }

    int x,i=0;
    scanf("%d",&x);
    for ( i = 0; i<n; i++) {
        if (x == array[i]) {
            printf("%d\n",i);
            break;
        }
    }
    if (i == n) {
        printf("-1\n");
    }
    return 0;
}
