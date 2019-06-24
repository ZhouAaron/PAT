//
//  main.cpp
//  PAT 1117 Eddington Number
//
//  Created by Aaron on 2019/6/22.
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
        scanf("%d",&v[i]);
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    
    for (int i = n-1; i>=0; i--) {
        if (v[i] > cnt) {
            cnt++;
        }
        else{
            break;
        }
    }
    printf("%d",cnt-1);
    return 0;
}
