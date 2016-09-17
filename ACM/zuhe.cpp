#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1<<10][10],m[1<<10],sum[10];

bool take(int s,int b){
    return (s>>b)&1;
}

bool check(int s,int t,int maks){  //判断从s可否走到t
     int rs=s/3,cs=s%3;
     int rt=t/3,ct=t%3;
     int dx=abs(rs-rt);
     int dy=abs(cs-ct);
     if(dx+dy==1)return true;  
     if(dx*dy==1||dx*dy==2) return true;
     if(dx*dy==4)return take(maks,4);
     if(dx==0)return take(maks,3*rs+1);
     if(dy==0)return take(maks,3+cs);
}

int main(){
    
    memset(sum,0,sizeof(sum));
    for(int i=0;i<9;i++)dp[1<<i][i]=1;
    for(int i=0;i<(1<<9);i++)m[i]=m[i/2]+i%2;

    for(int i=0;i<(1<<9);i++){
        for(int j=0;j<9;j++){
            sum[m[i]]+=dp[i][j];
            for(int k=0;k<9;k++){
                if(!take(i,k)){
                    if(check(j,k,i))
                        dp[i+(1<<k)][k] += dp[i][j];
                }
            }
        }
    }
  
    for(int i=1;i<=9;i++){
        cout<<sum[i]<<endl;
    }
    return 0;
}

//O(2^9*9*9)