#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=501;
const int minx=-10000;
struct ew{
	int e;
	int w;
};
vector<ew>G[maxn];
vector<ew>GT[maxn];
vector<int>important;
int degree[maxn];
int ve[maxn];
int vl[maxn];
int ee[maxn*4];
int el[maxn*4];
int n,m;//分别表示节点数，边数，权值

void init(){
	memset(degree,0,sizeof(degree));
	memset(ve,0,sizeof(ve));
	memset(ee,0,sizeof(ee));
	memset(el,0,sizeof(el));
	important.clear();
	for(int i=0;i<n;i++){
		G[i].clear();
		GT[i].clear();
	}
}

void AOE(){
	//queue<int>que;
	priority_queue<int,vector<int>,greater<int> >que;//正向拓扑
	stack<int>sta;//逆向拓扑
	for(int i=0;i<n;i++){
		if(degree[i]==0){
			que.push(i);
			degree[i]--;
		}
	}

	while(!que.empty()){
		int v=que.top();
		que.pop();
		sta.push(v);
		for(int i=0;i<G[v].size();i++){
			ve[G[v][i].e]=max(ve[G[v][i].e],ve[v]+G[v][i].w);
			degree[G[v][i].e]--;
			if(degree[G[v][i].e]==0)que.push(G[v][i].e);
		}
	}

	if(sta.size()!=n){//如果不等　说明存在回路
		cout<<"YOU HUI LU"<<endl;
		return;
	}

	int v=sta.top();
	for(int i=0;i<n;i++)vl[i]=ve[v];//初始化事件最迟发生时刻

	while(!sta.empty()){
		int v=sta.top();
		sta.pop();
		for(int i=0;i<GT[v].size();i++){
			vl[GT[v][i].e]=min(vl[GT[v][i].e],vl[v]-GT[v][i].w);
		}
	}
	int k=1;
	for(int s=0;s<n;s++){
		for(int i=0;i<G[s].size();i++){
			ee[k]=ve[s];
			el[k]=vl[G[s][i].e]-G[s][i].w;
			if(ee[k]==el[k])important.push_back(k);
			k++;
		}
	}

	for(int i=0;i<n;i++)cout<<ve[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)cout<<vl[i]<<" ";
	cout<<endl;
	for(int i=1;i<=m;i++)cout<<ee[i]<<" ";
	cout<<endl;
	for(int i=1;i<=m;i++)cout<<el[i]<<" ";
	cout<<endl;
	for(int i=0;i<important.size();i++)cout<<important[i]<<" ";
	cout<<endl;

}


int main(){
	int a,b,w;
	int i;
	while(cin>>n>>m){
		init();
		int tm=m;
		while(tm--){
			cin>>a>>b>>w;
			for(i=0;i<G[a].size();i++)if(G[a][i].e==b)break;
			if(i==G[a].size()){//建立邻接表
				degree[b]++;
				ew t;
				t.e=b;
				t.w=w;
				G[a].push_back(t);
			}
			else G[a][b].w=max(G[a][b].w,w);

			for(i=0;i<GT[b].size();i++)if(GT[b][i].e==a)break;
			if(i==GT[b].size()){//建立逆邻接表
				ew t;
				t.e=a;
				t.w=w;
				GT[b].push_back(t);
			}
			else GT[b][a].w=max(GT[b][a].w,w);
		}
		AOE();
	}
	return 0;
}
/*
7 10
0 1 3
0 2 2
0 3 6
1 4 4
1 3 2
2 3 1
2 5 3
3 4 1
4 6 3
5 6 4

7 11
0 1 8
0 3 4
0 4 5
3 4 1
4 1 2
4 2 7
4 5 2
1 2 3
2 6 6
5 6 9
5 2 3
*/