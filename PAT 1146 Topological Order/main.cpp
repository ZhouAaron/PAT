//
//  main.cpp
//  PAT 1146 Topological Order
//
//  Created by Aaron on 2019/6/9.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,n,m,k,in[1010],flag = 0;//n个顶点m条边 in表示入度,k表示要判断的数量
    scanf("%d %d",&n,&m);
    vector<int> v[1010];
    //存储一个有向图
    for (int i = 0; i<m; i++) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);//a指向b
        in[b]++;//b顶点入度加一
    }
    scanf("%d",&k);
    for (int i = 0; i<k; i++) {
        int judge =1;
        vector<int> tin(in,in+n+1);
        for (int j = 0; j<n; j++) {
            scanf("%d",&a);
            //判断a顶点的入度
            if (tin[a] != 0) {
                judge = 0;
            }
            //a顶点中所有到达的顶点的度减一
            for (int it : v[a]) {
                tin[it]--;
            }
        }
        if(judge == 1) continue;
        printf("%s%d",flag==1 ? " ":"",i);
        flag = 1;
    }

   
    
    return 0;
}
