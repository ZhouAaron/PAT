//
//  main.cpp
//  二叉树的静态实现
//
//  Created by Aaron on 5/10/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 50;
struct node{
    int data;
    int lchild;
    int rchild;
}Node[maxn];//节点数组，maxn为节点上限个数
int index1 = 0;
int newNode (int v){//分配一个Node数组中的节点给新的节点，index1为其下标
    Node[index1].data = v;
    Node[index1].lchild = -1;//以-1或maxn表示为空，因为数组的范围是0-manx-1
    Node[index1].rchild = -1;
    return index1++;
}
//查找
void search(int root , int x,int newData){
    if ( root == -1) {//用-1表示NULL
        return;//死树（递归边界）
    }
    if (Node[root].data == x) {//找到数据域为x的节点，把它修改为newdata
        Node[root].data = newData;
    }
    //往左子树搜索x（递归式）
    search(Node[root].lchild, x, newData);
    //往右子树搜索x（递归式）
    search(Node[root].rchild, x, newData);
}
//插入，root为根节点在数组的下标
void insert(int &root,int x){//加引用
    if (root == -1) {//空树，说明查找失败，也即插入位置（递归边界）
        root = newNode(x);//给root赋以新的节点
        return;
    }
    //由二叉树的的性质x应该插在左子树
    if (root) {
        insert(Node[root].lchild, x);
    }else{
        insert(Node[root].rchild, x);
    }
}
//二叉树的建立，函数返回根节点root的下标
int create(int data[],int n){
    int root = -1;
    for (int i = 0; i<n; i++) {
        insert(root, data[i]);//将data[0]~data[n-1]插入二叉树中
    }
    return root;
}

//先序遍历
void preorder(int root){
    if (root == -1) {
        return;
    }printf("%d\n",Node[root].data);
    preorder(Node[root].lchild);
    preorder(Node[root].rchild);
}
//中序遍历
void inorder(int root){
    if (root == -1) {
        return;
    }
    inorder(Node[root].lchild);
    printf("%d\n",Node[root].data);
    inorder(Node[root].rchild);
}
//后序遍历
void postorder(int root){
    if (root == -1) {
        return;
    }
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    printf("%d",Node[root].data);
}
//层序遍历
void layerOrder(int root){
  queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d",Node[now].data);
        if (Node[now].lchild != -1) {
            q.push(Node[now].lchild);
        }if (Node[now].rchild != -1) {
            q.push(Node[now].rchild);
        }
    }
    
}
int main(int argc, const char * argv[]) {
    
    
    return 0;
}
