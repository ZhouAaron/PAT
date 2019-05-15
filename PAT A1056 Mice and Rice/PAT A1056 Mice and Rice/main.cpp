//
//  main.cpp
//  PAT A1056 Mice and Rice
//
//  Created by Aaron on 5/12/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse{//老鼠
    int weight;//质量
    int rank;//排名
}mouse[maxn];
int main(int argc, const char * argv[]) {
    int NP,NG,order;
    scanf("%d%d",&NP,&NG);
    for (int i = 0; i<NP; i++) {
        scanf("%d",&mouse[i].weight);
    }
    queue<int> q;
    for (int i = 0; i<NP; i++) {
        scanf("%d",&order);
        q.push(order);
    }
    int temp = NP,group;
    while (q.size() != 1) {
        if (temp % NG == 0) {
            group = temp/NG;
        }else{
            group = temp/NG + 1;
        }
        //枚举每一组，选出该组中质量最大的老鼠
        for ( int i = 0; i<group; i++) {
            int k = q.front() ;//存放该组中质量最大的老鼠
            for (int j = 0; j<NG; j++) {
                //判断最后一组老鼠数量不足中，退出循环
                if (i*NG + j >= temp) {
                    break;
                }
                //队首老鼠编号
                int front = q.front();
                //当这个组中的现在所在队列的首元素大于这个组中当前质量最大的老鼠时，将当前质量最大的老鼠改为现在所在队列的第一个老鼠
                if (mouse[front].weight > mouse[k].weight) {
                    k = front;
                }
                //这轮老师排名为group+1
                //每一组比较之后，这组的排名都是一样的，但是由于后面又将最大的质量的老鼠又进入了队列 所以这组中最大的老鼠的排名将会改变
                //由于每组晋级一个老鼠，所以当前没有晋级的老鼠的排名都为group+1
                mouse[front].rank = group + 1;
                q.pop();//出队这个老鼠
            }
            q.push(k);
        }
        temp = group;
    }
    //当队列中只剩一只老鼠的时候，跳出了循环，并没有对这只老鼠进行排名，所以要将老鼠的排名设置为1
    mouse[q.front()].rank = 1;
    for (int i = 0; i<NP; i++) {
        printf("%d",mouse[i].rank);
        if (i<NP-1) {
            printf(" ");
        }
    }
    
    return 0;
}
