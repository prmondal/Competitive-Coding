#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;

        long p[n];
        for (int i = 0; i < n; i++) cin >> p[i];

        sort(p, p+n, greater<>());
        long ans = 0;
        long d = 0;

        for (int i = 0; i < n; i++) {
            long curr = max(p[i]-d, 0L);
            ans = (ans + curr) % MOD;
            d++;
        }

        cout << ans << endl;
    }
}
