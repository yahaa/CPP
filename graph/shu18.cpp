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
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			maps[i][j]=INF;
}

void dijkstra(int s,int n){
	for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;

	for (int i = 1; i <=n; i++){
        int x;
        int min_dis=INF;
        for (int j = 1; j <=n; j++){
            if (!vis[j] && dis[j] <=min_dis){
                x = j;
                min_dis = dis[j];
            }
        }
            vis[x] = 1;
            if(min_dis==INF)break;
            for (int j = 1; j <=n; j++)dis[j]=min(dis[j], dis[x] + maps[x][j]);
        }
}
int main(){
	int n,w;
	int start,ends;
	int tt=1;
	while(cin>>n){
		
		init(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				cin>>w;
				if(w!=-1)add_edge(i,j,w);
			}
			
		
		cin>>start>>ends;
		dijkstra(start,n);
		cout<<"Case "<<tt++<<endl;
		if(dis[ends]==INF)cout<<-1<<endl;
		else cout<<dis[ends]<<endl;
	}
	return 0;
}