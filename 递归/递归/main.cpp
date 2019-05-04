//
//  main.cpp
//  递归
//
//  Created by Aaron on 5/3/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
struct mooncake {
    double store;
    double sell;
    double price;
}maxn[1010];
bool cmp(mooncake a, mooncake b){
    return a.price>b.price;
}
int main(int argc, const char * argv[]) {
    int n;
    double D;
    scanf("%d %lf",&n,&D);
    for ( int i = 0; i<n; i++) {
        scanf("%lf",&maxn[i].store);
    }
    for (int i = 0; i<n; i++) {
        scanf("%lf",&maxn[i].sell);
        maxn[i].price = maxn[i].sell/maxn[i].store;
    }
    sort(maxn, maxn+n, cmp);
    double ans = 0;
    for (int i = 0; i<n; i++) {
        if (maxn[i].store<D) {
            D -= maxn[i].store;
            ans += maxn[i].sell;
        }else{
            ans += maxn[i].price *D;
            break;
        }
    }
    prev("%.2f",ans);
    
    return 0;
}
