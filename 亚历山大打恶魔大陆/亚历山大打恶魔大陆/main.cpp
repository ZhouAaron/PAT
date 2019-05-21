//
//  main.cpp
//  亚历山大打恶魔大陆
//
//  Created by Aaron on 5/21/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
int n,m,G[MAXV][MAXV];//n为顶点数，MAXV为最大顶点数
int d[MAXV];//顶点和集合s的最短距离
bool vis[MAXV] = {false};

int prim(){//默认0号为初始点，函数返回最小生成树的边权之和
    fill(d, d+MAXV, INF);//fill函数将整个d数组赋为INF
    d[0] = 0;//只有0号顶点到集合s的距离为0，其余为INF
    int ans = 0;//存放最小生成树的边权之和
    for (int i = 0;i<n; i++) {//循环n次
        int u = -1,MIN = INF;//u使d[u]最小，MIN存放该最小的d[u]
        for (int j = 0; j<n; j++) {
            if (vis[j] == false && d[j] <MIN) {
                u = j;
                MIN = d[j];
            }
        }
        
        if ( u == -1 ) {
            return -1;
        }
        vis[u] = true;//标记u已访问
        ans += d[u];//将与集合s距离最小的边加入最小生成树
        for (int v = 0; v<n; v++) {
            if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];//将G[u][v]赋值给d[v]
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    int u,v,w;
    scanf("%d%d",&n,&m);
    fill(G[0], G[0]+MAXV*MAXV, INF);
    for (int i = 0; i<m; i++) {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v] = G[v][u] = w;
    }
    int ans = prim();
    printf("%d\n",ans);
    return 0;
}
