/****************************************
求无向图的割点与割边，一下代码是用邻接矩阵存图
时间复杂度　　O(n*n)
改用领接表存图，时间复杂度为O(n+m)
****************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1000;
int n,m;
int G[maxn][maxn];
int num[maxn],low[maxn],flag[maxn],times,root;

void init(){
	memset(G,0,sizeof(G));
	memset(num,0,sizeof(num));
	memset(low,0,sizeof(low));
	memset(flag,0,sizeof(flag));
	times=0;
}

void add_edge(int s,int e){
	G[s][e]=1;
	G[e][s]=1;
}

void dfs(int cur,int father){
	int child=0;
	times++;
	num[cur]=times;
	low[cur]=times;
	for(int i=0;i<=n;i++){
		if(G[cur][i]){
			if(num[i]==0){//如果没有访问过，看还能不能往下层递归
				child++;
				dfs(i,cur);
				low[cur]=min(low[cur],low[i]);//核心的语句
				//割点
				if(cur!=root&&low[i]>=num[cur])flag[cur]=1;
				if(cur==root&&child==2)flag[cur]=1;
				//割边
				if(low[i]>num[cur])cout<<cur<<"--"<<i<<endl;
			}
			else if(i!=father){
				low[cur]=min(low[cur],num[i]);//核心的语句
			}
		}
	}
}

void Tarjan(){
	root=1;
	dfs(1,root);
	for(int i=0;i<=n;i++){
		if(flag[i]==1)cout<<i<<" ";
	}
}

int main(){
	int s,e;
	while(cin>>n>>m){
		init();
		for(int i=0;i<m;i++){
			cin>>s>>e;
			add_edge(s,e);
		}
		Tarjan();
	}
	return 0;
}