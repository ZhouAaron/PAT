//
//  main.cpp
//  PAT 1138 Postorder Traversal
//
//  Created by Aaron on 5/28/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
const int maxn = 50001;
struct node{
    int data;
    node *lchild,*rchild;
};
int m=0;
int preSQ[maxn],inSQ[maxn],postSQ[maxn];
node *create(int preL,int preR,int inL,int inR){
    if (preL>preR) {
        return NULL;
    }
    node *root = new node;
    int k = 0;
    root->data = preSQ[preL];
    for (k = inL; k<inR; k++) {
        if (preSQ[preL] == inSQ[k]) {
            break;
        }
    }
    int numberLeft = k-inL;
    root->lchild = create(preL+1, preL+numberLeft, inL, k-1);
    root->rchild = create(preL+numberLeft+1, preR, k+1, inR);
    return root;
}
//后序遍历
void postOrder(node *root){
    if (root == NULL) {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
//    printf("%d",root->data);
    postSQ[m] = root->data;
    m++;
}
int main(int argc, const char * argv[]) {
    int n ;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&preSQ[i]);
    }
    for (int i = 0; i<n; i++) {
        scanf("%d",&inSQ[i]);
    }
    node *root = create(0, n-1, 0, n-1);
    postOrder(root);
    printf("%d",postSQ[0]);
    return 0;
}
