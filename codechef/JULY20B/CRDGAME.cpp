#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ll digitSum(ll a) {
	ll ans = 0;
	while(a) {
		ans += a%10;
		a/=10;
	}

	return ans;
}

void solve() {
	int n,i;
	cin>>n;

	ll ap = 0;
	ll bp = 0;

	rep(i,n){
		ll a,b;
		cin>>a>>b;

		ll ads = digitSum(a);
		ll bds = digitSum(b);

		if (ads < bds) {
			bp++;
		} else if (ads > bds) {
			ap++;
		} else if (ads == bds) {
			ap++;
			bp++;
		}
	}

	if (ap == bp) {
		cout << 2 << " " << ap << endl;
	} else if (ap > bp) {
		cout << 0 << " " << ap << endl;
	} else {
		cout << 1 << " " << bp << endl;
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