//
//  main.cpp
//  进制转换
//
//  Created by Aaron on 5/7/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
//十进制转二进制
void printBinary(const unsigned int val){
    for (int i = 16; i>=0; i--) {
        if (val&(1<<i)) {
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
}

int main(int argc, const char * argv[]) {
    printBinary(1024);
    return 0;
}

