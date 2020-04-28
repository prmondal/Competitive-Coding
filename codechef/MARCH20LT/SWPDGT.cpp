#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        string as = to_string(a);
        string bs = to_string(b);
        int ans = -99999;

        if (a >= 10 && b >= 10) {
            int a1 = 10*(as[1]-'0')+(bs[1]-'0');
            int a2 = 10*(as[0]-'0')+(bs[0]-'0');
            ans = max(ans, a1+a2);

            a1 = 10*(bs[0]-'0')+(as[0]-'0');
            a2 = 10*(bs[1]-'0')+(as[1]-'0');
            ans = max(ans, a1+a2);

            a1 = 10*(as[0]-'0')+(bs[1]-'0');
            a2 = 10*(bs[0]-'0')+(as[1]-'0');
            ans = max(ans, a1+a2);
            cout << max(ans, a+b) << endl;
        } else if (a >= 10 && b < 10) {
            int a1 = 10*(bs[0]-'0')+(as[1]-'0');
            int a2 = as[0]-'0';
            ans = max(ans, a1+a2);
            cout << max(ans, a+b) << endl;
        } else if (b >= 10 && a < 10) {
            int a1 = bs[0]-'0';
            int a2 = 10*(as[0]-'0')+(bs[1]-'0');

            ans = max(ans, a1+a2);
            cout << max(ans, a+b) << endl;
        } else {
            cout << a + b << endl;
        }
    }
}
