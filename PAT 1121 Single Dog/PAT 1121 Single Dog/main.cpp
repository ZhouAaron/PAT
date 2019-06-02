//
//  main.cpp
//  PAT 1121 Single Dog
//
//  Created by Aaron on 5/30/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> x;
int main(int argc, const char * argv[]) {
    int n,a,b;
    scanf("%d",&n);
    vector<int> couple(100000);
    for (int i = 0; i<100000; i++) {
        couple[i] = -1;
    }
    for (int i = 0; i<n; i++) {
        scanf("%d %d", &a,&b);
        couple[a] = b;
        couple[b] = a;
    }
    
    int m;
    scanf("%d",&m);
    vector<int> patry(m),isExist(100000);
    
    for (int i = 0; i<m; i++) {
        scanf("%d",&patry[i]);
        if (couple[patry[i]] != -1) {
            isExist[couple[patry[i]]] = 1;
        }
    }
    
    set<int> s;
    for (int i  = 0; i<m; i++) {
        if (!isExist[patry[i]]) {
            s.insert(patry[i]);
        }
    }
    printf("%d\n",s.size());
    for (auto it = s.begin(); it!=s.end(); it++) {
        if (it!=s.begin()) {
            printf(" ");
        }
        printf("%05d",*it);
    }
    return 0;
}
