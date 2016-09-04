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
#define INF 0X3f3f
using namespace std;
const int mxn=1000005;
ll dp[mxn][2];
int c[mxn];
ll n,mm=4557430888798830399;
string str[mxn][2];
char ch[mxn];

int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++)scanf("%d",&c[i]);
		for(int i=1;i<=n;i++){
			scanf("%s",ch);
			str[i][0]=ch;
			reverse(ch,ch+str[i][0].length());
			str[i][1]=ch;
		}

		MS(dp,INF);
		dp[1][0]=0;
		dp[1][1]=c[1];
		for(int i=2;i<=n;i++){
			if(str[i][0]>=str[i-1][0]) dp[i][0]=min(dp[i][0],dp[i-1][0]);
			if(str[i][0]>=str[i-1][1]) dp[i][0]=min(dp[i][0],dp[i-1][1]);
			if(str[i][1]>=str[i-1][0]) dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
			if(str[i][1]>=str[i-1][1]) dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
			// for(int op=0;op<2;op++){
			// 	for(int k=0;k<2;k++){
			// 		if(str[i][k]>=str[i-1][op]){
			// 			dp[i][k]=min(dp[i][k],dp[i-1][op]+k*c[i]);
			// 		}
			// 	}
			// }
		}
		ll ans=min(dp[n][1],dp[n][0]);
		if(ans>=mm)ans=-1;
		printf("%I64d\n",ans);
	}
	return 0;
}
