#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int atk[n], def[n];
        map< int, vector<int>, greater<int> > m;
        
        for(int i = 0; i < n; i++) {
            cin >> atk[i];
        }
        
        for(int i = 0; i < n; i++) {
            cin >> def[i];
            int d = def[i];
            
            if(m.find(d) == m.end()) {
                vector<int> v;
                v.push_back(i);
                m[d] = v;
            } else {
                m[d].push_back(i);
            }
        }
        
        int ans = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            for(auto v: it->second) {
                int l = v-1, r = (v+1)%n;
                if(l < 0) {
                    l = n-1;
                }
                if(!(atk[l] >= def[v] || atk[r] >= def[v] || atk[l] + atk[r] >= def[v])) {
                    ans = def[v];
                    break;
                }
            }
            if(ans) break;
        }
        if(ans <= 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
