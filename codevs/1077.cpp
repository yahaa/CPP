/*************************************************************************
	> File Name: 1077.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月18日 星期四 12时37分51秒
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
int g[mx][mx];
int n;

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)g[i][j]=0;
			else g[i][j]=INF;
		}
	}
}

void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		}
		floyd();
		int m;
		scanf("%d",&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",g[--a][--b]);
		}
	}
	return 0;
}

