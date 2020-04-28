#include <bits/stdc++.h>
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

        vector<string> v;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        unordered_map<string, int> m;

        for(auto s: v) {
            int check[26] = {0};
            string k = "";

            for(auto c: s) {
                int key = c - 'a';

                if(!check[key]) {
                    check[key] = 1;
                    k += c;
                }
            }

            sort(k.begin(), k.end());

            if(m.find(k) != m.end()) {
                m[k]++;
            } else {
                m[k] = 1;
            }
        }

        string vowels = "aeiou";
        long ll = vowels.length();
        vector<string> sub;
        
        for(int i = 1; i <= pow(2, ll) - 1; i++) {
            string ss = "";
            
            for(int j = 0; j <= ll - 1; j++) {
                if(i & (1 << j)) {
                    ss += vowels[j];
                }
            }
            
            sub.push_back(ss);
        }
        
        long ans = 0;
        int l = sub.size();
        
        for(int i = 0; i < l; i++) {
            for(int j = i + 1; j < l; j++) {
                string s1 = sub[i];
                string s2 = sub[j];
                
                unordered_set<char> st;
                
                for(auto c1: s1) {
                    st.insert(c1);    
                }
                
                for(auto c2: s2) {
                    st.insert(c2);
                }
                
                if(m.find(s1) != m.end() && m.find(s2) != m.end() && st.size() == ll) {
                    //cout << s1 << " " << s2 << endl;
                    ans += m[s1] * m[s2];
                }
            }
        }
        
        if(m.find(vowels) != m.end() && m[vowels] > 1) {
            ans += m[vowels] * (m[vowels] - 1) / 2;
        }
        
        cout << ans << endl;
    }
}