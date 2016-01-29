#include <iostream>
#include <algorithm> //BFS  输入的地方有点特殊，其他还是一样的
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int maxn=101,maxm=11;
char maps[maxn][maxm];
int n,m;
int starti,startj,endi,endj;
int dis[maxn][maxm];
int dirx[]={-1,0,0,1};
int diry[]={0,-1,1,0};

void bfs(int x,int y){
	queue<pair<int,int> >a;
	a.push(make_pair(x,y));
	while(!a.empty()){
		x=a.front().first;
		y=a.front().second;
		a.pop();
		for(int i=0;i<4;i++){
			int tx=x+dirx[i];
			int ty=y+diry[i];
			if(tx>=0&&tx<n&&ty>=0&&ty<m&&maps[tx][ty]!='X'){
				if(!(tx==starti&&ty==startj)&&dis[tx][ty]==0){
					dis[tx][ty]=dis[x][y]+1;
					a.push(make_pair(tx,ty));
				}
			}
		}
	}
}
int main(){
	string start,end;
	while(cin>>start>>n){
		memset(dis,0,sizeof(dis));
		m=n;
		n*=n;
		for(int i=0;i<n;i++)cin>>maps[i];
		int slices1;
		cin>>starti>>startj>>slices1;
		int slices2;
		cin>>endi>>endj>>slices2;
		cin>>end;
		starti=starti+slices1*m;
		endi=endi+slices2*m;
		bfs(starti,startj);

		if(starti==endi&&startj==endj)cout<<m<<" "<<0<<endl;
		else {
			if(dis[endi][endj])cout<<m<<" "<<dis[endi][endj]<<endl;
			else cout<<"NO ROUTE"<<endl;
		}
	}
	return 0;
}