//
//  main.cpp
//  PAT 1042 Shuffling Machine
//
//  Created by Aaron on 2019/6/26.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    vector<int> v(55);
    vector<int> ans(55);
    vector<int> end(55);
//    map<string, int> mm;
    for (int i = 1; i<=54; i++) {
        end[i] = i;
        scanf("%d",&ans[i]);
    }
    for (int i = 0;i<n ; i++) {
        for (int j = 1; j<55; j++) {
//            v[j] = v[ans[j]];
            v[j] = end[j];
        }
        for (int k = 1; k<55; k++) {
            end[ans[k]] = v[k];
        }
    }
    char c[6] = {"SHCDJ"};
    for (int i = 1; i<55; i++) {
        end[i] = end[i]-1;
        printf("%c%d",c[end[i]/13],end[i]%13+1);
        if (i<54) {
            printf(" ");
        }
    }
    return 0;
}
