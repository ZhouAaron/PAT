//
//  main.cpp
//  PAT B1032 挖掘机技术哪家强
//
//  Created by 周杰 on 2019/4/11.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int MAXN = 10010;
int school[MAXN] = {0};
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int schId,schScore;
    for (int i = 0; i<n; i++) {
        scanf("%d %d",&schId,&schScore);
        school[schId] += schScore;
    }
    int k= 1,h;
    for (int i = 0; i<MAXN; i++) {
        if (school[i]>k) {
            k = school[i];
            h = i;
        }
    }
    printf("%d %d",h,k);
    
    return 0;
}
