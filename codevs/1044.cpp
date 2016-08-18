#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int INF=0X3FFFF;
const int mx=30;
int a[mx];
int n=0;
int ans1,ans2;
int dp[mx];
void solve(){
	int to=n;
	ans1=-1;
	ans2=0;
	while(to){
		fill(dp,dp+n,INF);
		for(int i=0;i<n;i++){
			if(a[i]<0)continue;
			*lower_bound(dp,dp+n,a[i])=a[i];
		}
		ans1=max((int)(lower_bound(dp,dp+n,INF)-dp),ans1);
		ans2++;
		for(int i=0;dp[i]!=INF;i++){
			if(dp[i]!=INF){
				for(int j=0;j<n;j++){
					if(dp[i]==a[j]){
						a[j]=-1;
						to--;
						break;
					}
				}
			}
		}
	}
}

int main(){
	int t;
	while(cin>>t){
		a[n++]=t;
	}
	reverse(a,a+n);
	solve();
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}