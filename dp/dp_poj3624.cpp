/*************************************************************************
	> File Name: dp_poj3624.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 11时40分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>
#include<cstring>
#include<set>
#include<bitset>
using namespace std;
const int maxn=12881;
int dp[maxn];
int main(){
	int n,m;
	while(cin>>n>>m){
		int weight,value;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>weight>>value;
			for(int j=m;j>=weight;j--){
				dp[j]=max(dp[j],dp[j-weight]+value);
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}

