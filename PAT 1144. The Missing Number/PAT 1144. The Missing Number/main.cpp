//
//  main.cpp
//  PAT 1144. The Missing Number
//
//  Created by Aaron on 6/3/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,a;
    scanf("%d",&n);
    map<int, int> m;
    for (int i = 0; i<n; i++) {
        scanf("%d",&a);
        m[a]++;
    }
    int ans = 1;
    while (ans) {
        if (m[ans]==0) {
            break;
        }
        ans++;
    }
    printf("%d",ans);
    return 0;
}
