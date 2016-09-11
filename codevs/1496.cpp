/*************************************************************************
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
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
int g[1200][1200];
int [][]dir= { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } };
int title = 0;
void setColor(int style, int r, int c) {
	title++;
	for (int i = 0; i < 4; i++)
		if (i == style) { 
			for (int j = 0; j < 4; j++)
				if (i != j){
					int x=r + dir[j][0]+1;
					int y=c + dir[j][1]+1;
					g[x][y]=i+1;
				}
	}
}

void cover(int startR, int startC, int dr, int dc, int size) {
	if (size == 1)return;
	int s = size / 2;
	int rr = (dr >= startR + s)?1:0;
	int cc = (dc >= startC + s)?1:0;
	for (int i = 0; i < 4; i++) {
		if (dir[i][0] == rr && dir[i][1] == cc) {
			for (int j = 0; j < 4; j++) {
				if (j == i)
					cover(startR + s * dir[j][0], startC + s * dir[j][1],dr, dc, s);
				else {
					cover(startR + s * dir[j][0], startC + s * dir[j][1],
						startR + s - 1 + dir[j][0],
						startC + s - 1 + dir[j][1], s);
				}
			}
		}
	}
}

int main(){
	int n,x,y;
	while(cin>>n){
		n=1<<n;
		cin>>x>>y;
		g[x][y]
		cover(0,0,x-1,y-1,n);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
			}
		}

	}
	return 0;
}
