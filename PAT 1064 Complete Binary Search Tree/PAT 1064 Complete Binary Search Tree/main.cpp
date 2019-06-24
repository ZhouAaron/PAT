//
//  main.cpp
//  PAT 1064 Complete Binary Search Tree
//
//  Created by Aaron on 2019/6/24.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1001;
int num[maxn],cnt[maxn],n,index1 = 0;
void inOrder(int root ){
    if (root > n) {
        return;
    }
    inOrder(root*2);//遍历左子树
    cnt[root] = num[index1++];
    inOrder(root*2+1);//遍历右子树
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&num[i]);
    }
    sort(num, num+n);
    inOrder(1);
    for (int i = 1; i<=n; i++) {
        printf("%d",cnt[i]);
        if (i<n) {
            printf(" ");
        }
    }
    return 0;
}
