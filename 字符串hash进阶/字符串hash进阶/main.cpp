//
//  main.cpp
//  字符串hash进阶
//
//  Created by Aaron on 2019/6/9.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
const int P = 10000019;
vector<int> ans;

//给出N个只有小写字母的字符串，求其中不同字符串的个数

//字符串hash
long long hashFunc(string str){
    long long H = 0;
    for (int i = 0; i<str.length(); i++) {
        H = (H * P + str[i] - 'a')%MOD;
    }
    return H;
}
int main(int argc, const char * argv[]) {
    string str;
    while (getline(cin, str),str != "#") {
        long long id = hashFunc(str);
        ans.push_back(id);
    }
    sort(ans.begin(), ans.end());
    int count = 0;
    for (int i = 0; i<ans.size(); i++) {
        if (i== 0||ans[i]!=ans[i-1]) {
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
