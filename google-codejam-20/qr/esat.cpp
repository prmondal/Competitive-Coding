#include <bits/stdc++.h>
using namespace std;

int query(int i) {
    cout << i << endl;
    int r;
    scanf("%d", &r);
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, b;
    scanf("%d%d", &t, &b);

    while(t--) {
        vector<int> ans(b+1);

        int l = 1; 
        int r = b;
        int q = 1;

        while(l <= r) {
            if (q != 1 && q % 10 == 1) {
                int sameidx = -1;
                int diffidx = -1;

                for (int i = 1; i < l; i++) {
                    if (ans[i] == ans[b+1-i]) {
                        sameidx = i;
                    } else {
                        diffidx = i;
                    }
                }

                if (sameidx != -1) {
                    if (query(sameidx) != ans[sameidx]) {
                        for (int i = 1; i <= l; i++) ans[i] ^= 1;
                        for (int i = r; i <= b; i++) ans[i] ^= 1;
                    }

                    if (diffidx != -1) {
                        if (query(diffidx) != ans[diffidx]) {
                            reverse(ans.begin()+1, ans.end());
                        }
                    } else {
                        query(1);
                    }
                } else {
                    query(1);
                    if (query(diffidx) != ans[diffidx]) {
                        for (int i = 1; i <= l; i++) ans[i] ^= 1;
                        for (int i = r; i <= b; i++) ans[i] ^= 1;
                    }
                }

                q += 2;
            }

            ans[l] = query(l);
            ans[r] = query(r);
            l++, r--;

            q += 2;
        }

        for (int i = 1; i <= b; i++) {
            cout << ans[i];
        }

        cout << endl;

        string check;
        cin >> check;
        if (check == "N") exit(0);
    }
}