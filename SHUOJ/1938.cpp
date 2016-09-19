#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long ll;
const int N =100000000;

bool prime[N];
ll p[N];
ll cnt;

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

ll work(ll n,ll p){
    ll ans = 0;
    while(n){
        ans += n / p;
        n /= p;
    }
    return ans;
}

ll Solve(ll n){
    ll ans = 0;
    for(int i=0; i<cnt && p[i]<=n; i++){
         int t=work(n, p[i]);
         if(t>0)ans++;
    }
    return ans;
}

int main(){

    isprime();
    cout<<cnt<<endl;
    ll n;
    while(cin>>n){
        cout<<Solve(n)<<endl;
    }
    return 0;
}
