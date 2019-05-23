//
//  main.cpp
//  拓扑排序
//
//  Created by Aaron on 5/23/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXV = 100;

vector <int> G[MAXV];
int n,m,inDegree[MAXV];
bool topologicalSort(){
    int num = 0;
    queue<int> q;
    for (int i = 0; i<n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i<G[u].size(); i++) {
            int v = G[u][i];
            inDegree[i]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
        G[u].clear();
        num++;
    }
    if (num == n) {
        return true;
    }else return false;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
