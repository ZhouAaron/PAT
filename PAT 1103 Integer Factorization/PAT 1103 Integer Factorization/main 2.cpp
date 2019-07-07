//
//  main.cpp
//  PAT 1103 Integer Factorization
//
//  Created by Aaron on 2019/7/5.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,k,p,maxFacSum = -1;
vector<int> v,ans,tempAns;
//初始化数组，存放p的n次方的值的序列，下标代表次数
void init(){
    int temp = 0,index = 1;
    while (temp<n) {
        v.push_back(temp);
        temp = (index,p);
        index++;
    }
}

void dfs(int index ,int tempSum,int tempK,int facSum){
    //当tempK的值 = k时 也就是加数的个数到达k的时候
    if (tempK == k) {
        //当前的总和是否为n 并且当前质因子的和最大时
        if (tempSum == n && facSum >maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while (index >= 1) {
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum+v[index], tempK+1, facSum + index);
        }
        if (index == 1) {
            return;
        }
        index--;
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&n,&k,&p);
    init();
    tempAns.resize(k);
    dfs(v.size()-1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ",n);
    for (int i = 0; i<ans.size(); i++) {
        if (i!=0) {
            printf(" + ");
        }
        printf("%d^%d",ans[i],p);
    }
    return 0;
}
