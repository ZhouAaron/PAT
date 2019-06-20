//
//  main.cpp
//  PAT A1142 Maximal Clique
//
//  Created by Aaron on 2019/6/10.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,m,b,k,Nv,Ne,e[210][210];//Nv代表点数Ne代表边数
    scanf("%d %d",&Nv,&Ne);
    //无向图存储
    for (int i = 0; i<Ne; i++) {
        scanf("%d %d",&a,&b);
        e[a][b] = e[b][a] = 1;
    }
    scanf("%d",&m);
    for (int i = 0; i<m; i++) {
        scanf("%d",&k);//k存储要查找的节点个数
        int hash[210] = {0},isClique = 1,isMaximal = 1;
        vector<int> v(k);
        //将要查询的节点数置为一
        for (int j = 0; j<k; j++) {
            scanf("%d",&v[j]);
            hash[v[j]] = 1;
        }
        //遍历每个节点
        for (int j = 0; j<Nv; j++) {
            if (isClique == 0) {
                break;
            }
            for (int l = j+1; l<k; l++) {
                //如果要查找的节点之间无边。就为非点集
                if (e[v[l]][v[j]] == 0) {
                    isClique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        //进行下一个查询，进行下一个查询时由于已经确定了是非点集，则无需进行下一步操作，之间进行下一步查询
        if (isClique == 0) {
            continue;
        }
        //在确认时点集的情况下
        for (int j = 1; j<=Nv; j++) {
            //让非查询节点进入if语句判断非查询节点中是否与每一个节点都有边，如果与每一个节点都有边则不是最大点集
            if (hash[j] == 0) {
                for (int l = 0; l<k; l++) {
                    //只要非查询节点与查询节点之间有一个无边，则不满足最大点集的条件，就退出循环
                    if (e[v[l]][j] == 0) {
                        break;
                    }
                    if (l == k-1) {//遍历至最后一个节点时
                        isMaximal = 0;
                    }
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaximal == 1) {
            printf("Yes\n");
        }
    }
    
    return 0;
}
