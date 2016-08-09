#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define ll long long
ll fac[10005][10005];
ll prime[1300];		//10000之内的素数不到 1300个 
ll inv[10005][10005];		//阶乘逆元 
int ant = 0;		//素数个数 
bool p[10011];
const int maxn=10000;
void getprime(){
	memset(p,true,sizeof(p));
	for (int i=2;i<=maxn;i++){
		if (p[i]){
			prime[ant++]=i;
			for(int j=i+i;j<=maxn;j+=i)p[j]=false;
		}
	}
}

ll quick_mod(ll n,ll m,ll mod){
	ll ans=1;
	n %= mod;
	while (m){
		if(m&1)ans = (ans * n) % mod;
		n =n*n%mod;
		m>>=1;
	}
	return ans;
}

void getfac(){
    for(int i=0;i<ant;i++){
        fac[prime[i]][0]=inv[prime[i]][0]=1;
        for(int j=1;j<prime[i];j++){
            fac[prime[i]][j]=(fac[prime[i]][j-1]*j)%prime[i];
            inv[prime[i]][j]=quick_mod(fac[prime[i]][j],prime[i]-2,prime[i]);
        }
    }
}

ll C(ll n,ll k,ll mod){
	if (k > n)return 0;
	else if (n == k)return 1;
	else
		return fac[mod][n] * (inv[mod][k] * inv[mod][n-k] % mod) % mod;
		//return fac[mod][n] * (inv[mod][fac[mod][k] * fac[mod][n-k] % mod]) % mod;		//实在是想不通这样求逆元错在哪里 
}

ll Lucas(ll n , ll k , ll mod){
	if (k == 0)		//递归终止条件 
		return 1;
	else
		return C(n % mod , k % mod , mod) * Lucas(n / mod , k / mod , mod) % mod;
}

int main(){
	ll mod;
	getprime();		//预处理素数表 
	getfac();		//预处理阶乘表 
	int Case = 1;
	ll n,k;
	while (~scanf ("%lld %lld %lld",&n,&k,&mod)){
		printf ("Case #%d: ",Case++);
		if (2*k > n)k = n-k;
		printf ("%lld\n",(Lucas(n+1 , k , mod) + n - k) % mod);
	}
	return 0;
}