#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    int a[n];

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    
    int ans = 0;

    for(int i = n - 2; i >= 0; i--) {
        if(a[i] % a[n-1] != 0) {
            ans = a[i];
            break;
        }
    }

    cout << ans << endl;
}
