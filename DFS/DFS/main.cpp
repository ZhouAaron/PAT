//
//  main.cpp
//  DFS
//
//  Created by Aaron on 5/12/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100;
struct node {
    int x,y;
}Node;
int n,m;//矩阵大小为n*m
int matrix[maxn][maxn];//01矩阵
bool inq[maxn][maxn] = {false};
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool judge(int x, int y){//判断坐标（x,y）是否需要访问
    //越界返回false
    if (x>=n||x<0||y>=m||y<0) {
        return false;
    }
    //当前位置为0，或（x,y）已入过队，返回false
    if (matrix[x][y] == 0 || inq[x][y] == true) {
        return false;
    }
    return true;
}
//BFS函数访问位置（x,y)所在的块，将该块中所有的“1”的inq都置为true
void BFS(int x,int y){
    queue<node> Q;
    Node.x = x;Node.y = y;
    Q.push(Node);//将结点Node入队
    inq[x][y] = true;
    while (!Q.empty()) {
        node top = Q.front();//取出队首元素
        Q.pop();//出队
        //循环四次得到四个相邻位置
        for (int i = 0; i<4; i++) {
            int newX = top.x+X[i];
            int newY = top.y+Y[i];
            if (judge(newX, newY)) {//如果新位置（newX，newY）需要访问
                //设置新的坐标
                Node.x = newX;Node.y = newY;
                //将结点Node加入队列
                Q.push(Node);
                //设置位置（newX，newY）已入过队
                inq[newX][newY] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    //读入01矩阵
    for (int x = 0; x<n; x++) {
        for (int y = 0; y<m; y++) {
            scanf("%d",&matrix[x][y]);
        }
    }
    int ans = 0;//存放块数
    for (int x = 0;x<n;x++){
        for (int y = 0; y<m; y++) {
            if (matrix[x][y] == 1&& inq[x][y] == false) {
                ans++;
                BFS(x, y);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
