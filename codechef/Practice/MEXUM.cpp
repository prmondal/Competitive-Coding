#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAXN =1e5+7;
ll p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p[0] = 1;
    for (int i = 1; i <= MAXN; i++) p[i] = (2LL*p[i-1]) % MOD;

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        ll ans = 0;
        ll prod = 1;
        ll sum = 0;

        for (ll mex = 1; mex <= n+1; mex++) {
            sum = (sum + mp[mex]) % MOD;

            ll newmex = (mex * prod) % MOD;
            newmex = (newmex * p[n-sum]) % MOD;
            
            ans = (ans + newmex) % MOD;
            prod = (prod * (p[mp[mex]] - 1)) % MOD;
        }

        cout << ans << endl;
    }
}
