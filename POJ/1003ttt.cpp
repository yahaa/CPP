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
const int maxn=60000+5;
ll a[maxn],b[maxn];
int main(){
	int t,n;
	ll suma,sumb;
	cin>>t;
	while(t--){
		cin>>n;
		suma=0,sumb=0;
		ll amin=10000000000,amx=-1000000000,bmin=1000000000,bmx=-1000000000;
		int ai,aj,bi,bj;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			suma+=a[i]*a[i];
			if(a[i]<amin){
				amin=a[i];
				ai=i;
			}
			if(a[i]>amx){
				amx=a[i];
				aj=i;
			}

		}
		for(int i=0;i<n;i++){
			scanf("%lld",&b[i]);
			sumb+=b[i]*b[i];
			if(b[i]<bmin){
				bmin=b[i];
				bi=i;
			}
			if(b[i]>bmx){
				bmx=b[i];
				bj=i;
			}
		}

		
		int k1=abs(ai-bi);
		int k2=abs(aj-bj);
		int k3=min(k1,k2);
		int k4=max(k1,k2);

		ll sum=0;
		for(int k=k3;k<=k4;k++){
			ll tsum1=0;
			for(int i=0;i<n;i++){
				tsum1+=a[i]*b[(i+k)%n];
			}
			sum=max(sum,tsum1);
		}
		
		cout<<suma+sumb-2*sum<<endl;


	}
	return 0;
}
