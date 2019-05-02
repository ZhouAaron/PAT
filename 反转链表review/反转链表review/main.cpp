//
//  main.cpp
//  反转链表review
//
//  Created by 周杰 on 2019/4/25.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
struct NODE {
    int address;
    int data;
    int next;
    int flag;
}node[MAXN];
bool cmp(NODE a,NODE b){
    return a.flag < b.flag;
}
int main(int argc, const char * argv[]) {
    int begin,n,k,address;
    scanf("%d %d %d",&begin,&n,&k);
    for ( int i = 0; i<MAXN; i++) {
        node[i].flag = MAXN;
    }
    for (int i = 0; i<n; i++) {
        scanf("%d",&address);
        scanf("%d %d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    int p = begin,count = 0;
    while (p != -1) {
        node[p].flag = count ++;
        p = node[p].next;
    }
    sort(node, node+MAXN, cmp);
    for (int i = 0; i<n/k; i++) {
        for (int j = (i+1)*k-1; j>i*k; j--) {
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].next);
        }
        printf("%05d %d",node[i*k].address,node[i*k].data);
        if (i<n/k-1) {
            printf("%05d",node[(i+2)*k-1].address);
        }
        else{
            if (n%k==0) {
                printf("-1\n");
            }else{
                printf(" %05d\n",node[(i+1)*k].address);
            for (int i = n/k*k; i<n; i++) {
                printf("%05d %d",node[i].address,node[i].data);
                if (i<n-1) {
                    printf("% 05d\n",node[i+1].address);
                }
                else{
                    printf(" -1\n");
                }
            }
                
            }
        }
    }
    
    
    return 0;
}
