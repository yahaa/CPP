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
map<string,int>mp;
const int mxn=205;
int dp[mxn][2],undp[mxn][2];
int p[mxn];
int visit[mxn];
int n;

void init(){
	MS(dp,0);
	MS(visit,0);
	fill(p,p+mxn,-1);
	for(int i=1;i<=mxn;i++){
		dp[i][1]=1;
		fill(undp[i],undp[i]+2,1);
	}
}

void treedp(int root){
	visit[root]=1;
	undp[root][0]=undp[root][1]=1;
	for(int i=1;i<=n;i++){
		if(!visit[i]&&p[i]==root){
			treedp(i);
			dp[root][0]+=max(dp[i][0],dp[i][1]);
			dp[root][1]+=dp[i][0];
			// if(dp[i][0]>dp[i][1])undp[root][0]=undp[i][0];
			// else if(dp[i][0]<dp[i][1])undp[root][0]=undp[i][1];
			// else undp[root][0]=0;
			// undp[root][1]=undp[i][0];

			if(dp[i][0]>dp[i][1]&&undp[i][0]==0)undp[root][0]=0;
			else if(dp[i][0]<dp[i][1]&&undp[i][1]==0)undp[root][0]=0;
			else if(dp[i][0]==dp[i][1])undp[root][0]=0;
			if(undp[i][0]==0)undp[root][1]=0;
		}
	}
}

int main(){
	while(cin>>n){
		int t=1;
		mp.clear();
		if(n==0)break;
		init();
		string s,f;
		cin>>s;
		int root;
		mp[s]=t++;
		root=mp[s];
		for(int i=1;i<=n-1;i++){
			cin>>s>>f;
			if(!mp[s])mp[s]=t++;
			if(!mp[f])mp[f]=t++;
			p[mp[s]]=mp[f];
		}
		treedp(root);
		if(dp[root][0]>dp[root][1]&&undp[root][0]==1){
			printf("%d Yes\n",dp[root][0]);
		}
		else if(dp[root][0]<dp[root][1]&&undp[root][1]==1){
			printf("%d Yes\n",dp[root][1]);
		}
		else printf("%d No\n",max(dp[root][0],dp[root][1]));
	}
	return 0;
}
