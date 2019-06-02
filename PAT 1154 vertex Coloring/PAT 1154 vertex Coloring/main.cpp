//
//  main.cpp
//  PAT 1154 vertex Coloring
//
//  Created by Aaron on 5/31/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node{
    int t1,t2;
};
int main(int argc, const char * argv[]) {
    int n,m;//n个顶点，m条边
    scanf("%d %d",&n,&m);
    vector<node> v(m);
    for (int i = 0; i<m; i++) {
        scanf("%d %d",&v[i].t1,&v[i].t2);
    }
    int k;//k个例子
    scanf("%d",&k);
    while (k--) {
        int a[10009] = {0};
        bool flag = true;
        set<int> s;
        //用a数组存储顶点所对应的颜色
        for (int i = 0; i<n; i++) {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        for (int i = 0; i<m; i++) {
            //v代表一条边 t1和t2代表这条边的两个顶点
        //用vi的顶点作为数组的index 当索引所指向的值相等时，就代表颜色相等。
            //当a数组中 顶点所对应的颜色相等时则退出循环
            if (a[v[i].t1] == a[v[i].t2]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d-coloring\n",s.size());
        }else{
            printf("No\n");
        }
    }
    return 0;
    


}
