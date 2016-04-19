#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=500;
const int INF=0X3FFFFF;
int vis[maxn][maxn];
struct edge{
	int w;
	int s;
	int e;
	bool operator <(edge a)const{
		return a.w>w;
	}
};

struct ew{
	int e;
	int w;
};
vector<ew>G[maxn];
int degree[maxn];
vector<edge>E;
int n,m;

void init(){
	memset(degree,0,sizeof(degree));
	memset(vis,0,sizeof(vis));
	E.clear();
	for(int i=0;i<maxn;i++)G[i].clear();
}

void addEdge(int a,int b,int w){
	edge te;
	te.w=w;
	te.s=a;
	te.e=b;
	int i;
	for(i=0;i<E.size();i++)if(E[i].s==te.s&&E[i].e==te.e)break;
	if(i==E.size())E.push_back(te);
	else E[i].w=min(E[i].w,w);
	degree[a]++;
	degree[b]++;
	ew tt;
	tt.e=b;
	tt.w=w;
	G[a].push_back(tt);
	tt.e=a;
	G[b].push_back(tt);
}

int POQUAN(){
	if(m<n-1)return -1;
	int edges=0;
	int ans=0;
	queue<int>quv;
	priority_queue<edge>que;
	for(int i=0;i<E.size();i++)que.push(E[i]);
	
	for(int i=0;i<=n;i++){
		if(degree[i]==1){
			quv.push(i);
			degree[i]=-1;
		}
	}
	while(edges<n-1){
		while(!quv.empty()){
			int v=quv.front();
			quv.pop();
			int u;
			for(int i=0;i<G[v].size();i++){
				if(degree[G[v][i].e]!=-1){
					u=i;
					break;
				}
			}
			if(!vis[v][u]){
				ans+=G[v][u].w;
				edges++;
				degree[u]--;
				vis[v][u]=1;
				vis[u][v]=1;
				if(degree[u]==1){
					quv.push(u);
					degree[u]=-1;
				}	
			}
		}

		while(quv.empty()&&edges<n-1){
			edge t=que.top();
			if(vis[t.s][t.e]){
				que.pop();
			}
			else {
				vis[t.s][t.e]=1;
				vis[t.e][t.s]=1;
				degree[t.s]--;
				if(degree[t.s]==1){
					quv.push(t.s);
					degree[t.s]=-1;
				}
				degree[t.e]--;
				if(degree[t.e]==1){
					quv.push(t.e);
					degree[t.e]=-1;
				}
				
				que.pop();
			}
		}
	}
	return ans;

}
int main(){
	int a,b,w;
	while(cin>>n>>m){
		init();
		for(int i=0;i<m;i++){
			cin>>a>>b>>w;
			addEdge(a,b,w);
		}
		int ans=POQUAN();
		if(ans==-1)cout<<"CAN'T FIND !"<<endl;
		else cout<<ans<<endl;
	}
	return 0;

}


/*
6 7
1 2 1
1 3 2
2 3 3
3 4 8
4 5 4
4 6 5
5 6 6

5 5
1 2 1
1 3 1
2 4 4
4 5 3

*/
