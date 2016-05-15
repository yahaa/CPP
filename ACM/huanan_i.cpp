/*************************************************************************
	> File Name: huanan_i.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月15日 星期日 12时25分15秒
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

struct dog{
	double i;
	double v;
};
dog dogs[11];
bool cmp(dog a,dog b){
	if(fabs(a.v)==fabs(b.v))return fabs(a.i)<fabs(b.i);
	else return fabs(a.v)>fabs(b.v);
}
int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n;
	double v;
	int cat[10];
	while(cin>>n>>v){
		for(int i=0;i<n;i++){
			cin>>dogs[i].i>>dogs[i].v;
		}
		MS(cat,0);
		sort(dogs,dogs+n,cmp);
		if(v<=fabs(dogs[0].v)&&dogs[0].i!=0)cout<<"Bad Dog"<<endl;
		else {
			double t=0;
			double x0=0;
			for(int i=0;i<n;i++){
				if(dogs[i].i==x0||cat[i])continue;
				double f=1;
				if(fabs(1*dogs[i].v+dogs[i].i-x0)<fabs(dogs[i].i-x0))f=-1;
				else f=1;
				t+=fabs(dogs[i].i+dogs[i].v*t-x0)/(v-f*fabs(dogs[i].v));
				x0=x0+(dogs[i].v>0)?v*t:-v*t;
			}
			printf("%.2f\n",t);
		}
	}


	return 0;
}

