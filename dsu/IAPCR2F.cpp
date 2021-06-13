// https://www.spoj.com/problems/IAPCR2F/
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

const int MAX_SIZE = 1e3+7; 
int parent[MAX_SIZE], size[MAX_SIZE], cost[MAX_SIZE];
int testCase = 1;

void makeSet(int v) {
    parent[v] = v;
    size[v] = 1;
}
 
int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}
 
void mergeSet(int p, int q) {
    int a = findSet(p);
    int b = findSet(q);
 
    if (a != b) {
        if (size[a] < size[b]) swap(a,b);
        
        parent[a] = b;
        size[b] += size[a];
        cost[b] += cost[a];
        cost[a] = 0;
    }
}

void solve() {
    int n,m;
    cin >> n >> m;

    int i;
    rep(i,n) {
        cin >> cost[i+1];
        makeSet(i+1);
    }

    rep(i,m) {
        int u,v;
        cin >> u >> v;
        mergeSet(u,v);
    }

    vi costs;
    rep(i,n) {
        if (cost[i+1]) costs.pb(cost[i+1]);
    }

    sort(all(costs));
    
    cout << "Case " << testCase++ << ": " << costs.size() << endl;

    int k = costs.size();
    for (int i = 0; i < k; i++) {
        if (i < k)
            cout << costs[i] << " ";
        else 
            cout << costs[i] << endl;
    }
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