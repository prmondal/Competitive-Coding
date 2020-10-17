ll modpow(ll x, ll b, int mod){
    ll res = 1;
    while(b){
        if(b&1)res = res * x % mod;
        x = x * x % mod;
        b>>=1;
    }
    return res;
}
 
ll modinv(ll x, int mod){
    return modpow(x, mod-2, mod);
}

ll modadd(ll a, ll b, int mod) {
    return (a + b) % mod;
}

ll modsub(ll a, ll b, int mod) {
    ll c = (a - b) % mod;
    if (c < 0) return (c + mod) % mod; 
    return c;
}

ll modmul(ll a, ll b, int mod) {
    return (a * b) % mod;
}

ll moddiv(ll a, ll b, int mod) {
    return (a * modpow(b, mod-2, mod)) % mod;
}