//
//  main.cpp
//  PAT 1125 Chain the Ropes
//
//  Created by Aaron on 2019/7/4.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for (int i = 0; i<n; i++) {
        int v2;
        scanf("%d",&v2);
        v[i] = v2;
    }
    sort(v.begin(), v.end());
    int a = v[0];
    for (int i = 1; i<n; i++) {
        a = (a + v[i])/2;
    }
    printf("%d",a);
    return 0;
}

