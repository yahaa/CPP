#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=501;
int G[maxn][maxn];
int degree[maxn];
int vist[maxn];
int n,m;
vector<int>ans;

void init(){
	memset(G,0,sizeof(G));
	memset(degree,0,sizeof(degree));
	memset(vist,0,sizeof(vist));
	ans.clear();
}

void topological(){
	int k;
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=1;i<=n;j++){
			if(!vist[j]&&degree[j]==0){
				vist[j]=1;
				k=j;
				ans.push_back(j);
				break;
			}
		}
	
		for(int j=1;j<=n;j++){
			if(G[k][j]){
				G[k][j]=0;
				degree[j]--;
			}
		}
	}
}
int main(){
	int a,b;
	while(cin>>n>>m){
		init();
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			if(G[a][b]==0){
				G[a][b]=1;
				degree[b]++;
			}
			
		}
		topological();
		for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<" ";
		cout<<ans[ans.size()-1]<<endl;
	}
	return 0;
}