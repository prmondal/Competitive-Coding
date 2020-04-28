#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,a,x,b,y;
    cin >> n >> a >> x >> b >> y;

    bool theyMeet = false;
    
    x++;
    y--;
    
    if (x > n) x = 1;
    if (y < 1) y = n;
    
    while(true) {
        if (a == b) {
            theyMeet = true;
            break;
        }
        
        a++;
        b--;
        
        if (a > n) a = 1;
        if (b < 1) b = n;
        
        if (a == x || b == y) break;
    }

    cout << (theyMeet ? "YES" : "NO") << endl;
}