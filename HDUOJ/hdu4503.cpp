/*************************************************************************
	> File Name: hdu4503.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月01日 星期一 21时55分42秒
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
	int t;
	cin>>t;
	int tm;
	while(t--){
		int sum=0;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&tm);
			sum+=tm*(n-tm-1);
		}
		double ans=(3.0*sum)/(n*(n-1)*(n-2));
		printf("%.3lf\n",1-ans);
	}

	return 0;
}

