//
//  main.cpp
//  PAT 1012 The Best Rank
//
//  Created by Aaron on 5/6/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
using namespace std;
struct STUDENT {
    int id,score[4],rank[4],Best;
}stu[2005];
int exist[1000000],flag = -1;
bool cmp1(STUDENT a, STUDENT b){
    return a.score[flag] > b.score[flag];
}
int main(int argc, const char * argv[]) {
    int n,m,id;
    scanf("%d %d",&n,&m);
    for (int i = 0; i<n; i++) {
        scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2]+stu[i].score[3]) / 3.0+0.5;
    }
    for (flag = 0; flag<=3; flag++) {
        sort(stu,stu+n,cmp1);
        stu[0].rank[flag] = 1;
        for (int i = 1; i<n; i++) {
            stu[i].rank[flag] = i+1;
            if (stu[i].score[flag] == stu[i-1].score[flag]) {
                stu[i].rank[flag] = stu[i-1].rank[flag];
            }
        }
    }

    for (int i = 0; i<n; i++) {
        exist[stu[i].id] = i+1;
        stu[i].Best = 0;
        int minn = stu[i].rank[0];
        for (int j = 1; j<=3; j++) {
            if (stu[i].rank[j]<minn) {
                minn = stu[i].rank[j];
                stu[i].Best = j;
            }
        }
    }
    char c[5] = {'A','C','M','E'};
    for (int i = 0; i<m; i++) {
        scanf("%d",&id);
        int temp = exist[id];
        if (temp) {
            int best = stu[temp-1].Best;
            printf("%d %c\n",stu[temp-1].rank[best],c[best]);
        }else{
            printf("N/A\n");
        }
    }
    

    return 0;
}
