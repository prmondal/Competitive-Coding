#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int count = 0;

        for(auto c : s) {
            if (c == '1') count++;
        }

        cout << (count % 2 != 0 ? "WIN" : "LOSE") << endl;
    }
}
