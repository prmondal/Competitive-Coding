#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    int s = 0;
    while(t--) {
    	s++;

    	int n;
    	cin>>n;
    	int a[n][n];

    	int k = 0, r = 0, c = 0;
    	bool duplicate;
    	int ca[n+1];

    	for (int i = 0; i < n; i++) {
    		duplicate = false;
    		memset(ca, 0, sizeof ca);

    		for (int j = 0; j < n; j++) {
    			cin >> a[i][j];

				if (i==j) k += a[i][j];

				if (ca[a[i][j]] > 0 && !duplicate) {
					r++;
					duplicate = true;
				} else if (!duplicate) {
					ca[a[i][j]]++;
				}
    		}
    	}

    	for (int j = 0; j < n; j++) {
    		duplicate = false;
    		memset(ca, 0, sizeof ca);

    		for (int i = 0; i < n; i++) {
    			if (ca[a[i][j]] > 0 && !duplicate) {
					c++;
					duplicate = true;
				} else if (!duplicate) {
					ca[a[i][j]]++;
				}
    		}
    	}

    	cout << "Case #" << s << ": " << k << " " << r << " " << c << "\n";
    }
}