//
//  main.cpp
//  test
//
//  Created by Aaron on 2019/7/7.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 110;
int h[maxn] = {0};
vector<int> G[maxn];
int leaf[maxn] = {0};
int max_h = 1;
void BFS(){
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int id = Q.front();
        Q.pop();
        max_h = max(max_h, h[id]);
        if (G[id].size() == 0) {
            leaf[h[id]]++;
        }
        for (int i = 0; i<G[id].size(); i++) {
            h[G[id][i]] = h[id]+1;//子节点的深度为当前节点的深度+1
            Q.push(G[id][i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    int N,M,k,parent,child;
    scanf("%d%d",&N,&M);
    for (int i = 0; i<M; i++) {
        scanf("%d%d",&parent,&k);
        for (int j = 0; j<k; j++) {
            scanf("%d",&child);
            G[parent].push_back(child);
        }
    }
     h[1] = 1;
    BFS();
   
    for (int i = 1; i<=max_h; i++) {
        if (i == 1) {
            printf("%d",leaf[1]);
        }else{
            printf(" %d",leaf[i]);
        }
    }
    return 0;
}
