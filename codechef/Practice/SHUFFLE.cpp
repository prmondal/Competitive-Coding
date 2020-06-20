#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int a[n], b[n];
        FOR(i,n) {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(a, a+n);
        bool possible = true;

        if (k==n) {
            possible = false;
        } else {
            FOR(i,n) {
                auto rmin = lower_bound(a, a+n, b[i]);
                auto rmax = upper_bound(a, a+n, b[i]);
                int idx = rmin - a;

                // handle duplicate
                if (rmax != a+n && rmax - rmin >= 2) {
                    if (k < rmax - rmin) possible = false;
                } else if (abs(i-idx) % k != 0) {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible?"yes":"no") << endl;
    }
}