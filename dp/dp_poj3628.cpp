/*************************************************************************
	> File Name: dp_poj3628.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 18时54分10秒
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
typedef long long ll;
const ll maxn=2000000;
ll dp[maxn];
ll c[25];
int main(){
	int n,b;
	while(cin>>n>>b){
		ll sum=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>c[i];
			sum+=c[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=c[i];j--){
				dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
			}
		}
		for(int i=1;i<=sum;i++){
			if(dp[i]>=b){
				cout<<dp[i]-b<<endl;
				break;
			}
		}
	}
	return 0;
}

