//
//  main.cpp
//  PAT 1153 Decode Registration Card of PAT
//
//  Created by Aaron on 5/28/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
const int maxn = 10000;
const int RES = 100;
struct CARD{
    string str;
    int num;
}card[maxn];
struct CASE{
    int term;
    string str;
}Mcase[RES];
bool cmp(CARD a, CARD b){
    return <#expression#>
}
void quiries(CASE a, CASE b){
    if (a.term == 1) {
        
    }
}
int main(int argc, const char * argv[]) {
    int n,m;//n为card数，m位查询数
    scanf("%d %d",&n,&m);
    //Input
    for (int i = 0; i<n; i++) {
        CARD temp ;
        string str;
        int a;
        cin>>str>>a;
        temp.str = str;
        temp.num = a;
        card[i] = temp;
    }
    for (int i = 0; i<m; i++) {
        int a ;
        string str;
        cin>>a>>str;
        CASE temp ;
        temp.term = a;
        temp.str = str;
        Mcase[i] = temp;
    }
    
    
    return 0;
}
