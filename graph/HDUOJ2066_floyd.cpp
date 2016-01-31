#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1001;
const int INF=0X3FFFFFFF;
int maps[maxn][maxn];
int start[maxn],ed[maxn];
int maxm;

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void init(){
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++){
			if(i==j)maps[i][j]=0;
			else maps[i][j]=INF;
		}
	memset(start,0,sizeof(start));
	memset(ed,0,sizeof(ed));
}

int floyd(){
	int ans=INF;
	for(int k=0;k<=maxm;k++)
		for(int i=0;i<=maxm;i++)
			if(maps[i][k]!=INF)   //添加这个条件可以优化　　　　这里相当于剪枝
			for(int j=0;j<=maxm;j++){
				maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
				if(start[i]&&ed[j])ans=min(ans,maps[i][j]);
			}
			return ans;
}


int main(){
	int t,s,d,a,b,w;
	while(scanf("%d%d%d",&t,&s,&d)!=EOF){
		init();
		while(t--){
			scanf("%d%d%d",&a,&b,&w);
			maxm=max(a,max(b,maxm));
			add_edge(a,b,w);
			add_edge(b,a,w);
		}
		int temp;
		while(s--){
			scanf("%d",&temp);
			start[temp]=1;
		}
		while(d--){
			scanf("%d",&temp);
			ed[temp]=1;
		}

		printf("%d\n",floyd());
	}
	return 0;
}