//
//  main.cpp
//  迷宫
//
//  Created by Aaron on 5/15/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 10001;
int n,m;//矩阵长宽
struct node{
    int x,y;//坐标信息
    int step;//走的步数
}S1,T,Node;
int a[4] = {0,0,1,-1};
int b[4] = {1,-1,0,0};
bool inq[maxn][maxn] = {false};
char matrix[maxn][maxn] = {0};
bool judge (int x,int y){
    if (x<0||y<0||x>n||y>m) {
        return false;
    }if (matrix[x][y] == '*') {
        return false;
    }
    if (inq[x][y] == true) {
        return false;
    }
    return true;
}
int BFS(){
    queue<node> q;
    q.push(Node);
    q.pop();
    while (!q.empty()) {
        node S = q.front();
        S.x = Node.x;
        S.y = Node.y;
//        int ans = 0;
        if (S.x == T.x && S.y == T.y) {
            return S.step;
        }
        for (int i = 0; i<4; i++) {
            int newX = S.x +a[i];
            int newY = S.y +b[i];
            if (judge(newX, newY)) {
                Node.x = newX;Node.y = newY;
                Node.step = S.step + 1;
                q.push(Node);//重点理解，她是吧这附近所有符合条件的节点都加入到队列中，这才实现了BFS
                inq[newX][newY] = true;
            }
        }
    }
    return  -1;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
