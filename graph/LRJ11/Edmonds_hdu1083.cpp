#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxv=405;
const int INF=0XFFFF;
int v;
vector<int> G[maxv];
int match[maxv];
bool used[maxv];

void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		int w=match[u];
		if(w<0||(!used[w]&&dfs(w))){
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}

int bipartite_matching(){
	int res=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=v;i++){
		if(match[i]<0){
			memset(used,0,sizeof(used));
			if(dfs(v))res++;
		}
	}
	return res;
}

void init(){
	for(int i=0;i<maxv;i++)G[i].clear();
}

int main(){
	int t;
	cin>>t;
	int p,n;
	while(t--){
		init();
		cin>>p>>n;
		v=n+p;
		int count,s;
		for(int i=1;i<=p;i++){
			cin>>count;
			while(count--){
				cin>>s;
				add_edge(i,p+s);
			}
		}
		int ans=bipartite_matching();
		cout<<ans<<endl;
		if(ans==p)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}