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
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;

const int mod = 1e9 + 7;

int main() {
    fastio;
    string s;
    cin >> s;

    int n = (int) s.size();

    ll ans = 0;
    ll right = 0;
    ll p = 1;

    for (ll i = n-1; i >= 0; i--) {
        ll val = s[i]-'0';
        ll kk = i*(i+1)/2;
        ll left = kk*p%mod;
        left = (left + right) % mod;
        right = (right + p*(n-i)%mod) % mod;
        ans = (ans + val * left % mod) % mod;
        p = (10*p) % mod;
    }

    cout << ans << endl;

}
