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
int dp[mxn][3];
int n;
int main(){
	while(cin>>n){
		MS(dp,INF);
		dp[0][0]=0;
		dp[0][1]=0;
		dp[0][2]=0;
		int op;
		for(int i=1;i<=n;i++){
			cin>>op;
			if(op==0){
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
			}
			if(op==1){
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
				dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			}
			if(op==2){
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
				dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
			}
			if(op==3){
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
				dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
				dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
			}
		}
		cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<endl;
	}
	return 0;
}
