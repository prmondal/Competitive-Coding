const int N=5007; // can be changed
int fact[N],invfact[N];

ll modpow(ll x, ll b, int mod){
    ll res = 1;
    while(b){
        if(b&1)res = res * x % mod;
        x = x * x % mod;
        b>>=1;
    }
    return res;
}

void preComF(){
	fact[0]=1;
	int i;
	for(i=1;i<N;i++){
		fact[i]=i*fact[i-1]%mod;
	}
	i--;
	invfact[i]=modpow(fact[i],mod-2,mod);
	for(i--;i>=0;i--){
		invfact[i]=invfact[i+1]*(i+1)%mod;
	}
}

int ncr(int n, int r, int mod){
	if(r > n || n < 0 || r < 0) return 0;
	return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}
