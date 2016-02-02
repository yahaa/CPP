#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=51;
const int INF=0x3FFFFFF;
int maps[maxn][maxn];
int vis[maxn];
int n,m,a,b;

void init(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)maps[i][j]=INF;
	memset(vis,0,sizeof(vis));
}

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void bfs(int s){
	queue<int>a;
	vis[s]=1;
	a.push(s);
	while(!a.empty()){
		int ts=a.front();
		cout<<ts<<" ";
		a.pop();
		for(int i=1;i<=n;i++){
			if(maps[ts][i]!=INF&&!vis[i]){
				vis[i]=1;
				a.push(i);
			}
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

		bfs(1);
	}
	return 0;
}