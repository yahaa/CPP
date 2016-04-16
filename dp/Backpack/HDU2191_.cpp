#include <iostream>    //多重背包 二进制转换成 01 背包
#include <string.h>  
#include <stdio.h>  
  
using namespace std;  
const int N = 1005;  
  
int dp[N];  
int c[N],w[N],num[N];  
int n,m;  
  
void ZeroOne_Pack(int cost,int weight,int n){  
    for(int i=n; i>=cost; i--)  
        dp[i] = max(dp[i],dp[i-cost] + weight);  
}  
  
void Complete_Pack(int cost,int weight,int n){  
    for(int i=cost; i<=n; i++)  
        dp[i] = max(dp[i],dp[i-cost] + weight);  
}  
  
int Multi_Pack(int c[],int w[],int num[],int n,int m){  
    memset(dp,0,sizeof(dp));  
    for(int i=1; i<=n; i++){  
        if(num[i]*c[i] > m)Complete_Pack(c[i],w[i],m);  
        else{  
            int k = 1;  
            while(k < num[i]){  
                ZeroOne_Pack(k*c[i],k*w[i],m);  
                num[i] -= k;
                k <<= 1;  
            }  
            ZeroOne_Pack(num[i]*c[i],num[i]*w[i],m);  
        }  
    }  
    return dp[m];  
}  
  
int main(){  
    int t;  
    cin>>t;  
    while(t--){  
        cin>>m>>n;  
        for(int i=1; i<=n; i++)cin>>c[i]>>w[i]>>num[i];  
        cout<<Multi_Pack(c,w,num,n,m)<<endl;  
    }  
    return 0;  
}  
