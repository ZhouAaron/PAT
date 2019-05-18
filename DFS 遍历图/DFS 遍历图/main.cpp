//
//  main.cpp
//  DFS 遍历图
//
//  Created by Aaron on 5/18/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 1000;
const int INF = 100000000;
////邻接矩阵
//int n,G[MAXV][MAXV];//n为定点数，MAXV为最大定点数
//bool vis[MAXV];//如果顶点i已被访问，则vis[i] = true初值为false
//
//void DFS(int u,int depth){//u为当前访问的顶点标号，depth为深度
//    vis[u] = true;//设置u已被访问
//    //如果需要对u进行一些操作，可以在这里进行
//    //对所有从u出发能到达的分支顶点进行枚举
//    for (int v = 0; v<n; v++) {
//        //如果v未被访问，则u可到达v
//        if (vis[v] == false && G[u][v] != INF) {
//            DFS(v, depth+1);//访问v深度加一
//        }
//    }
//}
////遍历图G
//void DFSTrave(){
//    for (int u = 0; u<n; u++) {
//        if (vis[u] == false) {
//            DFS(u, 1);//访问u和u所在的连通块，1表示为第一层
//        }
//    }
//}

vector<int> Adj[MAXV];
int n;
bool vis[MAXV] = {false};

void DFS(int u,int depth){
    vis[u] = true;
    for (int i = 0; i<Adj[u].size(); i++) {
        int v= Adj[u][i];
        if (vis[v] == false) {
            DFS(u, depth+1);
        }
    }
}
void DFSTrave(){
    for (int u = 0; u<n; u++) {
        if (vis[u] == false) {
            DFS(u, 1);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
