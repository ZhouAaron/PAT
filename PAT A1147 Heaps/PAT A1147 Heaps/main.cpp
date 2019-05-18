//
//  main.cpp
//  PAT A1147 Heaps
//
//  Created by Aaron on 5/17/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
   int m,n;
vector<int> v;
void postOrder(int index){
    if (index >=n) {
        return;
    }
    postOrder(index*2+1);
    postOrder(index*2+2);
    printf("%d%s",v[index],index == 0?"\n":" ");
}
int main(int argc, const char * argv[]) {
 
    scanf("%d %d",&m,&n);
     v.resize(n);
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            scanf("%d",&v[j]);
        }
        int flag = v[0] >v[1] ?1:-1;
        for (int j =0; j<=(n-1)/2; j++) {
            int left = j*2+1,right = j*2+2;
            //大顶堆
            if ((flag == 1) && (v[left]>v[j]||(right <n &&v[right]>v[j]))) {
                flag = 0;
            }
            //小顶堆
            if ((flag == -1) && (v[left]<v[j]||(right<n && v[right]<v[j]))) {
                flag = 0;
            }
        }
        if (flag == 0) {
            printf("Not Heap\n");
            postOrder(0);
        }if (flag == 1) {
            printf("Max Heap\n");
            postOrder(0);
        }
        if (flag == -1) {
            printf("Min Heap\n");
            postOrder(0);
        }
    }
    return 0;
}
