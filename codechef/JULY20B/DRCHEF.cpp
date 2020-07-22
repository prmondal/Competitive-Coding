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
	ll n,x,i;
	cin>>n>>x;

	vector<ll> v1,v2;

	rep(i,n) {
		ll a;
		cin>>a;

		if (x >= a) {
			v1.pb(a);
		} else {
			v2.pb(a);
		}
	}

	sort(v2.begin(), v2.end());

	ll days = 0;

	for (auto& e: v2) {
		if (x >= e) {
			x = 2*e;
			days++;
		} else {
			while(x < e) {
				x = 2*x;
				days++;
			}

			days++;
			x = 2*e;
		}
	}

	ll ans1 = days + (ll) v1.size();

	if (v1.size() > 0) {
		sort(v1.begin(), v1.end());
		v2.insert(v2.begin(), v1[v1.size()-1]);
		days = 0;

		for (auto& e: v2) {
			if (x >= e) {
				x = 2*e;
				days++;
			} else {
				while(x < e) {
					x = 2*x;
					days++;
				}

				days++;
				x = 2*e;
			}
		}

		cout << min(ans1, days + (ll)v1.size()-1);
	} else {
		cout << days << endl;
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