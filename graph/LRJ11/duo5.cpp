#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=205;
int dp[maxn][maxn];
int main(){
	int n,k;
	while(cin>>n>>k){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(j>i)dp[i][j]=0;
				else if(i==j)dp[i][j]=1;
				else dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
}