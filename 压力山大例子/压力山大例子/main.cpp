//
//  main.cpp
//  压力山大例子
//
//  Created by Aaron on 5/19/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 1000;//最大顶点数
const int INF = 1000000000;

int n,m,s,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

void Dijsktra(int s){
    fill(d,d+MAXV,INF);
    d[s] = 0;
    for (int i = 0; i<n; i++) {
        int u = -1,MIN = INF;
        for (int j = 0; j<n; j++) {
            if (vis[j] == false && d[j] <MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) {
            return;
        }vis[u] = true;
        for (int v = 0; v<n; v++) {
            if (vis[v] == false && G[u][v]!=INF && d[u]+G[u][v]<d[v]) {
                d[v] = d[u] +G[u][v];
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int u,v,w;
    scanf("%d%d%d",&n,&m,&s);
    fill(G[0], G[0]+MAXV*MAXV, INF);
    for (int i = 0; i<m; i++) {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v] = w;
    }
    Dijsktra(s);
    for (int i = 0; i<n; i++) {
        printf("%d",d[i]);
    }
    return 0;
}
