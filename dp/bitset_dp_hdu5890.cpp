/*************************************************************************
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;
int ans[55][55][55];
int a[55];
int n;
void solve(){
	int b[3];
	for(int i=0;i<3;i++){
		scanf("%d",&b[i]);
	}
	sort(b,b+3);
	int & res=ans[b[0]][b[1]][b[2]];
	if(~res){
		puts(res?"Yes":"No");
		return;
	}

	bitset<90>dp[11];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		if(i!=b[0]&&i!=b[1]&&i!=b[2] &&  a[i]<=87)
			for(int k=10;k>=1;k--){
				dp[k]|=dp[k-1]<<a[i];
			}
	}
	
	res=dp[10][87];
	puts(res?"Yes":"No");
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		MS(ans,-1);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int q;
		scanf("%d",&q);
		while(q--){
			solve();
		}
	}
	return 0;
}
