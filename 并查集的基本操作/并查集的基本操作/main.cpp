//
//  main.cpp
//  并查集的基本操作
//
//  Created by Aaron on 5/17/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int maxn = 1010;
int father[maxn];

int findFather(int x){
    while (x!=father[x]) {//如果不是根节点，继续循环
        x = father[x];//获得自己的根节点
    }
    return x;
}
void Union(int a,int b){
    int faA = findFather(a);//查找a的根节点，记为faA
    int faB = findFather(b);//查找b的根节点，记为faB
    if ( faA != faB) {//如果不属于同一个集合
        father[faA] = faB;//合并他们
    }
}
//路径压缩
//中心思想就是把所有节点的父亲节点改为根节点
int findFather1(int x){
    //由于x在下面的while中会变成根节点，因此先把原先的x保存一下
    int a = x;
    while (x != father[x]) {//寻找根节点
        x = father[x];
    }
    //到这里x存放的是根节点，下面吧路径上的所有节点的father都改成根节点
    while (a!=father[a]) {
        int z = a;//因为a 要被father[a]覆盖，所以先保存a的值，以修改father[a]
        a = father[a];//a回溯父亲节点
        father[z] = x;//将原先的节点a的父亲节点改为根节点
    }
    return x;
    
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
