#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 200005;

bool prime[N];
int p[N];
int cnt;

void isprime(){
    cnt = 0;
    memset(prime,true,sizeof(prime));
    for(int i=2; i<N; i++){
        if(prime[i]){
            p[cnt++] = i;
            for(int j=i+i; j<N; j+=i)
                prime[j] = false;
        }
    }
}

ll quick_mod(ll a,ll b,ll m){
    ll ans = 1;
    a %= m;
    while(b){
        if(b & 1)ans = ans * a % m;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

ll work(ll n,ll p){
    ll ans = 0;
    while(n){
        ans += n / p;
        n /= p;
    }
    return ans;
}

ll Solve(ll n,ll m,ll P){
    ll ans = 1;
    for(int i=0; i<cnt && p[i]<=n; i++){
        ll x = work(n, p[i]);
        ll y = work(n - m, p[i]);
        ll z = work(m, p[i]);
        x -= (y + z);
        ans=ans*quick_mod(p[i],x,P)%P;
        ans %= P;
    }
    return ans;
}

int main(){
    int t;
    isprime();
    cin>>t;
    while(t--){
        ll n,m,P;
        cin>>n>>m>>P;
        cout<<Solve(n,m,P)<<endl;
    }
    return 0;
}
