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
const int ni=41;
const int nk=7;
ll dp[ni][nk];
char s[ni];

ll value(int si,int ei){
	ll ans=0;
	for(int i=si;i<=ei;i++){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}

int main(){
	int n,nk;
	while(cin>>n>>nk){
		scanf("%s",s+1);
		MS(dp,0);
		for(int i=1;i<=n;i++)dp[i][0]=value(1,i);
		for(int k=1;k<=nk;k++){
			for(int i=k+1;i<=n;i++){
				for(int j=k;j<i;j++){
					dp[i][k]=max(dp[i][k],dp[j][k-1]*value(j+1,i));
				}
			}
		}
		cout<<dp[n][nk]<<endl;
	}
	
	return 0;
}
