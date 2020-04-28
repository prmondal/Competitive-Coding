#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		bool rows[n + 1];
		bool cols[n + 1];
		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(rows));
		for(int i = 1; i <= k; i++) {
			int r, c;
			cin >> r >> c;
			rows[r] = 1;
			cols[c] = 1;
		}
		int p = 1;
		int rr = -1;
		int cc = 1;
		for(int r = 1; r <= n; r++) {
			if(!rows[r]) {
				rr = r;
				break;
			}
		}
		cout << n-k << " ";
		while(p <= n - k) {
			while(!rows[rr]) {
				if(!cols[cc]) {
					cout << rr << " " << cc << " ";
					p++;
					
					cols[cc] = 1;
					rows[rr] = 1;
					break;
				} else {
					cc++;
				}
			}
			rr++;
		}
		cout << endl;
	}
}
