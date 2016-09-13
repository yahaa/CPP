#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAXN=110;
bool vis[MAXN];
int lowc[MAXN];
int g[MAXN][MAXN];
vector<pair<int,int> >all;
int Prim(int cost[][MAXN],int n){
	int ans=0;
	memset(vis,false,sizeof(vis));
	vis[0]=true;
	for(int i=1;i<n;i++)lowc[i]=cost[0][i];
	for(int i=1;i<n;i++){
		int minc=INF;
		int p=-1;
		for(int j=0;j<n;j++)
			if(!vis[j]&&minc>lowc[j]){
				minc=lowc[j];
				p=j;
				
			}
		if(minc==INF)return -1;
		
		ans+=minc;
		vis[p]=true;
		for(int j=0;j<n;j++)
		if(!vis[j]&&lowc[j]>cost[p][j]){
			lowc[j]=cost[p][j];
			if(minc)all.push_back(make_pair(i,p));
		}	
	}
	return ans;
}

int main(){
	int n,t;
	cin>>n;
	memset(g,INF,sizeof(g));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>t;
			if(j!=i){
				g[i][j]=t;
				g[j][i]=t;
			}
		}
	}

	int ans=Prim(g,n);
	cout<<all.size()<<endl;
	for(int i=0;i<all.size();i++){
		cout<<all[i].first<<" "<<all[i].second<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}