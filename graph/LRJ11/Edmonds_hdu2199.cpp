/*************************************************************************
	> File Name: Edmonds_hdu2199.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月02日 星期一 20时16分08秒
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
using namespace std;
const int maxv=105;
vector<int>G[maxv];
int match[maxv];
int used[maxv];
int n,m;
void init(){
	for(int i=0;i<maxv;i++)G[i].clear();
}

bool dfs(int mm){
	for(int i=0;i<G[mm].size();i++){
		int u=G[mm][i];
		if(!used[u]){
			used[u]=1;
			if(match[u]==-1||dfs(match[u])){
				match[u]=mm;
				return 1;
			}
		}
	}
	return 0;
}
int Edmonds(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<n;i++){
		memset(used,0,sizeof(used));
		if(dfs(i))ans++;
	}
	return ans;
}
int main(){
	while(cin>>n&&n){
		init();
		cin>>m;
		int t;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&t);
				if(t)G[i].push_back(j);
			}

		}
		int ans=Edmonds();
		cout<<ans<<endl;
	}
	return 0;
}
	
