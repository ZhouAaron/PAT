//
//  main.cpp
//  PAT 1148 werewolf
//
//  Created by Aaron on 5/26/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; i++) {
        cin>>v[i];
    }
    
    for (int i = 1; i<=n; i++) {
        for (int j = i+1; j<=n; j++) {
            vector<int> a(n+1,1);//初始化数组 1表示是人类
            //i和j表示是狼人
            a[i] = a[j] = -1;
            vector<int>lie;//存放说谎的人
            for (int k = 1; k<=n; k++) {
                /*
                 v[k] 1.如果说谎，假设v[k]指代的人是狼人，那么由于是假话，说明这个v[k]是正数， 此时由于指代的是狼人，那么a数组中v[k]代表的是-1
                 所以相乘 小于0
                 2.假设v[k] 指代的是好人，在说谎的条件下,v[k]其实是狼人，那么在a[k]当中表示-1
                 相乘小于0
                 3. 如果没有说谎，说v[k]是狼人，那么v[k] 为负数，a[v[k]]为负数则跳过这个if语句
                 如果说v[k]不是狼人，那么v[k]为正数a[v[k]]为正数,同样跳过这个语句
                 */
                if (v[k] * a[abs(v[k])] < 0) {
                    lie.push_back(k);
                }}
                //最后撒谎人总人数为2并且需要一个人为好人一个人为狼人
                if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                    cout<<i<<" "<<j;
                    return 0;
                
            }
        }
    }
    cout<<"No Solution";
    return 0;
}
