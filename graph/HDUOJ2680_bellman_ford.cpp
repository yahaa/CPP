#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=1001;
const int INF=0x3FFFFFF;
struct grap{
	int s,e,lengths;
};
vector<grap>maps;
int dis[maxn];
int n,m,gload;

void init(){
	maps.clear();
	for(int i=0;i<=n;i++)dis[i]=INF;
	dis[0]=0;
}

bool bellman_ford(){
	int nn=maps.size();
	for(int i=0;i<nn;i++)
		for(int j=0;j<nn;j++)dis[maps[j].e]=min(dis[maps[j].e],dis[maps[j].s]+maps[j].lengths);
	return true;
}

int main(){
	int ts,te,w,want,wants;
	grap temp1,temp2;
	while(scanf("%d%d%d",&n,&m,&gload)!=EOF){
		init();
		while(m--){
			scanf("%d%d%d",&ts,&te,&w);
			temp1.s=ts;
			temp1.e=te;
			temp1.lengths=w;
			maps.push_back(temp1);
		}

		scanf("%d",&want);
		while(want--){
			scanf("%d",&wants);
			temp1.s=0;
			temp1.e=wants;
			temp1.lengths=0;
			maps.push_back(temp1);
		}
		bellman_ford();
		if(dis[gload]!=INF)printf("%d\n",dis[gload]);
		else printf("%d\n",-1);
	}
	return 0;
}