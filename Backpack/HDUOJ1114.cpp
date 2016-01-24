#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=10005;
const int INF=100000000;
int dp[maxn];
	int t;
int main(){
	cin>>t;
	while(t--){
		dp[0]=0;
		for(int i=1;i<maxn;i++)dp[i]=INF;
		int empty,full;
		cin>>empty>>full;
		int total=full-empty;
		int n;
		cin>>n;
		int value,weight;
		for(int i=1;i<=n;i++){  //dp[j]表示 第i 件物品没有出现过
			cin>>value>>weight;  //dp[j-vi]+wi  表示  第i 件物品至少出现一次
			for(int j=0;j<=total;j++){
				if(j>=weight)dp[j]=min(dp[j],dp[j-weight]+value);   //滚动数组 版本完全背包
			}
		}

		if(dp[total]==INF)cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[total]<<"."<<endl;
	}
	return 0;
}