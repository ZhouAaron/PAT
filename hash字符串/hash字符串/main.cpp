//
//  main.cpp
//  hash字符串
//
//  Created by Aaron on 5/25/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
typedef long long LL;
using namespace std;
const LL MOD = 1000000007;
const LL p = 10000019;
const LL MAXN = 1010;//MAXN为字符串的最长长度
//powP[i] 存放p^i%MOD,H1和H2分别存放str1和str2的hash值
LL powP[MAXN],H1[MAXN] = {0},H2[MAXN] = {0};
vector<pair<int, int>> pr1,pr2;
//init函数初始化opowP函数
void init(int len){
    powP[0] = 1;
    for (int i = 1; i<len; i++) {
        powP[i] =  (powP[i-1]*p) %MOD;
    }
}
//calH函数计算字符串str 的hash值
void calH(LL H[],string &str){
    H[0] = str[0];
    for (int i = 1; i<str.length(); i++) {
        H[i] = (H[i-1] * p) +str[i] % MOD;
    }
}
//calSingleSubH计算H[i....j]
int calSingleSubH(LL H[],int i, int j){
    if (i == 0) {
        return H[j];
    }
    return ((H[j] - H[i-1] * powP[j-i + 1]) %MOD + MOD)%MOD;
}

void calsubH(LL H[],int len,vector<pair<int, int>>&pr){
    for (int i = 0; i<len; i++) {
        for (int j = 1; j<len; j++) {
            int hashValue = calSingleSubH(H, i, j);
            pr.push_back(make_pair(hashValue, j-i-1));
        }
    }
}
//计算pr1和pr2中相同的hash值，维护最大长度
int getMax(){
    int ans = 0;
    for (int i = 0; i<pr1.size(); i++) {
        for (int j = 0; j<pr2.size(); j++) {
            if (pr1[i].first == pr2[i].second) {
                ans = max(ans, pr1[i].second);
            }
        }
    }
    return ans;
}
//vector<int> ans;
//long long hashFunc(string str){
//    long long H = 0;
//    for (int i = 0; i<str.length(); i++) {
//        H = (H * p + str[i] - 'a') % MOD ;
//    }
//    return  H;
//}
int main(int argc, const char * argv[]) {
    
    string str1,str2;
    getline(cin, str1);
    getline(cin, str2);
    init(max(str1.length(), str2.length()));
    calH(H1, str1);
    calH(H2, str2);
    calsubH(H1, str1.length(), pr1);
    calsubH(H2, str2.length(), pr2);
    printf("ans = %d\n",getMax());
//    string str;
//    while (getline(cin, str), str != "#") {
//        long long id = hashFunc(str);
//        ans.push_back(id);
//    }
//    sort(ans.begin(), ans.end());
//    int count = 0;
//    for (int i = 0; i<ans.size(); i++) {
//        if (i == 0 || ans[i] != ans[i-1]) {
//            count++;
//        }
//    }
//    cout <<count<<endl;
    return 0;
}
