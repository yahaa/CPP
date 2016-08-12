#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}

int main(){
	ll t;
	cin>>t;
	ll a,b,c,d;
	while(t--){
		scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
		ll t=gcd(a,b);
		a/=t;
		b/=t;
		t=gcd(c,d);
		c/=t;
		d/=t;

		if(gcd(b,d)==1){
			printf("%lld\n",lcm(a,c));
		}
		else printf("%lld/%lld\n",lcm(a,c),gcd(b,d));
	}
	return 0;
}