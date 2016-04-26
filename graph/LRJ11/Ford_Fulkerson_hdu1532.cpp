#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3fffff;
const int maxv=405;
struct edge{
	int to,cap,rev;
	edge(int u,int t,int r):to(u),cap(t),rev(r){}
};

vector<edge>G[maxv];
bool used[maxv];
void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));//这个办法求残余网络图
}


int dfs(int v,int t,int f){
	if(v==t)return f;
	used[v]=1;
	for(int i=0;i<G[v].size();i++){
		edge&e=G[v][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	while(1){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0)return flow;
		flow+=f;
	}
}

void init(){
	for(int i=0;i<maxv;i++)G[i].clear();
}

int main(){
	int m,n;
	int from,to,cap;
	while(cin>>m>>n){
		init();
		while(m--){
			cin>>from>>to>>cap;
			add_edge(from,to,cap);
		}
		int ans=max_flow(1,n);
		cout<<ans<<endl;
	}
	return 0;
}