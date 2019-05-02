//
//  main.cpp
//  PAT A025 PAT Ranking
//
//  Created by 周杰 on 2019/5/2.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct Student {
    char id[15];
    int score;
    int rank;
    int location_number;
}stu[300];
bool cmp(Student a , Student b){
    if (a.score != b.score) {
        return a.score > b.score;
    }else{
        return strcmp(a.id, b.id)<0;
        
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,num = 0;
    int k ;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++) {
        
        scanf("%d",&k);
        for (int j = 0; j<k; j++) {
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].location_number = i;
            num++;
        }
        sort(stu + num -k, stu+num, cmp);
        
        stu[num-k].rank = 1;
        for ( int j = num - k +1; j<num; j++) {
            if (stu[j].score== stu[j-1].score) {
                stu[j].rank = stu[j-1].rank;
            }
            else{
                stu[j].rank = j + 1- (num -k);
            }
        }
    }
    printf("%d\n",num);
    sort(stu, stu+num, cmp);
    int r = 1;
    for (int i = 0; i<num;i++) {
        if (stu[i].score != stu[i-1].score&&i>0) {
            r = i+1;
        }
        printf("%s ",stu[i].id);
        printf("%d %d %d\n",r,stu[i].location_number,stu[i].rank);
        
    }
    
    return 0;
}

