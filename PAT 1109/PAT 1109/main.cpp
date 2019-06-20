//
//  main.cpp
//  PAT 1109
//
//  Created by Aaron on 6/2/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct node{
    int height;
    string name;
};
bool cmp(node a, node b){
    return a.height != b.height ? a.height >b.height : a.name < b.name;
}
int main(int argc, const char * argv[]) {
    int n,k,m;//n个人m行
    scanf("%d %d",&n,&k);
    vector<node> stu(n);
    for (int i = 0; i<n; i++) {
        cin>>stu[i].name;
        scanf("%d",&stu[i].height);
    }
    sort(stu.begin(), stu.end(), cmp);
    int t = 0,row = k;
    while (row) {
        if (row == k) {
            m = n- n / k * (k-1);
        }
        else{
            m = n / k;
        }
        vector<string> ans(m);
        ans[m/2] = stu[t].name;
        //左边一列
        int j = m / 2 - 1;
        for (int i = t + 1; i<t+m; i = i+2) {
            ans[j--] = stu[i].name;
        }
        //右边一列
        j = m / 2 + 1;
        for (int i = t + 2; i< t + m; i = i + 2 ) {
            ans[j++] = stu[i].name;
        }
        cout<<ans[0];
        for (int i = 1; i<m; i++) {
            cout<<" "<<ans[i];
        }
        cout<<endl;
        t = t + m;
        row--;
    }
    
    return 0;
}
