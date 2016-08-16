/*************************************************************************
	> File Name: hdu1728.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月16日 星期二 11时45分02秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;
const int mx=105;
struct node{
	int x,y,k;
	node(int a,int b,int v){
		x=a;
		y=b;
		k=v;
	}
};

char g[mx][mx];
int vis[mx][mx];
int n,m;
int k,y11,x1,y2,x2;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

bool can(int x,int y){
	if(x<1||x>n||y<1||y>m||g[x][y]=='*')return false;
	return true;
}

bool bfs(){
	MS(vis,0);
	node s(x1,y11,-1);
	queue<node>qu;
	qu.push(s);
	vis[x1][y11]=1;
	while(!qu.empty()){
		node t=qu.front();
		qu.pop();
		if(t.x==x2&&t.y==y2&&t.k<=k)return true;
		for(int i=0;i<4;i++){
			int x=t.x+di[i];
			int y=t.y+dj[i];
			while(can(x,y)){
				if(!vis[x][y]){
					vis[x][y]=1;
					node tp(x,y,t.k+1);
					qu.push(tp);
				}
				x+=di[i];
				y+=dj[i];
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
		cin>>k>>y11>>x1>>y2>>x2;
		bool ans=bfs();
		if(ans)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}

	return 0;
}

