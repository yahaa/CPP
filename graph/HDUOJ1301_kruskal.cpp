#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int maxn=30;
int preant[maxn];
struct graph{
	int s,e,w;
};
vector<graph>G;

void init(int n){
	G.clear();
	for(int i=0;i<=n;i++)preant[i]=i;
}

bool cmp(graph a,graph b){
	return a.w<b.w;
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


int kruskal(int n){
	sort(G.begin(),G.end(),cmp);
	int ans=0,counts=0;
	for(int i=0;i<G.size();i++){
		int s=G[i].s;
		int e=G[i].e;
		int w=G[i].w;
		int ts=find(s);
		int te=find(e);
		if(ts!=te){
			join(ts,te);
			counts++;
			ans+=w;
		}
		if(counts==n-1)break;
	}
	if(counts<n-1)ans=-1;
	return ans;
}

int main(){
	int n,e=1,m,w;
	map<char,int>node;
	graph temp;
	char start,ends;
	for(int i=65;i<=92;i++)node[(char)i]=e++;
	while(cin>>n&&n){
		init(n);
		for(int i=1;i<=n-1;i++){
			cin>>start>>m;
			while(m--){
				cin>>ends>>w;
				temp.s=node[start];
				temp.e=node[ends];
				temp.w=w;
				G.push_back(temp);
			}
		}

	int ans=kruskal(n);
	cout<<ans<<endl;

	}
	return 0;
}
