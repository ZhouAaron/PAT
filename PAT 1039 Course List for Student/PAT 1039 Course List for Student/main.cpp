//
//  main.cpp
//  PAT 1039 Course List for Student
//
//  Created by Aaron on 2019/6/29.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010;
const int M = 26*26*26*10+1;
vector<int> selectCourse[M];
int getID(char name[]){
    int id = 0;
    for (int i = 0; i<3; i++) {
        id = id*26+(name[i] - 'A');
    }
    id = id*10+(name[3]-'0');
    return id;
}
int main(int argc, const char * argv[]) {
    char name[5];
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i<k; i++) {
        int course ,x;
        scanf("%d %d",&course,&x);
        for (int j = 0; j<x; j++) {
            scanf("%s",name);
            int id = getID(name);
            //将学生的id与课程相对应
            selectCourse[id].push_back(course);
        }
    }
    for (int i = 0; i<n; i++) {
        scanf("%s",name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d",name,selectCourse[id].size());
        for (int j = 0; j<selectCourse[id].size(); j++) {
            printf(" %d",selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}
