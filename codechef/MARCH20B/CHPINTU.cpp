#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
    	int n,m;
    	cin >> n >> m;
    	
    	int f[n], p[n];
    	for (int i = 0; i < n; i++) cin >> f[i];
    	for (int i = 0; i < n; i++) cin >> p[i];
        bool found[m];
        memset(found, 0, sizeof found);
        
        vector<int> v(m, 0);
    	for (int i = 0; i < n; i++) {
    	    v[f[i]-1] += p[i];
    	    found[f[i]-1] = 1;
    	}
        
        int ans = INT_MAX;
        
    	for (int i = 0; i < m; i++) {
    	    if (found[i] > 0) ans = min(ans, v[i]);
    	}
    	
    	cout << ans << endl;
    }
}
