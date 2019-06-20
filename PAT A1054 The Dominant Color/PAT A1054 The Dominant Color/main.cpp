//
//  main.cpp
//  PAT A1054 The Dominant Color
//
//  Created by Aaron on 2019/6/14.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int N,M;//N*M
    scanf("%d %d",&N,&M);
    map<int,int> arr;
    int half = N*M/2;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            int temp ;
            scanf("%d",&temp);
            arr[temp]++;
            if (arr[temp]>half) {
                printf("%d",temp);
                return 0;
            }
        }
    }
    return 0;
}
