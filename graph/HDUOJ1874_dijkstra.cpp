#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=201;
const int INF=0x3FFFFFFF;
int dis[maxn],vis[maxn];
int maps[maxn][maxn];

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);     //错在没有添加　　min   细节问题
}

void init(int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			maps[i][j]=INF;
}

void dijkstra(int s,int n){
	for(int i=0;i<n;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;

	for (int i = 0; i <n; i++){
        int x;
        int min_dis=INF;
        for (int j = 0; j <n; j++){
            if (!vis[j] && dis[j] <=min_dis){
                x = j;
                min_dis = dis[j];
            }
        }
            vis[x] = 1;
            if(min_dis==INF)break;
            for (int j = 0; j <n; j++)dis[j]=min(dis[j], dis[x] + maps[x][j]);
        }
}
int main(){
	int n,m,a,b,w;
	int start,ends;
	while(cin>>n>>m){
		
		init(n);
		while(m--){
			cin>>a>>b>>w;   // a ：起点　　　b: 终点　　w: 路的长度
			add_edge(a,b,w);
			add_edge(b,a,w);
		}
		cin>>start>>ends;
		dijkstra(start,n);
		if(dis[ends]==INF)cout<<-1<<endl;
		else cout<<dis[ends]<<endl;
	}
	return 0;
}