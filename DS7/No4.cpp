#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=201;
const int INF=0x3FFFFFFF;
int dis[maxn],vis[maxn];
int maps[maxn][maxn];

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);  
}

void init(int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			maps[i][j]=INF;
}

void printAll(int n){
	for(int i=1;i<n;i++){
		cout<<dis[i]<<"  ";
	}
	cout<<endl;
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
            printAll(n);
        }
}


int main(){
	int n,m,a,b,w;
	while(cin>>n>>m){
		
		init(n);
		while(m--){
			cin>>a>>b>>w;   // a ：起点　　　b: 终点　　w: 路的长度
			add_edge(a,b,w);
		}
		dijkstra(0,n);
		

		
	}
	return 0;
}

/*
6 11
0 1 45
0 2 50
1 2 5
0 3 15
3 0 10
3 1 10
3 4 79
4 1 30
1 4 20
5 4 20
1 5 15
*/