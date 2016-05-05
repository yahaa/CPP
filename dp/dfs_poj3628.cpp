/*************************************************************************
	> File Name: dfs_poj3628.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 19时17分34秒
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
const int INF=0x3fffff;
int a[21];
int n,b;
int ans;
void dfs(int i,int sum){
	if(i>=n)return;
	if(sum>=b)ans=min(ans,sum-b);
	dfs(i+1,sum);
	dfs(i+1,sum+a[i+1]);
}
int main(){
	while(cin>>n>>b){
		ans=INF;
		for(int i=0;i<n;i++)cin>>a[i];
		dfs(-1,0);
		cout<<ans<<endl;
	}
}

