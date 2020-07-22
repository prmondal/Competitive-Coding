#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a-1;i>=b;i--)
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
#define inf (1000*1000*1000+7)
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

void solve() {
	int n;
	cin>>n;

	ll a[n], b[n];
	int i;
	unordered_map<ll,ll> m;
    ll gmin = LLONG_MAX;

	rep(i,n) {
        cin>>a[i];
		m[a[i]]++;
        gmin = min(gmin, a[i]);
	}

	rep(i,n) {
        cin>>b[i];
		m[b[i]]++;
        gmin = min(gmin, b[i]);
	}

    unordered_map<ll,ll> valid;

	for (auto& e: m) {
		if (e.second & 1) {
			cout << -1 << "\n";
			return;
		} else {
            valid[e.first] = e.second/2;
        }
	}
    
    unordered_map<ll,ll> curr = valid;
    vl v1, v2;
    rep(i,n) {
        if (curr[a[i]]) {
            curr[a[i]]--;
        } else {
            v1.pb(a[i]);
        }
    }

    curr = valid;
    rep(i,n) {
        if (curr[b[i]]) {
            curr[b[i]]--;
        } else {
            v2.pb(b[i]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<ll>());

    if (v1.size() != v2.size()) {
        cout << -1 << "\n";
        return;
    }

    if (v1.size() == 0) {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    int s = v1.size();

    rep(i,s) {
        ans += min(2LL*gmin, min(v1[i], v2[i]));
    }

    cout << ans << "\n";
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