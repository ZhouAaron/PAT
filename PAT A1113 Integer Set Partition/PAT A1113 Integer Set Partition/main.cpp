//
//  main.cpp
//  PAT A1113 Integer Set Partition
//
//  Created by Aaron on 2019/6/20.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
int main(int argc, const char * argv[]) {
    int n,sum = 0;
    int halfSum = 0;
    scanf("%d",&n);
    vector<int> v(n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i<n/2; i++) {
        halfSum += v[i];
    }
    printf("%d %d",n%2,sum-2*halfSum);
    return 0;
}
