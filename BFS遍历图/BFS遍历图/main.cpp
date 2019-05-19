//
//  main.cpp
//  BFS遍历图
//
//  Created by Aaron on 5/19/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100;
const int INF = 10000000000;
int n,G[maxn][maxn];//n为顶点数，MAXN为最大顶点数
bool inq[maxn] = {false};//若顶点i曾加入过队列，则inq[i] == true 初值为false
//邻接矩阵版本
//void BFS(int u){
//    queue<int> Q;
//    Q.push(u);
//    inq[u] = true;
//    while (!Q.empty()) {
//        int u = Q.front();
//        Q.pop();
//        for ( int v = 0; v<n; v++) {
//            if (inq[v] == false && G[u][v] !=INF ) {
//                Q.push(v);
//                inq[v] = true;
//            }
//        }
//    }
//}
//void BFSTrave(){
//    for (int u = 0; u<n; u++) {
//        if (inq[u] == false) {//如果u未曾加入过队列
//            BFS(u);//遍历u所在的连通块
//        }
//    }
//}


//邻接表版本
vector<int> Adj[maxn];
void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while (q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i<Adj[u].size(); i++) {
            int v = Adj[u][i];
            if (inq[v] == false) {
                q.push(v);
                inq[v]= true;
            }
        }
    }
}

void BFSTrave(){
    for (int u = 0; u<n; u++) {
        if (inq[u] == false) {
            BFS(u);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
