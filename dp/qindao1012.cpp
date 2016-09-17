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
const int t=88;
int dp[t][t];
int a[55],vi[55];
map<int,int>mp;

void init(){
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		it->second=1;
	}
}
int main(){
	int c;
	cin>>c;
	while(c--){
		int n,q;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]=1;
		}
		cin>>q;
		while(q--){
			init();
			int u,tu=0;
			MS(vi,0);
			MS(dp,0);
			for(int i=0;i<3;i++){
				scanf("%d",&u);
				if(!vi[u]){
					vi[u]=1;
					mp[a[u]]=0;
					tu++;
				}
			}

			if(n-tu<10)printf("No\n");
			else {
				MS(dp,0);
				for(int i=1;i<=87;i++){
					for(int j=1;j<=10;j++){
						if(i<j)dp[i][j]=0;
						else if(i==j){
							if(mp[1])dp[i][j]=1;
							else dp[i][j]=0;
						}
						else {
							if(mp[1])dp[i][j]=dp[i-1][j-1];
							if(mp[])dp[i][j]=+dp[i-1][j-1]+1;
						}
					}
				}
				if(dp[87][10])printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
