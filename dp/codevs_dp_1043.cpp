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

const int mxn=11;
int dp[mxn][mxn][mxn][mxn];
int g[mxn][mxn],n;
int main(){
	while(cin>>n){
		int a,b,v;
		while(cin>>a>>b>>v){
			if(a==0&&b==0&&v==0)break;
			g[a][b]=v;
		}
		MS(dp,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						int sum=g[i][j]+max(max(dp[i-1][j][ii-1][jj],dp[i-1][j][ii][jj-1]),max(dp[i][j-1][ii-1][jj],dp[i][j-1][ii][jj-1]));
						if(i==ii&&j==jj){
							dp[i][j][ii][jj]+=sum;
						}
						else dp[i][j][ii][jj]+=sum+g[ii][jj];
					}
				}
			}
		}
		cout<<dp[n][n][n][n]<<endl;
	}
	return 0;
}
