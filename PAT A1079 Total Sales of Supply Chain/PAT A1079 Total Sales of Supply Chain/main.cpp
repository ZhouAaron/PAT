//
//  main.cpp
//  PAT A1079 Total Sales of Supply Chain
//
//  Created by Aaron on 2019/6/13.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
struct node {
    double data;
    vector<int> child;
}Node[MAXN];
int N;//节点数
double P,r;//P为树根处价格，r为价格增量
double ans = 0;
void dfs(int index,int depth){
    if (Node[index].child.size() == 0) {
        ans += Node[index].data * pow(1+r,depth);
        return;
    }
    for (int i = 0; i<Node[index].child.size(); i++) {
        dfs(Node[index].child[i], depth+1);
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d %lf%lf",&N,&P,&r);
    r /= 100;
    for (int i = 0; i<N; i++) {
        int k ;
        scanf("%d",&k);
        if (k == 0) {
            scanf("%lf",&Node[i].data);
        }else{
            for (int j = 0; j<k; j++) {
                int child;
                scanf("%d",&child);
                Node[i].child.push_back(child);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f",ans*P);
    return 0;
}
