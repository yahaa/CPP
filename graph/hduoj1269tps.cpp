#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=10005;
vector<int>G[maxn];
int degree[maxn];
void init(){
	memset(degree,0,sizeof(degree));
	memset(G,0,sizeof(G));
}
int main(){
	int n,m;
	int a,b,i;
	while(cin>>n>>m){
		if(n==0&&m==0)break; 
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
		bool ans=true;
		for(int i=1;i<=n;i++){
			if(degree[i]==0){
				ans=false;
				break;
			}
		}
		if(ans)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}