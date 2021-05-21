//Problem Link - https://www.codechef.com/FEB17/problems/DISTNUM3
 
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
const int MAXN = 200005;
const int MAXD = 18;
 
int d[MAXN], anc[MAXN][MAXD];
int st[MAXN], et[MAXN], lookup[MAXN];
int vis[MAXN];
vi freq(MAXN,0);
vi adj[MAXN];
int arr[MAXN], arrCopy[MAXN];
const int BLOCK_SIZE = pow(MAXN,0.67);
int ans = 0;
int epoch = 0;

struct Query {
    int l;
    int r;
    int idx;
    int block;
    int updateNumber;
    int lcaIdx;
 
    Query() {}
 
    Query(int l, int r, int idx, int updateNumber, int lcaIdx): l(l), r(r), idx(idx), updateNumber(updateNumber), lcaIdx(lcaIdx) {
        block = l / BLOCK_SIZE;
    }
 
    bool operator<(const Query& o) const {
        if (block != o.block) return block < o.block;
        if (r / BLOCK_SIZE != o.r / BLOCK_SIZE) return r / BLOCK_SIZE < o.r / BLOCK_SIZE;
        return updateNumber < o.updateNumber;
    }
};
 
struct Update {
    int idx;
    int newVal;
    int oldVal;
 
    Update() {}
    Update(int idx, int newVal, int oldVal): idx(idx), newVal(newVal), oldVal(oldVal) {}
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

void addRemove(int x) {
    int u = lookup[x];

    if (!vis[u]) {
        if (freq[arr[u]]++ == 0) ans++;
    } else {
        if (freq[arr[u]]-- == 1) ans--;
    }

    vis[u] ^= 1;
}

void solve() {
    int n,q,i;
    cin >> n >> q;

    vi compressionHelperCache;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        compressionHelperCache.pb(arr[i]);
    }

    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(1,-1);

    vector<Query> queries;
    vii updateQueriesTemp;
    int queryIdx = 0;

    rep(i,q) {
        int t,l,r;
        cin >> t >> l >> r;
 
        if (t == 2) {
            updateQueriesTemp.pb({l, r});
            compressionHelperCache.pb(r);
        } else {
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

            queries.emplace_back(l, r, queryIdx++, (int) updateQueriesTemp.size(), lcaIdx);
        } 
    }

    sort(all(compressionHelperCache));
    compressionHelperCache.erase(unique(all(compressionHelperCache)), compressionHelperCache.end());

    for (int i = 1; i <= n; i++) {
        arr[i] = lower_bound(all(compressionHelperCache), arr[i]) - compressionHelperCache.begin() + 1;
        arrCopy[i] = arr[i];
    }

    vector<Update> updates;
    for (const auto& q: updateQueriesTemp) {
        int idx = q.first;
        int val = lower_bound(all(compressionHelperCache), q.second) - compressionHelperCache.begin() + 1;
        updates.emplace_back(idx, val, arrCopy[idx]);
        arrCopy[idx] = val;
    }

    sort(queries.begin(), queries.end());

    vector<ll> answer(q);
    int currL = 1;
    int currR = 0;
    int currUpdateIdx = 0;

    for (const auto& q: queries) {
        while (currUpdateIdx < q.updateNumber) {
            const auto& u = updates[currUpdateIdx];
            
            if (currL <= st[u.idx] && currR >= st[u.idx]) {
                addRemove(st[u.idx]);
            }

            if (currL <= et[u.idx] && currR >= et[u.idx]) {
                addRemove(et[u.idx]);
            }
 
            arr[u.idx] = u.newVal;
 
            if (currL <= st[u.idx] && currR >= st[u.idx]) {
                addRemove(st[u.idx]);
            }

            if (currL <= et[u.idx] && currR >= et[u.idx]) {
                addRemove(et[u.idx]);
            }
 
            currUpdateIdx++;
        }
 
        while (currUpdateIdx > q.updateNumber) {
            currUpdateIdx--;
            auto u = updates[currUpdateIdx];
            
            if (currL <= st[u.idx] && currR >= st[u.idx]) {
                addRemove(st[u.idx]);
            }

            if (currL <= et[u.idx] && currR >= et[u.idx]) {
                addRemove(et[u.idx]);
            }
 
            arr[u.idx] = u.oldVal;
 
            if (currL <= st[u.idx] && currR >= st[u.idx]) {
                addRemove(st[u.idx]);
            }

            if (currL <= et[u.idx] && currR >= et[u.idx]) {
                addRemove(et[u.idx]);
            }
        }
 
        while (currR < q.r) {
            currR++;
            addRemove(currR);
        }
 
        while (currR > q.r) {
            addRemove(currR);
            currR--;
        } 
 
        while (currL < q.l) {
            addRemove(currL);
            currL++;
        }
 
        while (currL > q.l) {
            currL--;
            addRemove(currL);
        }
 
        // INCLUDE LCA
        if (q.lcaIdx != lookup[q.l]) {
            addRemove(st[q.lcaIdx]);
        }
 
        answer[q.idx] = ans;
 
        // EXCLUDE LCA
        if (q.lcaIdx != lookup[q.l]) {
            addRemove(st[q.lcaIdx]);
        }
    }
 
    for (int i = 0; i < queryIdx; i++) {
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