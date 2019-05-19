//
//  main.cpp
//  PAT A1076 Forwards on Weibo
//
//  Created by Aaron on 5/19/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>

#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1010;
struct Node{
    int id;
    int layer;
};
vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};
int BFS(int s,int L){
    int numForward = 0;//转发数
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for (int i = 0; i<Adj[u].size(); i++) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if (inq[next.id] == false && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}


int main(int argc, const char * argv[]) {
    Node user;
    int n,L,numFollow,idFollow;
    scanf("%d%d",&n,&L);
    for (int i = 1; i<=n; i++) {
        user.id = i;
        scanf("%d",&numFollow);
        for (int j = 0; j<numFollow; j++) {
            scanf("%d",&idFollow);
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery ,s;
    scanf("%d",&numQuery);
    for (int i = 0; i<numQuery; i++) {
        memset(inq, false, sizeof(inq));
        scanf("%d",&s);
        int numForward = BFS(s, L);
        printf("%d\n",numForward);
    }
    return 0;
}
