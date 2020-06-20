#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define tri2 pair<pii,int>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define viii2 vector<tri2>
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define coutp(i) cout << fixed << setprecision(i)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"

void solve() {
	int n;
	cin>>n;

	int a[n], i;
	
	rep(i,n) {
		cin>>a[i];
	}

	bool possible = true;
	umapi m;

	rep(i,n) {
		int change = a[i] - 5;

		if (change > 0) {
			auto it = m.find(change);

			if (it == m.end()) {
				if (change == 10) {
					it = m.find(5);

					if (it == m.end()) {
						possible = false;
						break;
					}
					
					if (it->second >= 2) {
						m[5] -= 2;
						if (m[5] == 0) m.erase(it);
					} else {
						possible = false;
						break;
					}
				} else {
					possible = false;
					break;
				}
			} else {
				m[change]--;
				if (m[change] == 0) m.erase(it);
			}
		}

		m[a[i]]++;
	}

	if (possible) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}

/*

1 6 5 5 10 15 10 10
NO

1 4 5 10 15 10
NO

*/