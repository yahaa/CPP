ll power_mod(ll a, ll b, ll mod){
    ll ans = 1;
    while (b){
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

//费马小定理求逆元
inv2 = power_mod(a, mod - 2, mod);