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
#define INF 0X3F
using namespace std;
const int mxn=105;
int dp[mxn][mxn],n,sum[mxn];

int main(){
	while(cin>>n){
		MS(sum,0);
		MS(dp,INF);
		int t;
		for(int i=1;i<=n;i++){
			cin>>t;
			sum[i]=sum[i-1]+t;
			dp[i][i]=0;
		}
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				}
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}
