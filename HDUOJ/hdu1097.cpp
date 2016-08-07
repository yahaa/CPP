/*************************************************************************
	> File Name: hdu1097.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月07日 星期日 18时52分23秒
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
int a[10];
void find(){
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=9;i++){
		int t=i;
		int c=1;
		while(1){
			t*=i;
			int e=t%10;
			if(e==i)break;
			c++;
		}
		a[i]=c;
	}
}
int main(){

	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	find();
	int n,m;
	while(cin>>n>>m){
			int e=n%10;
			if(e==0||e==1){
				cout<<e<<endl;
				continue;
			}
			int c=a[e];
			int re=m%c;
			re=(re==0)?c:re;
			cout<<((int)pow(e,re))%10<<endl;

	}

	return 0;
}

