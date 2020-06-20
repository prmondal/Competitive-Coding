#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
    	string a,b;
    	cin>>a>>b;

    	ll k = 0;
    	ll l = 0;
    	int n = a.size();

    	vector<int> gap;
    	int i = 0, j = 0;
    	bool inIsland = false;

    	while (j < n) {
    		if (a[j] == b[j] && inIsland) {
    			j++;
    		} else if (a[j] == b[j]) {
    			inIsland = true;
    			j++;
    		} else if (inIsland) {
    			inIsland = false;
    			if (i > 0) gap.push_back(j-i); //ignore start island
    			i = j;
    			k++;
    		} else {
    			i++;
    			j++;
    			l++;
    		}
    	}

    	// ignore last island if any

    	// handle case if start is island
    	if (a[0] != b[0])
    		++k; // number of unequal group = number of island + 1

    	sort(gap.begin(), gap.end());

    	ll ans = k*l;
    	int kk = k;
    	for (int i = 1; i <= kk-1; i++) {
    		l += gap[i-1];
    		k--;

    		ans = min(ans, k*l);
    	}

    	cout << ans << "\n";
    }
}

/*
1
aaabsbsbsbsbsbdddddjkfkfkkfkd
aaikdskdjkwkssnbbbbddskklkkkd
25

1
bbabbccaabcccacabcbc
ccbbbcbabcaccabbaccc
19
*/