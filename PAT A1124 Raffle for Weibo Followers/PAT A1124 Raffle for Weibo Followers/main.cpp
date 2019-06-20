//
//  main.cpp
//  PAT A1124 Raffle for Weibo Followers
//
//  Created by Aaron on 2019/6/15.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    int M,N,S;
    scanf("%d %d %d",&M,&N,&S);
    map<string, int> map1;
    bool flag = false;
    string str;
    for (int i = 1; i<=M; i++) {
        cin>>str;
        if (map1[str] == 1) {
            S = S+1;
        }
        if (i == S && map1[str] == 0) {
            map1[str] = 1;
            flag = true;
            S = N+S;
            cout<<str<<endl;
        }
    }
    if (flag == false) {
        cout<<"Keep going...";
    }
    return 0;
}
