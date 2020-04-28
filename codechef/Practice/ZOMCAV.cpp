#include <bits/stdc++.h>
using namespace std;
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t;
   cin >> t;

   while(t--) {
        int n;
        cin >> n;

        int c[n+1], h[n+1], d[n+1], radiation[n+1];
        map<int, int> m;

        memset(c, 0, sizeof c);
        memset(h, 0, sizeof h);
        memset(d, 0, sizeof d);
        memset(radiation, 0, sizeof radiation);

        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        for (int i = 1; i <= n; i++) {
           if (c[i] == 0) continue;

           int l = max(1, i - c[i]);
           int r = min(n, i + c[i]);

           d[l] += 1;
           if (r < n) d[r + 1] += -1;
        }

        for (int i = 1; i <= n; i++) {
           cin >> h[i];
           m[h[i]]++;
        }

        bool possible = true;

        for (int i = 1; i <= n; i++) {
           if (i == 1) radiation[i] = d[i]; 
           else radiation[i] = radiation[i-1] + d[i];
           //cout << radiation[i] << " ";

           if (m.find(radiation[i]) == m.end() || m[radiation[i]] == 0) {
                possible = false;
                break;
           } else {
               m[radiation[i]]--;
           }
        }

        //cout << endl;

        cout << (possible ? "YES" : "NO") << endl;
   }
}