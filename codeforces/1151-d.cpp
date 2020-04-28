#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> diss;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        diss.push_back({a, b});
    }

    sort(diss.begin(), diss.end(), [](const pair<ll, ll>& d1, const pair<ll, ll>& d2) {
        return d1.first - d1.second > d2.first - d2.second;
    });

    ll j = 1;

    for (auto p: diss) {
        ans += (p.second * n - p.first) + j * (p.first - p.second);
        j++;
    }

    cout << ans << endl;
}
