#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int a[n];
        int pref[n];
        int suff[n];
        ll count = 0;
        
        unordered_map<int, vector<ll >> pairs;
        pairs[0].push_back(-1);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);

            if (i == 0) {
                pref[0] = a[i];
            } else {
                pref[i] = pref[i - 1] ^ a[i];
            }
            
            //printf("%d ", pref[i]);
            pairs[pref[i]].push_back(i);
        }

        //printf("\n");

        for (auto p: pairs) {
            int v = p.first;
            auto ids = p.second;
            ll sz = ids.size();
            
            if (sz < 2) continue;
            
            for (ll i = 0; i < sz; i++) {
                count += i*ids[i] - (sz-i-1)*ids[i];
            }
            
            count += -1 * sz*(sz-1)/2;
        }

        printf("%lld\n", count);
    }
}
