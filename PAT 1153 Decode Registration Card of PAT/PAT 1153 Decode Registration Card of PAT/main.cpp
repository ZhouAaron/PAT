//
//  main.cpp
//  test
//
//  Created by Aaron on 2019/6/17.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    string str;
    int value;
};
bool cmp (const node &a, const node &b){
    return a.value!=b.value ? a.value > b.value : a.str< b.str;
}
int main(int argc, const char * argv[]) {
    int n,m,k;
    string s;
    scanf("%d %d",&n,&m);
    vector<node> v(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i].str>>v[i].value;
    }
    for (int i = 1; i<=m; i++) {
        cin>>k>>s;
        int cnt = 0,sum = 0;
        printf("Case %d: %d %s\n",i,k,s.c_str());
        vector<node> ans;
        if (k == 1) {
            for (int j = 0; j<n; j++) {
                if (v[j].str[0] == s[0]) {
                    ans.push_back(v[j]);
                }
            }
        }else if (k == 2){
            for (int j = 0; j<n; j++) {
                if (v[j].str.substr(1,3) == s) {
                    cnt++;
                    sum += v[j].value;
                }
            }
            if (cnt != 0) {
                printf("%d %d\n",cnt,sum);
            }
        }else if (k == 3 ){
            unordered_map<string, int> mm;
            for (int j = 0; j<n; j++) {
                if (v[j].str.substr(4,6) == s) {
                    mm[v[j].str.substr(1,3)] ++;
                }
            }
            for (auto it  : mm) {
                ans.push_back({it.first,it.second});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int j = 0; j<ans.size(); j++) {
            printf("%s %d\n",ans[j].str.c_str(),ans[j].value);
        }
        if (((k == 1 ||k == 3) && ans.size() == 0) || (k == 2 && cnt == 0)) {
            printf("NA\n");
        }
    }
    return 0;
}
