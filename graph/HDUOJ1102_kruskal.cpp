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
int counts;    //用于统计城市个数


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
	int ans=0;
	for(int i=0;i<G.size();i++){
		int s=G[i].s;
		int e=G[i].e;
		int w=G[i].w;
		int ts=find(s);
		int te=find(e);
		if(ts!=te){
			join(ts,te);
			ans+=w;
			counts++;
		}
		if(counts==n-1)break;
	}
	if(counts<n-1)ans=-1;
	return ans;
}

void init(int n){
	G.clear();
	for(int i=0;i<=n;i++)preant[i]=i;
	counts=0;
}

int main(){
	int n,w,q,a,b;
	graph temp;
	while(cin>>n){
		init(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
			cin>>w;
			if(i!=j){
			temp.s=i;
			temp.e=j;
			temp.w=w;
			G.push_back(temp);
			}
		}
		cin>>q;
		while(q--){
			cin>>a>>b;
			int ts=find(a);
			int te=find(b);
			if(ts!=te){
			join(ts,te);
			counts++;
			}
		}

		int ans=kruskal(n);
		cout<<ans<<endl;
	}
	return 0;
}