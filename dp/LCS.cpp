/*
最长公共子序列
分析：
	设　dp[i][j] 为　s1s2...si　和s21s22...s2j对应的最长公共子序列
	1.当　s1[i]=s2[j] dp[i+1][j+1]=dp[i][j]+1;
	2.当　s1[i]!=s2[j] dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5001;
int dp[maxn][maxn];
string s1,s2;
int n,m;
void solve(){
	n=s1.length();
	m=s2.length();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s1[i]==s2[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else {
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>s1>>s2;
		solve();
		cout<<dp[n][m]<<endl;
	}
	return 0;
}