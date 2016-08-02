/*************************************************************************
	> File Name: hud5775.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月28日 星期四 21时17分43秒
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
const int maxn=100005;
int b[maxn];
int le[maxn];
int ri[maxn];
int n;
void add(int i,int v){
	while(i<=n){
		b[i]+=v;
		i+=i&-i;
	}
}

int sum(int i){
	int s=0;
	while(i>0){
		s+=b[i];
		i-=i&-i;
	}
	return s;
}
int a[maxn];

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int t;
	int k=1;
	cin>>t;
	int tm;
	while(t--){
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		for(int i=n;i>=1;i--){
			ri[a[i]]=sum(a[i])+i;
			le[a[i]]=min(i,a[i]);
			add(a[i],1);
		}
		printf("Case #%d:",k++);
		for(int i=1;i<=n;i++){
			printf(" %d",ri[i]-le[i]);
		}
		printf("\n");
	}

	return 0;
}

