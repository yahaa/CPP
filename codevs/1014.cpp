#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int mx=20005;
const int mn=35;
int dp[mx];

int main(){
	int v,n;
	while(cin>>v>>n){
		int ai;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&ai);
			for(int j=v;j>=ai;j--){
				dp[j]=max(dp[j],dp[j-ai]+ai);
			}
		}
		cout<<v-dp[v]<<endl;
	}
	return 0;
}

