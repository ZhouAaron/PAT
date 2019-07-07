//
//  main.cpp
//  PAT 1149 Dangerous Goods Packaging
//
//  Created by Aaron on 5/9/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,k,t1,t2;
    scanf("%d %d",&n,&k);
    //利用map与vector的混用，可以实现一对多的关系
    map<int,vector<int>> m;
    for (int i = 0; i<n; i++) {
        scanf("%d %d",&t1,&t2);
        //t1 对应容器 容器中添加元素t2
        //两边都需要互不兼容
        m[t1].push_back(t2);
        m[t2].push_back(t1);
    }
    
    while (k--) {
        int cnt ,flag = 0,a[100000] = {0};
        scanf("%d",&cnt);
        vector<int> v(cnt);
        for (int i = 0; i<cnt; i++) {
            scanf("%d",&v[i]);
            //将a数组中v[i]的位置置1
            a[v[i]] = 1;
        }
        for (int i = 0; i<v.size(); i++) {
            //m映射中v【i】所在的映射的元素数量
            for(int j = 0;j<m[v[i]].size();j++){
//                printf("----%d\n",m[v[i]].size());
                //a数组中m映射的v容器里的第j个元素
            if (a[m[v[i]][j]] == 1)
                flag = 1;
            }
            
        }
        printf("%s\n",flag ? "No":"Yes");
    }
    return 0;
}
