//
//  main.cpp
//  PAT A1060 Are They Equal
//
//  Created by 周杰 on 2019/4/21.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int n;//有效数字
string deal(string s1,int &e){
    int k = 0;//s的下标
    while (s1[0]=='0'&&s1.length()>0) {
        s1.erase(s1.begin());
    }
    if (s1[0] == '.') {
        s1.erase(s1.begin());
        while (s1[0] == '0' && s1.length()>0) {
            s1.erase(s1.begin());
            e--;
        }
    }else{
        while (k<s1.length()&&s1[k]!='.') {
            k++;
            e++;
        }
        if (k<s1.length()) {
            s1.erase(s1.begin()+k);
        }
    }
    if (s1.length() == 0) {
        e = 0;
    }

    int num = 0;
    k = 0;
    string res;
    while (num < n) {
        if (k<s1.length()) {
            res += s1[k++];
        }else{
            res += '0';
        }
        num ++;
    }
     return res;
}

int main(int argc, const char * argv[]) {
    string s1,s2,s3,s4;
    cin>>n>>s1>>s2;
    int e1 = 0,e2 = 0;
    s3 = deal(s1,e1);
    s4 = deal(s2,e2);
    if (s3 == s4 && e1 == e2) {
        cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
    }else{
        cout<<"NO 0."<<s3<<"*10^"<<e1<<"0."<<s4<<"*10^"<<e2<<endl;
    }
    
    
    return 0;
}
