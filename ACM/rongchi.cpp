
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod = 1000007;
const int maxn = 505;
ll C[maxn][maxn];
void inital(){
    memset(C, 0, sizeof(C));
      C[0][0] = 1;
    for (int i = 1; i<505; ++i)
    {
        C[0][i] = 1;
        for (int j = 1; j <= i; ++j)
        {
            C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
            C[j][i] %= 1000007;
        }
    }
}
 
void solve(int n, int m, int k){
 
    if (k<2 || k>n*m)cout << 0 << endl;
    else{
        long long ans = 0;
        ans = C[k][n*m] - 2 * C[k][(n - 1)*m] + C[k][(n - 2)*m] - 2 * C[k][n*(m - 1)] + C[k][n*(m - 2)] + (4 * C[k][(n - 1)*(m - 1)]) % 1000007;
        ans %= 1000007;
        ans = ans - 2 * C[k][(n - 1)*(m - 2)] - 2 * C[k][(m - 1)*(n - 2)] + C[k][(n - 2)*(m - 2)];
        while (ans<0)ans += 1000007;
        cout << ans % 1000007 << endl;
    }
     
}

int main(){
    inital();
    int t;
    cin >> t;
    int n, m, k;
    int j=1;
    while (t--){
        cin >> n >> m >> k;
        cout<<"Case "<<j++<<": ";
        solve(n, m, k);
    }
    return 0;
}