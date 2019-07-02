//
//  main.cpp
//  PAT 1047 Student List for Course
//
//  Created by Aaron on 2019/6/29.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 400010;
const int K = 2501;
char name[N][5];
vector<int> course[K];
bool cmp(int a,int b){
    return strcmp(name[a], name[b]) < 0;
}
int main(int argc, const char * argv[]) {
    int n,k;
    int courseID,c;
    scanf("%d %d",&n,&k);
    for (int i = 0; i<n; i++) {
        scanf("%s %d",&name[i],&c);
        for (int j = 0; j<c; j++) {
            scanf("%d",&courseID);
            course[courseID].push_back(i);
        }
    }
    for (int i = 1; i<=k; i++) {
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (int j =0; j<course[i].size(); j++) {
            printf("%s\n",name[course[i][j]]);
        }
    }
    return 0;
}
