#include <iostream>
#include <vector>
using namespace std;
const int maxn=10000;
vector<int>G[maxn];
int n;
int p[maxn];

void read_tree(){
	int s,e;
	for(int i=1;i<=n-1;i++){
		cin>>s>>e;
		G[s].push_back(e);
		G[e].push_back(s);
	}
}

void init(){
	for(int i=0;i<maxn;i++)G[i].clear();
}

void dfs(int cur,int fa){
	int d=G[cur].size();
	for(int i=0;i<d;i++){
		int v=G[cur][i];
		if(v!=fa)dfs(v,p[v]=cur);
	}
}

int main(){
	
	while(cin>>n){
		init();
		read_tree();
		int root;
		cin>>root;
		p[root]=-1;
		dfs(root,-1);
		for(int i=0;i<n;i++)cout<<i<<" "<<p[i]<<endl;
	}
}