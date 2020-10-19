#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define bit(x,i) (x&(1<<i))
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << endl

const int inf = 1e9+7;
const ll infl = (ll)1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;

    vl v(n);
    rep(i,n) cin >> v[i];

    ll ans = 1;
    if (n == 5) {
        rep(i,n) ans *= v[i];
        cout << ans << endl;
        return;
    }

    sort(all(v));

    int lastNegIdx = -1;
    rep(i,n) {
        if (v[i]>= 0) {
            lastNegIdx = i-1;
            break;
        }
    }

    if (lastNegIdx < 1) {
        for (int i = n - 1; i >= n - 5; i--)
            ans *= v[i];
        
        cout << ans << endl;
        return;
    }
    
    ans = v[n-1]*v[n-2]*v[n-3]*v[n-4]*v[n-5];

    if (lastNegIdx >= 4) {
        ll prod = 1;
        for (int i = 0; i <= 4; i++) {
            prod *= v[i];
        }

        ans = max(ans, prod);
    }

    if (lastNegIdx >= 3) {
        ll prod = 1;
        for (int i = 0; i <= 3; i++) {
            prod *= v[i];
        }
        prod *= v[n-1];
        ans = max(ans, prod);
    }
    
    if (lastNegIdx >= 1) {
        ll prod = 1;
        for (int i = 0; i <= 1; i++) prod *= v[i];
        prod *= v[n-1]*v[n-2]*v[n-3];
        ans = max(ans, prod);
    }

    cout << ans << endl;
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}