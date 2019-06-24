//
//  main.cpp
//  PAT A1116 Come on！Let's C
//
//  Created by Aaron on 2019/6/23.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <set>
#include <cmath>
using namespace std;
const int maxn = 10000;
int ran[maxn];
bool isPrime(int a){
    if (a<= 1) {
        return false;
    }
    int Sqrt = sqrt((double)a);
    for ( int i = 2; i<=Sqrt; i++) {
        if (a%i == 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n,k;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        int id;
        scanf("%d",&id);
        ran[id] = i+1;
    }
    scanf("%d",&k);
    set<int> ass;
    for (int i = 0; i<k; i++) {
        int m;
        scanf("%d",&m);
        if (ran[m] == 0) {
            printf("%.4d: Are you kidding?\n",m);
            continue;
        }
        if (ass.find(m) == ass.end()) {
            ass.insert(m);
        }else{
            printf("%.4d: Checked\n",m);
            continue;
        }
        if (ran[m] == 1) {
            printf("%.4d: Mystery Award\n",m);
        }else if (isPrime(ran[m])){
            printf("%.4d: Minion\n",m);
        }else{
            printf("%.4d: Chocolate\n",m);
        }
    }
    return 0;
}
