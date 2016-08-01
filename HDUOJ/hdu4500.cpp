/*************************************************************************
	> File Name: hdu4500.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月01日 星期一 20时27分16秒
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

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n,m;
	int a[21][21];
	int aa=-100;
	int t;
	while(scanf("%d%d",&n,&m)&&n&&m){
		aa=-100;
		int ti=0;
		int tj=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				t=0;
				if(i-1>=0){
					if(a[i][j]*a[i-1][j]>0)t-=abs(a[i-1][j]);
					else t+=abs(a[i-1][j]);
				}
				if(i+1<n){
					if(a[i][j]*a[i+1][j]>0)t-=abs(a[i+1][j]);
					else t+=abs(a[i+1][j]);
				}
				if(j-1>=0){
					if(a[i][j]*a[i][j-1]>0)t-=abs(a[i][j-1]);
					else t+=abs(a[i][j-1]);
				}
				if(j+1<m){
					if(a[i][j+1]*a[i][j]>0)t-=abs(a[i][j+1]);
					else t+=abs(a[i][j+1]);
				}
				if(t>aa){
					aa=t;
					ti=i;
					tj=j;
				}
				// else if(aa==t){
				// 	if(i<ti){
				// 		ti=i;
				// 		tj=j;
				// 	}
				// 	else if(ti==i){
				// 		if(j<tj){
				// 			ti=i;
				// 			tj=j;
				// 		}
				// 	}
				// }
			}
		}

		cout<<ti+1<<" "<<tj+1<<" "<<aa<<endl;

	}

	return 0;
}

