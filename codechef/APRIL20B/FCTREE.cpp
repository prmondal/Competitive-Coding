#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e6+7;
const int MAXN2 = 2e6+7;
const int MAXM = 1e5+7;
const int MAXD = 18;
const int MOD = 1e9+7;

int n, m;
int a[MAXN], vis[MAXN];
int d[MAXN], anc[MAXN][MAXD];
int st[MAXN], et[MAXN], lookup[MAXN];
ll inv[MAXN];

vector<int> adj[MAXN];

int epoch = 0;
ll ftscount = 1;
int BLOCK_SIZE;
ll ans[MAXM];
int spf[MAXN];

vector<pair<int,int>> ftcache[MAXN];
int runningfts[MAXN];

struct Query {
    int l, r, id, lca;
    bool operator < (const struct Query& q) {
        if (l / BLOCK_SIZE != q.l / BLOCK_SIZE) return l < q.l;
        return (l / BLOCK_SIZE & 1) ? r > q.r : r < q.r;
    }

} q[MAXM];

inline void dfs(int u, int p) {
    anc[u][0] = p;
    st[u] = ++epoch;
    lookup[st[u]] = u;

    for(int i = 1; i < MAXD; i++)
        anc[u][i] = anc[anc[u][i-1]][i-1];

    for(int v : adj[u]) {
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

inline void sieve() {
    spf[1] = 1; 

    for (int i=2; i<MAXN; i++) spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<MAXN; j+=i) {
                if (spf[j]==j) spf[j] = i; 
            }
        } 
    } 
}

inline void factors(const int& x) {
    if (x == 1) {
        ftcache[1].push_back({1,1});
        return;
    }

    int y = x;
    while(y > 1) {
        int c = 0;
        int sp = spf[y];
        
        while (y % sp == 0) {
            c++;
            y /= sp;
        }

        if (c > 0) ftcache[x].push_back({sp, c});
    }
}

inline ll mul(const ll& x, const ll& y)
{
    ll z = x * y;
    if (z >= MOD)
        z %= MOD;
    return z;
}

inline ll mod_pow(ll& x, int& p) {
    ll ans = 1;

    while(p) {
        if (p&1) ans = mul(ans, x);
        p = p >> 1;
        x = mul(x, x);
    }

    return ans;
}

inline void toggle(const int& x) {
    int u = lookup[x];
    auto& fts = ftcache[a[u]];

    if (vis[u]) {
        for (auto& e: fts) {
            int& v = e.first;
            int& c = e.second;

            if (runningfts[v] > 0) {
                ftscount = mul(ftscount, inv[runningfts[v] + 1]);
                runningfts[v] -= c;
            }

            ftscount = mul(ftscount, runningfts[v] + 1);
        }
    } else {
        for (auto& e: fts) {
            int& v = e.first;
            int& c = e.second;
            
            if (runningfts[v] > 0) {
                ftscount = mul(ftscount, inv[runningfts[v] + 1]);
            }

            runningfts[v] += c;
            ftscount = mul(ftscount, runningfts[v] + 1);
        }
    }

    vis[u] ^= 1;
}

inline void mo() {
    int currL = 1;
    int currR = 0;

    for (int i = 1; i <= m; i++) {
        while(currR < q[i].r) toggle(++currR);
        while(currL > q[i].l) toggle(--currL);
        while(currR > q[i].r) toggle(currR--);
        while(currL < q[i].l) toggle(currL++);

        if (q[i].lca != lookup[q[i].l]) toggle(st[q[i].lca]);
        ans[q[i].id] = ftscount;
        if (q[i].lca != lookup[q[i].l]) toggle(st[q[i].lca]);
    }
}

void solve() {
    for (int i = 1; i < MAXN; i++) adj[i].clear();
    memset(a, 0, sizeof a);
    memset(d, 0, sizeof d);
    memset(vis, 0, sizeof vis);
    memset(st, 0, sizeof st);
    memset(et, 0, sizeof et);
    memset(lookup, 0, sizeof lookup);
    memset(ans, 0, sizeof ans);
    memset(runningfts, 0, sizeof runningfts);
    ftscount = 1;
    epoch = 0;

    cin>>n;
    for (int i = 1; i <= n-1; i++) {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) cin >> a[i];

    cin>>m;

    anc[1][0] = 1;
    dfs(1, -1);
    BLOCK_SIZE = 1000; //sqrt(epoch); //1500
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin>>u>>v;

        if (st[u] > st[v])
            swap(u, v);

        q[i].id = i;
        q[i].lca = lca(u, v);

        if (q[i].lca == u) {
            q[i].l = st[u];
            q[i].r = st[v];
        } else {
            q[i].l = et[u];
            q[i].r = st[v];
        }
    }

    sort(q+1, q+m+1);
    mo();

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    for (int i = 1; i < MAXN; i++) factors(i);

    //for(int i=1; i<MAXN; i++) inv[i] = mod_pow(i, MOD-2);
    inv[1]=1;
    for(int i=2;i<MAXN;i++)inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}