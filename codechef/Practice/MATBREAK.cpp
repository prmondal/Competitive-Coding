#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 1e9+7;

ll modexp(ll a, ll p) {
	ll ans = 1;

	while (p > 0) {
		if (p & 1) {
			ans *= a;
			if (ans >= mod) ans %= mod;
		}

		a = a*a;
		if (a >= mod) a = a%mod;
		p = p >> 1;
	}

	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
    	ll n, a;
    	cin>>n>>a;
    	
    	ll last1 = a;
    	ll last2 = a;
    	ll ans = last1;

    	//2^1 + (2*2)^3 + ((2*2)*(2*2)^3)^5+...
    	for (ll i = 1, j = 1; i < n; i++, j += 2) {
    		ll k = 2*i+1;
    		last1 = (last1 * last2) % mod;
    		last2 = modexp(last1, k);
    		ans = (ans + last2) % mod;
    	}

    	printf("%lld\n", ans);
    }
}
