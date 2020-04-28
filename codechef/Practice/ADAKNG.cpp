#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int r,c,k;
        cin >> r >> c >> k;
        int cnt = 0;
        for(int i = 1; i <= 8; i++) {
            for(int j = 1; j <= 8; j++) {
                if(max(abs(r-i), abs(c-j)) <= k) cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
