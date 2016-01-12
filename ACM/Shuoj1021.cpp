#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int vistd[101][101];
int dis[101][101];
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
int n,m;
void bfs(int x,int y){
	queue<pair<int ,int> >a;
	a.push(make_pair(x,y));
	vistd[x][y]=1;
	while(!a.empty()){
		x=a.front().first;
		y=a.front().second;
		a.pop();
		for(int i=0;i<4;i++){
			int tx=x+dirx[i];
			int ty=y+diry[i];
			if((tx>=0&&ty>=0&&tx<n&&ty<m)&&dis[tx][ty]!=-1&&!vistd[tx][ty]){
				vistd[tx][ty]=1;
				dis[tx][ty]=dis[x][y]+1;
				a.push(make_pair(tx,ty));
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	char c;
	while(t--){
		memset(vistd,0,sizeof(vistd));
		memset(dis,0,sizeof(dis));
		int startx,starty,endx,endy;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>c;
				if(c=='S')startx=i,starty=j;
				else if(c=='E')endx=i,endy=j;
				else if(c=='#')dis[i][j]=-1;
			}
			bfs(startx,starty);
			cout<<dis[endx][endy]<<endl;
	}
	return 0;
}