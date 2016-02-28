#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=101;
const int INF=0X3FFFFFFF;
int maps[maxn][maxn];
int start[maxn],ed[maxn];

void add_edge(int a,int b,int w){
	maps[a][b]=min(maps[a][b],w);
}

void init(){
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++){
			 maps[i][j]=INF;
		}
	memset(start,0,sizeof(start));
	memset(ed,0,sizeof(ed));
}

bool floyd(){
	for(int k=0;k<=maxn;k++){
		for(int i=0;i<=maxn;i++){
			if(maps[i][k]!=INF)   //添加这个条件可以优化　　　　这里相当于剪枝
			for(int j=0;j<=maxn;j++){
				if(maps[i][k]==1&&maps[k][j]==1)maps[i][j]=1;
				if(maps[j][i]==1&&maps[j][i]==maps[i][j])return 0;
			}
		}
	}
	return 1;
}


int main(){
	int n,m,a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		while(m--){
			scanf("%d%d",&a,&b);
			add_edge(a,b,1);
		}
		if(floyd())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}