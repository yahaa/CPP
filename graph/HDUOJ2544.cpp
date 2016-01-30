#include<iostream>         //双向边添加时刻要记住，错误多次
#include<cstdlib>          //(1)当权值为非负时，用Dijkstra。
#include<algorithm>        //(2)当权值有负值，且没有负圈，则用SPFA，SPFA能检测负圈，但是不能输出负圈。
using namespace std;       //(4)SPFA检测负环：当存在一个点入队大于等于V次，则有负环，后面有证明。
const int MAXN = 2100;     //(3)当权值有负值，而且可能存在负圈，则用BellmanFord，能够检测并输出负圈。    
int G[MAXN][MAXN];
int vis[MAXN];
int dis[MAXN];
const int INF = 0x3FFFFFFF;         //最短路－－－－－－dijkstra

void init(int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j] = INF;
}


void add_edge(int a, int b, int w){
    G[a][b] = min(G[a][b],w);
}


void Dijkstra(int s, int n){
    for (int i = 0; i < n; i++)dis[i] = INF;
    for (int i = 0; i < n; i++) vis[i] = 0;
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
            for (int j = 0; j < n; j++){
                dis[j]=min(dis[j], dis[x] + G[x][j]);
            }
        }
}


int main(){
    int n, m;
    while (cin >> n >> m&&n&&m){
        init(n);
        int a, b, w;
        while (m--){
            cin >> a >> b >> w;
            a--;
            b--;
            add_edge(a, b, w);
            add_edge(b, a, w);
        }
        Dijkstra(0, n);
        cout << dis[n - 1] << endl;
    }
    return 0;
}