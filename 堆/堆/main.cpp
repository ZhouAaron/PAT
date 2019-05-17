//
//  main.cpp
//  堆
//
//  Created by Aaron on 5/17/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;
//heap为堆，n为元素个数
int heap[maxn] ,n = 10;
//对heap数组在[low，high]范围进行向下调整

//其中low为欲调整节点的数组下标，high一般为堆堆最后一个元素的数组下标
void downAdjust(int low, int high){
    /*
     由于堆是一颗完全二叉树，所以i = low，j= i*2
     完全二叉树：除了下面一层外，其余层的节点个数都达到了当层能达到的最大节点数，且下面一层只从左至右连续存在若干节点
     */
    int i = low,j = i*2;//i为欲调整节点，j为其左孩子
    while (j<=high) {//存在孩子节点
        //如果右孩子存在，且右孩子的值大于左孩子
        if (j+1 <= high&& heap[j+1] >heap[j]) {
            j = j+1;
        }
        //如果孩子中最大的权值比欲调整的结点i大
        if (heap[j] >heap[i]) {
            swap(heap[j],heap[i]);//交换最大权值的孩子与欲调整节点i
            i = j;//保持i为欲调整节点，j为i的左孩子
            j = i*2;
        }else{//孩子的权值比欲调整节点i小，调整结束
            break;
        }
    }
}

//建堆
/*
 假设序列中元素的个数为n，由于完全二叉树的叶子节点个数为[n/2],因此在数组下标在[1,[n/2]]范围内的节点都是非叶子节点，于是可以从[n/2]号为开始倒着枚举节点
 倒着是因为每次调整完一个节点之后，当前子树中权值最大的节点就会处在根节点的位置，这样当遍历到其父亲节点是，就可以h直接使用这个结果
 */
void createHeap(){
    for (int i = n/2; i>=1; i--) {
        downAdjust(i, n);
    }
}

//删除堆顶元素
void deleteTop(){
    heap[1] = heap[n--];//用最后一个元素覆盖堆顶元素，并让元素个数-1
    downAdjust(1, n);//向下调整堆顶元素
}
//对heap[low,high]范围进行向上调整
void upAdjust(int low,int high){
    //i为欲调整结点，j为其父亲
    int i = high,j = i/2;
    //当其父亲在范围内的时候
    while (j>=low) {
        //如果父亲的权值小于欲调整结点i的权值，那么就叫交换两个节点的权值
        if (heap[j] <heap[i]) {
            swap(heap[j], heap[i]);
            i = j;//保持i为欲调整的节点，j为i 的父亲
            j = i/2;
        }
        else{
            break;//父亲权值比欲调整节点i的权值大，调整结束
        }
    }
}
//添加元素
void insert(int x){
    heap[++n] = x;
    upAdjust(1, n);
}

//堆排序
void heapSort(){
    createHeap();
    for (int i = n; i>1; i--) {
        swap(heap[i], heap[1]);
        downAdjust(1, i-1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
