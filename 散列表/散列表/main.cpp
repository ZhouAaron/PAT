//
//  main.cpp
//  散列表
//
//  Created by 周杰 on 2019/5/2.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int maxn = 100010;
bool hashTable[maxn] = {false};

int main(int argc, const char * argv[]) {
    int n,m,x;
    scanf("%d %d",&n,&m);
    for (int i = 0; i<n; i++) {
        scanf("%d",&x);
        hashTable[x] = true;
    }
    for (int i = 0; i<m; i++) {
        scanf("%d",&x);
        if (hashTable[x] == true) {
            printf("yes!\n");
        }else{
            printf("no!\n");
        }
    }
    
    return 0;
}
