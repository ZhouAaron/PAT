//
//  main.cpp
//  PAT A1043 Is it a Binary search Tree
//
//  Created by Aaron on 5/16/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//const int maxn = 1010;
//节点的定义
struct node {
    int data;
    node *lchild,*rchild;
}Node;
//插入操作，相当于创建一个k树
void insert (node *& root ,int data){
    if (root == NULL) {
        root = new node;
        root->data = data ;
        root->rchild = root->lchild = NULL;
        return;
    }
    if (data<root->data) {
        insert(root->lchild, data);
    }
    else{
        insert(root->rchild, data);
    }
}
//前序遍历
void preOrderMirror(node *root,vector<int>&vi){
    if (root == NULL) {
        return;
    }
    vi.push_back(root->data);
    preOrderMirror(root->rchild, vi);
    preOrderMirror(root->lchild, vi);
}
//前序遍历
void preOrder(node *root,vector<int>&vi){
    if (root == NULL) {
        return;
    }
    vi.push_back(root->data);
    preOrder(root->lchild, vi);
    preOrder(root->rchild, vi);
}
//后序遍历
void postOrder(node *&root,vector<int>&vi){
    if (root == NULL) {
        return;
    }
    postOrder(root->lchild, vi);
    postOrder(root->rchild, vi);
    vi.push_back(root->data);
}
//后序遍历镜像树
void postOrderMirror(node *root,vector<int> &vi){
    if (root == NULL) {
        return;
    }
    postOrderMirror(root->rchild, vi);
    postOrderMirror(root->lchild, vi);
    vi.push_back(root->data);
}

//origin 存放初始序列
//使用容器 好处是每个都相当于定义了一个可变数组，在对比的时候也比较方便不需要像数组一样每一位都进行遍历
vector<int> origin,pre,preM,post,postM;

int main(int argc, const char * argv[]) {
    int n,data;
    scanf("%d",&n);
    node *root = NULL;
    for (int i = 0; i<n; i++) {
        scanf("%d",&data);
        origin.push_back(data);
        insert(root, data);
    }
    //前序遍历
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    //当初始序列=前序遍历时，打印yes 并把后序遍历打印出来
    if (origin == pre) {
        printf("YES\n");
        for (int i = 0; i<post.size(); i++) {
            printf("%d",post[i]);
            if (i<post.size()-1) {
                printf(" ");
            }
        }
    }//初始序列=前序遍历镜像树的时候打印yes，并把后序遍历镜像树打印出来
    else if(origin == preM){
        printf("YES\n");
        for (int i = 0; i<postM.size(); i++) {
            printf("%d",postM[i]);
            if (i<postM.size()-1) {
                printf(" ");
            }
        }
    }//当初始序列既不等于前序遍历也不等于镜像树的前序遍历时则打印NO
    else{
        printf("NO\n");
    }
    return 0;
}
