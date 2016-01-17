#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const LL mod=1000000007;
int cnt;
LL quick_mod(LL a,LL b)
{
    LL ans = 1;
    a %= mod;
    while(b)
    {
        if(b & 1)ans = ans * a % mod;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

LL Work(LL n)
{
    LL ans = 0;
    while(n)
    {
        ans += n /mod;
        n /= mod;
    }
    return ans;
}

LL Solve(LL n,LL m)
{
    LL ans = 1;
    for(int i=0; i<cnt && p[i]<=n; i++)
    {
        LL x = Work(n);
        LL y = Work(n - m);
        LL z = Work(m);
        x -= (y + z);
        ans *= quick_mod(p[i],x);
        ans %= P;
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        LL n,m,P;
        cin>>n>>m>>P;
        n += m - 2;
        m--;
        cout<<Solve(n,m,P)<<endl;
    }
    return 0;
}
