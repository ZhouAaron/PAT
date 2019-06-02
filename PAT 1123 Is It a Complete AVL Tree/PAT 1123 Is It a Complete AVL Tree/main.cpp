//
//  main.cpp
//  PAT 1123 Is It a Complete AVL Tree
//
//  Created by Aaron on 5/29/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct node{
    int data,height;
    node *lchild, *rchild;
};
node *newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}
int getHeight(node *root){
    if (root == NULL) {
        return 0;
    }
    return root->height;
}
int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}
void upgradeHeight(node* root){
    root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
//左旋
void leftRotate(node *&root){
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    upgradeHeight(root);
    upgradeHeight(temp);
    root = temp;
}
//右旋
void rightRotate(node *& root){
    node * temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    upgradeHeight(root);
    upgradeHeight(temp);
    root = temp;
}
void insert(node*& root,int v){
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    if (v<root->data) {
        insert(root->lchild, v);
        upgradeHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                rightRotate(root);
            }else if (getBalanceFactor(root->lchild) == -1){
                leftRotate(root->lchild);
                rightRotate(root);
            }
        }
    }else{
        insert(root->rchild, v);
        upgradeHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {
                leftRotate(root);
            }else if (getBalanceFactor(root->rchild) == 1){
                rightRotate(root->rchild);
                leftRotate(root);
            }
        }
    }
}
node *create(int data[],int n){
    node * root = NULL;
    for (int i = 0; i<n; i++) {
        insert(root, data[i]);
    }
    return root;
}
int is_Complete = 1, after = 0;
//使用BFS
vector<int> is_complete(node *root){
    vector<int> v;
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty()) {
        node *temp = Q.front();
        Q.pop();
        v.push_back(temp->data);
        if (temp->lchild != NULL) {
            if (after) {
                is_Complete = 0;
            }
            Q.push(temp->lchild);
        }else{
            after = 1;
        }
        if (temp->rchild != NULL) {
            if (after) {
                is_Complete = 0;
            }Q.push(temp->rchild);
        }else{
            after = 1;
        }
        
    }
    return v;
}
int main(int argc, const char * argv[]) {
    int n ;
    scanf("%d",&n);
    int data[20];
    for (int i = 0; i<n; i++) {
        scanf("%d",&data[i]);
    }
    node *root = create(data, n);
    vector<int > v = is_complete(root);
    for (int i = 0; i<v.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
         printf("%d",v[i]);
    }
    printf("\n%s",is_Complete ? "YES" : "NO");
    return 0;
}
