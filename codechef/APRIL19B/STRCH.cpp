#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string tt;
    getline(cin, tt);
    int t = stoi(tt);

    while(t--) {
        string nn;
        getline(cin, nn);
        int n = stoi(nn);

        string str;
        getline(cin, str);
        
        string s = str.substr(0, n);
        char x = str.substr(n+1).at(0);
        
        long ans = 0;
        int lastIdx = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == x) {
                int ni = i-lastIdx;
                ans += ni*(ni+1)/2;
                lastIdx = i+1;
            }
        }

        if(lastIdx < n) {
            int ni = n-lastIdx;
            ans += ni*(ni+1)/2;
        }

        ans = (long) n*(n+1)/2-ans;
        cout << ans << endl;
    }
}