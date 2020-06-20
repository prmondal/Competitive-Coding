#include <bits/stdc++.h>
using namespace std;
const int MAXN = 999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;

        int mind = MAXN;
        int minf = MAXN;

        int p[n], b[n];
        for (int i = 1; i <= n; i++) cin >> p[i-1];
        for (int i = 1; i <= n; i++) cin >> b[i-1];

        for (int i = 1; i <= n; i++) {
            if (b[i-1] == 0) {
                mind = min(mind, p[i-1]);
            } else {
                minf = min(minf, p[i-1]);
            }
        }

        if (n < 2) {
            cout << "no" << endl;
        } else {
            if (mind + minf <= 100-s)
                cout << "yes" << endl;
            else
                cout << "no" << endl;   
        }
    }
}
