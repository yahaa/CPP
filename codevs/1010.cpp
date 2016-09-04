#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mx=25;
int g[mx][mx];
int di[]={-2,-2,-1,-1,1,1,2,2};
int dj[]={-1,1,-2,2,-2,2,-1,1};
int bx,by,x,y;
bool can(int xi,int yj){
	if(x==xi&&y==yj)return 0;
	for(int i=0;i<8;i++){
		int tx=x+di[i];
		int ty=y+dj[i];
		if(tx==xi&&ty==yj)return 0;
	}
	return 1;
}
int main(){
	
	while(cin>>bx>>by>>x>>y){
		memset(g,0,sizeof(g));
		g[0][0]=1;
		for(int i=1;i<mx;i++){
			if(!can(0,i))g[0][i]=0;
			else g[0][i]=g[0][i-1];
			if(!can(i,0))g[i][0]=0;
			else g[i][0]=g[i-1][0];
		}
		for(int i=1;i<mx;i++){
			for(int j=1;j<mx;j++){
				if(!can(i,j))g[i][j]=0;
				else g[i][j]=g[i-1][j]+g[i][j-1];
			}
		}
		cout<<g[bx][by]<<endl;
	}
	return 0;
}