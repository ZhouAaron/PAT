//
//  main.cpp
//  平衡二叉树
//
//  Created by Aaron on 5/16/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
struct node{
    int data,height;
    node *lchild,*rchild;
};
//新建节点
node *newNode(int v){
    node *Node = new node;
    Node->data = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return  Node;
}
//获取以root为根节点的子树的当前height
int getHeight(node *root){
    if (root == NULL) {
        return 0;
    }else{
        return root->height;
    }
}
//计算节点root的平衡因子
int getBalanceFactor(node *root){
    //左子树的高度-右子树的高度
    return getHeight(root->rchild) - getHeight(root->rchild);
}
//更新节点root的height
//节点root所在子树的height等于其左子树的height与右子树的height的较大值加一
void updateHeight(node *root){
    //max（左孩子的height，有孩子的height） + 1
    root->height = max(getHeight(root->lchild), getHeight(root->rchild))+1;
}
void searchNode(node *root ,int v){
    if (root == NULL) {
        printf("search failed\n");
        return;
    }
    if (root->data == v) {
        printf("%d\n",root->data);
    }else if(root->data >v){
        searchNode(root->lchild, v);
    }else{
        searchNode(root->rchild, v);
    }
}

//左旋
/*
 步骤1:让B的左子树成为A的右子树
 步骤2:让A成为B的左子树
 步骤3:设根节点为节点B
 */
void Left(node* &root){
    node *temp = root->rchild;//root指向节点A，temp指向节点B
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
//右旋
/*
 步骤1：让A的右子树成为B的左子树
 步骤2: 让Bd成为A的d右子树
 步骤3: 将根节点设定为A
 */
void Right(node* &root){
    node *temp = root->lchild;//root指向节点B，temp指向节点A
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
    
}

/*
 树型。      判定条件。                         调整方法
 LL     BF（root）= 2，BF（root->lchild)=1    对root进行右旋
 LR。   BF (root) = 2,BF (root->lchild)=1    先对root->lchild左旋 在对root进行右旋
 RR     BF（root）= -1,BF(root->rchild)=-1   对root进行左旋
 RL    BF（root）= -2 BF（root->rchild）=1。  先对root->rchild右旋，再对root进行左旋
 */
void insertNode(node *& root,int v){
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    if (v<root->data) {//v比根节点的权值小
        insertNode(root->lchild, v);//往左子树插入
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {//LL型
                Right(root);
            }else if (getBalanceFactor(root->lchild) == -1){//LR型
                Left(root->lchild);
                Right(root);
            }
        }
    }else{//往右子树插入
        insertNode(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {//RR型
                Left(root);
            }else if (getBalanceFactor(root->rchild) ==1){//RL型
                Right(root->rchild);
                Left(root);
            }
        }
    }
}

node *Create(int data[],int n){
    node *root = NULL;
    for (int i = 0; i<n; i++) {
        insertNode(root, data[i]);
    }
    return root;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
