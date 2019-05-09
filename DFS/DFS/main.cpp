//
//  main.cpp
//  DFS
//
//  Created by Aaron on 5/8/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
const int maxn = 30;
int n ,V,maxValue = 0;//物品数年，背包容量V，最大价值maxValue
int w[maxn],c[maxn];//w为每件物品的重量， c为每件物品的价值
//DEF，index为当前处理的物品编号
//sumW，sumC分别为当前总重量和当前总价值
void DFS(int index,int sumW,int sumC){
    if (index == n) {//已经完成对n件物品的选择（死胡同）
        if (sumW <= V && sumC>maxValue) {
            //当当前总重量小于背包容量且背包里的价值大于之前物品最大价值时
            maxValue = sumC;
//            更新最大价值
        }
        return;
    }
    DFS(index + 1, sumW, sumC);//不选第index件物品
    //选择第index件物品
    DFS(index + 1, sumW + w[index], sumC + c[index]);
    
}
//深度优先搜索改进
void DFS1(int index , int sumW,int sumC){
    if (index == n) {
        return;
    }
    //不选第index件物品
    DFS1(index + 1, sumW, sumC);
    //当物品重量小于背包容量时
    if (sumW + w[index]<=V) {
        //当物品价值加上下一个物品价值大于最大价值时
        if (sumC + c[index]>maxValue) {
            maxValue = sumC + c[index];
        }
        DFS1(index + 1, sumW+w[index], sumC+c[index]);
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&V);
    for (int i = 0; i<n; i++) {
        scanf("%d",&w[i]);
    }
    for (int i = 0; i<n; i++) {
        scanf("%d",&c[i]);
    }
    DFS(0, 0, 0);//初始化
    printf("%d\n",maxValue);
    return 0;
}
