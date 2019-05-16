//
//  main.cpp
//  二叉查找树
//
//  Created by Aaron on 5/16/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
struct node {
    int data;
    node *lchild;
    node *rchild;
}Node;
//创建空节点
node *newNode(int v){
    node *Node = new node;
    Node->data = v;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}
//search 函数查找二叉查找树中数据域为x的节点
void searchTree(node *root,int x){
    if (root == NULL) {
        printf("search faild\n");
        return;
    }
    if (x == root->data) {
        printf("%d\n",root->data);
    }
    if (x< root->data) {
        searchTree(root->lchild, x);
    }if (x>root->data) {
        searchTree(root->rchild, x);
    }
}

//insert函数在二叉查找树中插入一个数据域为x的新节点，（注意参数root要加引用）
void insert(node* &root ,int x){
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (x == root->data) {
        return;
    }else if (x<root->data){
        insert(root->lchild, x);
    }else {
        insert(root->rchild, x);
    }
}
//二叉树的建立
node *create (int data[],int n){
    node *root = NULL;
    for (int i = 0; i<n; i++) {
        insert(root, data[i]);
    }
    return root;
}
//二叉查找树的删除
node *findMax(node *root){
    //不断往右直到没有右孩子
    while (root->rchild != NULL) {
        root = root->rchild;
    }
    return root;
}

node *findMin(node *root){
    //不断往左至到m没有左孩子
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}
void deleteNode(node *&root,int x){
    if (root == NULL) {
        return;//不存在权值为x的结点
    }
    //找到欲删除的节点时
    if (root->data == x) {
        //叶子节点直接删除
        if (root->lchild == NULL && root->rchild == NULL) {
            root = NULL;//将root地址直接设为null，这样画父节点就引用不到他
            //当左子树不为空时
        }else if(root->lchild != NULL){
            //找到root的前驱节点
            node *pre = findMax(root->lchild);
            root->data = pre->data;//用前驱覆盖root
            //在左子树中删除节点pre
            deleteNode(root->lchild, pre->data);
        }else{//右子树不为空时
            //找root的后继
            node *next = findMin(root->rchild);
            //将后继覆盖root
            root->data = next->data;
            //删除节点next
            deleteNode(root->rchild, next->data);
        }
    }else if (root->data > x){
        //在左子树中删除x
        deleteNode(root->lchild, x);
    }else{
        //在右子树中删除x
        deleteNode(root->rchild, x);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
