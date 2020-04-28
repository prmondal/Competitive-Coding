#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> pnts(2*n);

    for (int i = 0; i < 2*n; i++) cin >> pnts[i];

    sort(pnts.begin(), pnts.end());

	vector<pair<ll,ll>> coors(n);

	for (int i = 0; i < n; i++) {
		coors[i] = {pnts[i], pnts[n - i - 1]};
	}

	ll ans = abs(coors[n - 1].first - coors[0].first) * abs(coors[n - 1].second - coors[0].second);
	cout << ans << endl;
}
