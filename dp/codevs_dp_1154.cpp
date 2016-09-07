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
#include <fstream>
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
const int mxn=220;
ll dp[mxn][mxn];
ll w[mxn];
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		w[i+n]=w[i];
	}
	n*=2;
	MS(dp,0);
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n-1;j++){
			for(int k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+w[i]*w[k+1]*w[j+1]);
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n/2;i++){
		ans=max(ans,dp[i][i+n/2-1]);
	}
	cout<<ans<<endl;
	return 0;
}
