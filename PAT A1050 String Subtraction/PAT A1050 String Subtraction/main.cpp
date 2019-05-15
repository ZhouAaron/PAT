//
//  main.cpp
//  PAT A1050 String Subtraction
//
//  Created by Aaron on 5/13/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int max_len = 10005;
char a[max_len], b[max_len];
bool hashtable[128];

int main(int argc, const char * argv[]) {
    gets(a);
    gets(b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    for (int i = 0; i<lenB; i++) {
        hashtable[b[i]] = true;
    }
    for (int i = 0; i<lenA; i++) {
        if (hashtable[a[i]] == false ) {
            printf("%c",a[i]);
        }
    }
    return 0;
}
