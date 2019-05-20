//
//  main.cpp
//  Dijkstra算法
//
//  Created by Aaron on 5/19/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXV = 1000;
const int INF = 10000000000;
int n,G[MAXV][MAXV];//顶点数，maxv为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = {false};//标记数组，vis[i] == true 表示已经访问过
//邻接矩阵版本
////s为起点
//void Dijkstra(int s){
//    fill(d,d+MAXV,INF);//fill函数将整个d数组赋为INF
//    d[s] = 0;//起点s到达自身的距离为0;
//    for (int i = 0; i<n; i++) {//循环n次
//        int u = -1,MIN = INF;
//        //u使得d[u]最小，MIN存放最小的d[u]
//        for (int j = 0; j<n; j++) {
//            //寻找未访问顶点中d[]最小的
//            if (vis[j] == false && d[j] <MIN) {
//                u = j;
//                MIN = d[j];
//            }
//        }
//        //找不到小于d[u]说明剩下的顶点和起点s不连通
//        if (u == -1) {
//            return;
//        }
//        //标记u为已访问
//        vis[u] = true;
//        for (int v = 0; v<n; v++) {
//            //如果v未访问&&u能到达&&以u为中节点可以使d[u]更优
//            if (vis[v] == false && G[u][v] != INF && d[u] +G[u][v]<d[v]) {
//                d[v] = d[u] +G[u][v];//优化
//            }
//        }
//    }
//}

//邻接表版
struct Node{
    int v,dis;//v为边的目标顶点，dis为边权
};
vector<Node> Adj[MAXV];
void Dijkstra(int s){
    fill(d, d+MAXV, INF);
    d[s] = 0;
    for (int i = 0; i<n; i++) {
        int u = -1,MIN = INF;
        for (int j = 0; j<n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1 ) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j<Adj[u].size(); j++) {
            int v = Adj[u][j].v;;
            if (vis[v] == false && d[u] +Adj[u][j].dis <d[v]) {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
