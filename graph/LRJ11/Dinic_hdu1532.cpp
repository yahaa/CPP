#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxv=405;
const int INF=0X3FFFF;
struct edge{
	int to,cap,rev;
	edge(int t,int c,int r):to(t),cap(c),rev(r){}
};
int level[maxv];
int iter[maxv];
vector<edge> G[maxv];

void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			edge&e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v,int t,int f){
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge&e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
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
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

void init(){
	for(int i=0;i<maxv;i++)G[i].clear();
}
int main(){
	// int m,n;
	// int from,to,cap;
	// while(cin>>m>>n){
	// 	init();
	// 	while(m--){
	// 		cin>>from>>to>>cap;
	// 		add_edge(from,to,cap);
	// 	}
	// 	int ans=max_flow(1,n);
	// 	cout<<ans<<endl;
	// }

	int p,n;
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>p>>n;
		int s=n+p+2,t=s+1;//自己新建起点和汇点的例题 
		for(int i=1;i<=n;i++)add_edge(s,i,1);
		for(int i=1;i<=p;i++)add_edge(n+i,t,1);
		for(int i=1;i<=p;i++){
			int count,t;
			cin>>count;
			while(count--){
				cin>>t;//这个t 和上面的t 没有冲突
				add_edge(t,n+i,1);
			}
		}
		int ans=max_flow(s,t);
		//cout<<ans<<endl;
		if(ans==p)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}