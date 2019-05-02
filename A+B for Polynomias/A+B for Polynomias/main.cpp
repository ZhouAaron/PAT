//
//  main.cpp
//  A+B for Polynomias
//
//  Created by 周杰 on 2019/4/24.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>
#include <utility>
#include <map>
using namespace std;

map<int,double> s;
int main(int argc, const char * argv[]) {
//    int k;//存储项数
//    cin>>k;
//    set<pair<int, double>> st;
//    set<pair<int, double>> st2;
//    for (int i = 0; i<k; i++) {
//        int N ;
//        double a1 ;
//        pair<int, double> p;
//        cin>>N>>a1;
//        p = pair<int, double>(N,a1);
//        st.insert(p);
//    }
//    int k2;//存储项数2
//    cin>>k2;
//    for (int i = 0; i<k2; i++) {
//        int N1;
//        double a2;
//        pair<int, double> p1;
//        cin>>N1>>a2;
//        p1 = pair<int , double>(N1,a2);
//        st2.insert(p1);
//    }
//
//    int a[] = {0};
//    double b[] = {0};
//    int k ;
//    cin>>k;
//    for (int i = 0; i<k; i++) {
//        int q;
//        double m;
//        cin>>q>>m;
//        a[i] = q;
//        b[i] = m;
//    }
//    int c[] = {0};
//    int d[] = {0};
//    int k1;
//    cin>>k1;
//    for (int i = 0; i<k1; i++) {
//        int q;
//        double m;
//        cin>>q>>m;
//        c[i] = q;
//        d[i] = m;
//    }
//    int flag = 0;
//    for (int i = 0; i<k; i++) {
//        for (int j  = 0; j<k1; j++) {
//            if (a[i] == c[j]) {
//                b[i] += d[j];
//                flag ++;
//            }
//
//        }
//    }
//
//
//
//    return 0;
    int i1,t1;
    double t2;
    for(int z=0;z<2;z++)
    {
        scanf("%d",&i1);
        for(int i=0;i<i1;i++)
        {
            scanf("%d%lf",&t1,&t2);
            if(s.count(t1)==0)
                s[t1]=t2;
            else
                s[t1]+=t2;
        }
    }
    i1=0;
    for(map<int,double>::const_iterator m_it=s.begin();m_it!=s.end();m_it++)
    {
        if(m_it->second!=0.0&&m_it->second!=-0.0)
            i1++;
    }
    printf("%d",i1);
    for(map<int,double>::reverse_iterator m_it=s.rbegin();m_it!=s.rend();m_it++)
    {
        if(m_it->second!=0.0&&m_it->second!=-0.0)
            printf(" %d %.1lf",m_it->first,m_it->second);
    }
    printf("\n");
    return 0;

    
}
