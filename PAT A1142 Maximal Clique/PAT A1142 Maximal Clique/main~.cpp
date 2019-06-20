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
    int a,b,Nv,Ne;//Nv代表点数Ne代表边数
    scanf("%d %d",&Nv,&Ne);
    vector<int> v[Nv];
    for (int i = 0; i<Ne; i++) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d",&a);
    for (int i = 0; i<a; i++) {
        scanf("%d",&b);
        int isClique = 0;
        for (int j = 0; j<b; j++) {
            <#statements#>
        }
    }
    return 0;
}
