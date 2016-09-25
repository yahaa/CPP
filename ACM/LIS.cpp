#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1000;
int a[maxn];
int dp1[maxn];
int dp2[maxn];
int n;
int  solve(){
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	int ans=0;
	for(int i=n-1;i>=0;i--){
		dp2[i]=0;
		for(int k=n-1;k>i;k--){
			if(a[k]<a[i])dp2[i]=max(dp2[i],dp2[k]+1);
		}

	}
	for(int i=0;i<n;i++){
		dp1[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i])dp1[i]=max(dp1[i],dp1[j]+1);
		}
		ans=max(ans,dp1[i]+dp2[i]);
	}
	return ans;	
}


int main(){

	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ans=solve();
		cout<<n-ans<<endl;
	}
	return 0;
}
