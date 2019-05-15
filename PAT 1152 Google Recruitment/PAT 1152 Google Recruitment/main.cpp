//
//  main.cpp
//  PAT 1152 Google Recruitment
//
//  Created by Aaron on 5/14/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
bool isPrime(int n){
    if (n==0||n==1) {
        return false;
    }for (int i = 2; i*i <=n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int l,k;
    string s1;
    cin>>l>>k>>s1;
    for (int i = 0; i<=l-k; i++) {
        string t = s1.substr(i,k);
        int num = stoi(t);
        if (isPrime(num)) {
            cout<<t;
            return 0;
        }
    }
    cout<<"404\n";
    return 0;
}
