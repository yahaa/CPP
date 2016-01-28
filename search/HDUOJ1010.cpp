#include <iostream>
#include <cstdio>
#include <algorithm>     //经典的搜索题　　　dfs
#include <string>
using namespace std;
const int maxn=8;
int n,m,t;
int si,sj,ei,ej;
char maps[maxn][maxn];
bool escape=false;
int dirx[]={1,0,0,-1};
int diry[]={0,-1,1,0};

void dfs(int x,int y,int count){
	if(x<1||x>n||y<1||y>m)return;
	if(count==t&&x==ei&&y==ej)escape=true;
	if(escape)return;

	int remaint=t-count; //剪枝
	int remains=abs(ei-x)+abs(ej-y);
	if((remaint%2==0&&remains%2!=0)||(remaint%2!=0&&remains%2==0)||remaint<remains)return; //奇偶剪枝

	for(int i=0;i<4;i++){   //跑dfs
		int tx=x+dirx[i];
		int ty=y+diry[i];
		if(maps[tx][ty]!='X'){
			maps[tx][ty]='X';
			dfs(tx,ty,count+1);
			maps[tx][ty]='.'; //回朔
		}
	}
}
int main(){
	while(cin>>n>>m>>t&&n&&m&&t){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>maps[i][j];
				if(maps[i][j]=='S')si=i,sj=j;
				if(maps[i][j]=='D')ei=i,ej=j;
			}
		}

	escape=false;
	maps[si][sj]='X';
	dfs(si,sj,0);
	if(escape)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
	}
	return 0;
}