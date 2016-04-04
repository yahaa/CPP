#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100;
int dp[maxn][maxn];
int main(){
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i==j)dp[i][j]=1+dp[i][j-1];
				else dp[i][j]=dp[i-j][j]+dp[i][j-1];
			}
		}
		cout<<dp[n][n];
	}
	return 0;
}