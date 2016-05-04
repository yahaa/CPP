#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxv=505;
int match[maxv];
bool used[maxv];
vector<int>G[maxv];
int m,n;

void init(){
	for(int i=0;i<maxv;i++)G[i].clear();
}

bool dfs(int girl){
	for(int i=0;i<G[girl].size();i++){
		int b=G[girl][i];
		if(!used[b]){
			used[b]=1;
			if(!match[b]||dfs(match[b])){
				match[b]=girl;
				return 1;
			}
		}
	}
	return 0;
}

int Edmonds(){
	int ans=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=m;i++){
		memset(used,0,sizeof(used));
		if(dfs(i))ans++;
	}
	return ans;
}

int main(){
	int k;
	while(cin>>k&&k){
		init();
		scanf("%d%d",&m,&n);
		int g,b;
		for(int i=1;i<=k;i++){
			scanf("%d%d",&g,&b);
			G[g].push_back(b);
		}
		int ans=Edmonds();
		cout<<ans<<endl;
	}
	return 0;
}