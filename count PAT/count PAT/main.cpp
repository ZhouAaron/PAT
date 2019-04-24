//
//  main.cpp
//  count PAT
//
//  Created by 周杰 on 2019/4/23.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
//#include <string>
using namespace std;
int mod = 1000000007;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s1;
    cin>>s1;
    int p=0,pa=0,pat=0;
    for (int i = 0; i<s1.length();i++) {
        if(s1[i]=='P') {
            p++;
        }if (s1[i]=='A') {
            pa = (p+pa)%mod;
        }if (s1[i]=='T') {
            pat = (pat+pa)%mod;
        }
    }
    cout<<pat<<endl;
    
    return 0;
}
