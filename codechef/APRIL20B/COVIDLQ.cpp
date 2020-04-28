#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n];
        bool possible = true;
        vector<int> v;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                v.push_back(i);
            }
        }
        
        int size = v.size();
        if (size > 1) {
            for (int i = 1; i < size; i++) {
                if (v[i]-v[i-1] < 6) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
