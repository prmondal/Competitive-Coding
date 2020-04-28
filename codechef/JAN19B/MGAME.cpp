#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n,p;
	    cin >> n >> p;
	    
	    map<int, int, greater<int>> mp;
	    
	    for(int i = 1; i <= p; i++) {
	        for(int j = 1; j <= p; j++) {
	            for(int k = 1; k <= p; k++) {
	                int r = (((n % i) % j) % k) % n;
	                
	                if(mp.find(r) == mp.end()) {
	                    mp[r] = 1;
	                } else {
	                    mp[r]++;
	                }
	            }
	        }
	    }
	    
	    map<int, int>::iterator it = mp.begin();
	    cout << it->second << endl;
	}
}
