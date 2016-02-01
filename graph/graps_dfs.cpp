#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100;
const int INF=0x3FFFFF;
int maps[maxn][maxn];
int vis[maxn];
int n,m,a,b,sum;

void init(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)maps[i][j]=INF;
		memset(vis,0,sizeof(vis));
	sum=0;
}

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void dfs(int cur){
	cout<<cur<<" ";
	sum++;
	if(sum==n)return;
	for(int i=1;i<=n;i++){
		if(maps[cur][i]!=INF&&!vis[i]){    //从当前节点开始再次跑dfs
			vis[i]=1;
			dfs(i);
		}
	}
}


int main(){
	while(cin>>n>>m){
		init();
		while(m--){
			cin>>a>>b;
			add_edge(a,b,1);
			add_edge(b,a,1);
		}
		vis[1]=1;
		dfs(1);
	}
}