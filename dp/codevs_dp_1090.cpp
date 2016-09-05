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

const int mxn=55;
int dp[mxn][mxn];
int tree[mxn][mxn];
int w[mxn],n;

void pre(int a,int b){
	if(a>b)return;
	int t=tree[a][b];
	printf("%d ",t);
	pre(a,t-1);
	pre(t+1,b);
}

int main(){
	while(cin>>n){
		MS(dp,0);
		MS(tree,0);
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
			dp[i][i]=w[i];
			tree[i][i]=i;
		}
		for(int i=n;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++){
					int x=dp[i][k-1];
					int y=dp[k+1][j];
					x=(x==0)?1:x;
					y=(y==0)?1:y;
					if(dp[i][j]<x*y+w[k]){
						dp[i][j]=x*y+w[k];
						tree[i][j]=k;
					}
				}
			}
		}
		printf("%d\n",dp[1][n]);
		pre(1,n);
		cout<<endl;
	}
	return 0;
}
