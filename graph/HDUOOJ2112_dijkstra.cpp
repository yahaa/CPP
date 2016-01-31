#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn=151;
const int INF=0x3FFFFFF;
int maps[maxn][maxn];
int dis[maxn],vis[maxn];
map<string ,int>mp;

void init(){
	mp.clear();
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)maps[i][j]=INF;
}

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void dijkstra(int s,int n){
	 for (int i = 0; i < n; i++)dis[i] = INF,vis[i] = 0;
    dis[s] = 0;
    
    for (int i = 0; i < n; i++){
        int x;
        int min_dis=INF;
        for (int j = 0; j < n; j++){
            if (!vis[j] && dis[j] <=min_dis){
                x = j;
                min_dis = dis[j];
            }
        }
            vis[x] = 1;
            if(min_dis==INF)break;
            for (int j = 0; j < n; j++){
                dis[j]=min(dis[j], dis[x] + maps[x][j]);
            }
        }
}
int main(){
	int n,w;
	string start,ends,ts,te;

	
	int cnt;
	while(cin>>n&&n!=-1){
		init();
		cnt=3;
		cin>>start>>ends;
		mp[start]=1;
		mp[ends]=2;
		while(n--){
			cin>>ts>>te>>w;
			if(!mp[ts])mp[ts]=cnt++;
			if(!mp[te])mp[te]=cnt++;
			add_edge(mp[ts],mp[te],w);
			add_edge(mp[te],mp[ts],w);
		}
		
		if(start==ends){
			cout<<0<<endl;
			continue;
		}
		dijkstra(1,cnt);
		if(dis[2]!=INF)cout<<dis[2]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
