#include <iostream>
#include <algorithm>   //基本的dfs
#include <cstdio>
using namespace std;
const int maxn=101;
char maps[maxn][maxn];
int n,m,c;
int dirx[]={-1,-1,-1,0,0,1,1,1};
int diry[]={-1,0,1,-1,1,-1,0,1};

void dfs(int x,int y){
	if(x>n||x<1||y<1||y>m||maps[x][y]=='*')return;
	maps[x][y]='*';
	c--; //剪枝
	for(int i=0;i<8;i++){
		int tx=x+dirx[i];
		int ty=y+diry[i];
		dfs(tx,ty);
	}
}
int main(){
	int ans;
	while(cin>>n>>m&&n&&m){
		ans=0;
		c=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>maps[i][j];
				if(maps[i][j]=='@')c++;    //为剪枝设计
			}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(maps[i][j]=='@'){
					ans++;
					dfs(i,j);
					if(c==0)break;
				}
			}
			if(c==0)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}