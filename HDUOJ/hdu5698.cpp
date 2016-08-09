/*************************************************************************
	> File Name: hdu5698.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月09日 星期二 17时28分43秒
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
const ll mod=1000000007;

ll pows(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}


ll C(ll n,ll m){
	ll ans=1;
	for(int i=1;i<=m;i++){
		ll a=(n-m+i)%mod;
		ll b=i%mod;
		ans=ans*(a*pows(b,mod-2)%mod)%mod;
	}
	return ans;
}


ll lucas(ll n, ll m){  
    if(m == 0) return 1;  
    return C(n%mod, m%mod) * lucas(n/mod,m/mod)%mod;  
} 

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	ll n,m;
	while(cin>>n>>m){
		n=n+m-4;
		m-=2;
		printf("%lld\n",lucas(n,m));
	}
	return 0;
}

