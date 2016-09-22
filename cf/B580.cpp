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
const int maxn=100005;
struct people{
	int m,f;
};
people p[maxn];

bool cmp(people a,people b){
	return a.m<b.m;
}

int main(){
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>p[i].m>>p[i].f;
	}
	sort(p,p+n,cmp);
	ll sum=0;
	ll ans=0;
	int j=0,i=0;
	while(i<n){
		while(j<n&&p[j].m<p[i].m+d){
			sum+=p[j].f;
			j++;
		}
		ans=max(ans,sum);
		sum-=p[i++].f;
	}
	cout<<ans<<endl;
	return 0;
}
