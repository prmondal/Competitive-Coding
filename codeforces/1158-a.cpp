#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    vector<ll> b(n,0);
    vector<ll> g(m,0);

    ll ans = 0;
    ll bsum = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bsum += b[i];
    }
    
    for (int i = 0; i < m; i++) cin >> g[i];
    
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    
    ans += bsum;
    ans *= m;
    
    for (int i = 1; i < m; i++) {
        if (g[i] < b[n-1]) {
            cout << -1 << endl;
            return 0;
        }
        
        ans += g[i] - b[n-1];
    }

    if (g[0] < b[n-1]) {
        cout << -1 << endl;
        return 0;
    }

    if (g[0] != b[n-1]) ans += g[0] - b[n-2];
    
    cout << ans << endl;
}
