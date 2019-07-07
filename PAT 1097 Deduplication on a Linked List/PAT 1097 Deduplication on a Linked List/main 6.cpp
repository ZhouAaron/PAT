//
//  main.cpp
//  PAT 1097 Deduplication on a Linked List
//
//  Created by Aaron on 5/5/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace  std;
const int maxn = 100000;
struct NODE {
    int address,data,next,num = 2*maxn;
}node[maxn];
bool exist[maxn];
bool cmp(NODE a, NODE b){
    return a.num<b.num;
}

int main(int argc, const char * argv[]) {
    int begin ,n ,cnt1 = 0,cnt2 = 0,add;
    scanf("%d %d",&begin,&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&add);
        scanf("%d %d",&node[add].data,&node[add].next);
        node[add].address = add;
    }
    for (int i = begin; i!=-1; i = node[i].next) {
        if (exist[abs(node[i].data)] == false) {
            exist[abs(node[i].data)] = true;
            node[i].num = cnt1;
            cnt1++;
        }else{
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node+maxn, cmp);
    int cnt = cnt2+cnt1;
    for (int i = 0; i<cnt; i++) {
        if (i != cnt-1 && i != cnt1-1) {
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }else{
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
    }
    return 0;
}
