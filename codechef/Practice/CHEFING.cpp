#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    int c[26] = {0};
	    
	    for(int i = 1; i <= n; i++) {
	        string s;
	        cin >> s;
	        
	        bool b[26] = {0};
	        
	        for(auto ch: s) {
	            int k = ch - 'a';
	            
	            if(!b[k]) {
	                b[k] = 1;
	                c[k]++;
	            }
	        }
	    }
	    
	    int ans = 0;
	    
	    for(int i = 0; i < 26; i++) {
	        if(c[i] == n) ans++;
	    }
	    
	    cout << ans << endl;
	}
}
