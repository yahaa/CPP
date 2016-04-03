#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=501;
vector<int>G[maxn];//邻接表存储形式
vector<int>ans;
int n,m;
int degree[maxn];

void init(){
	for(int i=0;i<maxn;i++)G[i].clear();
	memset(degree,0,sizeof(degree));
	ans.clear();
}

void topological(){
	priority_queue<int, vector<int>, greater<int> >que;//优先队列
	for(int i=0;i<n;i++){
		if(degree[i]==0){
			que.push(i);
			degree[i]--;
		}
	}
	while(!que.empty()){
		int v=que.top();
		ans.push_back(v);
		que.pop();
		for(int i=0;i<G[v].size();i++){
			degree[G[v][i]]--;
			if(degree[G[v][i]]==0)que.push(G[v][i]);
		}
	}
}

int main(){
	int a,b,i;
	while(cin>>n>>m){
		init();
		while(m--){
			cin>>a>>b;
			i=0;
			for(i=0;i<G[a].size();i++)if(G[a][i]==b)break;
			if(i==G[a].size()){
				degree[b]++;
				G[a].push_back(b);
			}
		}
		topological();
		for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<" ";
		cout<<ans[ans.size()-1]<<endl;
	}
	return 0;
}


/*
6 9
1 0
1 4
4 0
0 2
0 3
2 3
5 3
5 2
5 4
*/