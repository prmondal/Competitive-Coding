#include <bits/stdc++.h>
using namespace std;
int index(string d) {
    if(d == "saturday") return 0;
    if(d == "sunday") return 1;
    if(d == "monday") return 2;
    if(d == "tuesday") return 3;
    if(d == "wednesday") return 4;
    if(d == "thursday") return 5;
    if(d == "friday") return 6;
}
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    string s,e; int l,r;
	    cin >> s >> e >> l >> r;
	    
	    int dur = index(e) - index(s);
	    
	    if(dur >= 0) dur += 1;
	    else dur += 8;
	    
	    int count = 0;
	    int result = 0;
	    
	    for(int i = 0; i < 15; i++) {
	        int j = dur + 7*i;
	        if(j >= l && j <= r) {
	            count++;
	            if(count == 1) result = j;
	        }
	    }
	    
	    if(count == 0) cout << "impossible" << endl;
	    else if(count == 1) cout << result << endl;
	    else cout << "many" << endl;
	}
}
