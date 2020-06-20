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

inline ll count2(ll num) {
	ll count = 0;
	while(!(num & 1)) {
		num = num >> 1;
		count++;
	}

	return count;
}

inline ll fpow(ll x, int p) {
    ll ans = 1;

    while(p) {
        if (p&1) ans = ans * x;
        p = p >> 1;
        x = x * x;
    }

    return ans;
}

void solve() {
	ll ts;
	cin >> ts;

	if (ts == 1) {
		cout << 0 << endl;
		return;
	}

	ll ans = 0, i;
	
	if (ts & 1) {
		ans = ts / 2;
	} else {
		ll tsCount2 = count2(ts);
		ll start = fpow(2LL, tsCount2+1);
		ans = ts/start;
	}

	cout << ans << endl;
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