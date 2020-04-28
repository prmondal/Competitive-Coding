#include <bits/stdc++.h>
using namespace std;
long fact(int n) {
    if(n == 1 || n == 0) return 1;
    return n * fact(n - 1);
}
long gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        long a[n], b[n], d[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
            d[i] = a[i];
        }
        map<int, pair<int, int>> mp;
        vector<int> v;
        for(int i = 0; i < m; i++) {
            int s, e;
            cin >> s >> e;
            reverse(a + s - 1, a + e);
            mp[i] = make_pair<int, int>(s - 1, e - 1);
            v.push_back(i);
        }
        int c = 1;
        while(next_permutation(v.begin(), v.end())) {
            for(int i = 0; i < m; i++) {
                int ss = mp[v[i]].first;
                int ee = mp[v[i]].second;
                reverse(d + ss, d + ee + 1);
            }
            bool matched = true;
            for(int i = 0; i < n; i++) {
                if(a[i] != d[i]) {
                    matched = false;
                    break;
                }
            }
            if(matched) c++;
            for(int i = 0; i < n; i++) {
                d[i] = b[i];
            }
        }
        
        long f = fact(m);
        long g = gcd(c, f);
        long p = c / g;
        long q = f / g;
        cout << p << "/" << q << endl;
    }
}
