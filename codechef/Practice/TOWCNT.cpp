#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct tower {
    int id;
    ll x;
    ll a;
    int t;
};

void solve() {
    ll h, n;
    cin>>h>>n;

    int ans[n];
    memset(ans, 0, sizeof ans);
    vector<tower> ts(n);

    for (int i = 0; i < n; i++) {
        tower tw;
        tw.id = i;
        int t;
        ll x, a;
        cin >> tw.t >> tw.x >> tw.a;
        ts[i] = tw;
    }

    sort(ts.begin(), ts.end(), [](const tower& t1, const tower& t2) {
        return t1.x < t2.x;
    });
    
    for (int i = 0; i < n-1; i++) {
        bool down = false;
        bool up = false;
        ll num_down, den_down, num_up, den_up;

        if (ts[i+1].t == 0) {
            down = 1;
            num_down = ts[i+1].a - ts[i].a;
            den_down = ts[i+1].x - ts[i].x;
        } else {
            up = 1;
            num_up = ts[i+1].a - ts[i].a;
            den_up = ts[i+1].x - ts[i].x;
        }

        ans[ts[i+1].id]++;
        ans[ts[i].id]++;

        for (int j = i+2; j < n; j++) {
            ll num = ts[j].a - ts[i].a;
            ll den = ts[j].x - ts[i].x;
            
            if (down && up) {
                if (num * den_down > num_down * den && num * den_up < num_up * den) {
                    ans[ts[j].id]++;
                    ans[ts[i].id]++;
                }
            } else if (down) {
                if (num * den_down > num_down * den) {
                    ans[ts[j].id]++;
                    ans[ts[i].id]++;
                }
            } else {
                if (num * den_up < num_up * den) {
                    ans[ts[j].id]++;
                    ans[ts[i].id]++;
                }
            }

            if (ts[j].t == 0) {
                if (!down) {
                    down = true;
                    num_down = num;
                    den_down = den;
                } else {
                    if (num * den_down > num_down * den) {
                        num_down = num;
                        den_down = den;
                    }
                }
            } else {
                if (!up) {
                    up = true;
                    num_up = num;
                    den_up = den;
                } else {
                    if (num * den_up < num_up * den) {
                        num_up = num;
                        den_up = den;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " "; 
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}