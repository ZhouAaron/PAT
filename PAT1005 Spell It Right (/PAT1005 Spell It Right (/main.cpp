//
//  main.cpp
//  PAT1005 Spell It Right (
//
//  Created by Aaron on 5/7/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int sum = 0;
    for (int i = 0; i<s.length(); i++) {
        sum += (s[i]-'0');
    }
    string array[10] = {"zero","one","two","three","four","five","six","seven","eight","nine",};
    string a = to_string(sum);
    cout<<array[a[0]-'0'];
    for ( int i = 1; i<a.length(); i++) {
        int n = a[i]-'0';
        cout<<" "<<array[n];
    }
    return 0;
}
