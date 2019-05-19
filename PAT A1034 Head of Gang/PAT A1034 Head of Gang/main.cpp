//
//  main.cpp
//  PAT A1034 Head of Gang
//
//  Created by Aaron on 5/18/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 10000000000;
map<int,string> intToString;
map<string,int> stringToInt;
map<string,int> Gang;
int G[maxn][maxn] = {0},weight[maxn] = {0};
int n,k,numPerson = 0;
bool vis[maxn] = {false};

//DFS函数访问单个连通块，nowVisit为当前访问的编号
//head为头目，numMember为成员编号，totalValue为连通块的总边权
void DFS(int nowVisit,int &head,int &numMember,int&totalValue){
    numMember++;//成员人数加一
    vis[nowVisit] = true;//标记nowVisit已访问
    if (weight[nowVisit] > weight[head]) {
        head = nowVisit;//当前访问节点的点权大于头目的点权，则更新头目
    }
    //枚举所有人
    for (int i = 0; i<numPerson; i++) {
        if (G[nowVisit][i] > 0) {//如果nowVisit能到达
            totalValue += G[nowVisit][i];//连通块的总边权增加该边权
            G[nowVisit][i] = G[i][nowVisit] = 0;//删除这条边，防止回头
            if (vis[i] == false) {//如果i为被访问，则递归访问i
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

//DFSTrave函数遍历整个图，获取每个连通块的信息
void DFSTrave(){
    for (int i = 0; i<numPerson; i++) {
        if (vis[i] == false) {
            int head = i,numMember = 0,totalValue = 0;//头目，成员数，总边权
            DFS(i, head, numMember, totalValue);//遍历i所在的连通块
            if (numMember > 2 && totalValue > k) {//成员数大于2且总边权大于k
                //head人数为numMember
                Gang[intToString[head]] = numMember;
            }
        }
    }
}
//change函数返回姓名str对应的编号
int change(string str){
    //如果str已经出现过
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];//返回编号
    }
    else{
        stringToInt[str] = numPerson;//str的编号为numPerson
        intToString[numPerson] = str;//numPerson对应str
        return numPerson++;//总人数加一
    }
}

int main(int argc, const char * argv[]) {
    int w;
    string str1,str2;
    cin>>n>>k;
    for (int i = 0; i<n; i++) {
        cin>>str1>>str2>>w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    //gang的个数
    cout<<Gang.size()<<endl;//遍历所有gang
    map<string,int>::iterator it;
    for (it = Gang.begin(); it!=Gang.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
