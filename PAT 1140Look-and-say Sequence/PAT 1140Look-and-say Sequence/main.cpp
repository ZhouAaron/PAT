//
//  main.cpp
//  PAT 1140Look-and-say Sequence
//
//  Created by Aaron on 6/3/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    int n,j;
    cin>>s>>n;
    for (int cnt = 1; cnt<n; cnt++) {
        string t;
        for ( int i = 0; i<s.length(); i=j) {
            for (j = i; j<s.length() && s[j] == s[i]; j++);
               t += s[i] + to_string(j - i);
            
        }
        s = t;
    }
    cout<<s;
    return 0;
}
