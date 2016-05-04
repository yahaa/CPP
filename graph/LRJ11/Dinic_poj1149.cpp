/*************************************************************************
  > File Name: Dinic_poj1149.cpp
  > Author: yahaa
  > Mail: yuanzihua0@gmail.com 
  > Created Time: 2016年05月04日 星期三 08时40分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
const int INF=0x3ffff;
const int maxv=405;
struct edge{
	int to,cap,rev;
	edge(int u,int t,int r):to(u),cap(t),rev(r){}
};

int bigh[maxv];
int key[maxv];
vector<edge>G[maxv];
bool used[maxv];
void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
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
	memset(key,-1,sizeof(key));
}

int main(){
	int m,n;
	while(cin>>m>>n){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d",&bigh[i]);
		}
		int count,total,index;
		for(int i=1;i<=n;i++){
			total=0;
			scanf("%d",&count);
			while(count--){
				scanf("%d",&index);
				if(key[index]==-1){
					key[index]=i;
					total+=bigh[index];
				}
				else {
					add_edge(key[index],i,INF);
				}
			}
			if(total)add_edge(0,i,total);
			int needs;
			scanf("%d",&needs);
			add_edge(i,n+1,needs);
		}
		int ans=max_flow(0,n+1);
		cout<<ans<<endl;
	}
	return 0;
}