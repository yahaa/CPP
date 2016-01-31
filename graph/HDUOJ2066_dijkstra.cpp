#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1001;
const int INF=0x3FFFFFFF;
int dis[maxn],vis[maxn];
int maps[maxn][maxn];

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);     //错在没有添加　　min   细节问题
}

void init(){
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
			maps[i][j]=INF;
}

void dijkstra(int s,int n){
	for(int i=0;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;

	for (int i = 0; i <=n; i++){
        int x;
        int min_dis=INF;
        for (int j = 0; j <=n; j++){
            if (!vis[j] && dis[j] <=min_dis){
                x = j;
                min_dis = dis[j];
            }
        }
            vis[x] = 1;
            for (int j = 0; j <=n; j++)dis[j]=min(dis[j], dis[x] + maps[x][j]);
        }
}
int main(){
	int t,s,d,a,b,w;    //t s  d 分别表示　　总的路线　　　和小草家相邻的地方的数　　　想去的地方数
	while(cin>>t>>s>>d){
		int maxm=-999999;
		init();
		while(t--){
			cin>>a>>b>>w;   // a ：起点　　　b: 终点　　w: 路的长度
			maxm=max(a,max(b,maxm));
			add_edge(a,b,w);
			add_edge(b,a,w);
		}
		
		int sm;
		while(s--){
			cin>>sm;
			maps[0][sm]=0;
		}
		dijkstra(0,maxm);
		int ans=INF;
		int ds;
		for(int i=0;i<d;i++){
			cin>>ds;
			ans=min(dis[ds],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}