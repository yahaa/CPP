/*************************************************************************
	> File Name: dp_hdu2546.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 13时20分45秒
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
int price[maxn];
int main(){
	int n,m;
	while(cin>>n&&n){
		for(int i=0;i<n;i++)cin>>price[i];
		sort(price,price+n);
		cin>>m;
		if(m<5){
			cout<<m<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n-1;i++){
			for(int j=m-5;j>=price[i];j--){
				dp[j]=max(dp[j],dp[j-price[i]]+price[i]);
			}
		}
		printf("%d\n",m-dp[m-5]-price[n-1]);
	}
	return 0;
}

