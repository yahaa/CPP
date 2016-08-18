/*
最长上升子序列
分析：
	定义dp[i]是以ai 为末尾的最长上升子序列长度
	在满足　j<i&&aj<ai的aj为结尾的子列末尾，追加上ai 后得到的子序列
	所以有　dp[i]=max(1,dp[j]+1);
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000;
const int INF=0x3fffff;
int a[maxn];
int dp[maxn];
int n;
int  solve(){//第一种做法
	int ans=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}

int solve2(){
	fill(dp,dp+n,INF);
	for(int i=0;i<n;i++){
		cout<<lower_bound(dp,dp+n,a[i])-dp;
		*lower_bound(dp,dp+n,a[i])=a[i];
	}
	return lower_bound(dp,dp+n,INF)-dp;
}
int main(){
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<solve()<<endl;
		cout<<solve2()<<endl;
	}
}