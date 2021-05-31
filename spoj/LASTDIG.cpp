#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int a,b;
    cin >> a >> b;
    
    if (b==0) {
        cout << 1 << "\n";
        return;
    }

    a = a%10;

    if (a==0 || a==1 || a==5 || a==6) {
        cout << a << "\n";
    } else if (a==4 || a==9) {
        cout << (int)pow(a,b%2==0?2:b%2)%10 << "\n";
    } else {
        cout << (int)pow(a,b%4==0?4:b%4)%10 << "\n";
    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }    
}