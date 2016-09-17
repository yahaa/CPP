#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define take(a,b) (((a)>>(b))&1)
int dp[1<<10][10],m[1<<10];
bool check(int s,int t,int Mask){//判断从s可否走到t
     int rs = s/3,cs = s%3;
     int rt = t/3,ct = t%3;
     int dx = abs(rs - rt);
     int dy = abs(cs - ct);
     if(dx + dy == 1) return true;//s,t相邻
     if(dx * dy == 1 || dx * dy == 2) return true;//st斜对角或者日字型
     if(dx * dy == 4) return take(Mask,4);
     if(dx == 0)return take(Mask,3*rs+1);
     if(dy == 0)return take(Mask,3+cs);
}
int main(){
    int i,j,k,sum = 0;
    for(i = 0;i < 9;i++) dp[1<<i][i] = 1;
    for(i = 0;i < (1<<9);i++) m[i] = m[i/2] + i%2;//计算二进制中1的个数
    for(i = 0;i < (1<<9);i++) {
        for(j = 0;j < 9;j++){
            if(m[i] >= 4) sum += dp[i][j];//访问点超过4个，则为可行路线，累加至答案
            for(k = 0;k < 9;k++) {
                if(take(i,k) == 0) {
                    if(check(j,k,i))
                        dp[i+(1<<k)][k] += dp[i][j];
                }
            }
        }
    }
    printf("The total number of Andriod is : %d\n",sum);
}