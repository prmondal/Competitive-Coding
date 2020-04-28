#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q,k;
    cin >> n >> q >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int start = 0;
    int end = n - 1;
    for(int i = 0; i < q; i++) {
        if(s[i] == '?') {
            int currMax = 0;
            int maxLen = 0;
            for(int j = start; j <= n - 1; j++) {
                if(a[j] == 1) {
                    currMax++;
                } else {
                    if(currMax <= k) {
                        maxLen = max(currMax, maxLen); 
                        currMax = 0;
                    }
                }
            }
            for(int j = 0; j <= end && start > end; j++) {
               if(a[j] == 1) {
                    currMax++;
                } else {
                    if(currMax <= k) {
                        maxLen = max(currMax, maxLen); 
                        currMax = 0;
                    }
                } 
            }
            cout << min(k, max(maxLen, currMax)) << endl;
        } else {
            if(start == 0) {
                start = n - 1;
            } else {
                start--;
            }
            end = start - 1;
        }
    }
}
