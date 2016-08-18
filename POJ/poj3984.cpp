#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

struct node{
	int x,y,px,py,dis;
	node(int a,int b,int c,int d,int e){
		x=a;
		y=b;
		px=c;
		py=d;
		dis=e;
	}
	node(){

	}
};

int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
int g[5][5];
node dis[5][5];

bool can(int x,int y){
	if(x<0||x>=5||y<0||y>=5||g[x][y]==1)return false;
	return true;
}

void show(int x,int y){
	if(x==-1&&y==-1)return;
	show(dis[x][y].px,dis[x][y].py);
	printf("(%d, %d)\n",x,y);
}

void bfs(){
	queue<node>qu;
	node t(0,0,-1,-1,0);
	qu.push(t);
	dis[0][0]=t;
	g[0][0]=1;
	while(!qu.empty()){
		node t1=qu.front();
		qu.pop();
		for(int i=0;i<4;i++){
			int x=t1.x+di[i];
			int y=t1.y+dj[i];
			if(can(x,y)){
				node t2(x,y,t1.x,t1.y,t1.dis+1);
				dis[x][y]=t2;
				qu.push(t2);
				g[x][y]=1;
			}
		}
	}
	show(4,4);
}
int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			cin>>g[i][j];
	}
	bfs();
	return 0;
}