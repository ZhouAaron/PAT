//
//  main.cpp
//  PAT 1024 Palindromic Number
//
//  Created by Aaron on 5/24/19.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
<<<<<<< HEAD
=======
using namespace std;
>>>>>>> refs/remotes/origin/master
struct bigNum{
    int lens;
    int num[1000];
    bigNum()
    {
        memset(num, 0, sizeof(num));
        lens = 0;
    }
    
};
bigNum change(char c[]){
    bigNum a;
    a.lens = strlen(c);
    for (int i = 0; i<a.lens; i++) {
        a.num[i] = c[a.lens - i - 1] - '0';
    }
    return a;
}
bigNum add(bigNum a, bigNum b){
    bigNum c;
    int carry = 0;
    for (int i = 0; i<a.lens; i++) {
        int temp = a.num[i] + b.num[i] +carry;
        c.num[c.lens++] = temp % 10;
        carry = temp/10;
    }
    if (carry != 0) {
        c.num[c.lens++] = carry;
    }
    return c;
}
<<<<<<< HEAD
//bigNum reverse (bigNum a){
//    bigNum b;
//    for (int i = a.lens -1; i>=0; i--) {
//        b.num[a.lens - 1 -i] = a.num[i];
//    }
//    return b;
//}
=======
bigNum reverse1 (bigNum a){
    bigNum b;
    for (int i = a.lens -1; i>=0; i--) {
        b.num[a.lens - 1 -i] = a.num[i];
    }
    return b;
}
>>>>>>> refs/remotes/origin/master
bool judge(bigNum st){
    int lens = st.lens;
    for (int i = 0; i<lens/2; i++) {
        if (st.num[i] != st.num[lens - i -1]) {
            return false;
        }
    }
    return true;
}
void showArray(bigNum a){
    for (int i = a.lens -1; i>=0; i--) {
        printf("%d",a.num[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    char str1[1000];
<<<<<<< HEAD
    int n;
=======
>>>>>>> refs/remotes/origin/master
    int T,K = 0;
    scanf("%s %d",str1,&T);
    bigNum a = change(str1);
    while (K<T && judge(a) == false) {
        bigNum b = a;
<<<<<<< HEAD
        reverse(b.lens,b.d+b.lens);
    }
=======
//        reverse(b.num, b.num + b.lens);
        b =reverse1(b);
        a = add(a, b);
        K++;
        
    }
    showArray(a);
    printf("%d\n",K);
>>>>>>> refs/remotes/origin/master
//    bigNum b;
//    scanf("%s %d",str1,&n);
//    //一开始就是回文数
//    b = change(str1);
//    if (judge(b)) {
//        showArray(b);
//        printf("%d",n);
//    }
//    bigNum h;
//    bigNum m;
//    int u ;
////    int flag = false;
//    for (int i = 0; i<n; i++) {
//        h = reverse(b);
//        m = add(b, h);
//        if (judge(m)) {
//            u = i;
//            break;
//        }
//    }
//    showArray(m);
//    printf("%d",u+1);
////    while (n--) {
////        h = reverse(b);
////        m = add(b, h);
////        flag = judge(m);
////        if (flag == true) {
////            break;
////        }
////            }
////    for (int i = 0; i<m.lens; i++) {
////        printf("%d\n",m.num[i]);
////
////    }
////    printf("%d\n",n);
    return 0;
}
