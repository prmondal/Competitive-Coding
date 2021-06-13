// https://www.spoj.com/problems/BUGLIFE
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

#define TEST

// Use mt19937_64 for 64 bit random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(l, r) uniform_int_distribution<int>(l, r)(rng)
#define shuf(v) shuffle(all(v), rng);

const int INF = 0x3f3f3f3f;
const ll INFL = 1LL << 61;
const double PI  = acos(-1);
const double EPS = 1e-9;
const int MAXN = 2021;

vi adj[MAXN];
int color[MAXN];
int k = 1;

bool dfs(int st) {
    bool valid = true;
    
    for (const auto& e: adj[st]) {
        if (color[e] != -1) {
            if (color[e] == color[st]) return false;
            continue;
        }

        color[e] = 1 - color[st];
        valid &= dfs(e);
    }

    return valid;
}

void solve() {
    int n,m;
    cin >> n >> m;
    int i;

    rep(i,MAXN) adj[i].clear();
    memset(color, -1, sizeof color);

    rep(i,m) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    f(i,1,n+1) {
        if (color[i] < 0) {
            color[i] = 0;
            if (!dfs(i)) {
                cout << "Scenario #" << k++ << ":" << endl;
                cout << "Suspicious bugs found!" << endl;
                return;
            }
        }
    }
    
    cout << "Scenario #" << k++ << ":" << endl;
    cout << "No suspicious bugs found!" << endl;
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