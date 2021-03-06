//Problem Link - https://www.spoj.com/problems/XXXXXXXX/
 
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
const int maxn = 50007;
 
int BLOCK_SIZE;
int arr[maxn], arrCopy[maxn];
ll ans = 0;
int freq[maxn];
 
struct Query {
    int l;
    int r;
    int idx;
    int block;
    int updateNumber;
 
    Query() {}
 
    Query(int l, int r, int idx, int updateNumber): l(l), r(r), idx(idx), updateNumber(updateNumber) {
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
 
void solve() {
    int n,i;
    cin >> n;
    BLOCK_SIZE = pow(n, 0.67);

    vi compressionHelperCache;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        compressionHelperCache.pb(arr[i]);
    }

    int q;
    cin >> q;

    vector<Query> queries;
    vii updateQueriesTemp;
    int queryIdx = 0;

    rep(i,q) {
        string t;
        int l,r;
        cin >> t >> l >> r;
 
        if (t == "U") {
            updateQueriesTemp.pb({l, r});
            compressionHelperCache.pb(r);
        } else {
            queries.emplace_back(l, r, queryIdx++, (int) updateQueriesTemp.size());
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
        int qL = q.l;
        int qR = q.r;
        int qIdx = q.idx;
 
        while (currUpdateIdx < q.updateNumber) {
            auto u = updates[currUpdateIdx];
            
            if (currL <= u.idx && currR >= u.idx) {
                if (freq[arr[u.idx]]-- == 1) ans -= compressionHelperCache[arr[u.idx]-1];
            }
 
            arr[u.idx] = u.newVal;
 
            if (currL <= u.idx && currR >= u.idx) {
                if (freq[arr[u.idx]]++ == 0) ans += compressionHelperCache[arr[u.idx]-1];
            }
 
            currUpdateIdx++;
        }
 
        while (currUpdateIdx > q.updateNumber) {
            currUpdateIdx--;
            auto u = updates[currUpdateIdx];
            
            if (currL <= u.idx && currR >= u.idx) {
                if (freq[arr[u.idx]]-- == 1) ans -= compressionHelperCache[arr[u.idx]-1];
            }
 
            arr[u.idx] = u.oldVal;
 
            if (currL <= u.idx && currR >= u.idx) {
                if (freq[arr[u.idx]]++ == 0) ans += compressionHelperCache[arr[u.idx]-1];
            }
        }
 
        while (currR < qR) {
            currR++;
            if (freq[arr[currR]]++ == 0) ans += compressionHelperCache[arr[currR]-1];
        }
 
        while (currR > qR) {
            if (freq[arr[currR]]-- == 1) ans -= compressionHelperCache[arr[currR]-1];
            currR--;
        } 
 
        while (currL < qL) {
            if (freq[arr[currL]]-- == 1) ans -= compressionHelperCache[arr[currL]-1];
            currL++;
        }
 
        while (currL > qL) {
            currL--;
            if (freq[arr[currL]]++ == 0) ans += compressionHelperCache[arr[currL]-1];
        }
 
        answer[qIdx] = ans;
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