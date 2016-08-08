#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll f[maxn];

void init(ll mod){
	f[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
	}
}

ll pows(ll a,ll n,ll mod){
	ll ans=1;
	a%=mod;
	while(n){
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	ll n,m,k;
	while(t--){
		scanf("%lld%lld%lld",&n,&m,&k);
		init(k);
		cout<<f[n]*pows(f[m]*f[n-m],k-2,k)%k<<endl;
	}
	return 0;
}