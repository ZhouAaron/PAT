//
//  main.cpp
//  PAT A1003 Emergency
//
//  Created by Aaron on 2019/6/26.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1e9;
int weight[MAXV],num[MAXV];//存放点权和路径条数
int G[MAXV][MAXV];//存储图
int d[MAXV],w[MAXV];
int N,M,C1,C2;//点数，边数，起点，终点
bool vis[MAXV] = {false};
void Dijstra(int s){
    fill(d, d+MAXV, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i<N; i++) {
        int u = -1,MIN = INF;
        for (int j = 0; j<N; j++) {
            if (vis[j] == false && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j<N; j++) {
            if (vis[j] == false && G[u][j] != INF) {
                if (d[u] + G[u][j] < d[j]) {
                    d[j] = d[u] + G[u][j];
                    w[j] = w[u] + weight[j];
                    num[j] = num[u];
                }else if (d[u] + G[u][j] == d[j]){
                    if (w[u] + weight[j] > w[j]) {
                        w[j] = w[u] + weight[j];
                    }
                    num[j] += num[u];
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    for (int i = 0; i<N; i++) {
        scanf("%d",&weight[i]);
    }
    int a,b,c;
    fill(G[0], G[0]+MAXV*MAXV, INF);
    for (int i = 0; i<M; i++) {
        scanf("%d %d %d",&a,&b,&c);
        G[a][b] = c;
        G[b][a] = c;
    }
    Dijstra(C1);
    printf("%d %d\n",num[C2],w[C2]);
    return 0;
}
