//
//  main.cpp
//  PAT A1127 ZigZagging on a Tree
//
//  Created by Aaron on 2019/6/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> inOrder,postOrder;//存储中序和后序
struct node {
    int layer;
    int data;
    node *lchild,*rchild;
};
//建树过程
node *creat(int postL,int postR,int inL,int inR){
    if (postL>postR) {
        return NULL;
    }
    node *root = new node;
    root->data = postOrder[postR];
    root->layer = 1;
    int  k;
    for (k = inL; k<inR; k++) {
        if (inOrder[k] == postOrder[postR]) {
            break;
        }
    }
    int numberLeft = k-inL;
    root->lchild = creat(postL, postL+numberLeft-1,inL ,k-1);
    root->rchild = creat(postL+numberLeft, postR-1, k+1, inR);
    return root;
}
void Layorder(node *root){
    
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&inOrder[i]);
    }
    for (int i = 0; i<n; i++) {
        scanf("%d",&postOrder[i]);
    }
    node *root = creat(0, n-1, 0, n-1);
    
    return 0;
}
