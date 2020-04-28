#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    int idx = 0;

    while(idx < n && s[idx] != '+') {
        idx++;
    }

    while(idx < n) {
        if (s[idx] == '-') {
            ans--;

            if(ans < 0) ans = 0;
        } else {
            ans++;
        }

        idx++;
    }

    cout << ans << endl;
}