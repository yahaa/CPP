/*************************************************************************
	> File Name: dp_hdu2602.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 13时02分49秒
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
const int maxn=1001;
int dp[maxn];
int volume[maxn];
int value[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,v;
		cin>>n>>v;
		for(int i=1;i<=n;i++)cin>>value[i];
		for(int i=1;i<=n;i++)cin>>volume[i];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=v;j>=volume[i];j--){
				dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
			}
		}
		cout<<dp[v]<<endl;
	}
	return 0;
}

