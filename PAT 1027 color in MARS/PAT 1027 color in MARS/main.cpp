//
//  main.cpp
//  PAT 1027 color in MARS
//
//  Created by Aaron on 5/7/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int a,b,c,n,m,q;
    int s,d,f;
    char array[] =
    {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
   
    scanf("%d %d %d",&a,&b,&c);
    s = a/13;
    n = a%13;
    d = b/13;
    m = b%13;
    f = c/13;
    q = c%13;
    printf("#%c%c%c%c%c%c",array[s],array[n],array[d],array[m],array[f],array[q]);
    return 0;
}
