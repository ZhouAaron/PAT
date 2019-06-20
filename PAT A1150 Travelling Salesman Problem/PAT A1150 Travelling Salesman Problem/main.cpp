//
//  main.cpp
//  PAT A1150 Travelling Salesman Problem
//
//  Created by Aaron on 2019/6/11.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int a,b,N,M,e[300][300],t;
int ans = 99999999;
int ansId = 0;
void check(int index){
    int m, flag = 1;
    int sum = 0;
    scanf("%d",&m);
    vector<int> v(m);//存储要查询的节点集合
    set<int> s;//放入set中用来判断放入节点个数是否为N，辅助判断是否示simple cycle
    for (int i = 0; i<m; i++) {
        scanf("%d",&v[i]);
        s.insert(v[i]);
    }
    //寻找是否节点之间有边，若无边则不是TS cycle
    for (int i = 0; i<m-1; i++) {
        if (e[v[i]][v[i+1]] == 0) {
            flag = 0;
        }
        sum += e[v[i]][v[i+1]];
    }
    if (flag == 0) {
        printf("Path %d: NA (Not a TS cycle)\n",index);
        //如果没有形成环或者没有包含所有节点则不是TS cycle
    }else if (s.size()!=N || v[0] != v[m-1]){
        printf("Path %d: %d (Not a TS cycle)\n",index,sum);
        //如果要查询的节点数不等于N+1个 其实就是m多于N+1个节点
    }else if (m!=N+1) {
        //不是最简单cycle
        printf("Path %d: %d (TS cycle)\n",index,sum);
        //用来存储所有例子中最少的边权合
        if (sum<ans) {
            ans = sum;
            ansId = index;
        }
    }
    else{
        printf("Path %d: %d (TS simple cycle)\n",index,sum);
        if (sum<ans) {
            ans = sum;
            ansId = index;
        }
    }
}
int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&N,&M);
    //存储无向图
    for (int i = 0; i<M; i++) {
        scanf("%d %d %d",&a,&b,&t);
        e[a][b] = e[b][a] = t;
    }
    scanf("%d",&a);
    //遍历每一个case
    for (int i = 1; i<=a; i++) {
        check(i);
    }
    printf("Shortest Dist(%d) = %d",ansId,ans);
    return 0;
}
