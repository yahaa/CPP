#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxl=4006;
const int mx=1005;
struct ss{
	int le,v;
};
int dp[mx][maxl][3];
ss a[mx];
int main(){
	int t;
	cin>>t;
	int tt=1;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,le,ans=0;
		cin>>n>>le;
		le*=2;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].le,&a[i].v);
			a[i].le*=2;
			ans=max(ans,a[i].v);
		}
		for(int i=1;i<=n;i++){
			for(int j=le;j>=a[i].le/2;j--){
				for(int k=0;k<3;k++){
					if(j>=a[i].le)
						dp[i][j][k]=max(dp[i-1][j-a[i].le][k]+a[i].v,dp[i-1][j][k]);
					if(k>0)
						dp[i][j][k]=max(dp[i-1][j-a[i].le/2][k-1]+a[i].v,dp[i-1][j][k]);
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		printf("Case #%d: %d\n",tt++,ans);

	}

	return 0;
}