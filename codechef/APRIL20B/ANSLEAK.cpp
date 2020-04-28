#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        for(int i = 0; i < n; i++) {
            int c[m+1];
            memset(c, 0, sizeof c);

            for (int j = 0; j < k; j++) {
                int answer;
                cin>>answer;
                c[answer]++;
            }

            int idx = -1;
            int mx = 0;
            for (int p = 1; p <= m; p++) {
                if (c[p] > mx) {
                    mx = c[p];
                    idx = p;
                }
            }

            if (i == n - 1) 
                cout << idx << endl;
            else
                cout << idx << " ";
        }
    }
}