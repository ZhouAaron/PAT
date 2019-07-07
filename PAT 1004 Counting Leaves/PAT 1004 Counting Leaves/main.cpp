//
//  main.cpp
//  PAT 1004 Counting Leaves
//
//  Created by Aaron on 2019/7/7.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 110;//最大节点数量
vector<int> G[maxn];//存储树
int leaf[maxn] = {0};
int max_h = 1;
void DFS(int index, int h){
    max_h = max(max_h,h);
    if (G[index].size() == 0) {
        leaf[h]++;
        return;
    }
    for (int i = 0; i<G[index].size(); i++) {
        //注意这里h不能写成h++这样会使h改变
        DFS(G[index][i], h+1);
    }
}
int main(int argc, const char * argv[]) {
    int N,M,parent,k,child;
    scanf("%d%d",&N,&M);
    for (int i = 0; i<M; i++) {
        scanf("%d%d",&parent,&k);
        for (int j = 0; j<k; j++) {
            scanf("%d",&child);
            G[parent].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d",leaf[1]);
    for (int i = 2; i<=max_h; i++) {
        printf(" %d",leaf[i]);
    }
    return 0;
}
