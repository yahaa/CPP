
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
int di[4]={1,-1,0,0};
int dj[4]={0,0,-1,1};
char g[505][505];
int m,n;
int a[17];

void dfs(int x,int y,int &k){
	if(x>=m||x<0||y>=n||y<0)return;
	if(g[x][y]=='#')return;
	if(g[x][y]=='.')k++;
	g[x][y]='#';
	for(int i=0;i<4;i++){
		int tx=x+di[i];
		int ty=y+dj[i];
		dfs(tx,ty,k);
	}
}
int main(){
	while(cin>>m>>n){
		memset(a,0,sizeof(a));
		m=5*m+1;
		n=5*n+1;
		for(int i=0;i<m;i++)scanf("%s",g[i]);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(g[i][j]!='#'){
					int k=0;
					dfs(i,j,k);
					a[k]++;
					k=0;
				}
			}
		}
		cout<<a[16]<<" "<<a[12]<<" "<<a[8]<<" "<<a[4]<<" "<<a[0]<<endl;
	}
	
	
	return 0;
}

