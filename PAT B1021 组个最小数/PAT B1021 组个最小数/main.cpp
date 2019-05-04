//
//  main.cpp
//  PAT B1021 组个最小数
//
//  Created by Aaron on 5/4/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int count [10];
    for (int i = 0; i<10; i++) {
        scanf("%d",&count[i]);
    }
    for (int i = 1; i<10; i++) {
        if (count[i]>0) {
            printf("%d",i);
            count[i]--;
            break;
        }
    }
    for (int i = 0; i<10; i++) {
        for ( int j = 0; j<count[i]; j++) {
            printf("%d",i);
        }
    }
    return 0;
}
