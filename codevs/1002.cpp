/*************************************************************************
	> File Name: 1002.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月04日 星期四 16时09分21秒
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
const int maxn=55;
bool use[maxn][maxn];
int  vi[maxn][maxn];
char mp[maxn][maxn];
int di[8]={0,0,-1,-1,-1,1,1,1};
int dj[8]={-1,1,-1,0,1,-1,0,1};
int n,m;
int G[maxn][maxn];


void visit(int x,int y,int index){
	if(x<0||x>=n||y<0||y>=m||mp[x][y]=='.'||vi[x][y])return;
	vi[x][y]=index;
	for(int i=0;i<8;i++){
		int tx=di[i]+x,ty=dj[i]+y;
		visit(tx,ty,index);
	}
}


void fourd(int x,int y){
	for(int i=x+1;i<n;i++){
		if(y-1>=0){
			G[vi[x][y]][vi[i][y]]=min(G[vi[x][y]][vi[i][y]],);
		}
	}
}


void buildG(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vi[i][j])fourd(i,j);
		}
	}
}

void init(){
	memset(use,0,sizeof(use));
	memset(vi,0,sizeof(vi));
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			G[i][j]=INF;
		}
	}
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	
	while(cin>>n>>m){
		init();
		for(int i=0;i<n;i++)scanf("%s",mp[i]);
		int ans=0;
		int total=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mp[i][j]=='#'&&vi[i][j]==0){
					total++;
					visit(i,j,total);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<vi[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}


/*
3 5
#...#
..#..
#...#
*/

