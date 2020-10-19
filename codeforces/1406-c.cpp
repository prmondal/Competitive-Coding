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

const int nax = 1e5 + 7;
int par[nax];
int sz[nax];
vector<vi> adj(nax);
int cent1 = -1, cent2 = -1;
int mn = nax;
int n;
int leaf = -1;

void dfs(int x, int p) {
    par[x] = p;
    sz[x]++;
    int mx = 0;

    for(auto e: adj[x]) {
        if (e == p) continue;

        dfs(e, x);
        sz[x] += sz[e];
        mx = max(mx, sz[e]);
    }

    mx = max(mx, n-sz[x]);

    if (mx < mn) cent1 = x, mn = mx, cent2 = -1;
    else if (mx == mn) cent2 = x;
}

void dfs2(int x, int p) {
    if (sz[x] == 1) {
        leaf = x;
        return;
    }

    for (auto e: adj[x]) {
        if (e != p) {
            return dfs2(e,x);
        }
    }
}

void solve() {
    cin >> n;

    f(i,1,n+1) {
        par[i] = -1;
        sz[i] = 0;
        adj[i].clear();
        cent1 = -1, cent2 = -1;
        mn = nax;
        leaf = -1;
    }

    rep(i, n-1) {
        int x,y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,0);
    
    //cout << "::" << cent1 << " " << cent2 << endl;
    
    if (cent2 == -1) {
        printf("1 %d\n1 %d\n", adj[1][0], adj[1][0]);
        return;
    }

    dfs2(cent1,par[cent1]);
    printf("%d %d\n%d %d\n", par[leaf], leaf, cent2, leaf);
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}