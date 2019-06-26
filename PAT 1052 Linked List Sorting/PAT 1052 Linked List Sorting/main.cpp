//
//  main.cpp
//  PAT 1052 Linked List Sorting
//
//  Created by Aaron on 2019/6/25.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct node {
    int address;
    int data;
    int next;
    bool flag;
}Node[maxn];
bool cmp (node a,node b){
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    }else{
        return a.data < b.data;
    }
}
int main(int argc, const char * argv[]) {
    for (int i = 0; i<maxn; i++) {
        Node[i].flag = false;
    }
    int n,start;
    scanf("%d %d",&n,&start);
    int address,data,next;
    for (int i = 0; i<n; i++) {
        scanf("%d %d %d",&address,&data,&next);
        Node[address].address = address;
        Node[address].data = data;
        Node[address].next = next;
    }
    int count = 0,p = start;
    while (p!=-1) {
        Node[p].flag = true;
        count++;
        p = Node[p].next;
        
    }
    if (count == 0) {
        printf("0 -1");
    }else{
        sort(Node, Node+maxn,cmp);
        printf("%d %05d\n",count,Node[0].address);
        for (int i = 0; i<count; i++) {
            if (i != count-1) {
                printf("%05d %d %05d\n",Node[i].address,Node[i].data,Node[i+1].address);
            }else{
                printf("%05d %d -1\n",Node[i].address,Node[i].data);
            }
        }
    }
    
    return 0;
}
