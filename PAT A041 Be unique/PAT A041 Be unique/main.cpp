//
//  main.cpp
//  PAT A041 Be unique
//
//  Created by Aaron on 5/13/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
int a[100001],hashTable[100001] = {0};
int main(int argc, const char * argv[]) {
    int n ;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&a[i]);
        hashTable[a[i]] ++;
    }
    int ans = -1;
    for (int i = 0; i<n; i++) {
        if (hashTable[a[i]] == 1) {
            ans++;
            printf("%d",a[i]);
            break;
        }
        if (ans == -1) {
            printf("None");
        }
    }
    return 0;
}
