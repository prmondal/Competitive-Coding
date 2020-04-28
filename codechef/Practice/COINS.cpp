#include <iostream>
using namespace std;
long dollar(long n, long a[]) {
    if(n==0 || n==1) return n;
    if(a[n]) return a[n];
    return a[n] = max(n, dollar(n/2, a) + dollar(n/3, a) + dollar(n/4, a));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n;
    while(cin >> n) {
        long* a = new long[n+1];
        a[0] = a[1] = 1;
        cout << dollar(n, a) << endl;
    }
}
