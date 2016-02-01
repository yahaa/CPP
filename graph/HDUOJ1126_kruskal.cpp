#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn=101;
int preant[maxn];
struct graph{
	int s,e;
	double w;
};
struct point{
	double x,y;
};
vector<graph>G;
vector<point>p;

void init(int n){
	G.clear();
	p.clear();
	for(int i=0;i<=n;i++)preant[i]=i;

}

double getlength(point a,point b){
	double l1=abs(a.x-b.x);
	double l2=abs(a.y-b.y);
	return sqrt(l1*l1+l2*l2);
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

double kruskal(int n){
	sort(G.begin(),G.end(),cmp);
	double ans=0;
	int counts=0;
	for(int i=0;i<G.size();i++){
		int s=G[i].s;
		int e=G[i].e;
		double w=G[i].w;
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


int main(){
	int n;
	double x,y;
	point tp;
	graph tg;
	while(cin>>n){
		init(n);
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			tp.x=x;
			tp.y=y;
			p.push_back(tp);
		}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				tg.s=i;
				tg.e=j;
				tg.w=getlength(p[i],p[j]);
				G.push_back(tg);
			}
		}
	}

	double ans=kruskal(n);
	printf("%.2f\n",ans);
	}
	return 0;
}