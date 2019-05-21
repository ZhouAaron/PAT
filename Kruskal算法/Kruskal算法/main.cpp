//
//  main.cpp
//  Kruskal算法
//
//  Created by Aaron on 5/21/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 110;
const int MAXE = 10010;
//边集定义部分
struct edge {
    int u,v;
    int cost;
}E[MAXV];
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
//并查集部分
int father[MAXV];
int findFather(int x){
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    //路径压缩
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

//kruskal部分，返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
int kruskal(int n,int m){
    //ans为所求边权之和，Num_edge为当前生成树的边数
    int ans = 0,Num_edge = 0;
    for ( int i = 0; i<n; i++) {
        father[i] = i;//并查集初始化
    }
    sort(E, E+m, cmp);//所有边按边权从小到大排序
    for (int i = 0; i<m; i++) {
        int faU = findFather(E[i].u);//查询测试边两个端点所在集合的根节点
        int faV = findFather(E[i].v);
        if (faU != faV) {//如果不在一个集合中
            father[faU] = faV;//合并集合（即把测试边加入到最小生成树中
            ans += E[i].cost;//边权之和增加测试边的边权
            Num_edge++;//当前生成树的边数加一
            if (Num_edge == n-1) {//
                break;
            }
        }
    }
    //无连通使返回-1
    if (Num_edge != n-1) {
        return -1;
    }
    else{
        return ans;
    }
}


int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i<m; i++) {
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);
    }
    int ans = kruskal(n, m);
    printf("%d",ans);
    return 0;
}
