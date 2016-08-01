/*************************************************************************
	> File Name: hdu1054.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月29日 星期日 20时43分02秒
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
const int maxn=1505;
int G[maxn][maxn];
int used[maxn],match[maxn];
int v1,v2;

int dfs(int u){
	for(int i=1;i<=v2;i++){
		if(G[u][i]&&!used[i]){
			used[i]=1;
			if(!match[i]||dfs(match[i])){
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}


int bipart_match(){
	int ans=0;
	MS(match,0);
	for(int i=1;i<=v1;i++){
		MS(used,0);
		if(dfs(i))ans++;
	}
	return ans;

}



int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n;
	int s,e,num;
	string ss;
	while(cin>>n){
		MS(G,0);
		FOR(i,n){
			cin>>ss;
			s=ss[0]-'0';
			num=ss[3]-'0';
			FOR(j,num){
				cin>>e;
				G[s+1][e+1]=1;
			}
		}
		v1=v2=n;
		int ans=bipart_match();
		cout<<ans<<endl;
	}

	return 0;
}

