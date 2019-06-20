#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}
int main() {
    //邮箱容量，与目的地距离，每单位油可以跑的距离
    double cmax, d, davg;
    int n;//油站数量
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
    //当前所在距离，能够到达的距离，当前站点的价格，总价格
    if(sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
//        初始距离不为0 ，表示无法启动
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    //当目前距离 小于目的地总距离时
    while(nowdis < d) {
        //能到达的距离 = 现在的距离+ 油箱油量*每单位油可以跑的距离
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if(sta[i].dis <= nowdis) continue;
            
            if(sta[i].price < nowprice) {
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            //表示油箱价格>现在的价格
            if(sta[i].price < minPrice) {
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        //flag = 0 表示现在油箱油的价格比以后任一油站的油价低
        if(flag == 0 && minPrice != inf) {
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;
        }
        if(flag == 0 && minPrice == inf) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}
