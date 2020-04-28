#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        long x, k;
        cin>>x>>k;

        long nofactors = 0;

        while(x%2 == 0) {
            nofactors++;
            x = x/2;
        }

        int sq = sqrt(x);
        for (int i = 3; i < sq; i+=2) {
            while(x%i == 0) {
                nofactors++;
                x = x/i;
            }
        }

        if(x > 2) nofactors++;

        if (nofactors >= k) {
            cout << "1" << "\n";
        } else {
            cout << "0" << "\n";
        }
    }
}
