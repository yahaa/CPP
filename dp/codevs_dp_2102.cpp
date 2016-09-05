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
#define INF 0X3F
using namespace std;
const int mxn=205;
int dp[mxn][mxn],n,sum[mxn],a[mxn];

int main(){
	while(cin>>n){
		MS(sum,0);
		MS(dp,INF);
		int t;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i+n]=a[i];
			dp[i][i]=0;
		}
		n*=2;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				}
			}
		}
		int ans=10000000;
		for(int i=1;i<=n/2-1;i++){
			ans=min(dp[i][i+n/2-1],ans);
		}
		cout<<ans<<endl;
		MS(dp,INF);
		for(int i=1;i<=n;i++){
			a[i]=-a[i];
			sum[i]=-sum[i];
			dp[i][i]=0;
		}

		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				}
			}
		}

		ans=10000000;
		for(int i=1;i<=n/2-1;i++){
			ans=min(dp[i][i+n/2-1],ans);
		}
		cout<<-ans<<endl;
	}
	return 0;
}