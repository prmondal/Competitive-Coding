//Problem Link - https://www.spoj.com/problems/COT2/
 
#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define repr(i,n) for(int i=n-1;i>=0;i--)
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
#define uniq(v) v.erase(v.unique(all(v)), v.end())
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << endl
 
//#define TEST
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;
const int MAXN = 1e5+7;
const int MAXD = 18;
 
int d[MAXN], anc[MAXN][MAXD];
int st[MAXN], et[MAXN], lookup[MAXN << 1];
int vis[MAXN];
vi freq(MAXN,0);
vi adj[MAXN];
int ans = 0;
int epoch = 0;
 
inline ll gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = 1LL << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct Query {
    int l;
    int r;
    int idx;
    int lcaIdx;
    ll ord;
 
    Query() {}
 
    Query(int l, int r, int idx, int lcaIdx): l(l), r(r), idx(idx), lcaIdx(lcaIdx) {
        ord = gilbertOrder(l, r, 21, 0);
    }
 
    bool operator<(const Query& o) const {
        return ord < o.ord;
    }
};
 
inline void dfs(int u, int p) {
    anc[u][0] = p;
    st[u] = ++epoch;
    lookup[st[u]] = u;
 
    for(int i = 1; i < MAXD; i++)
        anc[u][i] = anc[anc[u][i-1]][i-1];
 
    for(const auto& v : adj[u]) {
        if(v == p)
            continue;
 
        d[v] = d[u] + 1;
        dfs(v, u);
    }
 
    et[u] = ++epoch;
    lookup[et[u]] = u;
}
 
inline int lca(int u, int v) {
    if(d[u] < d[v])
        swap(u, v);
 
    for(int i = MAXD - 1; ~i; i--)
        if(d[u] - d[v] >= (1<<i))
            u = anc[u][i];
 
    if(u == v)
        return u;
 
    for(int i = MAXD - 1; ~i; i--) {
        if(anc[u][i]^anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
 
    return anc[u][0];
}

void addRemove(int x, const vi& arr) {
    int u = lookup[x];

    if (!vis[u]) {
        if (freq[arr[u]]++ == 0) ans++;
    } else {
        if (freq[arr[u]]-- == 1) ans--;
    }

    vis[u] ^= 1;
}

void solve() {
    int n, q, i;
    cin >> n >> q;
 
    vi arr(n+1), tempArr;
    rep(i,n) {
        cin >> arr[i+1];
        tempArr.pb(arr[i+1]);
    }
 
    sort(all(tempArr));
    tempArr.erase(unique(all(tempArr)), tempArr.end());
 
    rep(i,n) {
        arr[i+1] = lower_bound(all(tempArr), arr[i+1]) - tempArr.begin() + 1;
    }
 
    tempArr.clear();
    
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(1,-1);
    
    vector<Query> queries;
    vi answer(q);
 
    rep(i,q) {
        int l,r;
        cin >> l >> r;
 
        if (st[l] > st[r]) {
            swap(l,r);
        }
        
        int lcaIdx = lca(l,r);
 
        if (lcaIdx == l) {
            l = st[l];
            r = st[r];
        } else {
            l = et[l];
            r = st[r];
        }
 
        queries.emplace_back(l,r,i,lcaIdx);
    }
 
    sort(all(queries));
 
    int currL = 1;
    int currR = 0;
    
    for (const auto& q: queries) {
        int qL = q.l;
        int qR = q.r;
        int qIdx = q.idx;
        int lcaIdx = q.lcaIdx;
        
        while (currR < qR) {
            currR++;
            addRemove(currR, arr);
        }
 
        while (currR > qR) {
            addRemove(currR, arr);
            currR--;
        } 
 
        while (currL < qL) {
            addRemove(currL, arr);
            currL++;
        }
 
        while (currL > qL) {
            currL--;
            addRemove(currL, arr);
        }
 
        // INCLUDE LCA
        if (lcaIdx != lookup[qL]) {
            addRemove(st[lcaIdx], arr);
        }
 
        answer[qIdx] = ans;
 
        // EXCLUDE LCA
        if (lcaIdx != lookup[qL]) {
            addRemove(st[lcaIdx], arr);
        }
    }
 
    rep(i,q) {
        cout << answer[i] << "\n";
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