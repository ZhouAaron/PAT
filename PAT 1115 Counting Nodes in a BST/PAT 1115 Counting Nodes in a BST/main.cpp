//
//  main.cpp
//  PAT 1115 Counting Nodes in a BST
//
//  Created by Aaron on 2019/6/23.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * left,*right;
};
//建立二叉树过程
node *build(node *root,int v){
    if (root == NULL) {
        root = new node;
        root->data = v;
        root->left = root->right = NULL;
    }else if (root->data >= v){
        root->left = build(root->left, v);
    }else{
        root->right = build(root->right, v);
    }
    return root;
}
//v用来存储每一层节点的信息
vector<int> v(1000);
int maxDepth = -1;
void dfs(node *root ,int depth){
    if (root == NULL) {
        maxDepth = max(maxDepth, depth);
        return;
    }
    //存放节点数量
    v[depth]++;
    dfs(root->left, depth+1);
    dfs(root->right, depth+1);
}
int main(int argc, const char * argv[]) {
    int n,t;
    scanf("%d",&n);
    node* root = NULL;
    for (int i = 0; i<n; i++) {
        scanf("%d",&t);
        root = build(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d",v[maxDepth-1],v[maxDepth-2],v[maxDepth-1]+v[maxDepth-2]);
    return 0;
}
