//
//  main.cpp
//  PAT 1106 Lowest Price in Supply Chain
//
//  Created by Aaron on 2019/7/6.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100001;
const double INF = 1e12;
vector<int> Node[maxn];
int n,num = 0;
double p,r,ans = INF;

void DFS(int index ,int depth){
    if (Node[index].size() == 0) {
        double price = p * pow(1+r, depth);
        if (price < ans) {
            ans = price ;
            num = 1;
        }else if (price == ans){
            num++;
        }
        return;
    }
    for (int i = 0; i<Node[index].size(); i++) {
        DFS(Node[index][i], depth+1);
    }
}
int main(int argc, const char * argv[]) {
    int k,child;
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100;
    for (int i = 0; i<n; i++) {
        scanf("%d",&k);
        if (k!=0) {
            for (int j = 0; j<k; j++) {
                scanf("%d",&child);
                Node[i].push_back(child);
            }
        }
    }
    DFS(0, 0);
    printf("%.4f %d\n",ans,num);
    
    return 0;
}
