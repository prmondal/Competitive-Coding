#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	
	long a[n], b[m];
	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int j = 0; j < m; j++) cin >> b[j];
	
	unordered_map<long, pair<int, int>> mp;
	
	int ii = 0, jj = 0, t = 0;
	
    while(jj < m && t < n+m-1) {
        long sum = a[ii] + b[jj];
        mp[sum] = make_pair(ii, jj);
        cout << ii << " " << jj << endl;
        t++;
        jj++;
    }
    
    if(t < n+m-1) {
        ii = 1;
        jj = 0;
    }
    while(ii < n && t < n+m-1) {
        long sum = a[ii] + b[jj];
        
        if(mp.find(sum) == mp.end()) {
            mp[sum] = make_pair(ii, jj);
            cout << ii << " " << jj << endl;
            t++;
        }
        
        ii++;
        
        if(ii == n && t < n+m-1) {
            jj++;
            ii = 1;
        }
    }
}
