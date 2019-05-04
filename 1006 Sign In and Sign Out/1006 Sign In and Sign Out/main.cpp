//
//  main.cpp
//  1006 Sign In and Sign Out
//
//  Created by Aaron on 5/3/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main(int argc, const char * argv[]) {

    int n, min_n = INT_MAX, max_n = INT_MIN;
    scanf("%d",&n);
    string unlocked, locked;
    for (int i = 0; i<n; i++) {
        string t;
        cin>>t;
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int tempIN = h1*3600+m1*60+s1;
        int tempOut = h2*3600+m2*60+s2;
        if (tempIN<min_n) {
            min_n = tempIN;
            unlocked = t;
        }if(tempOut > max_n){
            max_n =  tempOut ;
            locked = t;
        }
    }
    cout<<unlocked<<" "<<locked;
    return 0;
}
