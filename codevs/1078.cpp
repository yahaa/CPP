#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
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
	int n;
	graph temp;
	while(cin>>n){
		init(n);
		int t;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&t);
				if(t!=0){
					temp.s=i;
					temp.e=j;
					temp.w=t;
					G.push_back(temp);
				}
			}
		}

		int ans=kruskal(n);
		cout<<ans<<endl;
	}
	
	return 0;
}