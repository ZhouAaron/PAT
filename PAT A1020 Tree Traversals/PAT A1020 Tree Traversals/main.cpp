//
//  main.cpp
//  PAT A1020 Tree Traversals
//
//  Created by Aaron on 5/10/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 50;
int post[maxn] ,in[maxn],pre[maxn];
int n;
//二叉树的定义
struct node{
    int data;
    node *lchild;
    node *rchild;
};

/*
 后序遍历区间：[postL postR]
 中序遍历区间：[inL inR]
 */
node *postMidCreate(int postL,int postR,int inL,int inR){
    if (postL>postR) {
        return NULL;
    }
    node *root = new node;
    //后序遍历中最后一个节点为根节点，首先找到根节点，则可以在中序遍历中分左右子树
    root->data = post[postR];
    int k;
    for ( k = inL; k<inR; k++) {
        //说明已经找到中序遍历中的根节点
        if (in[k] == post[postR]) {
            break;
        }
    }
    //左子树中节点的个数
    int numleft = k-inL;
    root->lchild = postMidCreate(postL, postL+numleft-1, inL, k-1);
    root->rchild = postMidCreate(postL+numleft, postR-1, k+1, inR);
    return root;
}
int num = 0;
void LayerOrder(node *root){
    queue<node*> q;//注意队列中必须要存地址
    //因为队列中保存的只是原元素的一个副本，如果直接存储node型 当需要修改队首元素时，就无法对原元素进行修改
    q.push(root);//进队
    while (!q.empty()) {
        node *now = q.front();//取出队首元素
        q.pop();
        printf("%d",now->data);
        num++;
        if (num<n) {
            printf(" ");
            if (now->lchild != NULL) {
                q.push(now->lchild);
            }
            if (now->rchild != NULL) {
                q.push(now->rchild);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&post[i]);
    }
    for (int i = 0; i<n; i++) {
        scanf("%d",&in[i]);
    }
    node *root = postMidCreate(0, n-1, 0, n-1);
    LayerOrder(root);
    return 0;
}
