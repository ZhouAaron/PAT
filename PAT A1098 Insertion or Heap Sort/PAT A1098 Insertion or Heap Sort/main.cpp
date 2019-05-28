//
//  main.cpp
//  PAT A1098 Insertion or Heap Sort
//
//  Created by Aaron on 5/23/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 110;
int a[MAXN],b[MAXN],c[MAXN];//a是原始数组，b是目标数组，c是暂存数组
int N ;
bool isSame(int A[],int B[]){
    for (int i = 1; i<=N; i++) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}
void showArray (int a[]){
    for (int i = 1; i<=N; i++) {
        printf("%d",a[i]);
        if (i < N) {
            printf(" ");
        }
    }
    printf("\n");
}
bool insertSort(int n){
    bool flag = false;
    for (int i = 2; i<=n; i++) {
//        int temp = c[i],j = i;
//        while (j > 1 && temp < c[j-1]) {
//            c[i] = c[j-1];
//            j--;
//            if (isSame(c, b)) {
//                flag = true;
//            }
//        }
//        c[j] = temp;
        if (i != 2 && isSame(c, b)) {
            flag = true;
        }
        sort(c, c+i+1);
        if (flag == true) {
            return true;
        }
    }
    return false;
}
void downAdjust(int low ,int high){
    int i = low ,j = i * 2;
    while (j <= high) {
        if (j+1<=high && c[j+1]>c[j]) {
            j = j+1;
        }
        if (c[j] > c[i]) {
            swap(c[j],c[i]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}
void creatHeap(){
    bool flag = false;
    for (int i = N/2; i>=1; i--) {
        downAdjust(i, N);//建堆
    }
    for (int i = N; i>1; i--) {
        if (i != N && isSame(c, b)) {
            flag = true;
        }
        swap(c[i], c[1]);
        downAdjust(1, i-1);
        if (flag == true) {
            showArray(c);
            return;
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d",&N);
    for (int i = 1; i<=N; i++) {
        scanf("%d",&a[i]);
        c[i] = a[i];
    }for (int i = 1; i<=N; i++) {
        scanf("%d",&b[i]);
    }
    if (insertSort(N)) {
        printf("Insertion Sort\n");
        showArray(c);
    }else{
        printf("Heap Sort\n");
        for (int i = 1; i<=N; i++) {
            c[i] = a[i];
        }
        creatHeap();
    }
    
    return 0;
}
