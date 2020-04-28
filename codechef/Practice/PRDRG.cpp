#include <bits/stdc++.h>
using namespace std;
typedef struct {
    long long x, y;
} Frac;
const int N = 50;
int main() {
    Frac a[N];
    a[0].x = 1;
    a[0].y = 1;
    a[1].x = 1;
    a[1].y = 2;
    
    for(int i = 2; i < N; i++) {
        if(i % 2 == 0) {
            a[i].x = 2*a[i-1].x - 1;
        } else {
            a[i].x = a[i-1].y - a[i-1].x;
        }
        
        a[i].y = a[i-1].y * 2;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Frac f = a[n];
        cout << a[n].x << " " << a[n].y << endl;
    }
}
