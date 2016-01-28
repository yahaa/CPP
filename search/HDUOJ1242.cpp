#include <iostream>
#include <algorithm>//经典的 bfs
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=201;
char maps[maxn][maxn];
int dis[maxn][maxn];
int n,m;
int starti,startj,endi,endj;
int dirx[]={-1,0,0,1};
int diry[]={0,-1,1,0};

void bfs(int x,int y){
	queue<pair<int,int> >ans;
	ans.push(make_pair(x,y));
	while(!ans.empty()){
		x=ans.front().first;
		y=ans.front().second;
		ans.pop();
		for(int i=0;i<4;i++){
			int tx=x+dirx[i];
			int ty=y+diry[i];
			if(tx>=0&&tx<n&&ty>=0&&ty<m&&maps[tx][ty]!='#'){
				int sets=(maps[tx][ty]=='x')?2:1;
				if((!(tx==starti&&ty==startj)&&dis[tx][ty]==0)||dis[tx][ty]>dis[x][y]+sets){
					dis[tx][ty]=dis[x][y]+sets;//利用dis[tx][ty]==0判断dis[tx][ty]是否走过
					ans.push(make_pair(tx,ty));//如果tx ty 走过通过判断dis[tx][ty]>dis[x][y]+sets更新dis[tx][ty]
				}
			}
		}
	}
}

int main(){
	while(cin>>n>>m){
		memset(dis,0,sizeof(dis));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>maps[i][j];
				if(maps[i][j]=='r'){
					starti=i;
					startj=j;
				}
				if(maps[i][j]=='a'){
					endi=i;
					endj=j;
				}
			}

			bfs(starti,startj);
			if(dis[endi][endj])cout<<dis[endi][endj]<<endl;
			else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}