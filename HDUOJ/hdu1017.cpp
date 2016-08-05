/*************************************************************************
	> File Name: hdu1017.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月05日 星期五 14时39分05秒
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

bool can(int a,int b,int m){
	return (a*a+b*b+m)%(a*b)==0?true:false;
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);

	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		if(ii)printf("\n");
		int n,m;
		int k=1;
		while(cin>>n>>m){
			if(n==0&&m==0)break;
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(can(i,j,m))ans++;
				}
			}
			printf("Case %d: %d\n",k++,ans);
		}
	}
	return 0;
}

