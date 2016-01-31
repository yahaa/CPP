#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1001;
const int INF=0x3FFFFFF;
int maps[maxn][maxn];
int vis[maxn],dis[maxn];
int n,m,gload;

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void init(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)maps[i][j]=INF;

}

void dijkstra(int s,int n){
	for(int i=0;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;

	for(int i=0;i<=n;i++){
		int x;
		int min_dis=INF;
		for(int j=0;j<=n;j++){
			if(!vis[j]&&dis[j]<min_dis){
				x=j;
				min_dis=dis[j];
			}
		}

		vis[x]=1;
		if(min_dis==INF)break;
		for(int j=0;j<=n;j++)dis[j]=min(dis[j],dis[x]+maps[x][j]);
	}
}
int main(){
	int a,b,w;
	int want,tt;
	while(scanf("%d%d%d",&n,&m,&gload)!=EOF){
		init();
		while(m--){
			scanf("%d%d%d",&a,&b,&w);
			add_edge(a,b,w);
		}
		scanf("%d",&want);
		while(want--){
			scanf("%d",&tt);
			maps[0][tt]=0;
		}

		dijkstra(0,n);
		if(dis[gload]==INF)printf("-1\n");
		else printf("%d\n",dis[gload]);
	}
	return 0;
}