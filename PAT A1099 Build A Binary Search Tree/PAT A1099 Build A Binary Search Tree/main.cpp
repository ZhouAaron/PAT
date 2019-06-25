//
//  main.cpp
//  PAT A1099 Build A Binary Search Tree
//
//  Created by Aaron on 2019/6/23.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
//节点
struct node {
    int data;
    int left,right;
}Node[maxn];
int in[maxn],n,num = 0;
void inOrder(int root){
    if (root == -1) {
        return;
    }
    inOrder(Node[root].left);
    Node[root].data = in[num++];
    inOrder(Node[root].right);
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    //num用来输出节点之间的空格
    num = 0;
    while (!q.empty()) {
        //当前节点
        int now = q.front();
        q.pop();
        printf("%d",Node[now].data);
        num++;
        if (num<n) {
            printf(" ");
        }
        if (Node[now].left != -1) {
            q.push(Node[now].left);
        }if (Node[now].right != -1) {
            q.push(Node[now].right);
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d %d",&Node[i].left,&Node[i].right);
    }
    for (int i = 0; i<n; i++) {
        scanf("%d",&in[i]);
    }
    sort(in, in+n);
    inOrder(0);
    bfs(0);
    return 0;
}
