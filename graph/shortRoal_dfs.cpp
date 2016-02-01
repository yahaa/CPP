#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=51;
const int INF=0X3FFFFFF;
int vis[maxn],maps[maxn][maxn];
int n,m,a,b,w;
int min_dis=INF;

void init(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)maps[i][j]=INF;
	memset(vis,0,sizeof(vis));
}

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void dfs(int s,int dis){
	if(dis>min_dis)return;   //这里相当于减枝
	if(s==n){   //找到终点
		min_dis=min(min_dis,dis);
		return;
	}

	for(int i=1;i<=n;i++){
		if(maps[s][i]!=INF&&!vis[i]){
			vis[i]=1;
			dfs(i,dis+maps[s][i]);
			vis[i]=0;
		}
	}

}

int main(){
	while(cin>>n>>m){
		init();
		while(m--){
			cin>>a>>b>>w;
			add_edge(a,b,w);
			add_edge(b,a,w);
		}
		vis[1]=1;
		dfs(1,0);
		cout<<min_dis<<endl;
	}
	return 0;
}