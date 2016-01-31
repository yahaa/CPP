#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=101;
const int INF = 0x3FFFFFFF;
int n,m;
int maps[maxn][maxn];

void init(){
	for(int i=1;i<maxn;i++){
		for(int j=1;j<maxn;j++){
			if(i==j)maps[i][j]=0;
			else maps[i][j]=INF;
		}
	}
}

void add_edge(int a,int b,int c){
	maps[a][b]=c;
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
			}
}


int main(){
	int a,b,c;
	while(cin>>n>>m&&n&&m){
		init();
		while(m--){
			cin>>a>>b>>c;
			add_edge(a,b,c);
			add_edge(b,a,c);
		}

		floyd();
		cout<<maps[1][n]<<endl;
	}
	return 0;
}