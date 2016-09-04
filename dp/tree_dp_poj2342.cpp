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
const int mxn=6005;
int dp[mxn][2];
int p[mxn];
int visit[mxn];
int n;

void init(){
	MS(dp,0);
	MS(visit,0);
	fill(p,p+mxn,-1);
}

void treedp(int root){
	visit[root]=1;
	for(int i=1;i<=n;i++){
		if(!visit[i]&&p[i]==root){
			treedp(i);
			dp[root][0]+=max(dp[i][0],dp[i][1]);
			dp[root][1]+=dp[i][0];
		}
	}
}

int main(){
	while(cin>>n){
		init();
		for(int i=1;i<=n;i++)scanf("%d",&dp[i][1]);
		int c,f;
		while(scanf("%d%d",&c,&f)&&c&&f)p[c]=f;
		int root;
		for(int i=1;i<=n;i++)
			if(p[i]==-1)root=i;
		treedp(root);
		int ans=max(dp[root][1],dp[root][0]);
		printf("%d\n",ans);
	}
	return 0;
}
