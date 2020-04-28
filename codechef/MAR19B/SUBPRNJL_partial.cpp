#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        long n, k;
        cin >> n >> k;

        long a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        long ans = 0;
        
        map<long, long, greater<long>> psm;
        
        for(int l = 1; l <= n; l++) {
            map<long, long, greater<long>> mp;
            
            if(l == 1) {
                for(int i = 0; i <= n-1; i++) {
                    if(i > 0) {
                        mp.erase(a[i-1]);
                        mp[a[i]] = 1;
                    } else {
                        mp[a[i]] = 1;
                        psm = mp;
                    }
                    
                    if(mp.count(1) > 0) ans++;
                } 
            } else {
                for(int i = 0; i <= n-l; i++) {
                    int s = i;
                    int e = i+l-1;
                    
                    if(i > 0) {
                        mp[a[s-1]]--;
                        auto it = mp.find(a[s-1]);
                        if(it->second == 0) mp.erase(it);
                    } else {
                        mp = psm;
                    }
                    
                    if(mp.count(a[e]) > 0) {
                        mp[a[e]]++;
                    } else {
                        mp[a[e]] = 1;
                    }
                    
                    if(i == 0) {
                        psm = mp;
                    }
                    
                    long m = ceil((double)k/l);
                    long kk = k%m == 0 ? k/m : k/m+1;
                    
                    if(kk == l) {
                        auto it = mp.begin();
                        if(mp.count(it->second) > 0) ans++;
                    } else if(kk == 1) {
                        auto it = mp.rbegin();
                        if(mp.count(it->second) > 0) ans++;
                    } else {
                        long sum = 0;
                        auto it = mp.rbegin();

                        while(it != mp.rend()) {
                            sum += it->second;

                            if(sum >= kk) {
                                if(mp.count(it->second) > 0) ans++;

                                break;
                            } else {
                                it++;
                            }
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
}
