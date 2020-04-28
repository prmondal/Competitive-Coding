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
		int a[n+1], b[n+1];
		bool claim = true;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++) {
			cin >> b[i];
		}
        
        if(a[1] != 0 || b[n] != 0 || a[n] != b[1]) {
			claim = false;
		}
			
		for(int i = 2; i <= n && claim; i++) {
			if(a[i] == 0) {
				claim = false;
				break;
			}
		}
		for(int i = 1; i < n && claim; i++) {
			if(b[i] == 0) {
				claim = false;
				break;
			}
		}
        
        for(int i = 2; i < n && claim; i++) {
			if(a[i] + b[i] < a[n] || a[n] + b[i] < a[i] || b[1] + a[i] < b[i]) {
				claim = false;
				break;
			}
		}
		if(claim) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
