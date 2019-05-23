//
//  main.cpp
//  Bellman-Ford
//
//  Created by Aaron on 5/23/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1000;
const int INF = 10000000000;
using namespace std;
struct Node{
    int v,dis;//v为邻接边的的目标顶点，dis为邻接边的边权
};
vector<Node> Adj[MAXV];//图G的邻接表
int n;//n为顶点数，MAXV为最大顶点数
int d[MAXV],num[MAXV];//起点到达各点的最短路径长度,num记录顶点的入队次数
bool inq[MAXV];//顶点是否在队列中
bool Bellman(int s){
    fill(d, d+MAXV,INF);
    d[s] = 0;//起点s到达自身的距离为0
    //求解数组d的部分
    for (int i = 0; i<n-1; i++) {//执行n-1次，n为顶点数
        for (int u = 0; u<n; u++) {//每轮操作遍历边数
            for (int j = 0 ; j<Adj[u].size(); j++) {
                int v = Adj[u][j].v;//邻接边的顶点
                int dis = Adj[u][j].dis;//邻接边的边权
                if (d[u]+dis < d[v]) {
                d[v] = d[u] + dis;//松弛
                }
                
            }
        }
    }
    //判断负环
    for (int u = 0; u<n; u++) {//对每条边进行判断
        for (int j = 0; j<Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if (d[u] + dis <d[v]) {//说明图中仍有从原点可达的负环
                return false;
            }
        }
    }
    return true;
}
bool SPFA(int s){
    //初始化部分
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d+MAXV, INF);
    //源点入队
    queue<int> Q;
    Q.push(s);
    inq[s] = true;//源点 已入队
    num[s]++;//原点入队次数加一
    d[s] = 0;//原点的d值为0
    //主体部分
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        //遍历u的所有邻接边
        for (int j = 0; j<Adj[u].size(); j++) {
            int v = Adj[u][j].dis;
            int dis = Adj[u][j].dis;
            //松弛操作
            if (d[u]+dis < d[v]) {
                d[v] = d[u] +dis;
                if (!inq[v]) {//如果v不在队列中
                    Q.push(v);
                    inq[v] = true;
                    num[v] ++;
                    if (num[v] >= n) {//有可达负环
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
