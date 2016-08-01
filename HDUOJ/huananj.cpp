/*************************************************************************
	> File Name: huananj.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月15日 星期日 14时41分37秒
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
int dp[2001][2001];
int main(){
	
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int a[2000];
	int n;
	while(cin>>n){
		MS(dp,0);
		FOR(i,n)scanf("%d",&a[i]);
		sort(a,a+n);
		int ans=0;
		for(int i=a[0];i<=a[n-1];i++){
			for(int j=0;j<=a[n-1]-a[0];j++){
				if(j==i)dp[i][j]=1;
				else if(i>j&& dp[i-j][j])dp[i][j]=dp[i-j][j]+1;
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

