//
//  main.cpp
//  PAT B 1001 害死人不偿命的（3n+1）猜想
//
//  Created by 周杰 on 2019/4/11.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int i ;
    int count = 0;
    scanf("%d",&i);
    while (i!=1) {
        if (i %2 == 0) {
            i = i/2;
            count++;
        }else{
            i = (3 * i +1)/2;
            count++;
        }
    }
    printf("%d",count);
    
    return 0;
}
