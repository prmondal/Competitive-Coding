// Problem link - https://cses.fi/problemset/task/1690/
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define bit(x,i) (x&(1<<i))
#define uniq(v) v.erase(v.unique(all(v)), v.end())
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << "\n"

//#define TEST

// Use mt19937_64 for 64 bit random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(l, r) uniform_int_distribution<int>(l, r)(rng)
#define shuf(v) shuffle(all(v), rng);

const int INF = 0x3f3f3f3f;
const ll INFL = 1LL << 61;
const double PI  = acos(-1);
const double EPS = 1e-9;

const int MOD = 1e9+7;

void solve() {
    int n,m,i;
    cin >> n >> m;
    
    vector<vi> dp((1<<n), vi(n+1,0));
    vi adj[n+1];

    rep(i,m) {
        int a,b;
        cin >> a >> b;
        adj[b].pb(a);
    }

    dp[1][1] = 1;

    for (int s = 2; s < (1<<n); s++) {
        if ((s & (1<<(n-1))) && s != ((1<<n)-1)) continue;
        for (int c = 1; c <= n; c++) {
            if (s & (1<<(c-1))) {
                for (const auto& e: adj[c]) {
                    if (s & (1<<(e-1)))
                        dp[s][c] = (dp[s][c] + dp[s ^ (1<<(c-1))][e]) % MOD;
                }
            }
        }
    }

    cout << dp[(1<<n)-1][n] << endl; 
}

int main() {
    fastio;
#ifdef TEST
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
#else
    solve();    
#endif    
}