#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=51;
int dp[maxn];
int value[maxn],weight[maxn];
int main(){
	int n,total;
	int tt=1;
	while(cin>>n>>total){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)cin>>value[i];
		for(int i=1;i<=n;i++)cin>>weight[i];

		for(int i=1;i<=n;i++)
			for(int j=total;j>=weight[i];j--)dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
		cout<<"Case "<<tt++<<":";
		cout<<dp[total]<<endl;

	}
}