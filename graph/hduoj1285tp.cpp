#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
// const int maxn=501;
// int G[maxn][maxn];//邻接矩阵存储图
// int degree[maxn];
// int vist[maxn];
// int n,m;
// vector<int>ans;

// void init(){
// 	memset(G,0,sizeof(G));
// 	memset(degree,0,sizeof(degree));
// 	memset(vist,0,sizeof(vist));
// 	ans.clear();
// }

// void topological(){
// 	int k;
// 	for(int i=1;i<=n;i++){
// 		k=0;
// 		for(int j=1;i<=n;j++){
// 			if(!vist[j]&&degree[j]==0){
// 				vist[j]=1;
// 				k=j;
// 				ans.push_back(j);
// 				break;
// 			}
// 		}
	
// 		for(int j=1;j<=n;j++){
// 			if(G[k][j]){
// 				G[k][j]=0;
// 				degree[j]--;
// 			}
// 		}
// 	}
// }
// int main(){
// 	int a,b;
// 	while(cin>>n>>m){
// 		init();
// 		for(int i=1;i<=m;i++){
// 			cin>>a>>b;
// 			if(G[a][b]==0){//重边度数不能相加
// 				G[a][b]=1;
// 				degree[b]++;
// 			}
			
// 		}
// 		topological();
// 		for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<" ";
// 		cout<<ans[ans.size()-1]<<endl;
// 	}
// 	return 0;
// }
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
	priority_queue<int, vector<int>, greater<int> >que;
	for(int i=1;i<=n;i++){
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