//
//  main.cpp
//  PAT 1032 Sharing
//
//  Created by Aaron on 2019/6/25.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int maxn = 100010;
struct node {
    int next;
    char c;
    bool flag;
}Node[maxn];
int main(int argc, const char * argv[]) {
    int start1,start2,n;
    for (int i = 0; i<maxn; i++) {
        Node[i].flag = false;
    }
    scanf("%d %d %d",&start1,&start2,&n);
    int address,next;
    char data;
    for (int i = 0; i<n; i++) {
        scanf("%d %c %d",&address,&data,&next);
        Node[address].c = data;
        Node[address].next = next;
        
    }
    int p;
    for (p = start1; p!=-1; p = Node[p].next) {
        Node[p].flag = true;
    }
    for (p = start2; p!=-1; p = Node[p].next) {
        if (Node[p].flag == true) {
            break;
        }
    }
    if (p!=-1) {
        printf("%05d\n",p);
    }else{
        printf("-1\n");
    }
    
    return 0;
}
