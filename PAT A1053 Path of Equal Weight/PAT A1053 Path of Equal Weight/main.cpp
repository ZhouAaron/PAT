//
//  main.cpp
//  PAT A1053 Path of Equal Weight
//
//  Created by Aaron on 5/15/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
//节点定义
struct node{
    int weight;
    vector<int> child;
}Node[maxn];
//按节点数据域从大到小排序
bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}
int n,m,S;//节点，边数=非叶子节点的个数，给定的和
int path[maxn];//记录路径
//当前访问的节点时index，numNode为当前路径path上的节点个数
//sum为和
void DFS(int index1, int numNode,int sum){
    //当和大于所给定的值之后，直接返回
    if (sum >S) {
        return;
    }
    //当和sum = s之后先判断当前节点是否时叶子节点
    if (sum == S) {
        if (Node[index1].child.size() != 0) {
            return;
        }
        //到达叶子节点，此时path【】z中存放了一条路径，输出他
        for (int i = 0; i<numNode; i++) {
            printf("%d",Node[path[i]].weight);
            if (i<numNode-1) {
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
        return;
    }
    //循环当前节点子节点的个数
    for (int i = 0; i<Node[index1].child.size(); i++) {
        //结点index的第i的子节点编号
        int child = Node[index1].child[i];
        path[numNode] = child;//将结点child加到路径path的末尾
        DFS(child, numNode+1, sum+Node[child].weight);
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&n,&m,&S);
    for (int i = 0; i<n; i++) {
        scanf("%d",&Node[i].weight);
    }
    int id,k,child;//节点编号
    //建立树的过程
    for (int i = 0 ; i<m; i++) {
        scanf("%d%d",&id,&k);
        for (int j = 0; j<k; j++) {
            scanf("%d",&child);
            //第id个节点有k个子节点，将子节点存放到上一个节点的容器中
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);
    
    return 0;
}
