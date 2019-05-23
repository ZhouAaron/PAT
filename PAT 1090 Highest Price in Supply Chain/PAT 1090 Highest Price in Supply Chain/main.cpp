//
//  main.cpp
//  PAT 1090 Highest Price in Supply Chain
//
//  Created by Aaron on 5/21/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
double p,r;
int n,maxDepth = 0,num = 0;
vector<int> child[maxn];
void DFS (int index ,int depth){
    if (child[index].size() == 0) {
        if (depth > maxDepth) {
            maxDepth = depth;
            num = 1;
        }
        else if(depth == maxDepth){
            num++;
        }
        return;
    }
    for (int i = 0; i<child[index].size(); i++) {
        DFS(child[index][i], depth+1);
    }
}
int main(int argc, const char * argv[]) {
    int father, root;
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100;
    for (int i =0; i<n; i++) {
        scanf("%d",&father);
        if (father != -1) {
            child[father].push_back(i);
        }else{
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n",p*pow(1+r,maxDepth),num);
    return 0;
}
