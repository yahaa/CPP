#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1005;
int dp[maxn],a[maxn];
int dpsolve(int n){
	int ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i]=a[i];
		for(int j=0;j<i;j++){
			if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+a[i]);
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}

int main(){
	int n;
	while(cin>>n&&n){
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<dpsolve(n)<<endl;
	}
	return 0;
}