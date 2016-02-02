#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=101;
int counts;
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
	int n,m,a,b,w,t;
	graph temp;
	while(scanf("%d",&n)&&n){
		init(n);
		m=n*(n-1)/2;
		while(m--){
			scanf("%d%d%d%d",&a,&b,&w,&t);
			temp.s=a;
			temp.e=b;
			temp.w=w;
			if(t){
				join(a,b);
				counts++;
			}
			else G.push_back(temp);
		}
		
		int ans=kruskal(n);
		printf("%d\n",ans);
	}
	return 0;
}