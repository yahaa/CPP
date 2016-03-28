#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b){
    if (b == 0) return a;
    return GCD(b, a%b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, x1, x2;
        cin >> a >> b;
        x1 = b;
        for (int i = 1; i<a; i++){
            cin >> b;
            if (x1<b){
                x2 = x1;
                x1 = b;
                b = x2;
            }
            x1=x1*b/GCD(x1, b);
        }
        cout << x1 << endl;
    }
    return 0;
}