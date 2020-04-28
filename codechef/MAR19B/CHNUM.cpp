#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long a[n];
        long c1 = 0;
        long c2 = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];

            if(a[i] >= 0) {
                c1++;
            } else {
                c2++;
            }
        }
        
        if(c1 != 0 && c2 != 0) {
            cout << c1 << " " << c2 << endl;
        } else if(c1 != 0) {
            cout << c1 << " " << c1 << endl;
        } else if(c2 != 0) {
            cout << c2 << " " << c2 << endl;
        }
    }
}
