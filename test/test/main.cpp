//
//  main.cpp
//  test
//
//  Created by Aaron on 5/15/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100001;
//int n,K,x,maxSumSqu;
//vector<int> temp ,ans;
//int a[maxn];
//void DFS(int index ,int nowK,int sum,int sumSqu){
//    if (nowK == K && sum == x) {
//        if (sumSqu>maxSumSqu) {
//           maxSumSqu = sumSqu;
//            ans = temp;
//
//        }
//        return;
//    }
//    if (index == n||nowK>K||sum>x) {
//        return;
//    }
//    temp.push_back(a[index]);
//    DFS(index+1, nowK+1, sum+a[index], sumSqu+a[index]*a[index]);
//    temp.pop_back();
//    DFS(index+1, nowK, sum, sumSqu);
//
//}

int n,m;//n行m列
int matrix[maxn][maxn] = {0};//存放矩阵
bool inq[maxn][maxn] = {false};//判断是否已经入过队
int a[4] = {0,0,1,-1};//用来访问元素上下左右的辅助工具
int b[4] = {1,-1,0,0};
//结点定义用来表示结点坐标
struct node {
    int x;
    int y;
}Node;
//判断这个坐标是否合法并且是否入过队
bool judge(int newX,int newY){
    if (newX<0||newX>n||newY<0||newY>m) {
        return false;
    }if (matrix[newX][newY] == 0||inq[newX][newY] == true) {
        return false;
    }return true;
}

void DFS(int x,int y){
    queue<node> Q;//DFS用队列实现
    Node.x = x,Node.y = y;
    Q.push(Node);//出队
    inq[x][y] = true;//出队之后，将这个结点表示已经入过队
    while (!Q.empty()) {//当队不为空时，继续循环，后面会有判断这个下一个结点是否为1 如果为1 则将这个结点重新入队
        node top = Q.front();//取出当前队列队首元素
        Q.pop();//将队列队元素出队
        //循环这个结点的上下左右四个位置
        for (int i = 0; i<4; i++) {
            int newX = top.x+a[i];
            int newY = top.y+b[i];
            
            if (judge(newX, newY)) {
                inq[newX][newY] = true;
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    for (int i = 0; i<n; i++) {
        for (int j =0; j<m; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    int ans = 0;
    for (int i= 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (matrix[i][j]&& inq[i][j] == true) {
                ans++ ;
                DFS(i, j);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
