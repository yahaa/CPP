#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn=500;
const int INF=0X3FFFFF;
struct edge{
	int w;
	int s;
	int e;
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
	E.clear();
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)G[i][j]=INF;
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


	for(i=0;i<G[a].size();i++)if(G[a][i].e==b)break;
	if(i==G[a].size()){//建立邻接表
		degree[b]++;
		degree[a]++;
		ew t;
		t.e=b;
		t.w=w;
		G[a].push_back(t);
	}
	else G[a][b].w=min(G[a][b].w,w);

	for(i=0;i<G[b].size();i++)if(G[b][i].e==a)break;
	if(i==G[b].size()){
		ew t;
		t.e=a;
		t.w=w;
		G[b].push_back(t);
	}
	else G[b][a].w=min(G[b][a].w,w);
}

int POQUAN(){
	int ans=0;
	queu<int>que;
	int c=0;
	for(int i=0;i<n;i++){
		if(degree[i]==1)que.push(i);
		degree[i]--;
	}

}
int main(){
	int a,b,w;
	while(cin>>n>>m){
		init();
		while(m--){
			cin>>a>>b>>w;
			addEdge(a,b,w);
		}
		int ans=POQUAN();
		if(ans==-1)cout<<"CAN'T FIND !"<<endl;
		else cout<<ans<<endl;
	}

}