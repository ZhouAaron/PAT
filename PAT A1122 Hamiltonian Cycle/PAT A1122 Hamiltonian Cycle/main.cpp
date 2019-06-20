//
//  main.cpp
//  PAT A1122 Hamiltonian Cycle
//
//  Created by Aaron on 2019/6/16.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 201;
int main(int argc, const char * argv[]) {
    int n,m;//n为顶点数，m为边数
    scanf("%d %d",&n,&m);
    int vv[MAXN][MAXN];
    for (int i = 0; i<m; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        vv[a][b] = vv[b][a] = 1;
    }
    int k;
    scanf("%d",&k);
    for (int i = 0 ; i<k; i++) {
        int c;
        vector<int> ve;
        set<int> se;
        scanf("%d",&c);
        int flag = 1,flag1 = 1;
        for (int j = 0; j<c; j++) {
            int h;
            scanf("%d",&h);
            ve.push_back(h);
            se.insert(h);
        }//如果集合中的节点不为N，（没有包含所有节点），c-1！=n表示多走或少走｜｜表示第一个节点不等于最后一个节点（没有构成环）
        if (se.size()!=n||c-1!=n||ve[0]!=ve[c-1]) {
            flag = 0;
        }//判断每一条边是否都是连通的
        for (int j = 0; j<c-1; j++) {
            if (vv[ve[j]][ve[j+1]] == 0) {
                flag1 = 0;
            }
        }
        printf("%s",flag &&flag1 ? "YES\n":"NO\n");
    }
    return 0;
}
