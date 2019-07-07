//
//  main.cpp
//  PAT 1107 Social Clusters
//
//  Created by Aaron on 2019/7/6.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn] ;
int isRoot[maxn] = {0};//isRoot[x] = 以x号人作为根节点的社交网络有多少人
int course[maxn] = {0};//存储个集合中的根节点，
int findFather(int x){
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    //路径压缩
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faB] = faA;
    }
}
void init(int n){
    for (int i = 1; i<=n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}
//大的排前面
bool cmp(int a,int b){
    return a>b;
}
int main(int argc, const char * argv[]) {
    int n,k,h;
    scanf("%d",&n);
    init(n);
    for (int i = 1; i<= n; i++) {
        scanf("%d:",&k);
        for (int j = 0; j<k; j++) {
            scanf("%d",&h);
            if (course[h] == 0) {
                course[h] = i;//course[h]第一次有人喜欢
            }
            Union(i, findFather(course[h]));
        }
    }
    for (int i = 1; i<=n; i++) {
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i<= n; i++) {
        if (isRoot[i] != 0) {
            ans++;
        }
    }
    printf("%d\n",ans);
    sort(isRoot+1, isRoot+n+1, cmp);
    for (int i = 1; i<= ans ; i++) {
        printf("%d",isRoot[i]);
        if (i < ans) {
            printf(" ");
        }
    }
    return 0;
}
