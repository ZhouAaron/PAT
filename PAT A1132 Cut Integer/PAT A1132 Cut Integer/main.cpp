//
//  main.cpp
//  PAT A1132 Cut Integer
//
//  Created by Aaron on 2019/6/15.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
//#include <cmath>
using namespace std;
int getDigits(int x){
    int a = 0;
    while (x) {
        x = x/10;
        a++;
    }
    return a;
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        int a,b,c,count;
        scanf("%d",&a);
        count = getDigits(a);
        int d=1;
        for (int i = 0; i<count/2; i++) {
            d = 10*d;
        }
        b = a/d;
        c = a%d;
        if ( b*c != 0 && a%(b*c) == 0) {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}
