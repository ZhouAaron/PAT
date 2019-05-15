//
//  main.cpp
//  PAT A1051 Pop Sequence
//
//  Created by Aaron on 5/11/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];//保存题目给定的出栈序列
stack<int> st;//定义栈，用以存放int型数据
int main(int argc, const char * argv[]) {
    int M,N,K;//栈的容量，给出数据长度，例子数量
    scanf("%d %d %d",&M,&N,&K);
    while (K--) {
        //清空栈
        while (!st.empty()) {
            st.pop();//使用pop（）函数和top（）函数之前必须先使用empty（）函数判断栈是否为空
        }
        //读入数据
        for (int i = 1; i<=N; i++) {
            scanf("%d",&arr[i]);
        }
        int current = 1;
        int flag = true;
        //进栈顺序为1234567
        for (int i = 1; i<=N; i++) {
            st.push(i);
            if (st.size() > M) {
                flag = false;
                break;
            }
            /*当栈不为空的时候，并且栈顶= 数组中的元素时（即测试序列第i个元素时）即可出栈
             否则跳过这个循环，继续进栈
             */
            while (!st.empty()&& st.top() == arr[current]) {
                st.pop();
                current++;
            }
        }
        if (st.empty() && flag == true) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    
    return 0;
}

