#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        map<int, vector<int>> m;
        map<int, vector<int>>::iterator it;
        
        int n;
        cin >> n;
        long a[n];
        bool b[100001] = {false};
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[a[i]] = true;
            
            it = m.find(a[i]);
            
            if(it != m.end()) {
                (it->second).push_back(i+1);
            } else {
                vector<int> v;
                v.push_back(i+1);
                m[a[i]] = v; 
            }
        }
        
        bool found = false;
        
        for(it = m.begin(); it != m.end() && !found; it++) {
            vector<int> v = it->second;
            
            if(v.size() > 1) {
                /*cout << it->first << " - ";
                for(auto idx : v) cout << idx << ", ";
                cout << endl;*/
            
                int c = 0;
                for(auto idx : v) {
                    if(b[idx]) c++;
                    if(c >= 2) {
                        found = true;
                        break;
                    }
                }
            }
        }
        
        cout << (found ? "Truly Happy" : "Poor Chef") << endl;
    }
}
