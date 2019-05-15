//
//  main.cpp
//  树
//
//  Created by Aaron on 5/14/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1010;
//由于这个定义无法预知子节点的个数，只能将child数组的长度开到最大，对于节点较多的数组 会导致开辟过多的空间

//struct node{
//    int data;//数据域
//    int child[maxn];//指针域，存放所有子节点的下标
//}Node[maxn];//节点数组，maxn为结点上限个数

struct node {
    int data;
    vector<int> child;
    int layer;//记录层号
}Node[maxn];
//新建节点
int index1 = 1;
int newNode(int v){
    Node[index1].data = v;
    Node[index1].child.clear();//清空子节点
    return index1++;
};

//树的先根遍历
void PreOrder(int root){
    printf("%d",Node[root].data);
    for (int i = 0; i<Node[root].child.size(); i++) {
        PreOrder(Node[root].child[i]);//递归访问节点root的所有子结点
    }
}

//树的层序遍历
void LayerOrder(int root){
    queue<int> q;
    q.push(root);//将根节点入队
    Node[root].layer = 0;//记根节点的层号为0
    while (!q.empty()) {
        int front = q.front();//取出队首元素
        printf("%d",Node[front].data);
        q.pop();//队首元素出队
        for (int i = 0; i<Node[front].child.size(); i++) {
            Node[Node[front].child[i]].layer = Node[front].layer + 1;//子节点层号为当前节点层号加1；、 q.push(Node[front].child[i]);//将当前节点的所有节点入队
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
