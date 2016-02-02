#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=201;
const int INF=0X3FFFFF;
int preant[maxn];
struct graph{
	int s,e,w;
};
vector<graph>G;

void init(int n){
	G.clear();
}

bool cmp(graph a,graph b){
	return a.w<b.w;
}

void initpreant(int n){
	for(int i=0;i<=n;i++)preant[i]=i;
}

int find(int x){
	int r=x;
	while(preant[r]!=r)r=preant[r];

	int tr=x,tp;
	while(preant[tr]!=r){
		tp=preant[tr];
		preant[tr]=r;
		tr=tp;
	}
	return r;
}

void join(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		preant[x]=y;
	}
}

int main(){
	int n,m,s,e,w,Q;
	graph temp;
	while(cin>>n>>m){
		init(n);
		while(m--){
			cin>>s>>e>>w;
			temp.s=s;
			temp.e=e;
			temp.w=w;
			G.push_back(temp);
		}

		sort(G.begin(),G.end(),cmp);

		cin>>Q;
		while(Q--){
			cin>>s>>e;
			int ans=INF;
			for(int i=0;i<G.size();i++){
				initpreant(n);
				for(int j=i;j<G.size();j++){
					int ts=G[j].s;
					int te=G[j].e;
					int tss=find(ts);
					int tee=find(te);
					join(tss,tee);
					if(find(s)==find(e)){
						ans=min(ans,G[j].w-G[i].w);
						break;
					}
				}
			}
			if(ans==INF)cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
	return 0;
}
