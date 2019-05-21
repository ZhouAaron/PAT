//
//  main.cpp
//  Prim算法
//
//  Created by Aaron on 5/21/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 1000;//最大顶点数
const int INF = 10000000000;
int n,G[MAXV][MAXV];
int d[MAXV];//顶点与集合s的最短距离
bool vis[MAXV] = {false};
//邻接矩阵版
////默认0号为初始点，函数返回最小生成树的边权之和
//int prim(){
//    fill(d, d+MAXV, INF);
//    d[0] = 0;//只有0号顶点到集合s的距离为0，其余全为INF
//    int ans = 0;//存放最小生成树的边权之和
//    for (int i = 0; i<n; i++) {//循环n次
//        int u = -1,MIN = INF;//u使d[u]最小，MIN存放该最小的d[u]
//        for (int j = 0; j<n; j++) {
//            if (vis[j] == false && d[j] <MIN) {
//                u = j;
//                MIN = d[j];
//            }
//        }
//        //找不到小于INF的d[u]，则剩下的顶点和集合s不连通
//        if (u == -1) {
//            return -1;
//        }
//        vis[u] = true;//标记u为已访问
//        ans += d[u];//将与集合s距离最小的边加入最小的生成树
//        for (int v = 0; v<n; v++) {
//            //当v为访问&&u能到达v&&以u为中介点可以使v离集合s更近
//            if (vis[v] == false && G[u][v] !=INF && G[u][v] < d[v]) {
//                d[v] = G[u][v];//将G[u][v]赋值给d[v]
//            }
//        }
//    }
//    return ans;//返回最小生成树的边权之和
//}

//邻接表版本
struct Node {
    int v,dis;
};
vector<Node> Adj[MAXV];
int Prim(){
    fill(d, d+MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i<n; i++) {
        int u = -1,MIN = INF;
        for (int j = 0; j<n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) {
            return -1;
        }
        vis[u] = true;
        ans += d[u];
        for (int j = 0; j<Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (vis[v] == false && Adj[u][j].dis <d[v]) {
                d[v] = Adj[u][j].dis;
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
