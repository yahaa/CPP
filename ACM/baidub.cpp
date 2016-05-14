/*************************************************************************
	> File Name: baidub.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月14日 星期六 12时09分12秒
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
int dp[205][3];
int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n;
	while(cin>>n){
		MS(dp,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2;j++){
				if(j>i)dp[i][j]=dp[i][i];
				else if(i==j)dp[i][j]=1+dp[i][j-1];
				else dp[i][j]=dp[i][j-1]+dp[i-j][j];
			}
		}
		cout<<dp[n][2]<<endl;
	}
	return 0;
}

