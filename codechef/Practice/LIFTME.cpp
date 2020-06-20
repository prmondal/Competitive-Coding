#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
    	int n, q;
    	cin>>n>>q;

    	long long ans = 0;
    	long long last = 0;

    	for (int i = 1; i <= q; i++) {
    		int s, e;
    		cin>>s>>e;

    		ans += abs(s-last);
    		ans += abs(e-s);
    		last = e;
    	}

    	cout << ans << endl;
    }
}
