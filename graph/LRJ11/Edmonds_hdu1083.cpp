#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxv=405;
const int INF=0XFFFF;
int G[maxv][maxv];
int match[maxv];
bool used[maxv];
int p,n;

int dfs(int u){
	for(int i=1;i<=n;i++){
		if(G[u][i]&&!used[i]){
			used[i]=1;
			if(!match[i]||dfs(match[i])){
				//match[u]=i;
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	int count,vt;
	while(t--){
		memset(G,0,sizeof(G));
		memset(match,0,sizeof(match));
		cin>>p>>n;
		for(int i=1;i<=p;i++){
			cin>>count;
			while(count--){
				cin>>vt;
				G[i][vt]=1;
				//G[vt][i]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++){
			memset(used,0,sizeof(used));
			if(dfs(i))ans++;
		}
		if(ans==p)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}
	return 0;
}