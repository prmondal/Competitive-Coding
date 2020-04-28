#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    int casecount = 0;
    while(t--) {
    	casecount++;

    	string s;
        cin >> s;

        string ans = "";

        int l = s[0]-'0';
        for (int i = 1; i <= l; i++) ans += "(";
        ans += s[0];

        int last = l;
        for (int i = 1; i < s.size(); i++) {
            int curr = s[i]-'0';

            if (curr >= last) {
                for (int k = 1; k <= curr-last; k++) {
                    ans += "(";
                    l++;
                }

                ans += s[i];
            } else {
                for (int k = 1; k <= last-curr; k++) {
                    ans += ")";
                    l--;
                }

                ans += s[i];
            }

            last = curr;
        }

        for (int k = 1; k <= l; k++) ans += ")";
        cout << "Case #" << casecount << ": " << ans << "\n";
    }
}