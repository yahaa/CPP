#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=101;
int preant[maxn];
struct graph{
	int s,e,w;
};
vector<graph>G;


int find(int x){   //并查集中的找
	int r=x;
	while(preant[r]!=r)r=preant[r];

	int tr=x,tp;//路径压缩
	while(preant[tr]!=r){
		tp=preant[tr];
		preant[tr]=r;
		tr=tp;
	}
	return r;
}

void join(int a,int b){//h合并
	int x=find(a);
	int y=find(b);
	if(x!=y){
		preant[x]=y;
	}
}

bool cmp(graph a,graph b){//降序
	return a.w<b.w;
}

int kruskal(int n){   //时间复杂度由边的数量决定　　假设有　　m条边　　时间复杂度　　为　O(mlogm)
	sort(G.begin(),G.end(),cmp);
	int ans=0,count=0;
	for(int i=0;i<G.size();i++){
		int s=G[i].s;
		int e=G[i].e;
		int w=G[i].w;
		int ts=find(s);
		int te=find(e);
		if(ts!=te){
			join(ts,te);
			ans+=w;
			count++;
		}
		if(count==n-1)break;
	}
	if(count<n-1)ans=-1;
	return ans;
}

void init(int n){
	G.clear();
	for(int i=0;i<=n;i++)preant[i]=i;
}

int main(){
	int n,m,a,b,w;
	graph temp;
	while(cin>>m>>n){
		if(m==0)break;
		init(n);
		while(m--){
			cin>>a>>b>>w;
			temp.s=a;
			temp.e=b;
			temp.w=w;
			G.push_back(temp);
		}
		
		int ans=kruskal(n);
		if(ans==-1)cout<<"?"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}