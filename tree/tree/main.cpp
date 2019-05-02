//
//  main.cpp
//  tree
//
//  Created by 周杰 on 2019/4/28.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace  std;
//二叉树的结构体
typedef struct BTree{
    int val;
    struct BTree *left, *right;
}BTree;
 //二叉树的类，包含着操作二叉树的各种方法
class Tree{
public:
    BTree *create_node(int level,string pos);
    void PreOrder(BTree *t);//先序遍历
    void InOrder(BTree *t);//中序遍历
    void PostOrder(BTree *t);//后序遍历
    
    BTree *root;
};
//用先序遍历的方法构造一个二叉树
BTree* Tree::create_node(int level, string pos){
    int data;
    BTree *node = new BTree;
    cout<<"please enter data:level"<<level<<" "<<pos<<endl;
    cin>>data;
    if ( data == 0) {
        return NULL;
    }
    node->val = data;
    node->left = create_node(level+1,"left");
    node->right = create_node(level+1, "right");
    return node;
}
void Tree::PreOrder(BTree *t){
    if (t) {
        cout<<t->val<<endl;
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void Tree::PostOrder(BTree *t){
    if (t) {
        PostOrder(t->left);
        PostOrder(t->right);
        cout<<t->val<<endl;
    }
}
void Tree::InOrder(BTree *t){
    if (t) {
        InOrder(t->left);
        cout<<t->val<<endl;
        InOrder(t->right);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Tree tree;
    tree.root = tree.create_node(1, "root");
    cout<<"Pre"<<endl;
    tree.PreOrder(tree.root);
    
    cout<<"In"<<endl;
    tree.InOrder(tree.root);
    
    cout<<"Post"<<endl;
    tree.PostOrder(tree.root);
    return 0;
}
